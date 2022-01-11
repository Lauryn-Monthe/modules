/*
 * bargraph.c
 *
 *  Created on: 26.10.2021
 *      Author: Samer Nekola und Lauryn Lorna Monthe
 */
#include <Bargraph/bargraph.h>

void lcd_Draw_Bargraph(uint16_t x,uint16_t y, uint16_t width, uint16_t height, uint16_t value, uint16_t Colour,  uint16_t bgColour)
{
	uint16_t 	X_length = 0;
	uint16_t	prozent = (value*100)/1024;
	X_length = (width*prozent)/100;

	ILI9341_Draw_Rectangle(x, y, width, height, bgColour);
	ILI9341_Draw_Rectangle(x, y, X_length, height, Colour);
}
