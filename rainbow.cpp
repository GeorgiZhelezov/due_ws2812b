/*
 * rainbow.cpp
 *
 *  Created on: Sep 1, 2019
 *      Author: g2
 */

#include "rainbow.h"

//From Sophisticated Gentleman
//topDot
int dotSpeedMax =3;
int dotSpeedHoldMax=7;
int dotSpeedAccelerateMax=1;
//const int tailLenMax=5;
int dotSpeedHold[14] ={dotSpeedHoldMax};
int dotSpeed[14] ={dotSpeedMax};
int dotSpeedAccelerate[14]={dotSpeedAccelerateMax};
int dotSpeedCurrent[14] = {0};
int dotTail[14][5]; //[14][tailLenMax = 5]
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



