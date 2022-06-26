/*Si se importara otro .h que tiene la funcion
  Menu_inicio() se sobreescribirian si no tiene
  El Controlador::Menu_inicio(sim);*/


/////////////    ARCHIVO DE CABECERA    //////////////////////////
#include "Controlador.h"										//
//////////////////////////////////////////////////////////////////


///////////////   PROGRAMA PRINCIPAL   ///////////////////////////
int main() {													//
	int sim = 0;												//
																//
		while(1) {												//
			sim++;												//
			Controlador driver;									//
			driver.Controlador::Menu_Inicio(sim);				//
																//
			if(driver.Controlador::Get_Opcion() == 1) {			//
				driver.Controlador::Set_Valores();				//
				driver.Controlador::Logica();					//
				driver.Controlador::Mostrar(sim);				//
			}													//
			else break;											//
		}														//
																//
	return 0;													//
}																//
//////////////////////////////////////////////////////////////////
