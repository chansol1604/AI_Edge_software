/*
 * STEPPER.c
 *
 *  Created on: Sep 21, 2023
 *      Author: user
 */


#include "STEPPER.h"
#include "delay.h"

void stepMoterSpeed(int speed)
{
  delay_us((60000000/stepMoterHalfStep)/speed);
}

void stepMoterHalfDrive(int step)
{
  uint8_t step1 = step % 8;
  switch (step1) {
    case 0:
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, SET);
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET);
      break;
    case 1:
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, SET);
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET);
      break;
    case 2:
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, RESET);
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET);
      break;
    case 3:
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, RESET);
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET);
      break;
    case 4:
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, RESET);
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET);
      break;
    case 5:
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, RESET);
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, SET);
      break;
    case 6:
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, RESET);
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, SET);
      break;
    case 7:
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, SET);
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, SET);
      break;
  }
}
