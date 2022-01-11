/*
 * potis.h
 *
 *  Created on: 02.11.2021
 *      Author: Lauryn Lorna Monthe und Samer Nekola
 */

#ifndef POTENTIOMETER_POTIS_H_
#define POTENTIOMETER_POTIS_H_

#include "stm32f4xx.h"

#define Poti_1 GPIO_PIN_7
#define Poti_2 GPIO_PIN_6

ADC_HandleTypeDef ADC_handle_structure_1;
ADC_ChannelConfTypeDef ADC_channel_structure_1;

ADC_HandleTypeDef ADC_handle_structure_2;
ADC_ChannelConfTypeDef ADC_channel_structure_2;

void potis_init();
void potis_GPIO_init();
void potis_init(void);
void potis_ADC1_init();
void potis_ADC2_init();
uint32_t potis_getVal(uint8_t poti_num);

#endif /* POTENTIOMETER_POTIS_H_ */
