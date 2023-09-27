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

void Motor_Play(uint16_t GPIO_Pin, uint8_t * buff, int * flag);
void SG90_Play(uint16_t *adcValue, int * flag);
void SG90_Init(uint16_t *adcValue, int * flag);
void Timer_start(uint8_t * temp, int *flag, uint8_t * buff);

#endif /* INC_MOTOR_H_ */
