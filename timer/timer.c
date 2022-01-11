/*
 * timer.c
 *
 *  Created on: 21.11.2021
 *      Author: T440s
 */
#include <timer/timer.h>

void timer_TIM_init(){
	__HAL_RCC_TIM1_CLK_ENABLE();
	tim_handle_struct.Instance = TIM1;
	tim_handle_struct.Init.Prescaler = (SystemCoreClock / 10000) - 1;
	/*Configuration of timer blinking dot*/
	//tim_handle_struct.Init.Period = 10000 - 1;
	/*Configuration of timer dimming dot*/
	tim_handle_struct.Init.Period = 100 - 1;
	tim_handle_struct.Init.CounterMode = TIM_COUNTERMODE_UP;
	tim_handle_struct.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim_handle_struct.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	tim_handle_struct.Init.RepetitionCounter = 0;
	HAL_TIM_Base_Init(&tim_handle_struct);
}

void timer_oc_init(){
	tim_oc_handle_struct.OCMode = TIM_OCMODE_PWM1;
	/*Configuration of timer blinking dot*/
	tim_oc_handle_struct.Pulse = 10000;
	/*Configuration of timer dimming dot*/
	//tim_oc_handle_struct.Pulse = 50;
	tim_oc_handle_struct.OCIdleState = TIM_OCIDLESTATE_SET;
	tim_oc_handle_struct.OCPolarity = TIM_OCPOLARITY_HIGH;
	tim_oc_handle_struct.OCNIdleState = TIM_OCNIDLESTATE_RESET;
	tim_oc_handle_struct.OCNPolarity = TIM_OCNPOLARITY_LOW;
	tim_oc_handle_struct.OCFastMode = TIM_OCFAST_DISABLE;
	HAL_TIM_OC_ConfigChannel(&tim_handle_struct, &tim_oc_handle_struct, TIM_CHANNEL_2);
}

void timer_GPIO_init(){
	__HAL_RCC_GPIOE_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();

	GPIO_init_struct.Pin = DOT;
	GPIO_init_struct.Mode = GPIO_MODE_AF_PP;
	GPIO_init_struct.Alternate = GPIO_AF1_TIM1;
	HAL_GPIO_Init(GPIOE, &GPIO_init_struct);

	GPIO_InitTypeDef GPIO_init_structD;
	GPIO_init_structD.Pin = SEG_1|SEG_2|SEG_3|SEG_4|GPIO_PIN_11;
	GPIO_init_structD.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_init_structD.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOD, &GPIO_init_structD);
}

void timer_init(void) {
	timer_TIM_init();
	timer_oc_init();
	timer_GPIO_init();
}
