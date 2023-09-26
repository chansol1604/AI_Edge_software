![image](https://github.com/chansol1604/AI_Edge_software/assets/58240527/f179089b-912b-4a4b-a608-5ef1cca63ba9)# Intel AI_EDGE_SOFTWARE

(Intel)AI_Edge_software 과정에서 공부한 것 정리한 공간

##### ADC_BASIC ###########
아날로그인 가변저항의 값을 디지털로 변환해서 출력하는 프로그램

![스크린샷 2023-09-20 150640](https://github.com/chansol1604/AI_Edge_software/assets/58240527/19c65b9d-d64c-4ca3-98e8-59469cadccd9)


##### ADC_DMA #############
조도센서와 가변저항의 값을 받아 출력하는 프로그램 

![KakaoTalk_20230920_153102278](https://github.com/chansol1604/AI_Edge_software/assets/58240527/eccd2fe8-c1a6-42fb-af59-3552039fd25d)


##### ADC_JOYSTICK_LCD ####
조이스틱의 동작 여부에 따라 LCD에 left, right, straight, rearguard를 출력하고 조이스틱을 누를 경우 빈 화면을 출력하는 프로그램

![adc_joystick_lcd](https://github.com/chansol1604/AI_Edge_software/assets/58240527/f6923d28-2b59-4b53-8749-2ef179789953)


##### ADC_JOYSTICK ########
조이스틱의 동작 여부에 따라 해당하는 LED에 빛을 출력하고 조이스틱을 누를 경우 설정해둔 LED가 TOGGLE 되도록 설정한 프로그램

https://github.com/chansol1604/AI_Edge_software/assets/58240527/309cc178-45eb-4a65-8d72-20059106f66d


##### BUZZER ##############
수동 부저를 이용한 간단한 소리 예제 프로그램

![KakaoTalk_20230920_154450282_01](https://github.com/chansol1604/AI_Edge_software/assets/58240527/968e1f18-5bc8-4bd7-b9b8-18aed4587a86)


##### BUZZER02 ############
a, b, c, d, e, f, g, h 의 값을 보내줬을 때 수동부저를 이용해 값에 맞는 음을 출력하는 프로그램

![KakaoTalk_20230920_154450282](https://github.com/chansol1604/AI_Edge_software/assets/58240527/0dded8fc-7191-435f-a860-b71caf39a2a6)


##### Embedded_Setting_default
새로운 프로젝트를 만들 때마다 기본 세팅 값을 설정하기 귀찮아 만든 기본 틀

##### FAN_DC_MOTOR
DC_MOTOR_R300을 이용해 선풍기를 구현한 예제

https://github.com/chansol1604/AI_Edge_software/assets/58240527/de88560f-684c-430a-9b78-1ab008737a07


##### I2C ##################
LCD에 카운터를 세는 것을 출력하는 프로그램

![KakaoTalk_20230920_155957085](https://github.com/chansol1604/AI_Edge_software/assets/58240527/dd5f8f0b-6a97-46fd-b103-41d7ca510459)



##### I2C_ULTRASONIC ########
초음파 센서를 이용해 거리를 LCD에 출력하는 프로그램

![KakaoTalk_20230920_161606328](https://github.com/chansol1604/AI_Edge_software/assets/58240527/d2d6b5c1-6095-4e62-923d-c628df0c7fa3)


##### LED_BLINK ##############
LED가 깜빡이는 간단한 프로그램

![0920162819230129](https://github.com/chansol1604/AI_Edge_software/assets/58240527/f63df3de-749e-4b43-a2d3-440ef67ad791)


##### LED_BLINK00 ############
버튼을 누르고 있을 때 LED에 불이 들어오는 프로그램

![0920163108544696](https://github.com/chansol1604/AI_Edge_software/assets/58240527/853c92d4-3044-4fc4-b044-e153baea9654)


##### LED_IT ##################
LED가 한 칸씩 이동하며 출력되고 버튼을 누르면 인터럽트를 이용해 이동하는 방향을 바꿔 출력하는 프로그램

![KakaoTalk_20230920_164152895](https://github.com/chansol1604/AI_Edge_software/assets/58240527/bd995f43-5cd4-4c35-acf9-d1abad473d47)


##### LED_SHIFT ################
LED_IT와 동작은 같지만 인터럽트를 사용하지 않은 예제

![KakaoTalk_20230920_164704622](https://github.com/chansol1604/AI_Edge_software/assets/58240527/833aa29b-f1b0-47c8-8f04-b9dff21b4491)


##### LED_SHIFT02 ###############
버튼 3개를 이용해 LED를 출력하는 예제, 1번 버튼은 오른쪽 방향으로 LED를 shift 시키고 2번은 좌우로 반복, 3번은 좌측으로 shift 이동시킴.

![KakaoTalk_20230920_165345268](https://github.com/chansol1604/AI_Edge_software/assets/58240527/da8e3205-c6bc-4bd4-8bcc-f02d8c4cb7d3)


##### MOTOR_28BYJ_48 #############
모터를 90도 돌리고 잠깐 멈췄다 반복하는 예제

https://github.com/chansol1604/AI_Edge_software/assets/58240527/6bceedbf-192d-4104-b26f-389b68f0c509


##### PWM90 ######################
SG90 서브 모터를 움직이는 간단한 예제

![KakaoTalk_20230920_171222740](https://github.com/chansol1604/AI_Edge_software/assets/58240527/51430a18-cf73-43b3-be30-2b13aff5906a)


##### PWM90 ######################
SG90 서브 모터를 0도, 90도, 180도로 반복해서 움직이는 예제

https://github.com/chansol1604/AI_Edge_software/assets/58240527/6897c38f-3871-4f63-8d2b-60814a5d0371


###### PWM_UART01 ###################
uart 통신으로 보낸 a, b, c로 SG90 서브 모터를 각각의 각도로 제어하는 예제

![0920170855720100](https://github.com/chansol1604/AI_Edge_software/assets/58240527/0cb660d7-0566-440f-887a-6b565c03339a)


##### RTC ###########################
시간과 날짜를 통신으로 받고 그 값을 다시 출력해주는 예제

![스크린샷 2023-09-20 171503](https://github.com/chansol1604/AI_Edge_software/assets/58240527/8afad84b-9f0b-455c-9eaf-e196f8313f14)


##### RTC_MOTOR_28BYJ_48 #############
각도를 받아 모터를 움직이는 예제

![스크린샷 2023-09-21 142019](https://github.com/chansol1604/AI_Edge_software/assets/58240527/99d207ae-181c-4dfb-b60c-b3a34253e1fa)
https://github.com/chansol1604/AI_Edge_software/assets/58240527/21b73f1b-c0a8-4660-a3b4-86fcc61ed429


##### TIMER ##########################
타이머를 이용해 LED를 토글시키는 예제

![0920172022208260](https://github.com/chansol1604/AI_Edge_software/assets/58240527/f1c5b2fa-d3d7-4c3a-b43a-d7d66e0ac4f1)


###### UART




