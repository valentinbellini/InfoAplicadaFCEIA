/*
 ============================================================================
 Name        : Ejercicio206.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	unsigned char R, G, B;
}RGB;

typedef struct{
	int alto, ancho;
	RGB **pixel;
}ImagenRGB;

typedef unsigned char Gris;

typedef struct{
	int alto, ancho;
	Gris **pixel;
}ImagenGris;

ImagenRGB *creaImagenRGB( int ancho, int alto ){
	ImagenRGB *IMG1;//3 malloc
	int i;
	IMG1 = (ImagenRGB*)malloc(sizeof(ImagenRGB));
	IMG1->ancho = ancho;
	IMG1->alto = alto;
	IMG1->pixel=(RGB**)malloc(alto*sizeof(RGB*));
	for(i=0;i<alto;i++)
	IMG1->pixel[i]=(RGB*)malloc(ancho*sizeof(RGB));
	return IMG1;//nunca retornar puntero a var.local
	/*ahora tengo una matriz de pixeles RGB*/
}


int main(void) {
	ImagenRGB *IMG1 = creaImagenRGB(5,5);



	return EXIT_SUCCESS;
}
