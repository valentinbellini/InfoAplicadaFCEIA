/*
 * Ejercicio009.c
 *
 *  Created on: 25 mar. 2022
 *      Author: valentin
 */


#include <stdio.h>
#include <stdlib.h>

#define BitSet(a,b)   ( (a) |= (1 << (b) ) )
#define BItClear(a,b) ( (a) &= ~(1 << (b) ) )
#define BitCheck(a,b) ( (a) &  (1 << (b) ) )
#define BitToggle(a,b)( (a) ^= (1 << (b) ) )

void print_binary(int number){
	if(number){
		print_binary(number >> 1);
		putc((number & 1) ? '1':'0', stdout);
	}
}
int main(void) {
//	char buffer[33];
//	unsigned int entrada = 89321,
//			salido = 0,
//			pin = 0;
//
//	//STEAR PUN DE SALIDA
//	pin = 4;
//	BitSet(salida,pin);
//
//	pin = 2;
//	BitSet(salida,pin);
//
//	printf("El pin %d de la entrada esta en: %s \n", pin, ((BitCheck(entrada,pin)) ));

	print_binary(25);


	return EXIT_SUCCESS;
}


