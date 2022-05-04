/*
 ============================================================================
 Name        : Ejercicio011.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

unsigned rightRot (unsigned x, int n){
	int i;
	for (i=0; i<n; i++){
		if((x & 1) == 0) x = x >> 1;
		else {
			x = x >> 1;
			x = x | 0x80;
		}
	}
	return x;
}

int main(void) {
	unsigned int x = 0xB7;
	unsigned int xx = rightRot(x,5);
	printf("success");
	return EXIT_SUCCESS;
}
