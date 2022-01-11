/*
 * joystick.h
 *
 *  Created on: 24.10.2021
 *      Author: Samer Nekola und Lauryn Lorna Monthe
 */

#ifndef JOYSTICK_JOYSTICK_H_
#define JOYSTICK_JOYSTICK_H_
#include "stm32f4xx.h"

#define JOY_A GPIO_PIN_6
#define JOY_B GPIO_PIN_9
#define JOY_C GPIO_PIN_10
#define JOY_D GPIO_PIN_11
#define JOY_P GPIO_PIN_12

#define JOY_UP JOY_D
#define JOY_DOWN JOY_A
#define JOY_LEFT JOY_B
#define JOY_RIGHT JOY_C
#define JOY_PRESS JOY_P


void joystick_init(void);
void GPIOG_init();
uint16_t joystick_read();

#endif /* JOYSTICK_JOYSTICK_H_ */
