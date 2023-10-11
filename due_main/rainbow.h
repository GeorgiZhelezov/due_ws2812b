/*
 * rainbow.h
 *
 *  Created on: Sep 1, 2019
 *      Author: g2
 */

#ifndef RAINBOW_H_
#define RAINBOW_H_

#include "due_main.h"

//From Sophisticated Gentleman

//rainbowBG()
extern CRGB rainbowBG_CRGB[NUM_LEDS_PS];
//end rainbowBG()

//rainbowBGCycleV()
extern CRGB rainbowBGCycleV_CRGB[255];
//end rainbowBGCycleV()

//rainbowBGCycleH()
extern uint8_t currentStrip;
extern CRGB rainbowBGCycleH_CRGB[14];
//end rainbowBGCycleH()

//rainbowBGSnake()
extern CRGB rainbowBGSnake_CRGB[NUM_LEDS_PS];
//end rainbowBGSnake()
//End of Sophisticated Gentleman


void rainbowBG();
void rainbowBGCycleV();
void rainbowBGCycleH();
void rainbowBGSnake();

#endif /* RAINBOW_H_ */
