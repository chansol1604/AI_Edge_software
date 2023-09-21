/*
 * STEPPER.h
 *
 *  Created on: Sep 21, 2023
 *      Author: user
 */

#ifndef INC_STEPPER_H_
#define INC_STEPPER_H_

#include "tim.h"
#include "string.h"
#include "stdlib.h"

#define stepMoterHalfStep	4096
#define stepMoterFullStep	2048

#define WAVE_DRIVE 	0
#define FULL_DRIVE 	1
#define HALF_DRIVE 	2

enum{
  ccw,
  cw
};

typedef struct{
  GPIO_TypeDef * gpio[4];
  uint16_t p_num[4];
  int motorStep;
  uint8_t d_mode;
  uint8_t c_mode;
}motorInfo;


static uint8_t FD_PATTERN[4][4] = {
    {1, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 1},
    {1, 0, 0, 1}
};

static uint8_t WD_PATTERN[4][4] = {
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1}
};

static uint8_t HD_PATTERN[8][4] = {
    {1, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 1, 1},
    {0, 0, 0, 1},
    {1, 0, 0, 1}
};


void stepInit(motorInfo motor);
void stepCtlr(uint8_t * buff, motorInfo * motor);
void stepMoterSpeed(int speed);
void stepMoterHalfDrive(int step, motorInfo motor);
void stepMoterFastDrive(int step, motorInfo motor);
void stepMoterWaveDrive(int step, motorInfo motor);

#endif /* INC_STEPPER_H_ */
