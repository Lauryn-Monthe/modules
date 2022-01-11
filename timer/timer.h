/*
 * timer.h
 *
 *  Created on: 21.11.2021
 *      Author: Lauryn Lorna Monthe
 */

#ifndef TIMER_TIMER_H_
#define TIMER_TIMER_H_

#include "stm32f4xx.h"

#define SEG_1 GPIO_PIN_14
#define SEG_2 GPIO_PIN_15
#define SEG_3 GPIO_PIN_0
#define SEG_4 GPIO_PIN_1
#define DOT   GPIO_PIN_11


TIM_HandleTypeDef tim_handle_struct;
TIM_OC_InitTypeDef tim_oc_handle_struct;
GPIO_InitTypeDef GPIO_init_struct;

void timer_TIM_init();
void timer_init();
void timer_oc_init();
void timer_GPIO_init();

#endif /* TIMER_TIMER_H_ */
