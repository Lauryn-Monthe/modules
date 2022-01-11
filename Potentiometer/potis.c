/*
 * potis.c
 *
 *  Created on: 02.11.2021
 *  Author: Lauryn Lorna Monthe und Samer Nekola
 *  @brief Use the 2 potentiometers of Analog Test Board
 */

#include <Bargraph/bargraph.h>
#include <Potentiometer/potis.h>


/**
 * @brief	initialization of poti 1 and poti 2
 * @param   none
 * @retval	none
 */
void potis_init(void){
	potis_GPIO_init();
	__HAL_RCC_ADC1_CLK_ENABLE();
	__HAL_RCC_ADC2_CLK_ENABLE();
	potis_ADC1_init();
	potis_ADC2_init();
}

/**
 * @brief	initialization of poti 1 and poti 2
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
 *
 */
void potis_ADC1_init(){
	ADC_handle_structure_1.Instance = ADC1;
	ADC_handle_structure_1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
	ADC_handle_structure_1.Init.Resolution = ADC_RESOLUTION_12B;
	ADC_handle_structure_1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	ADC_handle_structure_1.Init.ScanConvMode = DISABLE;
	ADC_handle_structure_1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	ADC_handle_structure_1.Init.ContinuousConvMode = ENABLE;
	ADC_handle_structure_1.Init.NbrOfConversion = 1;
	ADC_handle_structure_1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	HAL_ADC_Init(&ADC_handle_structure_1);

	ADC_channel_structure_1.Channel = ADC_CHANNEL_7;
	ADC_channel_structure_1.Rank = 1;
	ADC_channel_structure_1.SamplingTime = ADC_SAMPLETIME_84CYCLES;
	HAL_ADC_ConfigChannel(&ADC_handle_structure_1, &ADC_channel_structure_1);
}


/**
 * @brief	initialization of poti 2
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
 *
 */
void potis_ADC2_init(){
	ADC_handle_structure_2.Instance = ADC2;
	ADC_handle_structure_2.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
	ADC_handle_structure_2.Init.Resolution = ADC_RESOLUTION_12B;
	ADC_handle_structure_2.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	ADC_handle_structure_2.Init.ScanConvMode = DISABLE;
	ADC_handle_structure_2.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	ADC_handle_structure_2.Init.ContinuousConvMode = ENABLE;
	ADC_handle_structure_2.Init.NbrOfConversion = 1;
	ADC_handle_structure_2.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	HAL_ADC_Init(&ADC_handle_structure_2);

	ADC_channel_structure_2.Channel = ADC_CHANNEL_6;
	ADC_channel_structure_2.Rank = 1;
	ADC_channel_structure_2.SamplingTime = ADC_SAMPLETIME_84CYCLES;
	HAL_ADC_ConfigChannel(&ADC_handle_structure_2, &ADC_channel_structure_2);
}

/*
 * @brief to controll which Poti is used, activate the needed ADC Handler to start conversation
 * @param poti_num gets the value of the selected ADC converted value
 * @retval	value of conversion
 */
uint32_t potis_getVal(uint8_t poti_num){
	if (poti_num == Poti_1){
		/* Poll for regular conversion complete */
		HAL_StatusTypeDef ret = HAL_ADC_PollForConversion(&ADC_handle_structure_1, 1000);
		if(ret != HAL_TIMEOUT)
		{
			uint32_t ADC_val = HAL_ADC_GetValue(&ADC_handle_structure_1);
			/* Return the selected ADC converted value */
			return ADC_val;
		}
	}
	else if(poti_num == Poti_2){
		/* Poll for regular conversion complete */
		HAL_StatusTypeDef ret = HAL_ADC_PollForConversion(&ADC_handle_structure_2, 1000);
		if(ret != HAL_TIMEOUT)
		{
			uint32_t ADC_val = HAL_ADC_GetValue(&ADC_handle_structure_2);
			/* Return the selected ADC converted value */
			return ADC_val;
		}
	}
	else {}

	/* Return 0 if no ADC is performed */
	return 0;
}

/*
 * @brief Initialize GPIO ports for the Potentionmeter by enabling the needed Pins
 * @param   none
 * @retval	none
 */
void potis_GPIO_init(){
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef GPIO_init_structA;

	GPIO_init_structA.Pin = Poti_1 | Poti_2;
	GPIO_init_structA.Mode = GPIO_MODE_ANALOG;
	GPIO_init_structA.Speed = GPIO_SPEED_MEDIUM;

	HAL_GPIO_Init(GPIOA, &GPIO_init_structA);
}
