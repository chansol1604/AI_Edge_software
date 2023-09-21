/*
 * STEPPER.h
 *
 *  Created on: Sep 21, 2023
 *      Author: user
 */

#ifndef INC_STEPPER_H_
#define INC_STEPPER_H_

#include "tim.h"

#define stepMoterHalfStep	4096
#define stepMoterFullStep	2048

enum{
  ccw,
  cw
};

void stepMoterSpeed(int speed);
void stepMoterHalfDrive(int step);


#endif /* INC_STEPPER_H_ */
