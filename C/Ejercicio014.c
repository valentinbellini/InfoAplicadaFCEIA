

#include <stdio.h>
#include <stdlib.h>

// El operador ^ (XOR) aplica a los bits homólogos de sus operandos
// la tabla de conjunción lógica excluyente,
// caracterizada porque el resultado es 1 cuando solo uno de
// los bits bits es 1; en todos los demás casos el resultado es 0.
int XorSwap (int *n1,int *n2){
	if (n1 != n2){
		*n1 ^= *n2 ; *n2 ^= *n1; *n1 ^= *n2;
	}
	return 0;
}
int main(void) {
	int x = 3;
	int y = 5;
	XorSwap(x,y);
	printf("Valor de X: %d, Valor de Y: %d",x,y);
	return EXIT_SUCCESS;
}
