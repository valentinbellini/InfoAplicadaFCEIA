
#ifndef AVION_H_
#define AVION_H_

class Avion
{
public:
	Avion(char* nv, char* d);
	void mostrarDatos(void);
	char* getNombreVuelo(void);
	char* getDestino(void);
	void setDestino(char* d);
	void setNombreVuelo(char* nv);
	~Avion(void);
protected:
	char* nombrevuelo;
	char* destino;
};

#endif /* AVION_H_ */
