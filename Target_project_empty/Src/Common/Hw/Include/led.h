/*
 * led.h
 *
 *  Created on: Oct 13, 2023
 *      Author: user
 */

#ifndef SRC_COMMON_HW_INCLUDE_LED_H_
#define SRC_COMMON_HW_INCLUDE_LED_H_

#include "hw_def.h"		// 하드웨어 정보 가져오기 위해



#ifdef _USE_HW_LED

#define LED_MAX_CH	HW_LED_MAX_CH

// led를 제어하기 위한 api 작성
bool ledInit(void);
void ledOn(uint8_t ch);
void ledOff(uint8_t ch);
void ledToggle(uint8_t ch);

#endif

#endif /* SRC_COMMON_HW_INCLUDE_LED_H_ */
