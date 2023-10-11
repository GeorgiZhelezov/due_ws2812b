/*
 * calc_pos.cpp
 *
 *  Created on: Sep 1, 2019
 *      Author: g2
 */

#include "calc_pos.h"


short calc_pos()
{
	if (col % 2)
	{
		return NUM_LEDS_PS * (col + 1) - row - 1;
	}
	else
	{
		return NUM_LEDS_PS * col + row;
	}
}
