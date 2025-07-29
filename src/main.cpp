/*
	main.cpp - entry point for code
	Copyright (C) 2025 Camren Chraplak

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "main.h"

void setup() {

	Serial.begin(BAUD_RATE);
	delay(3000);

	nvmInit(NVM_SIZE);
}

#define I8KEY (uint16_t)0b0110001001100001

void keyToChar2(uint16_t key, char* keyStr) {
	uint8_t key0 = key & LEAST_BYTE;
	uint8_t key1 = (key & SECOND_LEAST_BYTE) >> 8;

	keyStr[0] = key0;
	keyStr[1] = key1;
	keyStr[2] = '\0';
}

void loop() {

	int8_t i8val = -128;
	int8_t i8valr;

	nvmWriteValue(I8KEY, i8val);
	nvmGetValue(I8KEY, &i8valr);

	if (i8valr != i8val) {
		Serial.println("Not Equal?");
	}

	Serial.println(i8valr);

	delay(5000);

	i8val = 127;

	nvmWriteValue(I8KEY, i8val);
	nvmGetValue(I8KEY, &i8valr);

	Serial.println(i8valr);

	delay(5000);
}
