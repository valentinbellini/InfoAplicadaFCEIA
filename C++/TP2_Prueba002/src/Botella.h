/*
 * Botella.h
 *
 *  Created on: 16 jun. 2022
 *      Author: valentin
 */

#ifndef BOTELLA_H_
#define BOTELLA_H_

typedef struct entradas{
	bool X = 0;
	bool Y = 0;
}entradas;

class Botella {
private:
	bool llenado;
	bool tapado;

public:
	Botella():llenado(false),tapado(false){}
	virtual ~Botella();
	bool getTapado(int); //Responde si una botella esta tapada o no
	bool getllenado(int); //REsponde si una botella esta llena o no
	void logica(entradas[],int);

};

#endif /* BOTELLA_H_ */
