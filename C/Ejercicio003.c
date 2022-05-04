/*
 ============================================================================
 Name        : Ejercicio003.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define CANT_DIAS 30
#define MAX_RAND 150
#define MIN_RAND 0

float promedio(int numeros[]){
		float suma = 0;
		for (int i = 0; i < CANT_DIAS; i++){
			suma += numeros[i];
		}
		printf("\nEl promedio de lluvia en mm es: %04.2f \n",suma/CANT_DIAS);
		return suma/CANT_DIAS;
}
int minimo(int numeros[]){
	int minimo = 1;
	for (int i = 0; i < CANT_DIAS; i++){
		if(numeros[i] < numeros[minimo]) minimo = i+1;
	}
	printf ("Minimo de lluvia en el dia: %d\n",minimo);
	return minimo;
}
int maximo(int numeros[]){
	int maximo = 1;
	for (int i = 0; i < CANT_DIAS; i++){
		if(numeros[i] > numeros[maximo]) maximo = i+1;
	}
	printf ("Maximo de lluvia en el dia: %d\n",maximo);
	return maximo;
}

int relleno_random(int lluvia_leida[CANT_DIAS]){
	for (int i = 0; i < CANT_DIAS; i++){
			//printf("Ingrese la cantidad de agua caida el dia %d: ",i+1);
			//scanf("%d", &valor_lluvia);
			int lluvia_random = rand();
			lluvia_random = lluvia_random / (pow(2,31)-1)*MAX_RAND;
			lluvia_leida[i] = lluvia_random;
			printf("%d - ",lluvia_leida[i]);
		}
}

int main(void) {
	srand(time(NULL));

	int lluvia_leida[CANT_DIAS];
//	int MODO_AUTO = 0;

	relleno_random(lluvia_leida);

	promedio(lluvia_leida);
	minimo(lluvia_leida);
	maximo(lluvia_leida);

return EXIT_SUCCESS;
}
