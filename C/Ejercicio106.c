/*
 ============================================================================
 Name        : Ejercicio106.c
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
	char *text1 = " Sera Cierto ?? ";
	int largo = strlen(text1)+1;
	char *result = (char *) malloc (largo);
	printf("La cadena: ");
	puts(text1);
	printf("Se encuentra: %s\n",(strlen(text1)>1 ? "No vacia":"Vacia"));
	printf("El largo de la cadena es: %d\n",strlen(text1));
	strcpy(result,text1);
	printf("Copia: [ %s ]\n",result);

	return EXIT_SUCCESS;
}
