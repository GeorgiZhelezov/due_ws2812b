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
	FastLED.addLeds<WS2811_PORTD, 7>(strip, NUM_LEDS_PS * 2);

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
	read_mux();


	rainbowBGCycleV();
	rainbowBGCycleH();


	led_set();
	uart2_rx_bt();
	FastLED.show();
	Serial.println(FastLED.getFPS());
	delay(RESET_DELAY);
}
