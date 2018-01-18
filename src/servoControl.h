/* servoControl.h
 * Copyright 2018 ShellAddicted <shelladdicted@gmail.com>
 * GitHub: https://github.com/ShellAddicted
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _SERVO_CONTROL_H_
#define _SERVO_CONTROL_H_

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/ledc.h>

class servoControl{
	protected:
	const int _freqHz = 50;

	ledc_channel_t _ledcChannel;
	unsigned int _min;
	unsigned int _max;
	
	double getDutyByPercentage(double percentage);
	double getDutyByuS(double uS);

	public:
	void attach(gpio_num_t pin, unsigned int minuS = 400, unsigned int maxuS = 2600, ledc_channel_t ledcChannel = LEDC_CHANNEL_0, ledc_timer_t ledcTimer = LEDC_TIMER_0);
	void writeMicroSeconds(unsigned int uS);
	void write(unsigned int value);
	void detach();
};
#endif