/*
 ============================================================================
 Name        : Ejercicio201.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tiempo {
		int anio, mes, dia, hora, minuto, segundo;
	}Tiempo;

typedef struct {
	char * nombre;
	Tiempo ultima_mod;
} Archivo;

Tiempo t1 = {2019,8,25,15,30,0};
Tiempo t2 = {2022,4,12,21,55,1};
Tiempo t3 = {2016,1,2,8,24,20};


int compara_tiempos (Tiempo* t1, Tiempo* t2){
	int actual = 0;
	(t1->anio > t2->anio) ? (actual = 1) : (actual = 2);
	if (t1->anio == t2->anio){
		(t1->mes > t2->mes) ? (actual = 1) : (actual = 2);
		if (t1->mes == t2->mes){
			(t1->dia > t2->dia) ? (actual = 1) : (actual = 2);
			if(t1->dia == t2->dia){
				(t1->hora > t2->hora) ? (actual = 1) : (actual = 2);
			}
		}
	}
	printf("El tiempo t%d es más actual\n",actual);
	return actual;
}
void imprime_tiempo (Tiempo t1){
	printf("La fecha de t1 es: %d/%d/%d %d:%d:%0.2d\n\n",t1.dia,t1.mes,t1.anio,t1.hora,t1.minuto,t1.segundo);
}
void ordena_alpha(Archivo * lista, int n){
	int i, j;
	Archivo temp;
	for (i = 0; i < (n-1); i++){
		for (j = i+1; j < n; j++){
			if(strcmp(lista[i].nombre,(lista+j)->nombre) > 0){
				temp = lista[i];
				lista[i] = lista[j];
				lista[j] = temp;
			}
		}
	}
}

int main(void) {

	compara_tiempos(&t1,&t2);
	imprime_tiempo(t1);
	Archivo lista[] = {{"Archivo2",t1},{"Archivo3",t2},{"Archivo1",t3}};
	int cant = sizeof(lista)/sizeof(lista[0]);
	for(int i = 0; i < cant; i++){
		printf("%s \n", lista[i].nombre);
	}
	printf("\nAhora utilizando el ordenamiento por nombre: \n");
	ordena_alpha(lista,cant);
	for(int i = 0; i < cant; i++){
		printf("%s -- %.2d / %.2d / %.2d\n",(lista+i)->nombre,lista[i].ultima_mod.anio,lista[i].ultima_mod.mes,lista[i].ultima_mod.dia);
	}
	return EXIT_SUCCESS;
}

