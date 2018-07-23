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

#include "servoControl.h"

double servoControl::getDutyByPercentage(double percentage){
	if (percentage <= 0){
		return 0;
	}
	if (percentage > 100){
		percentage = 100;
	}
	return (percentage / 100.0) * ((2<<14)-1); // LEDC_TIMER_15_BIT
}

double servoControl::getDutyByuS(double uS){
	return getDutyByPercentage(((uS * 100.0)/(1000000/_freqHz)));
}

void servoControl::attach(gpio_num_t pin, unsigned int minuS, unsigned int maxuS, ledc_channel_t ledcChannel, ledc_timer_t ledcTimer){
	_min = minuS;
	_max = maxuS;
	_ledcChannel = ledcChannel;

	ledc_timer_config_t timer_conf;
	timer_conf.duty_resolution 	= LEDC_TIMER_15_BIT;
	timer_conf.freq_hz    		= _freqHz;
	timer_conf.speed_mode 		= LEDC_HIGH_SPEED_MODE;
	timer_conf.timer_num  		= ledcTimer;
	ledc_timer_config(&timer_conf);

	ledc_channel_config_t ledc_conf;
	ledc_conf.channel		= _ledcChannel;
	ledc_conf.duty			= 0;
	ledc_conf.gpio_num		= (int)pin;
	ledc_conf.intr_type		= LEDC_INTR_DISABLE;
	ledc_conf.speed_mode	= LEDC_HIGH_SPEED_MODE;
	ledc_conf.timer_sel		= ledcTimer;
	ledc_channel_config(&ledc_conf);
}

void servoControl::detach(){
	ledc_stop(LEDC_HIGH_SPEED_MODE, _ledcChannel, 0);
}

void servoControl::writeMicroSeconds(unsigned int uS){
	ledc_set_duty(LEDC_HIGH_SPEED_MODE, _ledcChannel, getDutyByuS(uS));
	ledc_update_duty(LEDC_HIGH_SPEED_MODE, _ledcChannel);
}

void servoControl::write(unsigned int value) {
	// 0 = MinServoAngle ; 180 = Max ServoAngle;
	int scale = (value - 0) * (_max - _min) / (180 - 0) + _min;
	writeMicroSeconds(scale);
}

