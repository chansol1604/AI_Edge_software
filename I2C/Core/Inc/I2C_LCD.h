/*
 * I2C_LCD.h
 *
 *  Created on: Sep 14, 2023
 *      Author: user
 */

#ifndef INC_I2C_LCD_H_
#define INC_I2C_LCD_H_

#include "stm32f4xx_hal.h"
#include "i2c.h"

void LCD_Send_cmd(char cmd);
void LCD_Send_data(char data);
void LCD_Clear(void);
void LCD_Put_cur(int row, int col);
void LCD_Init(void);
void LCD_Send_string(char *str);

#endif /* INC_I2C_LCD_H_ */
