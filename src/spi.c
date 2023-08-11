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
#include <wiringPi.h>
#include <wiringPiSPI.h>

#include "wiringpitest.h"

#define MAX_SIZE (1024*1024)

static int setup;
static int fd;

static int setup_spi(int cs, int speed)
{
	if (wiringPiSetup() == -1)
		exit(1);

	fd = wiringPiSPISetup(cs, speed);

	return 1;
}

int store_spi(void *args)
{
	struct spi_args *arguments = (struct spi_args *) args;
	unsigned char *data = (unsigned char *)malloc(MAX_SIZE);

	if (!setup) {
		setup = setup_spi(arguments->cs, arguments->speed);
	}

	if (wiringPiSPIDataRW(arguments->cs, data, MAX_SIZE) == -1) {
		perror("Failed read/write spidev");
		return -1;
	}

	return fd;
}
