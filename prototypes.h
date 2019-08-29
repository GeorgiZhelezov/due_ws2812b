/*
 * prototypes.h
 *
 *  Created on: 13.04.2019 ?.
 *      Author: GLap
 */

#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_

void read_data();
void led_set();
void uart2_rx_bt();

short calc_pos();
short condition(short);

uint32_t getvals(char *, uint8_t);
uint32_t flagBG();
uint32_t solid_color();

CRGB led_clear();
CRGB modes();
CRGB testing();

void rainbowBG();
void rainbowBGCycleV();
void rainbowBGCycleH();
void rainbowBGSnake();

#endif /* PROTOTYPES_H_ */
