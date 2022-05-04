/*
 ============================================================================
 Name        : Ejercicio002.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define CANT_NUMS 3

int main(void) {

	int valor = 0;
	int i = 0;
	int leidos[CANT_NUMS];

	while (1){
		printf ("Ingrese un numero entero o cero para finalizar: ");
		scanf("%d",&valor);

		if (valor == 0){
			printf("Fin");
			break;
		} else {
			for(i = 0; i < CANT_NUMS; i++){
				if (leidos[i] == valor)
				printf("El valor %d está en la posición %d de los valores ingresados.\n",valor,i);
				i++;
			}
		}
	}

	return EXIT_SUCCESS;
}
