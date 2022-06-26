#include "Avion.h"
#include <string.h>
#include <iostream>
using std::cout;

Avion::Avion(char* nv, char* d){
	nombrevuelo=new char[strlen(nv)+1];
	strcpy_s(nombrevuelo, strlen(nv)+1,nv);
	destino=new char[strlen(d)+1];
	strcpy_s(destino, strlen(d)+1,d);
}
char* Avion::getDestino(void){ return destino; }
char* Avion::getNombreVuelo(void){ return nombrevuelo;}
void Avion::setDestino(char* d){
	delete [] destino;
	destino=new char[strlen(d)+1];
	strcpy_s(destino, strlen(d)+1,d);
}
void Avion::setNombreVuelo(char* nv)
{
	delete [] nombrevuelo;
	nombrevuelo=new char[strlen(nv)+1];
	strcpy_s(nombrevuelo, strlen(nv)+1,nv);
}
void Avion::mostrarDatos(void){cout<<"El vuelo se llama: "<<nombrevuelo<<" y tiene destino: "<<destino<<"\n";}
Avion::~Avion(void){
}
