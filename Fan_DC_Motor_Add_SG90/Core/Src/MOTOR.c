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

void SG90_Init(uint16_t *adcValue, int * flag, char * temp)
{
  RTC_TimeTypeDef sTime;

  if(flag[0]==1){
    int i =0;
    for(i; i<250; i++){
      TIM1->CCR1 = i;
      HAL_Delay(5);
    }
    for(i; i>0; i--){
      TIM1->CCR1 = i;
      HAL_Delay(5);
    }
  }
  else{
    SG90_Play(adcValue, flag, &sTime);
  }
  if((int)adcValue[1]<10){
    flag[0]=0;
  }
  if(flag[1]==1){
    HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BCD);
    if(sTime.Minutes==0x00){
      sTime.Hours = sTime.Hours-1;
    }
    sprintf(temp, "\r%02d:%02d:%02d", (int)sTime.Hours, 60 - (int)sTime.Minutes, 60 - (int)sTime.Seconds);

  }
}

void SG90_Play(uint16_t *adcValue, int * flag, RTC_TimeTypeDef *sTime)
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
  if((int)adcValue[1]<10)
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
  if((int)adcValue[2]<10){
    if(flag[1]==0){
      sTime->Hours = 0x01;
      sTime->Minutes = 0x00;
      sTime->Seconds = 0x00;
      flag[1] = 1;
    }
    HAL_RTC_SetTime(&hrtc, sTime, RTC_FORMAT_BCD);
  }
}
