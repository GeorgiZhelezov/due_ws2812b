/*
 * vars.h
 *
 *  Created on: 13.04.2019 ?.
 *      Author: GLap
 */

#ifndef VARS_H_
#define VARS_H_

CRGB strip[1008];

CRGB rainbowColor;
CRGB rainbow_arr[72];

boolean
rainbowResetFlag = 0;

uint8_t
brightness  = 20,
col           = 0,
row           = 0,

red_dot[14] = { 0 },

command     = 3,
command_last = command,

rainbowR    = 0,
rainbowG    = 0,
rainbowB    = 0;

uint16_t
raw_data[APPROX_SAMPLES][NUM_STRIPS] = { 0 },
data[NUM_STRIPS] = { 0 };


float counter = 0;

uint32_t
colorPickerColor         = CRGB::Red,

strip_delays[NUM_STRIPS] = { 25000, 16000, 10000, 6300, 4000, 2500, 1600, 1000, 630, 400, 250, 160, 100, 63 },

valRed                   = 0,
valGreen                 = 0,
valBlue                  = 0;

//From Sophisticated Gentleman
//topDot
int dotSpeedMax =3;
int dotSpeedHoldMax=7;
int dotSpeedAccelerateMax=1;
const int tailLenMax=5;
int dotSpeedHold[14] ={dotSpeedHoldMax};
int dotSpeed[14] ={dotSpeedMax};
int dotSpeedAccelerate[14]={dotSpeedAccelerateMax};
int dotSpeedCurrent[14] = {0};
int dotTail[14][tailLenMax];
//end topDot

//rainbowBG()
CRGB rainbowBG_CRGB[NUM_LEDS_PS];
//end rainbowBG()

//rainbowBGCycleV()
int currentColourV = 255;
int cycleSpeedV = 0;
int initialSpeedV = 4;
CRGB rainbowBGCycleV_CRGB[255];
//end rainbowBGCycleV()

//rainbowBGCycleH()
int cycleSpeedH = 0;
int initialSpeedH = 0;
uint8_t currentStrip=0;
CRGB rainbowBGCycleH_CRGB[14];
//end rainbowBGCycleH()

//rainbowBGSnake()
CRGB rainbowBGSnake_CRGB[NUM_LEDS_PS];
//end rainbowBGSnake()


//End of Sophisticated Gentleman



#endif /* VARS_H_ */
