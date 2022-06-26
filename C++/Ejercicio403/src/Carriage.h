
#ifndef CARRIAGE_H_
#define CARRIAGE_H_

class Carriage {
private:
	bool asientos [40];
	bool clase_tren; // 1 primera ; 0 segunda
	double precio;
public:
	Carriage(bool clase);
	bool getAsiento(int); //Para ver si un asiento está ocupado pasamos indice
	void setAsiento(int);  //Setear el estado del asiento pasamos indice
	void ocuparAsientos(); // Función genérica
	int contarAsientos();
	double obtenerPrecio();
	virtual ~Carriage();
};

#endif /* CARRIAGE_H_ */
