
using namespace std;
#include <stdlib.h>
#include "Carriage.h"
#include <time.h>
#include <iostream>

Carriage::Carriage(bool clase) {
	clase_tren = clase;
	for(int i = 0; i < 40; i++) asientos[i] = false;
	clase ? precio = 1840 : precio = 970;
}
void Carriage::ocuparAsientos(){
	double prob = clase_tren ? 0.1 : 0.4;
	for(int i = 0; i < 40; i++){
		asientos[i] = ((double)rand() / RAND_MAX < prob);
	}
}
bool Carriage::getAsiento(int lugar){return asientos[lugar];}
void Carriage::setAsiento(int lugar){asientos[lugar] = true;}
int Carriage::contarAsientos(){
	int count = 0;
	for(int i = 0; i < 40; i++){
		if (asientos[i]) count+=1;
	}
	return count;
}
double Carriage::obtenerPrecio(){return precio;}
Carriage::~Carriage() {
}

