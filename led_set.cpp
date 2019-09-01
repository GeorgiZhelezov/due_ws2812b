/*
 * led_set.cpp
 *
 *  Created on: Sep 1, 2019
 *      Author: g2
 */

#include "led_set.h"


void led_set()
{
	for (col = 0; col < NUM_STRIPS; col++)
	{
		for (row = 0; row < NUM_LEDS_PS; row++)
		{
			strip[calc_pos()] = modes();
		}

		if (col % 2 == 0)
		{
			strip[NUM_LEDS_PS * col + red_dot[col]] = red_dot[col] != 0 ? CRGB::White : CRGB::Black;
		}
		else
		{
			strip[NUM_LEDS_PS + NUM_LEDS_PS * col - red_dot[col]] = red_dot[col] != 0 ? CRGB::White : CRGB::Black;
		}
	}
}
