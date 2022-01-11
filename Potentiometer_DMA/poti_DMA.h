/*
 * poti_DMA.h
 *
 *  Created on: 10.11.2021
 *      Author: Lauryn Lorna Monthe und Samer Nekola
 */

#ifndef POTENTIOMETER_DMA_POTI_DMA_H_
#define POTENTIOMETER_DMA_POTI_DMA_H_


#include "stm32f4xx.h"
#include <Bargraph/bargraph.h>
#include <Potentiometer/potis.h>


DMA_HandleTypeDef DMA_handle_structure_1;
DMA_HandleTypeDef DMA_handle_structure_2;

void potis_dma_DMA2_init();
void potis_dma_ADC1_init();
void potis_dma_ADC2_init();
void potis_dma_init();
void potis_dma_getVal(uint8_t poti_num);
uint16_t potis_dma_getAverage(uint32_t *pData);

uint32_t pData1[100];
uint32_t pData2[100];


#endif /* POTENTIOMETER_DMA_POTI_DMA_H_ */
