/*
 * lauflicht.c
 *
 *  Created on: 24.10.2021
 *      Author:  Lauryn Lorna Monthe und Samer Nekola
 *      @brief	 runninglight with seg led board
 */

/**
 * @brief	call of the initialization methods
 * @param   none
 * @retval	none
 */
#include <RunningLight/runningLight.h>

void lauflicht_init(){
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOE_CLK_ENABLE();
	GPIO_init_1();
}

/**
 * @brief	initialization of gpio port D
 * @param   none
 * @retval	none
 */
void GPIO_init_1(){

	GPIO_InitTypeDef GPIO_init_structD;
	GPIO_init_structD.Pin = LED_A | LED_B |LED_C|LED_D|LED_E|LED_F|SEG_1|SEG_2|SEG_3|SEG_4;
	GPIO_init_structD.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_init_structD.Pull = GPIO_NOPULL;
	GPIO_init_structD.Speed = GPIO_SPEED_MEDIUM;

	HAL_GPIO_Init(GPIOD, &GPIO_init_structD);

	GPIO_InitTypeDef GPIO_init_structE;

		GPIO_init_structE.Pin = LED_G;
		GPIO_init_structE.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_init_structE.Pull = GPIO_NOPULL;
		GPIO_init_structE.Speed = GPIO_SPEED_MEDIUM;

		HAL_GPIO_Init(GPIOE, &GPIO_init_structE);
}

/*Array of all leds*/
uint16_t array_of_leds[] = {LED_A, LED_B,LED_C,LED_D,LED_E,LED_F};

/**
 * @brief	runninglight method
 * @param   none
 * @retval	none
 */
void lauflicht_run(){
	/*Set all pins of all segements*/
	HAL_GPIO_WritePin(GPIOD, SEG_1|SEG_2|SEG_3|SEG_4, GPIO_PIN_SET);
	/*Set pin of led G*/
	HAL_GPIO_WritePin(GPIOE, LED_G, GPIO_PIN_SET);
	for(int i =0; i < 6; i++){
		/*Reset all pins of array_of_leds*/
		HAL_GPIO_WritePin(GPIOD, array_of_leds[i], GPIO_PIN_RESET);
		utils_delay_ms(1000);
		/*Set all pins of array_of_leds*/
		HAL_GPIO_WritePin(GPIOD, array_of_leds[i], GPIO_PIN_SET);
		utils_delay_ms(1000);
	}
	for(int i =5; i >=0; i--){
		HAL_GPIO_WritePin(GPIOD, array_of_leds[i], GPIO_PIN_RESET);
		utils_delay_ms(1000);
		HAL_GPIO_WritePin(GPIOD, array_of_leds[i], GPIO_PIN_SET);
		utils_delay_ms(1000);
	}
}

/**
 * @brief	Waiting time method
 * @param   none
 * @retval	none
 */
void utils_delay_ms(uint32_t t){
	int i;
	for(i = t*5000; i> 0; i--);
}

