/*
 * DR_ADC.c
 *
 *  Created on: 29 de oct. de 2019
 *      Author: chor
 */

#include "TPL2_FIR_eq_rip.h"

void ADC_Init(void)
{

	//1.- Activo la alimentacion del dispositivo desde el registro PCONP:
	PCONP |= 1<<12;
	//2.- Configuro los pines del ADC0
	//ADC0.5 (pote) : P1[31]->PINSEL3: 30:31
	MySetPINSEL(1,31,PINSEL_FUNC3);
	//3.- Activo interrupcion del canal 5:
	AD0INTEN = 0x20;
	//4.- Configuro la velocidad de muestreo en 200kHz:
	//4.1 - Primero el ADCCLK en 25MHz
	PCLKSEL0 &= ~(0x03<<24);
	//4.2 - Y luego el divisor como 12, para muestrear a 25MHz/65*13 = 29,5kHz:
	AD0CR = 0x0C00;
	//5.- Selecciono que voy a tomar muestras del canal AD0.5:
	AD0CR |= 0x20;
	//6.- Selecciono que el ADC muestree solo, con BURST = 1 y START = 000:
	AD0CR &= ~(0x0F<<24);
	AD0CR |= 1<<16;
	//7.- Activo el ADC (PDN = 1):
	AD0CR |= 1<<21;
	//8.- Activo interrupcion en el NVIC:
	ISER0 |= (1<<22);
}

void ADC_IRQHandler(void)
{
	uint32_t ADC_value;
	float32_t inputf32;

	ADC_value = (AD0DR5 >> 4) & 0xFFF;

	inputf32 = (float32_t)ADC_value/4096;

	arm_float_to_q31(&inputf32,&inputQ31,BLOCK_SIZE);

/* ----------------------------------------------------------------------
** Call the FIR process function for every blockSize samples
** ------------------------------------------------------------------- */
	arm_fir_q31(&S, &inputQ31, &outputQ31, BLOCK_SIZE);

	DAC_SetValue((uint16_t)outputQ31);

}
