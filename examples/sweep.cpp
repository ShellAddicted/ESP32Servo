/* sweep.cpp
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

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "servoControl.h"


extern "C" void app_main(){
	servoControl myServo;
	myServo.attach(GPIO_NUM_23);
	//Defaults: myServo.attach(pin, 400, 2600, LEDC_CHANNEL_0, LEDC_TIMER0);
	// to use more servo set a valid ledc channel and timer
	
	myServo.write(0);
	vTaskDelay(1000 / portTICK_RATE_MS);
	
	while (1){
		for (int i = 0; i<180; i++){
			myServo.write(i);
			vTaskDelay(10 / portTICK_RATE_MS);
		}
		for (int i = 180; i>0; i--){
			myServo.write(i);
			vTaskDelay(10 / portTICK_RATE_MS);
		}
	}
}