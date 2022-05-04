/*
 ============================================================================
 Name        : Ejercicio103.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	float vector[5];
	float *pv;
	pv = vector;
	printf("Ingrese 5 numeros reales\n");
	int i;
	for (i = 0; i < 5; i++){
		scanf("%f",pv+i);
	}
	printf("Mostramos el vector en orden inverso:\n");
	for (i = 0; i < 5; i++){
		printf("%f , ",*(pv+(4-i)));
	}


	return EXIT_SUCCESS;
}
