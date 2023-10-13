/*
 * ap.c
 *
 *  Created on: Oct 13, 2023
 *      Author: user
 */

#include "ap.h"



void apInit(void)
{

}

void apMain(void)
{
  int i =0;
  while(1)
  {
//    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
    i++;
    i=i%4;
    ledToggle(i);
    delay(500);

  }
}
