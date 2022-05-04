/*
 ============================================================================
 Name        : Ejercicio105.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void) {
	float cantidad, precio;
	float *pc, *pp;
	pc = &cantidad;
	pp = &precio;
	printf("Ingrese la cantidad de kg que desea: \n");
	scanf("%f",&cantidad);
	printf("Ingrese el precio por kg del producto \n");
	scanf("%f",&precio);
	float precioTotal = *pc * *pp;
	if (precioTotal > 99.99){
		precioTotal = precioTotal * 0.9;
		printf("Aplicando descuento...\n");
	}
	printf("El precio a pagar es de: %f",precioTotal);


	return EXIT_SUCCESS;
}
