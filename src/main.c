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

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "wiringpitest.h" 

static struct i2c_args *i2c_info;
static struct spi_args *spi_info;

static int fd;

static void *bg_gpio_thread(void *param)
{
	int ret;

	ret = store_gpio();
	if (ret < 0) {
		printf("Failed using gpio\n");
	}

	return NULL;
}

static void *bg_i2c_thread(void *param)
{
	int ret;

	fd = store_i2c(param);
	if ((ret = fd) < 0) {
		printf("Failed using i2c\n");
	}

	return NULL;
}

static void *bg_spi_thread(void *param)
{
	int ret;

	fd = store_spi(param);
	if ((ret = fd) < 0) {
		printf("Failed using spi\n");
	}

	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t gpio, i2c, spi;
	int gpioTh, i2cTh, spiTh;
	int param, ret;
	char *cmd = (char *)malloc(sizeof(char) * 15);

	if (argc < 2) {
		printf("Need param Call \"wiringpi-test --help\"\n");
		return -1;
	}

	if(!strcmp(argv[1], "gpio")) {
		param = 100;

		gpioTh = pthread_create(&gpio, NULL, bg_gpio_thread, &param);
		if (gpioTh < 0) {
			perror("Failed create gpio thread");
			exit(0);
		}

		show_header();
	}

	if(!strcmp(argv[1], "i2c")) {
		snprintf(cmd, 15, "%s%s", "i2cdetect -y ", argv[2]);
		ret = system(cmd);
		if (ret < 0) {
			perror("system cmd error");
		}

		printf("Input i2c device address: ");
		ret = scanf("%x", &param);
		if (ret < 0) {
			perror("input error");
		}

		i2c_info->addr = param;
		i2c_info->bus = argv[2];

		i2cTh = pthread_create(&i2c, NULL, bg_i2c_thread, (void *) i2c_info);
		if (i2cTh < 0) {
			perror("Failed create i2c thread");
			exit(0);
		}

		show_i2cbus(fd);
	}

	if(!strcmp(argv[1], "spi")) {
		printf("Input spi speed (default: 1000000): ");
		ret = scanf("%d", &param);
		if (ret < 0) {
			perror("input error");
		}

		if (param < SPI_SPEED) {
			spi_info->speed = SPI_SPEED;
		}
		else {
			spi_info->speed = param;
		}

		spi_info->cs = atoi(argv[2]);

		spiTh = pthread_create(&spi, NULL, bg_spi_thread, (void *) spi_info);
		if (spiTh < 0) {
			perror("Failed create spi thread");
			exit(0);
		}

		show_spidata();
	}

	close(fd);

	return 0;
}
