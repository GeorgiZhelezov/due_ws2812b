/*
 * led_set.cpp
 *
 *  Created on: Sep 1, 2019
 *      Author: g2
 */

#include "led_set.h"


void led_set()
{
	red_dot_calc();

	for (col = 0; col < NUM_STRIPS; col++)
	{
		for (row = 0; row < NUM_LEDS_PS; row++)
		{
			strip[calc_pos()] = modes();
		}

		red_dot_set();
	}
}
