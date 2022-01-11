/*
 * S.h
 *
 *  Created on: 23.10.2021
 *      Author: Lauryn Lorna Monthe und Samer Nekola
 */

#ifndef SEG_LED_BOARD_SEGLED_H_
#define SEG_LED_BOARD_SEGLED_H_

#include "stm32f4xx.h"

void utils_gpioport_write(GPIO_TypeDef* GPIOx, uint16_t BitMuster);
uint16_t utils_gpioport_read(GPIO_TypeDef* GPIOx);

#endif /* SEG_LED_BOARD_SEGLED_H_ */
