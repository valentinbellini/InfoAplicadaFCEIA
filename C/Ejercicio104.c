/*
 ============================================================================
 Name        : Ejercicio104.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {

	typedef char string[10];
	string semana[7] = {"Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"};
	string *p;
	p = &semana;
	printf("Ingrese un numero entre 1 y 7: ");
	int numero;
	scanf("%d",&numero);
	while(numero < 1 || numero > 7){
		printf("Numero no valido, ingrese nuevamente: ");
		scanf("%d",&numero);
	}
	printf("%s",p+numero-1);



	return EXIT_SUCCESS;
}
