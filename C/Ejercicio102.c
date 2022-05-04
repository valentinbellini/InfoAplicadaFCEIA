/*
 ============================================================================
 Name        : Ejercicio102.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i = 5, j[]={1,2,3,4,5};
	char x = 'a', pal [] ="texto en c";
	int *pi;
	char *pc;

	printf("La dirección de i es: %p y su valor es: %d \n",&i,i);
	pi = &i;
	printf("La dirección de i es: %p y su valor es: %d \n",pi,*pi);
	printf("\n");
	int k;
	for (k = 0; k < 5; k++){
		printf("El elemento %d del vector j tiene la dirección %p y el valor %d\n",k+1,&j[k],j[k]);
		int *pj;
		pj = j;
		printf("El elemento %d del vector j tiene la dirección %p y el valor %d\n",k+1,pj+k,*(pj+k));
		printf("\n");
	}
	printf("\n");
	printf("El valor del caracter x es: %c y su lugar en memoria es: %p\n",x,&x);
	pc = &x;
	printf("El valor del caracter x es: %c y su lugar en memoria es: %p\n",*pc,pc);
	return EXIT_SUCCESS;
}
