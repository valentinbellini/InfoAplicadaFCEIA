/*
 ============================================================================
 Name        : Ejercicio202.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct{
	int n;
	double *coeficiente;
}Polinomio;

Polinomio * creaPolinomio(int orden){
	Polinomio *p;
	p = (Polinomio*) malloc(sizeof(Polinomio));
	if (p == NULL){
		printf("error: malloc no pudo reservar memoria para el polinomio");
	}
	p->n = orden;
	p->coeficiente = (double*)calloc((orden+1),sizeof(double)); //Los seteo ya en 0 con calloc
	if (p->coeficiente == NULL){
		printf("error: calloc no pudo reservar memoria para los coeficientes");
	}
	return p;
}
void setCoef (int n, double c, Polinomio *P){
	if (n <= P->n){
		P->coeficiente[n] = c;
	}
	else{
		printf("error: El orden de coeficiente ingresado es mayor al grado del polinomio");
	}
}
void imprimir_Polinomio(Polinomio * P, int n){
	printf("Polinomio: ");
	for(int i = 0; i < n; i++){
		printf("%.2f x%d ",P->coeficiente[n-1-i],n-1-i);
		if(i < n-1){
			printf("+ ");
		}
	}
	printf("\n");
}
double especializa(double x, Polinomio * P){
	double suma = 0;
	int i;
	for (i = 0; i <= P->n; i++){
//		suma += P->coeficiente[i] * pow(x,i);
	}
	return suma;
}
void destruye_Polinomio(Polinomio *p){
	free(p->coeficiente);
	free(p);
}

int main(void) {
	Polinomio *p1 = creaPolinomio(3); //Devuelve un polinomio a una estructura tipo Polinomio del orden creado y coeficientes nulos
	setCoef(0,3,p1);
	setCoef(1,5.32,p1);
	setCoef(2,-10,p1);
	setCoef(3,3.45,p1);
	printf("Seteados los coeficientes, imprimimos el polinomio:\n");
	imprimir_Polinomio(p1,4);
	destruye_Polinomio(p1);
	printf("\nLiberamos el espacio en memoria del polinomio:\n");
	imprimir_Polinomio(p1,4);

	return EXIT_SUCCESS;
}
