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
#include <unistd.h>

#include "wiringpitest.h" 

static void *bg_gpio_thread(void *param)
{
	int ret;

	ret = store_gpio();
	if (ret < 0) {
		printf("Failed using gpio\n");
	}

	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t gpio;
	int gpioTh;
	int param = 100;

	gpioTh = pthread_create(&gpio, NULL, bg_gpio_thread, &param);
	if (gpioTh < 0) {
		perror("Failed create gpio thread");
		exit(0);
	}

	show_header();

	return 0;
}
