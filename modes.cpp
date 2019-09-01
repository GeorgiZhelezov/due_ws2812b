/*
 * modes.cpp
 *
 *  Created on: Sep 1, 2019
 *      Author: g2
 */

#include "modes.h"

short condition(short stripNum)
{
	currentStrip = stripNum;
	return row < data[stripNum];
}

CRGB modes()
{
	if (condition(col))
	{
		switch (command)
		{
			case 0:
				command = command_last;
				break;
			case 1:
				return rainbowBG_CRGB[row];
			case 2:
				return rainbowBGCycleV_CRGB[row];
			case 3:
				return rainbowBGCycleH_CRGB[currentStrip];
			case 4:
				return colorPickerColor;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				return testing();
			case 9:
				break;
			case 10:
				break;
			case 11:
				break;
			case 12:
				break;
			case 13:
				break;
			default:
				Serial.println("DEFAUT SETCOLOR");
				return CRGB::Black;
		}
	}
	else
	{
		return CRGB::Black;
	}
}
