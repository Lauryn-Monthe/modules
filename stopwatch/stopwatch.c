/*
 * stopwatch.c
 *
 *  Created on: 05.12.2021
 *      Author: Lauryn Lorna Monthe and Samer Nekola
 * @brief 	Module for using timer and interrupt to create a stopwatch
 *
 */

#include <stopwatch/stopwatch.h>
/*
 * @brief	Initialization of timer 2, set priority of his interrupt and IRQ enable.
 * @param   none
 * @retval	none
 */
void stopwatch_TIM_init(){
	__HAL_RCC_TIM2_CLK_ENABLE();
	tim_handle_struct.Instance = TIM2;
	tim_handle_struct.Init.Prescaler = ((SystemCoreClock/2) / 100000) - 1;
	tim_handle_struct.Init.Period = 10 - 1;
	tim_handle_struct.Init.CounterMode = TIM_COUNTERMODE_UP;
	tim_handle_struct.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim_handle_struct.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	tim_handle_struct.Init.RepetitionCounter = 0;
	HAL_TIM_Base_Init(&tim_handle_struct);
	HAL_NVIC_SetPriority(TIM2_IRQn, 1, 2);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

/*
 * @brief	Initialization of user button (PA0), set priority of his interrupt and IRQ enable.
 * @param   none
 * @retval	none
 */
void stopwatch_gpio_init(){
	__HAL_RCC_GPIOA_CLK_ENABLE();

	nvic_GPIO_init_struct.Pin = USER_BUTTON;
	nvic_GPIO_init_struct.Mode = GPIO_MODE_IT_RISING;
	nvic_GPIO_init_struct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &nvic_GPIO_init_struct);
	HAL_NVIC_SetPriority(EXTI0_IRQn, 1, 0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}

/*
 * @brief	Start of timer 2
 * @param   none
 * @retval	none
 */
void stopwatch_start(){
	HAL_TIM_Base_Start_IT(&tim_handle_struct);
}

/*
 * @brief	Save time when the user button is pressed
 * @param   none
 * @retval	none
 */
void stopwatch_save_time(){
	counter = 2;
	h = stopwatch_h;
	m = stopwatch_m;
	s = stopwatch_s;
	milli_s = stopwatch_milli_s;
}
