

//////////////////    DEFINICION    //////////////////
#ifndef CONTROLADOR_H_								//
#define CONTROLADOR_H_								//
//////////////////////////////////////////////////////


///////////////////    LIBRERIA     //////////////////
#include <string>									//
//////////////////////////////////////////////////////


/////////////////     ESTRUCTURA     /////////////////
typedef struct{										//
	int opcion;										//
	int n_eventos;									//
}Datos_inicio;										//
//////////////////////////////////////////////////////


///////////////////     CLASE     ////////////////////
class Controlador{									//
													//
private:											//
	bool *X_llenado;								//
	bool *Y_tapado;									//
	bool *SAL_A;									//
	bool *SAL_B;									//
	bool *SAL_C;									//
	std::string *accion;							//
	std::string *evento;							//
	Datos_inicio inicio;							//
													//
public:												//
	Controlador() {};								//
	void Menu_Inicio(int);							//
	int  Get_Opcion() {return inicio.opcion;}		//
	void Set_Valores();								//
	void Logica();									//
	void Mostrar(int);								//
	virtual ~Controlador();							//
};													//
//////////////////////////////////////////////////////


#endif /* CONTROLADOR_H_ */
