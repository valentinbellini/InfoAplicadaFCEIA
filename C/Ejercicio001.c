/*
 ============================================================================
 Name        : Ejercicio001.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x = 10, y = 20, z = 30, aux;
	aux = z;
	z = y;
	y = x;
	x = aux;

	return EXIT_SUCCESS;
}
