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
#include <string.h>
#include <time.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#include "wiringpitest.h"

static int setup;
static int fd;

static int setup_i2c(int address, char *bus)
{
	char *device = (char *)malloc(sizeof(char) * 11);

	if (wiringPiSetup() == -1)
		exit(1);

	snprintf(device, 11, "%s%s", "/dev/i2c-", bus);
	fd = wiringPiI2CSetupInterface(device, address);

	return 1;
}

int store_i2c(void *args)
{
	struct i2c_args *arguments = (struct i2c_args *) args;
	/* int data; */

	if (!setup) {
		setup = setup_i2c(arguments->addr, arguments->bus);
	}

	// TODO
	// Is there a general test routine?
	/*
	srand(time(NULL));
	data = rand() % 2;

	wiringPiI2CWrite(fd, data);
	*/

	delay(500);

	return fd;
}
