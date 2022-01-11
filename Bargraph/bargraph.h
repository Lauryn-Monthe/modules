/*
 * bargraph.h
 *
 *  Created on: 26.10.2021
 *      Author: Samer Nekola und Lauryn Lorna Monthe
 */

#ifndef BARGRAPH_BARGRAPH_H_
#define BARGRAPH_BARGRAPH_H_
#include "stm32f4xx.h"

void lcd_Draw_Bargraph(uint16_t x,uint16_t y, uint16_t width, uint16_t height, uint16_t value, uint16_t Colour,  uint16_t bgColour);

#endif /* BARGRAPH_BARGRAPH_H_ */
