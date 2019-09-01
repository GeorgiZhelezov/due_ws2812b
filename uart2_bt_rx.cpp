/*
 * uart2_bt_rx.cpp
 *
 *  Created on: Sep 1, 2019
 *      Author: g2
 */

#include "uart2_bt_rx.h"

void uart2_rx_bt()
{
	//command = 2;

	if (Serial2.available())
	{
		char rcv_msg[64] = { 0 };
		char rcv_backup[64] = { 0 };

		short rcv_idx = 0;

		while (Serial2.available() && rcv_idx < 64)
		{
			rcv_msg[rcv_idx] = Serial2.read();
			rcv_idx++;
			delayMicroseconds(500);
		}

		if (rcv_msg[0] != '+')
		{
			strcpy(rcv_backup, rcv_msg);

			command_last = command;
			command = (uint8_t) getvals(rcv_msg, 1);
			strcpy(rcv_msg, rcv_backup);
			colorPickerColor = getvals(rcv_msg, 2);

			brightness = (colorPickerColor >> 24) & 0xFF;
			FastLED.setBrightness(brightness);
		}

		/*Serial.println(rcv_backup);
		 Serial.println(lastCommand);
		 Serial.println(command);*/
	}
}

uint32_t getvals(char *str, uint8_t mode)
{
	char *token = NULL;

	switch (mode)
	{
		case 1:
			token = strtok(str, "]");
			token = strtok(token, "[");
			return atol(token);
		case 2:
			token = strpbrk(str, "{");
			token = strtok(token, "}");
			token = strtok(token, "{");
			return atol(token);
		default:
			Serial.println("GETVALS -1 DEFAULT BREAK");
			return -1;
	}
}

