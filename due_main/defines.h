/*
 * defines.h
 *
 *  Created on: 13.04.2019 ?.
 *      Author: GLap
 */

#ifndef DEFINES_H_
#define DEFINES_H_

#define PIN_OUTPUT0   23
#define PIN_OUTPUT1   25
#define PIN_OUTPUT2   27
#define PIN_OUTPUT3   29
#define PIN_OUTPUT4   31
#define PIN_OUTPUT5   33
#define PIN_OUTPUT6   35

#define PIN_ANALOG_IN0  A0
#define PIN_ANALOG_IN1  A1
#define PIN_ANALOG_IN2  A2
#define PIN_ANALOG_IN3  A3
#define PIN_ANALOG_IN4  A4
#define PIN_ANALOG_IN5  A5

#define PIN_ADC_PEAK_DETECTOR1 PIN_ANALOG_IN3
#define PIN_ADC_PEAK_DETECTOR2 PIN_ANALOG_IN4

#define PIN_MUX1_A    4
#define PIN_MUX1_B    3
#define PIN_MUX1_C    2
#define PIN_MUX1_EN   9

#define PIN_MUX2_A    7
#define PIN_MUX2_B    6
#define PIN_MUX2_C    5
#define PIN_MUX2_EN   10

#define PIN_MUX_RESET 8

#define PIN_CAP_RESET 51

#define MUX_ENABLE    1
#define MUX_DISABLE   0

#define IC_74HC_ENABLE  0
#define IC_74HC_DISABLE 1

#define PIN_74HC245_OE  49
#define PIN_74HC245_DIR 47

#define NUM_LEDS    1008
#define NUM_STRIPS    14
#define NUM_LEDS_PS   (NUM_LEDS / NUM_STRIPS)

#define MAP_MIN     0
#define MAP_MAX     (NUM_LEDS_PS - 1)
#define BAUD_RATE   115200
#define NOISE_FILTER  0
#define RESET_DELAY   9
#define APPROX_SAMPLES  8

#endif /* DEFINES_H_ */
