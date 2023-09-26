/*
 * MOTOR.c
 *
 *  Created on: Sep 26, 2023
 *      Author: user
 */

#include "MOTOR.h"


void Motor_Play(uint16_t GPIO_Pin, uint8_t * buff){
  if(GPIO_Pin == GPIO_PIN_10)
    {
      TIM3->CCR1 = 0;
      sprintf(buff, "stop       ");
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET);
      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, RESET);
    }
    else if(GPIO_Pin == GPIO_PIN_11){
      TIM3->CCR1 = 5000;
      sprintf(buff, "RUN : 1       ");
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET);
      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, RESET);
    }
    else if(GPIO_Pin == GPIO_PIN_12){
      sprintf(buff, "RUN : 2       ");
      TIM3->CCR1 = 7500;
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, SET);
      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, RESET);
    }
    else if(GPIO_Pin == GPIO_PIN_2){
      sprintf(buff, "RUN : 3       ");
      TIM3->CCR1 = 9999;
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET);
      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, SET);
    }
}
