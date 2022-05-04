/*
 ============================================================================
 Name        : Ejercicio205.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct matrix {
	short filas, col;
	int** matriz; //Puntero a arreglo de punteros que apuntan a enteros (filas)
}Matriz;

void allocate(Matriz *M1, short n, short m){
	int i;
	M1->filas = n;
	M1->col = m;
	M1->matriz = (int**) malloc(n*sizeof(int*));
	for (i = 0; i < M1->filas; i++){
		M1->matriz[i] = (int*) calloc(m,sizeof(int));
	}
}
void llenar_matriz (Matriz *M1){
	int n, m, value;
	for (n = 0; n < M1->filas; n++){
		for (m = 0; m < M1->col; m++){
			value = rand() %50 +10;
			M1->matriz[n][m] = value;
		}
	}
}
void imprimir (Matriz *M1){
	int i, j;
	printf("Matriz: \n");
	for (i = 0; i < M1->filas; i++){
		for (j = 0; j < M1->col; j++){
			printf("%d ",M1->matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void liberar(Matriz *M1){
	int n;
		for (n = 0; n < M1->filas; n++){
			free(M1->matriz[n]);
		}
		free(M1->matriz);
		free(M1);
}

int main(void) {
	srand(time(NULL));
	Matriz *M1 = (Matriz*)malloc(sizeof(Matriz));
	if(M1 == NULL){
		printf("Error. No se pudo reservar espacio para el puntero a matriz M1");
		return -1;
	}
	allocate(M1,3,3);
	llenar_matriz(M1);
	imprimir(M1);


	Matriz *M2 = (Matriz*)malloc(sizeof(Matriz));
	if(M2 == NULL){
			printf("Error. No se pudo reservar espacio para el puntero a matriz M2");
			return -2;
	}
	allocate(M2,3,3);
	llenar_matriz(M2);
	imprimir(M2);

	liberar(M2);
	liberar(M1);
	return EXIT_SUCCESS;
}
