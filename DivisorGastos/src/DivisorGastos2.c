/*
 ============================================================================
 Name        : DivisorGastos.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
	int cantidad = 0;
	printf("Ingrese la cantidad de personas para dividir gastos: ");
	scanf("%d",&cantidad);

    typedef char cadenaCaracteres [50]; //Definimos el tipo cadenaCaracteres
    cadenaCaracteres personas[cantidad]; //Creamos un vector de cadenas
    int gastoPersonal [cantidad];
    int suma = 0;
    //USAR CALLOC
    float dif [cantidad];
    int estado [cantidad];

	for(int i=0;i<cantidad;i++){
		printf("Ingrese nombre %d: ",i+1);
		scanf("%s",personas[i]);
		printf("¿Cuánto gastó? ");
		scanf("%d", &gastoPersonal[i]);
		suma += gastoPersonal[i];
	}
	float eachOne = suma / cantidad;
	printf("\n");
	printf("La suma total gastada es de: %d\n",suma);
	printf("Cada persona debe poner: %f\n",eachOne);

	for (int i = 0; i < cantidad; i++){
		dif[i] = gastoPersonal[i] - eachOne; //NEgativo = debe
		printf("%s... tu saldo está en: %f\n",personas[i],dif[i]);
		if (dif[i] < 0) {
			estado[i] = 1; // 1 = deudor, 0 = acredor
		} else{
			estado[i] = 0;
		}
	}

	for (int i = 0; i < cantidad; i++){ //RECORRE A TODOS
			if (estado[i] == 1){ // Si la persona es deudora
				while (estado[i] == 1){ //Entonces mientras sea deudor
					for (int j = 0; j < cantidad; j++){ //Recorremos las personas
						if (estado[j] == 0){ //Y cuando encontramos un acredor
							// REALIZAR TRANSFERENCIA
							if (abs(dif[i]) <= abs(dif[j])){
								dif[j] = dif[j] - abs(dif[i]);
								printf("%s Debe darle %f pesos a %s\n",personas[i],personas[j],dif[i]);
								dif[i] = 0;
							}
						}
					}
					printf("Este deudor saldo las deudas\n");
					//estado[i] == 0;
					break;
				}
			}
		}
	for (int i = 0; i < cantidad; i++){
		printf("\n");
		printf("%s, tu saldo está en %f",personas[i],dif[i]);
	}


	//for(int i=0;i<cantidad;i++){
	//	printf("%d . Nombre: %s \n", i+1, arrayCadenas[i]);
	//}

system("PAUSE");
return 0;
}
