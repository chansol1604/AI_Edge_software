/*
 * ap.c
 *
 *  Created on: Oct 13, 2023
 *      Author: user
 */

#include "ap.h"



void apInit(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

   /* GPIO Ports Clock Enable */
   __HAL_RCC_GPIOB_CLK_ENABLE();

   /*Configure GPIO pin Output Level */
   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);

   /*Configure GPIO pin : PB1 */
   GPIO_InitStruct.Pin = GPIO_PIN_1;
   GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
   GPIO_InitStruct.Pull = GPIO_NOPULL;
   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
   HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

void apMain(void)
{
  while(1)
  {
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
    delay(500);

  }
}
