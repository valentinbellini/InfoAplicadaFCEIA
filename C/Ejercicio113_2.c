/*
 ============================================================================
 Name        : Ejercicio113_2.c
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
	char *client_code = "192.168.1.1";
		//printf("Ingrese su código de cliente: ");
		//scanf("%s",client_code);
		printf("El código del cliente es: [%s]\n",client_code);
		int longitud = strlen(client_code);
		printf("La longitud de la cadena es: %d\n",longitud);

		int i, est;
		char *p,*a;
		p = strrchr (client_code,'.');
		a = strrchr (client_code,'@');

		if (p != NULL && a == NULL){
		printf("El codigo de cliente ingresado es de tipo IP");
//		printf("El caracter fue encontrado en la posicion %d\n",p-client_code+1);
//		printf ("Last occurrence of character in [%s] is [%s]",client_code, p);
		}
		if (p != NULL && a != NULL){
			printf("El codigo de cliente ingresado es de tipo MAIL");
		}
		else if (p == NULL && a == NULL){
			printf("El codigo de cliente ignresado es de tipo TARJETA");
		}

	return EXIT_SUCCESS;
}
