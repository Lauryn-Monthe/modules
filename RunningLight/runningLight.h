/*
 * lauflicht.h
 *
 *  Created on: 24.10.2021
 *      Author: T440s
 */

#ifndef LAUFLICHT_LAUFLICHT_H_
#define LAUFLICHT_LAUFLICHT_H_
#include "stm32f4xx.h"

#define LED_A GPIO_PIN_7
#define LED_B GPIO_PIN_4
#define LED_C GPIO_PIN_5
#define LED_D GPIO_PIN_6
#define LED_E GPIO_PIN_12
#define LED_F GPIO_PIN_11
#define LED_G GPIO_PIN_12
#define SEG_1 GPIO_PIN_14
#define SEG_2 GPIO_PIN_15
#define SEG_3 GPIO_PIN_0
#define SEG_4 GPIO_PIN_1

void lauflicht_init();
void GPIO_init_1();
void lauflicht_run();
void utils_delay_ms(uint32_t t);
#endif /* LAUFLICHT_LAUFLICHT_H_ */
