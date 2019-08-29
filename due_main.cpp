#include "Arduino.h"
#include "FastLED.h"
#include "defines.h"
#include "vars.h"
#include "prototypes.h"

void setup()
{
	FastLED.addLeds<WS2811_PORTD, 7>(strip, 144);

	FastLED.setBrightness(brightness);

	Serial.begin(BAUD_RATE);
	Serial2.begin(BAUD_RATE);

	pinMode(PIN_ANALOG_IN3, INPUT);
	pinMode(PIN_ANALOG_IN4, INPUT);

	pinMode(PIN_CAP_RESET, OUTPUT);

	pinMode(PIN_MUX1_A, OUTPUT);
	pinMode(PIN_MUX1_B, OUTPUT);
	pinMode(PIN_MUX1_C, OUTPUT);

	pinMode(PIN_MUX2_A, OUTPUT);
	pinMode(PIN_MUX2_B, OUTPUT);
	pinMode(PIN_MUX2_C, OUTPUT);

	pinMode(PIN_MUX1_EN, OUTPUT);
	pinMode(PIN_MUX2_EN, OUTPUT);

	digitalWrite(PIN_MUX1_EN, MUX_ENABLE);
	digitalWrite(PIN_MUX2_EN, MUX_ENABLE);

	pinMode(49, OUTPUT);
	pinMode(47, OUTPUT);

	digitalWrite(49, LOW);
	digitalWrite(47, HIGH);


	rainbowBG();
}

void loop()
{
	read_data();


	rainbowBGCycleV();
	rainbowBGCycleH();


	led_set();
	uart2_rx_bt();
	FastLED.show();
	Serial.println(FastLED.getFPS());
	delay(RESET_DELAY);
}

void read_data()
{
	uint8_t mux_out_addr[3], raw_row, raw_col;
	uint16_t avg[NUM_STRIPS] = { 0 };

	for (raw_row = 0; raw_row < APPROX_SAMPLES - 1; raw_row++)
	{
		for (raw_col = 0; raw_col < NUM_STRIPS; raw_col++)
		{
			raw_data[raw_row][raw_col] = raw_data[raw_row + 1][raw_col];
		}
	}

	for (raw_col = 0; raw_col < 8; raw_col++)
	{
		mux_out_addr[0] = (~raw_col & 0x01);
		mux_out_addr[1] = (~raw_col & 0x02) >> 1;
		mux_out_addr[2] = (~raw_col & 0x04) >> 2;

		digitalWrite(PIN_MUX1_A, mux_out_addr[0]);
		digitalWrite(PIN_MUX1_B, mux_out_addr[1]);
		digitalWrite(PIN_MUX1_C, mux_out_addr[2]);

		raw_data[APPROX_SAMPLES - 1][raw_col] = analogRead(PIN_ANALOG_IN2);

		if (raw_col < 6)
		{
			digitalWrite(PIN_MUX2_A, mux_out_addr[0]);
			digitalWrite(PIN_MUX2_B, mux_out_addr[1]);
			digitalWrite(PIN_MUX2_C, mux_out_addr[2]);

			raw_data[APPROX_SAMPLES - 1][raw_col + 8] = analogRead(PIN_ANALOG_IN3);
		}
	}

	for (raw_row = 0; raw_row < NUM_STRIPS; raw_row++)
	{
		for (raw_col = 0; raw_col < APPROX_SAMPLES; raw_col++)
		{
			avg[raw_row] += raw_data[raw_col][raw_row];
		}
	}

	for (raw_col = 0; raw_col < NUM_STRIPS; raw_col++)
	{
		avg[raw_col] /= APPROX_SAMPLES;

		data[raw_col] = map(avg[raw_col], 0, 1023, MAP_MIN, MAP_MAX);

		if (red_dot[raw_col] <= data[raw_col])
		{
			red_dot[raw_col] = data[raw_col];
			dotSpeed[raw_col] = dotSpeedMax;
			dotSpeedHold[raw_col] = dotSpeedHoldMax;
			dotSpeedCurrent[raw_col] = dotSpeedMax;
			dotSpeedAccelerate[raw_col] = dotSpeedAccelerateMax;
		}
		else if (dotSpeedCurrent[raw_col] == 0)
		{
			red_dot[raw_col]--;
			dotSpeedCurrent[raw_col] = dotSpeed[raw_col];
			if (dotSpeedAccelerate[raw_col] > 0)
				dotSpeedAccelerate[raw_col]--;
			else
			{
				dotSpeed[raw_col]--;
				dotSpeedAccelerate[raw_col] = dotSpeedAccelerateMax;
			}
			if (dotSpeed[raw_col] < 0)
				dotSpeed[raw_col] = 0;
		}
		else if (dotSpeedHold[raw_col] > 0)
			dotSpeedHold[raw_col]--;
		else
			dotSpeedCurrent[raw_col]--;
	}

	digitalWrite(PIN_CAP_RESET, HIGH);
	digitalWrite(PIN_CAP_RESET, LOW);

	//DEBUG
	//for (i = 0; i < 14; i++)
	//{
	//  Serial.print(approx[i]);
	//  Serial.print(" ");
	//}
	//Serial.println();
	//END DEBUG
}

