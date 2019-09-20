/*
 * red_dot.cpp
 *
 *  Created on: Sep 20, 2019
 *      Author: g2
 */
#include"red_dot.h";

//topDot
static int dotSpeedMax =3;
static int dotSpeedHoldMax=7;
static int dotSpeedAccelerateMax=1;
//const int tailLenMax=5;
static int dotSpeedHold[14] ={dotSpeedHoldMax};
static int dotSpeed[14] ={dotSpeedMax};
static int dotSpeedAccelerate[14]={dotSpeedAccelerateMax};
static int dotSpeedCurrent[14] = {0};
//int dotTail[14][5]; //[14][tailLenMax = 5]
//end topDot

uint8_t red_dot[14];

void red_dot_calc()
{
	for (uint8_t cnt = 0; cnt < NUM_STRIPS; cnt++)
	{
		if (red_dot[cnt] <= data[cnt])
		{
			red_dot[cnt] = data[cnt];
			dotSpeed[cnt] = dotSpeedMax;
			dotSpeedHold[cnt] = dotSpeedHoldMax;
			dotSpeedCurrent[cnt] = dotSpeedMax;
			dotSpeedAccelerate[cnt] = dotSpeedAccelerateMax;
		}
		else if (dotSpeedCurrent[cnt] == 0)
		{
			red_dot[cnt]--;
			dotSpeedCurrent[cnt] = dotSpeed[cnt];
			if (dotSpeedAccelerate[cnt] > 0)
				dotSpeedAccelerate[cnt]--;
			else
			{
				dotSpeed[cnt]--;
				dotSpeedAccelerate[cnt] = dotSpeedAccelerateMax;
			}
			if (dotSpeed[cnt] < 0)
				dotSpeed[cnt] = 0;
		}
		else if (dotSpeedHold[cnt] > 0)
			dotSpeedHold[cnt]--;
		else
			dotSpeedCurrent[cnt]--;
	}
}

void red_dot_set()
{
	if (col % 2 == 0)
	{
		strip[NUM_LEDS_PS * col + red_dot[col]] = red_dot[col] != 0 ? CRGB::White : CRGB::Black;
	}
	else
	{
		strip[NUM_LEDS_PS + NUM_LEDS_PS * col - red_dot[col]] = red_dot[col] != 0 ? CRGB::White : CRGB::Black;
	}
}

