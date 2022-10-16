#include "DR_myPINSEL.h"

void MySetPINSEL(uint8_t puerto, uint8_t pin, uint8_t modo){
	/* esta funcion configura para que voy a usar el pin elegido*/

	uint32_t * dir_pinsel = PINSEL;//PINSEL es la direccion inicial
	dir_pinsel = dir_pinsel + (2*puerto);
	/*cada posicion es de 32 bits y necesito 2 bits por cada uno de los
	 * 32 bits de cada puerto, por eso le sumo (2*puerto)*/

	if((puerto > 4) || (pin > 31) || (modo > 3)) return;

	if(pin > 15){//por comodidad

			dir_pinsel ++;//tengo que pasar al otro PINSEL
			pin-= 16;//para que no me pase de largo
		}
	switch(modo){

		case 0:
			*dir_pinsel &= ~(1<<(2*pin));
			*dir_pinsel &= ~(1<<(2*pin)+1);
			break;
		case 1:
			*dir_pinsel |= (1<<(2*pin));
			*dir_pinsel &= ~(1<<(2*pin)+1);
			break;
		case 2:
			*dir_pinsel &= ~(1<<(2*pin));
			*dir_pinsel |= (1<<(2*pin)+1);
				break;
		case 3:
			*dir_pinsel |= (1<<(2*pin));
			*dir_pinsel |= (1<<(2*pin)+1);
					break;
		}
}
