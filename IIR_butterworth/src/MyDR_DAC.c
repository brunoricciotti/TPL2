/*
 * DR_DAC.c
 *
 *  Created on: 29 de oct. de 2019
 *      Author: chor
 */

#include <MyDR_DAC.h>


void DAC_Init(void)
{
	//1.- Selecciono el clock del DAC como 25MHz:
	PCLKSEL0 &= ~(0x03<<22);
	//2.- Configuro los pines del DAC
	//DAC : P0[26]->PINSEL1: 20:21
	SetPINSEL(0,26,PINSEL_FUNC2);
	//Pongo una R de pull down en el pin:
	SetMODE(0,26,3);
	//3.- Configuro el DAC:

	//Si lo quiero configurar con double buffer:
	//DACCNTVAL = 0x000000FA; //CNTVAL = 125 => 25MHz/125 = 200kHz
	//DACCTRL = 0x00000006; 	//DBLBUF_ENA = 1, CNT_ENA = 1

	//Si lo quiero configurar sin double buffer:
	DACCTRL &= ~(0x03 << 1);
}

void DAC_SetValue (uint16_t value)
{
	DACR = ((value & 0x03FF)<<6) | (1<<16);
}
