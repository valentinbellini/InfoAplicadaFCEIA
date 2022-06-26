/*
 * Botella.cpp
 *
 *  Created on: 16 jun. 2022
 *      Author: valentin
 */

#include "Botella.h"
using namespace std;
#include <stdlib.h>
#include <time.h>
#include <iostream>

bool Botella::getTapado(int numero){return llenado;}
bool Botella::getllenado(int numero){return tapado;}

void Botella::logica(entradas vector[],int cant_eventos){
	bool A = 0, B = 0, C = 0;
	Botella botellas[cant_eventos];

	for(int i = 0; i < cant_eventos; i++){

		if (vector[i].X = vector[i].Y = false){
			C = 1; //Movemos la cinta transportadora
			A = B = 0;

		}
		vector[i].X ? botellas[i].llenado = true : false;
		vector[i].Y ? botellas[i+1].tapado = true: false;

	}


}


Botella::~Botella() {
}

