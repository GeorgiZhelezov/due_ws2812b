/*
 * read_mux.cpp
 *
 *  Created on: Sep 1, 2019
 *      Author: g2
 */
#include "read_mux.h"

void read_mux()
{
	uint8_t mux_out_addr[3], raw_row, raw_col;
	uint16_t avg[NUM_STRIPS] = { 0 };

	for (raw_row = 0; raw_row < APPROX_SAMPLES - 1; raw_row++)
	{
		for (raw_col = 0; raw_col < NUM_STRIPS; raw_col++)
		{
			raw_data[raw_row][raw_col] = raw_data[raw_row + 1][raw_col];
		}
	}

	for (raw_col = 0; raw_col < 8; raw_col++)
	{
		mux_out_addr[0] = (~raw_col & 0x01);
		mux_out_addr[1] = (~raw_col & 0x02) >> 1;
		mux_out_addr[2] = (~raw_col & 0x04) >> 2;

		digitalWrite(PIN_MUX1_A, mux_out_addr[0]);
		digitalWrite(PIN_MUX1_B, mux_out_addr[1]);
		digitalWrite(PIN_MUX1_C, mux_out_addr[2]);

		raw_data[APPROX_SAMPLES - 1][raw_col] = analogRead(PIN_ADC_PEAK_DETECTOR1);

		if (raw_col < 6)
		{
			digitalWrite(PIN_MUX2_A, mux_out_addr[0]);
			digitalWrite(PIN_MUX2_B, mux_out_addr[1]);
			digitalWrite(PIN_MUX2_C, mux_out_addr[2]);

			raw_data[APPROX_SAMPLES - 1][raw_col + 8] = analogRead(PIN_ADC_PEAK_DETECTOR2);
		}

		// for (uint8_t i = 0; i < sizeof(mux_out_addr); i++)
		// {
		// 	Serial.print(mux_out_addr[i]);
		// 	Serial.print(" ");
		// }
		// Serial.println();
	}

	for (raw_row = 0; raw_row < NUM_STRIPS; raw_row++)
	{
		for (raw_col = 0; raw_col < APPROX_SAMPLES; raw_col++)
		{
			avg[raw_row] += raw_data[raw_col][raw_row];
		}
	}

	for (raw_col = 0; raw_col < NUM_STRIPS; raw_col++)
	{
		avg[raw_col] /= APPROX_SAMPLES;

		data[raw_col] = map(avg[raw_col], 0, 1023, MAP_MIN, MAP_MAX);
	}

	digitalWrite(PIN_CAP_RESET, HIGH);
	digitalWrite(PIN_CAP_RESET, LOW);

	//DEBUG PRINT DATA
	// {
	// 	char buff[128], temp[8];
	// 	memset(buff, 0, sizeof(buff));
	// 	memset(temp, 0, sizeof(temp));

	// 	int wrote;
	// 	for (int i = 0; i < NUM_STRIPS; i++)
	// 	{
	// 		wrote = snprintf(temp, sizeof(temp), "%2d ", data[i]);
	// 		strncat(buff, temp, wrote);
	// 		if (i == 6) { strncat(buff, "  ", 2); }

	// 		memset(temp, 0, sizeof(temp));
	// 	}
	// 	Serial.println(buff);
	// }
	// END DEBUG PRINT DATA
}
