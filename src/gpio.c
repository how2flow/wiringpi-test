/*******************************************************************************
 Copyright (C) 2022-2023 Steve Jeong <steve@how2flow.net>
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#include "wiringpitest.h"

static int setup = 0;

/* mapping */
static int phyToPin[64] = {
	-1,
	-1, -1,
	 8, -1,
	 9, -1,
	 7, 15,
	-1, 16,
	 0,  1,
	 2, -1,
	 3,  4,
	-1,  5,
	12, -1,
	13,  6,
	14, 10,
	-1, 11,
	30, 31,
	21, -1,
	22, 26,
	23, -1,
	24, 27,
	-1, -1,
	-1, -1,
	/* padding */
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1
};

static int setup_gpio(void)
{
	int phy; // physical header pin number
	int pin; // wiringpi pin number

	wiringPiSetup();

	for (phy = 1; phy <= 40; phy++) {
		pin = phyToPin[phy];

		if (pin == -1)
			continue;

		if (getAlt(pin) > 1)
			continue;

		pinMode(pin, OUTPUT);
		digitalWrite(pin, LOW);
	}

	return 1;
}

static void toggle_gpio(int pin)
{
		digitalWrite(pin, HIGH);
		delay(500);
		digitalWrite(pin, LOW);
		delay(500);
}

int store_gpio(void)
{
	int phy; // physical header pin number
	int pin; // wiringpi pin number

	if (!setup) {
		setup = setup_gpio();
	}

	for (phy = 1; phy <= 40; phy++) {
		pin = phyToPin[phy];

		if (pin == -1)
			continue;

		if (getAlt(pin) > 1)
			continue;

		toggle_gpio(pin);
	}

	return 0;
}
