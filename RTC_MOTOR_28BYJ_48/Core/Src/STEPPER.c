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


void stepInit(motorInfo motor){
  for(int i=0; i<motor.motorStep; i++)//4096 = 360, 2086 = 180, 1043 = 90
    {
      if(motor.d_mode==HALF_DRIVE){
        stepMoterHalfDrive(i, motor);
        stepMoterSpeed(10);
      }
      else if(motor.d_mode == WAVE_DRIVE){
        stepMoterWaveDrive(i, motor);
        stepMoterSpeed(5);
      }
      else if(motor.d_mode == FULL_DRIVE){
        stepMoterFullDrive(i, motor);
        stepMoterSpeed(3);
      }
    }
    HAL_Delay(1000);

}
void stepCtlr(uint8_t * buff, motorInfo * motor){
  int stepFlag=0;
  float exData = (float)4096/(float)360;
  char * stepData;
  char * p;
  char * dp;
  if((p = strstr((char*)buff,"ccw"))!=NULL)
  {
    motor->c_mode = ccw;
    stepFlag += 3;
    if((dp = strstr((char*)buff,"HD"))!=NULL){
      motor->d_mode = HALF_DRIVE;
      stepFlag +=2;
    }
    else if((dp = strstr((char*)buff,"WD"))!=NULL){
      motor->d_mode = WAVE_DRIVE;
      stepFlag +=2;
    }
    else if((dp = strstr((char*)buff,"FD"))!=NULL){
      motor->d_mode = FULL_DRIVE;
      exData /=2;
      stepFlag +=2;
    }
  }
  else if((p = strstr((char*)buff,"cw"))!=NULL)
  {
    motor->c_mode= cw;
    stepFlag += 2;
    if((dp = strstr((char*)buff,"HD"))!=NULL){
      motor->d_mode = HALF_DRIVE;
      stepFlag +=2;
    }
    else if((dp = strstr((char*)buff,"WD"))!=NULL){
      motor->d_mode = WAVE_DRIVE;
      stepFlag +=2;
    }
    else if((dp = strstr((char*)buff,"FD"))!=NULL){
      motor->d_mode = FULL_DRIVE;
      exData /=2;
      stepFlag +=2;
    }
  }
  stepData = p + stepFlag;
  if(buff[0]!='\0'){
    motor->motorStep = atoi(stepData)*exData;
  }
}

void stepMoterHalfDrive(int step, motorInfo motor)
{
  uint8_t step1 = step % 8;
  if(motor.c_mode == ccw){
    step1 = 8 - step1;
  }
  switch (step1) {
    case 0:
      for(int i =0; i<4; i++){
	HAL_GPIO_WritePin(motor.gpio[i], motor.p_num[i], HD_PATTERN[step1][i]);
      }
      break;
    case 1:
      for(int i =0; i<4; i++){
	HAL_GPIO_WritePin(motor.gpio[i], motor.p_num[i], HD_PATTERN[step1][i]);
      }
      break;
    case 2:
      for(int i =0; i<4; i++){
      	HAL_GPIO_WritePin(motor.gpio[i], motor.p_num[i], HD_PATTERN[step1][i]);
      }
      break;
    case 3:
      for(int i =0; i<4; i++){
	HAL_GPIO_WritePin(motor.gpio[i], motor.p_num[i], HD_PATTERN[step1][i]);
      }
      break;
    case 4:
      for(int i =0; i<4; i++){
	HAL_GPIO_WritePin(motor.gpio[i], motor.p_num[i], HD_PATTERN[step1][i]);
      }
      break;
    case 5:
      for(int i =0; i<4; i++){
      	HAL_GPIO_WritePin(motor.gpio[i], motor.p_num[i], HD_PATTERN[step1][i]);
      }
      break;
    case 6:
      for(int i =0; i<4; i++){
      	HAL_GPIO_WritePin(motor.gpio[i], motor.p_num[i], HD_PATTERN[step1][i]);
      }
      break;
    case 7:
      for(int i =0; i<4; i++){
      	HAL_GPIO_WritePin(motor.gpio[i], motor.p_num[i], HD_PATTERN[step1][i]);
      }
      break;
  }
}

void stepMoterFullDrive(int step, motorInfo motor)
{
  uint8_t step1 = step % 4;
  if(motor.c_mode == ccw){
    step1 = 4 - step1;
  }
  switch (step1) {
    case 0:
      for(int i =0; i<4; i++){
     	HAL_GPIO_WritePin(motor.gpio[i], motor.p_num[i], FD_PATTERN[step1][i]);
      }
      break;
    case 1:
      for(int i =0; i<4; i++){
	HAL_GPIO_WritePin(motor.gpio[i], motor.p_num[i], FD_PATTERN[step1][i]);
      }
      break;
    case 2:
      for(int i =0; i<4; i++){
	HAL_GPIO_WritePin(motor.gpio[i], motor.p_num[i], FD_PATTERN[step1][i]);
      }
      break;
    case 3:
      for(int i =0; i<4; i++){
	HAL_GPIO_WritePin(motor.gpio[i], motor.p_num[i], FD_PATTERN[step1][i]);
      }
      break;

  }
}

void stepMoterWaveDrive(int step, motorInfo motor)
{
  uint8_t step1 = step % 4;
  if(motor.c_mode == ccw){
    step1 = 4 - step1;
  }
  switch (step1) {
    case 0:
      for(int i =0; i<4; i++){
	HAL_GPIO_WritePin(motor.gpio[i], motor.p_num[i], WD_PATTERN[step1][i]);
      }
      break;
    case 1:
      for(int i =0; i<4; i++){
	HAL_GPIO_WritePin(motor.gpio[i], motor.p_num[i], WD_PATTERN[step1][i]);
      }
      break;
    case 2:
      for(int i =0; i<4; i++){
	HAL_GPIO_WritePin(motor.gpio[i], motor.p_num[i], WD_PATTERN[step1][i]);
      }
      break;
    case 3:
      for(int i =0; i<4; i++){
	HAL_GPIO_WritePin(motor.gpio[i], motor.p_num[i], WD_PATTERN[step1][i]);
      }
      break;
  }
}

