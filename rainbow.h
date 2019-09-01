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
//topDot
extern int dotSpeedMax;
extern int dotSpeedHoldMax;
extern int dotSpeedAccelerateMax;
extern int dotSpeedHold[14];
extern int dotSpeed[14];
extern int dotSpeedAccelerate[14];
extern int dotSpeedCurrent[14];
extern int dotTail[14][5];
//end topDot

//rainbowBG()
extern CRGB rainbowBG_CRGB[NUM_LEDS_PS];
//end rainbowBG()

//rainbowBGCycleV()
extern int currentColourV;
extern int cycleSpeedV;
extern int initialSpeedV;
extern CRGB rainbowBGCycleV_CRGB[255];
//end rainbowBGCycleV()

//rainbowBGCycleH()
extern int cycleSpeedH;
extern int initialSpeedH;
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
