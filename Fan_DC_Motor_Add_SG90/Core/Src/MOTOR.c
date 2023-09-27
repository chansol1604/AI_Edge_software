/*
 * MOTOR.c
 *
 *  Created on: Sep 26, 2023
 *      Author: user
 */

#include "MOTOR.h"


void Motor_Play(uint16_t GPIO_Pin, uint8_t * buff, int * flag){
  if(GPIO_Pin == GPIO_PIN_10)
    {
      TIM3->CCR1 = 0;
      sprintf(buff, "stop       ");
      flag[0]=0;
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

void SG90_Init(uint16_t *adcValue, int * flag)
{
  if(flag[0]==1){
    int i =0;
    for(i; i<250; i++){
      TIM1->CCR1 = i;
      HAL_Delay(3);
    }
    for(i; i>0; i--){
      TIM1->CCR1 = i;
      HAL_Delay(3);
    }
  }
  else{
    SG90_Play(adcValue, flag);
  }
  if((int)adcValue[1]<10){
    flag[0]=0;
  }
}

void SG90_Play(uint16_t *adcValue, int * flag)
{
  if((int)adcValue[0]>4000)
  {
    TIM1->CCR1 = 250;
  }
  if((int)adcValue[0]<10)
  {
    TIM1->CCR1 = 50;
  }
  if((int)adcValue[1]>4000)
  {
    TIM1->CCR1 = 150;
  }
  if((int)adcValue[1]==0)
  {
    if(flag[0]!=0){
      flag[0]=0;
      adcValue[1] = 10;
      HAL_Delay(1000);
    }
    else{
      flag[0] = 1;
      HAL_Delay(1000);
    }
  }
  if((int)adcValue[2]==0){
    HAL_Delay(10);
    if((int)adcValue[2]==0){
      flag[1]++;
    }
  }
}

void Timer_start(uint8_t * temp, int *flag, uint8_t * buff){
  static int time[3];
  if(flag[1]==0){
    time[0] = 0;
    time[1] = 1;
    time[2] = 0;
  }
  else{
    if(time[2]==0){
      time[2] = 1;
    }
    int s;
    s= 60 - time[0];
    if(s==60){
      s=0;
    }
    sprintf(temp, "%02d:%02d:%02d", flag[1]-time[2], 60-time[1], s);
    time[0]++;
    if(time[0]==60){
      time[1]++;
      time[0] = 0;
    }
    if(time[1]==61){
      time[2] ++;
      time[1] = 1;
    }
    if((time[2]-1)==flag[1])
    {
      time[2] = 0;
      flag[1] = 0;
      TIM3->CCR1 = 0;
      sprintf(buff, "stop       ");
      flag[0]=0;
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET);
      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, RESET);
    }
  }
}
