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
#include <unistd.h>

#include "wiringpitest.h" 

int show_header(void)
{
	float cnt = 0;
	int ret;

	while (cnt < 60) {
		ret = system("clear");
		if (ret < 0) {
			perror("failed");
		}

		ret = system("sync && gpio readall");
		if (ret < 0) {
			perror("failed");
		}

		cnt += 0.1;
		printf("time: %.1f\n", cnt);
		usleep(100000);
	}

	return 0;
}
