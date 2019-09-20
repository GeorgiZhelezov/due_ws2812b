/*
 * due_main.h
 *
 *  Created on: Sep 1, 2019
 *      Author: g2
 */

#ifndef DUE_MAIN_H_
#define DUE_MAIN_H_

#include "Arduino.h"
#include "FastLED.h"
#include "defines.h"

#include "read_mux.h"
#include "led_set.h"
#include "uart2_bt_rx.h"
#include "calc_pos.h"
#include "modes.h"

#include "rainbow.h"
#include "red_dot.h"
#include "testing.h"

extern CRGB strip[1008];

extern uint8_t brightness;
extern uint8_t col;
extern uint8_t row;
extern uint8_t command;
extern uint8_t command_last;
extern uint8_t red_dot[14];

extern uint16_t raw_data[APPROX_SAMPLES][NUM_STRIPS];
extern uint16_t data[NUM_STRIPS];

extern uint32_t colorPickerColor;

#endif /* DUE_MAIN_H_ */
