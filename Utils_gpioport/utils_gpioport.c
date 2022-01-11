/*
 * S.c
 *
 *  Created on: 23.10.2021
 *  	Author: Lauryn Lorna Monthe und Samer Nekola
 */

#include <Utils_gpioport/utils_gpioport.h>

void utils_gpioport_write(GPIO_TypeDef* GPIOx, uint16_t BitMuster)
{
	GPIOx -> ODR = BitMuster;
}

uint16_t utils_gpioport_read(GPIO_TypeDef* GPIOx)
{
	return GPIOx -> IDR;
}

