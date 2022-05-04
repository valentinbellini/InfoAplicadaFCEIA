/*
 * Ejercicio009.c
 *
 *  Created on: 25 mar. 2022
 *      Author: valentin
 */


#include <stdio.h>
#include <stdlib.h>

#define BitSet(a,b)   ( (a) |= (1 << (b) ) ) //pone a 1 el bit b del número a
#define BItClear(a,b) ( (a) &= ~(1 << (b) ) ) //pone a 0 el bit b del número a
#define BitCheck(a,b) ( (a) &  (1 << (b) ) ) //verifica si el bit b del número a es un 0 o un 1
#define BitToggle(a,b)( (a) ^= (1 << (b) ) ) //cambia el bit b del número a por su valor complementario

void print_binary(int number){
	if(number){
		print_binary(number >> 1);
		putc((number & 1) ? '1':'0', stdout);
	}
}
int main(void) {
	print_binary(3);

	char buffer[33];
	printf("%s\n",itoa(3,buffer,2));

	return EXIT_SUCCESS;
}

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

