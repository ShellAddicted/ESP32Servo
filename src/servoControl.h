/*
MIT License

Copyright (c) 2018 ShellAddicted <github.com/ShellAddicted>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
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