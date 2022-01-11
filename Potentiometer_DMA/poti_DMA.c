/*
 * poti_DMA.c
 *
 *  Created on: 10.11.2021
 *  Author: Lauryn Lorna Monthe und Samer Nekola
 *
 *  @brief Use the 2 potentiometers of Analog Test Board with DMA
 *
 */

#include <Potentiometer_DMA/poti_DMA.h>

/*
 * @brief	call of the initialization methods, Initialize Potentionmeter by enabling ADC clocks and GPIO ports
 * @param   none
 * @retval	none
 */
void potis_dma_init(){
	potis_GPIO_init();
	__HAL_RCC_DMA2_CLK_ENABLE();
	__HAL_RCC_ADC1_CLK_ENABLE();
	__HAL_RCC_ADC2_CLK_ENABLE();
	potis_dma_DMA2_init();
	potis_dma_ADC1_init();
	potis_dma_ADC2_init();
}

/*
 * @brief	initialization of ADC1
 * @param   none
 * @retval	none
 * @Config:
 * 	Instance: set register base address ADC1
 * 	ClockPrescaler: select ADC clock prescaler to deliver 84 MHz
 * 	Resolution: configures the ADC resolution to display 12bit result of conversation
 * 	DataAlign: specifies ADC data alignment to right (MSB on register bit 11
 * 	ScanConvMode: configures the sequencer of regular and injected groups to one source of channels
 * 	EOCSelection: setting EOC (End Of Conversion) flag if conversation is done
 * 	ContinousConvMode: Specifies the conversion is performed in continuous mode for regular group to get new values if conversation done
 * 	NbrOfConversion:  Specifies the number of ranks that will be converted within the regular group sequencer.
 * 	ExternalTrigConv: Selects the external event used to trigger the conversion start of regular group set to ADC_SOFTWARE_START, external triggers are disabled.
 * 	Channel: Specifies the channel to configure into ADC regular group. Channel 7 of the STM board is the left trigger
 * 	Rank: Specifies the rank in the regular group sequencer it must be between Min_Data = 1 and Max_Data = 16
 * 	SamplingTime: Sampling time value to be set for the selected channel, set as ADC clock cycles,
 * 				  Conversion time is the addition of sampling time (84) and processing time
 */
void potis_dma_ADC1_init(){
	ADC_handle_structure_1.Instance = ADC1;
	ADC_handle_structure_1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
	ADC_handle_structure_1.Init.Resolution = ADC_RESOLUTION_12B;
	ADC_handle_structure_1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	ADC_handle_structure_1.Init.ScanConvMode = DISABLE;
	ADC_handle_structure_1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	ADC_handle_structure_1.Init.ContinuousConvMode = ENABLE;
	ADC_handle_structure_1.Init.NbrOfConversion = 1;
	ADC_handle_structure_1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	ADC_handle_structure_1.Init.DMAContinuousRequests = ENABLE;
	ADC_handle_structure_1.DMA_Handle = &DMA_handle_structure_1;
	HAL_ADC_Init(&ADC_handle_structure_1);

	ADC_channel_structure_1.Channel = ADC_CHANNEL_7;
	ADC_channel_structure_1.Rank = 1;
	ADC_channel_structure_1.SamplingTime = ADC_SAMPLETIME_84CYCLES;
	HAL_ADC_ConfigChannel(&ADC_handle_structure_1, &ADC_channel_structure_1);
}

/*
 * @brief	initialization of ADC2
 * @param   none
 * @retval	none
 * Config:
 * 	Instance: set register base address ADC2
 * 	ClockPrescaler: select ADC clock prescaler to deliver 84 MHz
 * 	Resolution: configures the ADC resolution to display 12bit result of conversation
 * 	DataAlign: specifies ADC data alignment to right (MSB on register bit 11
 * 	ScanConvMode: configures the sequencer of regular and injected groups to one source of channels
 * 	EOCSelection: setting EOC (End Of Conversion) flag if conversation is done
 * 	ContinousConvMode: Specifies the conversion is performed in continuous mode for regular group to get new values if conversation done
 * 	NbrOfConversion:  Specifies the number of ranks that will be converted within the regular group sequencer.
 * 	ExternalTrigConv: Selects the external event used to trigger the conversion start of regular group set to ADC_SOFTWARE_START, external triggers are disabled.
 * 	Channel: Specifies the channel to configure into ADC regular group. Channel 6 of the STM board is the right trigger
 * 	Rank: Specifies the rank in the regular group sequencer it must be between Min_Data = 1 and Max_Data = 16
 * 	SamplingTime: Sampling time value to be set for the selected channel, set as ADC clock cycles,
 * 				  Conversion time is the addition of sampling time (84) and processing time
 */