void led_set()
{
	for (col = 0; col < NUM_STRIPS; col++)
	{
		for (row = 0; row < NUM_LEDS_PS; row++)
		{
			strip[calc_pos()] = modes();
		}

		if (col % 2 == 0)
		{
			strip[NUM_LEDS_PS * col + red_dot[col]] = red_dot[col] != 0 ? CRGB::White : CRGB::Black;
		}
		else
		{
			strip[NUM_LEDS_PS + NUM_LEDS_PS * col - red_dot[col]] = red_dot[col] != 0 ? CRGB::White : CRGB::Black;
		}
	}
}

void uart2_rx_bt()
{
	//command = 2;

	if (Serial2.available())
	{
		char rcv_msg[64] = { 0 };
		char rcv_backup[64] = { 0 };

		short rcv_idx = 0;

		while (Serial2.available() && rcv_idx < 64)
		{
			rcv_msg[rcv_idx] = Serial2.read();
			rcv_idx++;
			delayMicroseconds(500);
		}

		if (rcv_msg[0] != '+')
		{
			strcpy(rcv_backup, rcv_msg);

			command_last = command;
			command = (uint8_t) getvals(rcv_msg, 1);
			strcpy(rcv_msg, rcv_backup);
			colorPickerColor = getvals(rcv_msg, 2);

			brightness = (colorPickerColor >> 24) & 0xFF;
			FastLED.setBrightness(brightness);
		}

		/*Serial.println(rcv_backup);
		 Serial.println(lastCommand);
		 Serial.println(command);*/
	}
}

uint32_t getvals(char *str, uint8_t mode)
{
	char *token = NULL;

	switch (mode)
	{
		case 1:
			token = strtok(str, "]");
			token = strtok(token, "[");

			return atol(token);
			break;
		case 2:
			token = strpbrk(str, "{");
			token = strtok(token, "}");
			token = strtok(token, "{");

			return atol(token);
			break;
		default:
			Serial.println("GETVALS -1 DEFAULT BREAK");

			return -1;
			break;
	}
}

short calc_pos()
{
	if (col % 2)
	{
		return NUM_LEDS_PS * (col + 1) - row - 1;
	}
	else
	{
		return NUM_LEDS_PS * col + row;
	}
}

short condition(short stripNum)
{
	currentStrip = stripNum;
	return row < data[stripNum];
}

CRGB modes()
{
	if (condition(col))
	{
		switch (command)
		{
			case 0:
				command = command_last;
				break;
			case 1:
				return rainbowBG_CRGB[row];
			case 2:
				return rainbowBGCycleV_CRGB[row];
			case 3:
				return rainbowBGCycleH_CRGB[currentStrip];
			case 4:
				return solid_color();
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				return testing();
			case 9:
				break;
			case 10:
				break;
			case 11:
				break;
			case 12:
				break;
			case 13:
				break;
			default:
				Serial.println("DEFAUT SETCOLOR");
				return CRGB::Black;
		}
	}
	else
	{
		return led_clear();
	}
}

CRGB led_clear()
{
	return CRGB(0, 0, 0);
}

uint32_t solid_color()
{
	//valRed = (colorPickerColor >> 16) & 0xFF;
	//valGreen = (colorPickerColor >> 8) & 0xFF;
	//valBlue = colorPickerColor & 0xFF;

	return colorPickerColor;
}

CRGB testing()
{
	return CRGB(0, 0, 0);
}

void rainbowBG()
{
	static bool calc_complete = false;
	if (!calc_complete)
	{
		int currColour = 183;
		int rainbowDecrement = 216 / (NUM_LEDS_PS);
		for (int i = 0; i < NUM_LEDS_PS; i++)
		{
			rainbowBG_CRGB[i] = CHSV(currColour -= rainbowDecrement, 255, 255);
			if (currColour == 0)
				currColour = 3;
		}
		calc_complete = true;
	}
}
void rainbowBGCycleV()
{
	if (cycleSpeedV == 0)
	{
		currentColourV--;
		if (currentColourV < 0)
			currentColourV = currentColourV + 255;
		for (int i = 0; i < 255; i++)
		{
			if (currentColourV > 255)
				currentColourV = 0;
			rainbowBGCycleV_CRGB[i] = CHSV(currentColourV, 255, 255);
			currentColourV++;
		}
		cycleSpeedV = initialSpeedV;
	}
	else
		cycleSpeedV--;
}
void rainbowBGCycleH()
{
	if (cycleSpeedH == 0)
	{
		for (int i = 0; i < 14; i++)
		{
			rainbowBGCycleH_CRGB[i] = rainbowBGCycleV_CRGB[i];
		}

		cycleSpeedH = initialSpeedH;
	}
	else
		cycleSpeedH--;
}
void rainbowBGSnake()
{
	int currentColour = 255;
	int rainbowDecrement = 288 / (NUM_LEDS_PS);
	for (int i = 0; i < NUM_LEDS_PS; i++)
	{
		rainbowBG_CRGB[i] = CHSV(currentColour -= rainbowDecrement, 255, 255);
		if (currentColour <= 4)
			currentColour = 4;
	}
}
