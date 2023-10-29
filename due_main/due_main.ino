#include "due_main.h"

CRGB strip[1008];

uint8_t col;
uint8_t row;
uint8_t brightness   = 20;
uint8_t command      = 2;
uint8_t command_last = command;

uint16_t data[NUM_STRIPS];
uint16_t raw_data[APPROX_SAMPLES][NUM_STRIPS];

uint32_t colorPickerColor = CRGB::Red;

void setup()
{
	// WS2811_PORTD - pins 25,26,27,28,14,15,29,11 (all available on the due)
	//https://github.com/FastLED/FastLED/wiki/Parallel-Output
	FastLED.addLeds<WS2811_PORTD, 7>(strip, NUM_LEDS_PS * 2);

	FastLED.setBrightness(brightness);

	Serial.begin(BAUD_RATE);
	Serial2.begin(BAUD_RATE);

	pinMode(PIN_ADC_PEAK_DETECTOR1, INPUT);
	pinMode(PIN_ADC_PEAK_DETECTOR2, INPUT);

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

	pinMode(PIN_74HC245_OE, OUTPUT);
	pinMode(PIN_74HC245_DIR, OUTPUT);

	digitalWrite(PIN_74HC245_OE, LOW);
	digitalWrite(PIN_74HC245_DIR, HIGH);

	rainbowBG();
}

void loop()
{
	read_mux();

	rainbowBGCycleV();
	rainbowBGCycleH();

	led_set();

	// uart2_rx_bt();
	
	FastLED.show();
	// Serial.println(FastLED.getFPS());

	delay(RESET_DELAY);
}
