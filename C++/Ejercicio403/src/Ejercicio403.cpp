
#include <iostream>
using namespace std;
#include "Carriage.h"



int main() {
	srand(time(NULL));

	Carriage vagon (false); // 1 primera, 0 segunda
	Carriage vagon2 (true);

	vagon.ocuparAsientos();
	cout << "Vagón 1: \n";
	for(int j = 0; j < 40; j++){
		cout << "[" << vagon.getAsiento(j) << "] ";
		if(j == 9 || j == 19 || j == 29){
			cout << "\n";
		}
	}
	vagon2.ocuparAsientos();
	cout << "\n\nVagón 2: \n";
	for(int j = 0; j < 40; j++){
		cout << "[" << vagon2.getAsiento(j) << "] ";
		if(j == 9 || j == 19 || j == 29){
			cout << "\n";
		}
	}

	bool consulta_lugar = vagon.getAsiento(3);
	cout << "\n\nEl asiento consutlado (3) del vagón 1 se encuentra: " << consulta_lugar <<"\n\n";

	vagon.setAsiento(0);
	vagon.setAsiento(1);
	vagon.setAsiento(2);
	cout << "Reservando asientos 1, 2 y 3. del vagón 1... \n\n";

	cout << "Actualización vagón 1: \n";
	for(int j = 0; j < 40; j++){
		cout << "[" << vagon.getAsiento(j) << "] ";
		if(j == 9 || j == 19 || j == 29){
			cout << "\n";
		}
	}

	vagon2.setAsiento(15);
	cout << "\n\nReservando asiento 15 del vagon 2...\n\n";

	cout << "Actualización vagón 2: \n";
	for(int j = 0; j < 40; j++){
		cout << "[" << vagon2.getAsiento(j) << "] ";
		if(j == 9 || j == 19 || j == 29){
			cout << "\n";
		}
	}

	int cant_ocupados = vagon.contarAsientos();
	int cant_ocupados2 = vagon2.contarAsientos();

	cout << "\n\nAsientos ocupados en vagon 1: " << cant_ocupados;
	cout << "\nAsientos ocupados en vagon 2: " << cant_ocupados2;
	cout << "\n\nTotal en tikets vendidos en vagon 1: $" << cant_ocupados*vagon.obtenerPrecio();
	cout << "\nTotal en tikets vendidos en vagon 2: $" << cant_ocupados2*vagon2.obtenerPrecio();
	cout << "\n\nTOTAL VENDIDO EN TREN: $" << cant_ocupados*vagon.obtenerPrecio() + cant_ocupados2*vagon2.obtenerPrecio();
	return 0;
}
