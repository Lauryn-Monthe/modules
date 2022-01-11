/*
 * stopwatch.h
 *
 *  Created on: 05.12.2021
 *      Author: T440s
 */

#ifndef STOPWATCH_STOPWATCH_H_
#define STOPWATCH_STOPWATCH_H_
#include "stm32f4xx.h"

#define USER_BUTTON	GPIO_PIN_0
TIM_HandleTypeDef tim_handle_struct;
GPIO_InitTypeDef nvic_GPIO_init_struct;
uint16_t counter;
volatile uint16_t stopwatch_micro_s;
volatile uint16_t stopwatch_milli_s;
volatile uint16_t stopwatch_s;
volatile uint16_t stopwatch_m;
volatile uint16_t stopwatch_h;
volatile uint16_t h;
volatile uint16_t s;
volatile uint16_t m;
volatile uint16_t milli_s;
void stopwatch_TIM_init();
void stopwatch_gpio_init();
void stopwatch_start();
void stopwatch_save_time();

#endif /* STOPWATCH_STOPWATCH_H_ */
