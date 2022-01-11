/*
 * joystick.c
 *
 *  Created on: 24.10.2021
 *      Author: Author: Lauryn Lorna Monthe und Samer Nekola
 */
#include <Joystick/joystick.h>
#include <Utils_gpioport/utils_gpioport.h>

void joystick_init(void){
	__HAL_RCC_GPIOG_CLK_ENABLE();
	GPIOG_init();
}

void GPIOG_init(){

	GPIO_InitTypeDef GPIO_init_structG;

	GPIO_init_structG.Pin = JOY_A | JOY_B |JOY_C|JOY_D|JOY_P ;
	GPIO_init_structG.Mode = GPIO_MODE_INPUT;
	GPIO_init_structG.Pull = GPIO_PULLUP;
	GPIO_init_structG.Speed = GPIO_SPEED_MEDIUM;

	HAL_GPIO_Init(GPIOG, &GPIO_init_structG);

}

uint16_t joystick_read(){
	uint16_t gpio_idr = utils_gpioport_read(GPIOG);
	return gpio_idr;
}