void potis_dma_ADC2_init(){
	ADC_handle_structure_2.Instance = ADC2;
	ADC_handle_structure_2.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
	ADC_handle_structure_2.Init.Resolution = ADC_RESOLUTION_12B;
	ADC_handle_structure_2.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	ADC_handle_structure_2.Init.ScanConvMode = DISABLE;
	ADC_handle_structure_2.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	ADC_handle_structure_2.Init.ContinuousConvMode = ENABLE;
	ADC_handle_structure_2.Init.NbrOfConversion = 1;
	ADC_handle_structure_2.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	ADC_handle_structure_2.Init.DMAContinuousRequests = ENABLE;
	ADC_handle_structure_2.DMA_Handle = &DMA_handle_structure_2;
	HAL_ADC_Init(&ADC_handle_structure_2);

	ADC_channel_structure_2.Channel = ADC_CHANNEL_6;
	ADC_channel_structure_2.Rank = 1;
	ADC_channel_structure_2.SamplingTime = ADC_SAMPLETIME_84CYCLES;
	HAL_ADC_ConfigChannel(&ADC_handle_structure_2, &ADC_channel_structure_2);
}

/*
 * @brief	initialization of DMA2
 * @param   none
 * @retval	none
 * Config:
 * 	Instance: set register base address Stream0 or Stream2
 * 	Channel: Specifies the channel used for the specified stream as STM34F4 Reference manual on table 41
 * 			 shows,	the needed channels and stream for ADC1 is Stream 0 Channel 0 and ADC2 is Stream 2 Channel 1
 * 	Direction: Specifies the data will be transferred from peripheral to memory.
 * 	PeriphInc: Specifies the Peripheral address register should be not incremented.
 * 	MemInc: Specifies the memory address register should be incremented.
 * 	PeriphDataAlignment: Specifies the Peripheral data width as 16Bit int.
 * 	MemDataAlignment: Specifies the Memory data width as 16Bit int.
 * 	Mode: Specifies the operation mode of the DMAy Streamx.
 *         @note The circular buffer mode cannot be used if the memory-to-memory.
 *         data transfer is configured on the selected Stream
 * 	Priority: Specifies the software priority for the DMAy Streamx.
 * 	FIFOMode: Specifies if the FIFO mode or Direct mode will be used for the specified stream.
 *    		  @note The Direct mode (FIFO mode disabled) cannot be used if the memory-to-memory
 *   		  data transfer is configured on the selected stream
 */
void potis_dma_DMA2_init(){
	/*DMA2 Stream0 channel 0 for ADC1*/
	DMA_handle_structure_1.Instance = DMA2_Stream0;
	DMA_handle_structure_1.Init.Channel = DMA_CHANNEL_0;
	DMA_handle_structure_1.Init.Direction = DMA_PERIPH_TO_MEMORY;
	DMA_handle_structure_1.Init.PeriphInc = DMA_PINC_DISABLE;
	DMA_handle_structure_1.Init.MemInc = DMA_MINC_ENABLE;
	DMA_handle_structure_1.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
	DMA_handle_structure_1.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
	DMA_handle_structure_1.Init.Mode = DMA_CIRCULAR;
	DMA_handle_structure_1.Init.Priority = DMA_PRIORITY_HIGH;
	DMA_handle_structure_1.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
	HAL_DMA_Init(&DMA_handle_structure_1);

	/*DMA2 Stream2 channel 1 for ADC2*/
	DMA_handle_structure_2.Instance = DMA2_Stream2;
	DMA_handle_structure_2.Init.Channel = DMA_CHANNEL_1;
	DMA_handle_structure_2.Init.Direction = DMA_PERIPH_TO_MEMORY;
	DMA_handle_structure_2.Init.PeriphInc = DMA_PINC_DISABLE;
	DMA_handle_structure_2.Init.MemInc = DMA_MINC_ENABLE;
	DMA_handle_structure_2.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
	DMA_handle_structure_2.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
	DMA_handle_structure_2.Init.Mode = DMA_CIRCULAR;
	DMA_handle_structure_2.Init.Priority = DMA_PRIORITY_HIGH;
	DMA_handle_structure_2.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
	HAL_DMA_Init(&DMA_handle_structure_2);
}


/*
 * @brief to controll which Poti is used, activate the needed ADC Handler to start conversation
 * @param   poti number
 * @retval	value after conversion
 */
void potis_dma_getVal(uint8_t poti_num){
	if(poti_num == 1){
		HAL_ADC_Start_DMA(&ADC_handle_structure_1, pData1, 100);
	}
	else{
		HAL_ADC_Start_DMA(&ADC_handle_structure_2, pData2, 100);
	}
}

/**
 * @brief	get average of last 100 scans
 * @param   pointer to store value after conversion
 * @retval	average of last 100 scans
*/
uint16_t potis_dma_getAverage(uint32_t *pData){
	uint16_t average = pData[0];
	for(int i =1; i<4; i++){
		average += pData[i];
	}
	average /= 4;
	return average;
}


