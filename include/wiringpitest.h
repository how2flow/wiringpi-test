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

#ifndef __WIRINGPITEST_H__
#define __WIRINGPITEST_H__

#define SPI_SPEED 1000000

/* struct */
struct i2c_args {
	unsigned int addr;
	char *bus;
};

struct spi_args {
	int cs;
	int speed;
};

/* vars */

/* functions */
int show_header(void);
int show_i2cbus(int fd);
int show_spidata(void);

int store_gpio(void);
int store_i2c(void *args);
int store_spi(void *args);
#endif
