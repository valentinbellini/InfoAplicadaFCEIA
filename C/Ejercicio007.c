/*
 * Ejercicio007.c
 *
 *  Created on: 25 mar. 2022
 *      Author: valentin
 */
#include <stdio.h>
#include <stdlib.h>

#define TRUE 2
#ifdef TRUE
	#undef TRUE
	#define TRUE 1
//#else
//	#define TRUE 1
#endif

int main(void) {

	printf("Ingreso al programa");
	if (1 == TRUE){
		printf("La etiqueta fue redefinida exitosamente");
	}

return EXIT_SUCCESS;
}
