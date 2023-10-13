/*
 * led.c
 *
 *  Created on: Oct 13, 2023
 *      Author: user
 */

#include "led.h"



typedef struct
{
  GPIO_TypeDef *port;
  uint16_t 	pin;
  GPIO_PinState on_state;
  GPIO_PinState off_state;
}led_tbl_cfg;

led_tbl_cfg led_tbl[LED_MAX_CH]=
    {
	{GPIOB, GPIO_PIN_1, GPIO_PIN_SET, GPIO_PIN_RESET},
	{GPIOB, GPIO_PIN_15, GPIO_PIN_SET, GPIO_PIN_RESET},
	{GPIOB, GPIO_PIN_14, GPIO_PIN_SET, GPIO_PIN_RESET},
	{GPIOB, GPIO_PIN_13, GPIO_PIN_SET, GPIO_PIN_RESET}
    };

bool ledInit(void)
{
  bool ret = true;
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
//  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);

  /*Configure GPIO pin*/
//  GPIO_InitStruct.Pin = GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  for(int i=0; i<LED_MAX_CH; i++)
  {
    GPIO_InitStruct.Pin = led_tbl[i].pin;
    HAL_GPIO_Init(led_tbl[i].port, &GPIO_InitStruct);
  }
  return ret;
}

void ledOn(uint8_t ch)
{
  if(ch>= LED_MAX_CH) return;
  HAL_GPIO_WritePin(led_tbl[ch].port, led_tbl[ch].pin, GPIO_PIN_SET);
}

void ledOff(uint8_t ch)
{
  if(ch>= LED_MAX_CH) return;
  HAL_GPIO_WritePin(led_tbl[ch].port, led_tbl[ch].pin, GPIO_PIN_RESET);
}

void ledToggle(uint8_t ch)
{
  HAL_GPIO_TogglePin(led_tbl[ch].port, led_tbl[ch].pin);
}
