/*
 * MOTOR.h
 *
 *  Created on: Sep 26, 2023
 *      Author: user
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "main.h"
#include "stdio.h"
#include "rtc.h"

void Motor_Play(uint16_t GPIO_Pin, uint8_t * buff, int * flag);
void SG90_Play(uint16_t *adcValue, int * flag, RTC_TimeTypeDef *sTime);
void SG90_Init(uint16_t *adcValue, int * flag, char *temp);

#endif /* INC_MOTOR_H_ */
