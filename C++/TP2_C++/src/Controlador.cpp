
////////////////////     LIBRERIAS    ////////////////////
#include "Controlador.h"								//
#include <iostream>	//cin y cout						//
#include <vector>										//
#include <stdlib.h>	// valor rand()						//
#include <time.h>										//
using namespace std;									//
//////////////////////////////////////////////////////////


//////////////    DEFINICIONES Y MACROS    ///////////////
#define EVENT_MAX 100									//
#define ANCHO_TEXTO -5									//
#define CONVERTIR(a) ( (a) ? "SI" : "NO" )				//
//////////////////////////////////////////////////////////


////////////////////     ARREGLOS     ////////////////////
vector<string>Acciones = {"Llenando",					//
						  "Tapando",					//
						  "Llenando y tapando",			//
						  "Cinta en movimiento",		//
						  "No se puede llenar",			//
						  "No se puede tapar"};			//
														//
vector<string>Eventos = {"Imposible",					//
		    			 "Relevante"};					//
//////////////////////////////////////////////////////////


/////////////////    FUNCIONES MIEMBRO    ////////////////
void Controlador::Menu_Inicio(int n) {					//
	int opcion;
	inicio.n_eventos = 0;
	if(n == 1) cout<<endl<<"-------------------- Bienvenido!! --------------------"<<endl<<endl;
	cout<<"Elige una de las siguientes opciones:"<<endl;
	cout<<"1 - Realizar una simulación."<<"\n";
	cout<<"2 - Salir del programa."<<endl<<endl;
	cout<<"Pulsa 1 para simular o 2 para salir del programa:  ";
	cin>>opcion;

	while((opcion != 1) && (opcion != 2)){
		cout<<"Debes ingresar el número de alguna de las opciones del menu:  ";
		cin>>opcion;
	}
	inicio.opcion = opcion;

	if(opcion == 1){
		cout<<"Ingresa la cantidad de eventos que deseas generar:  ";
		cin>>inicio.n_eventos;

		while((inicio.n_eventos <= 0) || (inicio.n_eventos > EVENT_MAX)){
			if(inicio.n_eventos <= 0){
				cout<<"Opción inválida. La cantidad de eventos a simular debe ser un número positivo:  ";
				cin>>inicio.n_eventos;
			}

			else{
				if(inicio.n_eventos > EVENT_MAX){
					cout<<"La cantidad de eventos ingresada es demasiado grande, por favor ingresa un valor menor a "<<EVENT_MAX<<":  ";
					cin>>inicio.n_eventos;
				}
			}
		}
		cout<<"Cantidad de eventos de la simulación: "<<inicio.n_eventos<<endl;
	}
	else cout<<"Fin del programa."<<endl;
}
														//
void Controlador::Set_Valores() {						//
	int i, n  = inicio.n_eventos;

	X_llenado = new bool[n];
	Y_tapado  = new bool[n];
	SAL_A 	  = new bool[n];
	SAL_B 	  = new bool[n];
	SAL_C 	  = new bool[n];
	accion 	  = new string[n];
	evento 	  = new string[n];

	srand(time(NULL));

	for(i = 0; i < n; i++){
		int valor_random_1 = rand() % 2;
		int valor_random_2 = rand() % 2;

		if(valor_random_1) X_llenado[i] = true;
		else X_llenado[i] = false;
		if(valor_random_2) Y_tapado[i] = true;
		else Y_tapado[i] = false;

		SAL_A[i] = false;
		SAL_B[i] = false;
		SAL_C[i] = false;
	}
}
														//
void Controlador::Logica() {							//
	int i,
		flag = 0,
		n = inicio.n_eventos;

	for(i = 0; i < n; i++){
		if(!i){	// En el primer evento...
			if(!Y_tapado[i]){	// Si no se quiere tapar
				if(X_llenado[i]){	// Si se quiere llenar
					// Se esta llenando.
					SAL_A[i] = true;
					SAL_B[i] = false;
					SAL_C[i] = false;
					accion[i].assign(Acciones[0]);
					evento[i].assign(Eventos[1]);
				}
				else{	// Si no se quiere llenar
					// Se esta moviendo la cinta.
					SAL_A[i] = false;
					SAL_B[i] = false;
					SAL_C[i] = true;
					accion[i].assign(Acciones[3]);
					evento[i].assign(Eventos[1]);
				}
			}
			else{	// Si se quiere tapar
				// No se puede tapar (Suceso imposible).
				SAL_A[i] = false;
				SAL_B[i] = false;
				SAL_C[i] = false;
				accion[i].assign(Acciones[5]);
				evento[i].assign(Eventos[0]);
			}
		}

		else{	// Después del primer evento...
			if(!Y_tapado[i] && !X_llenado[i]){ // Si no se quiere tapar ni llenar
				// Se mueve la cinta.
				SAL_A[i] = false;
				SAL_B[i] = false;
				SAL_C[i] = true;
				accion[i].assign(Acciones[3]);
				evento[i].assign(Eventos[1]);
				if(SAL_A[i-1]){	// Bandera para recordar si antes se estaba llenando
					flag = 1;
				}
			}

			else{
				if(!Y_tapado[i] && X_llenado[i]){	// Si se quiere llenar y no tapar
					if(!SAL_B[i-1] || (SAL_B[i-1] && SAL_A[i-1])){	// Si antes se estaba llenando y tapando o
																	// Si antes no se estaba tapando
						// Se esta llenando.
						// Se termino de tapar (2da condicion).
						SAL_A[i] = true;
						SAL_B[i] = false;
						SAL_C[i] = false;
						accion[i].assign(Acciones[0]);
						evento[i].assign(Eventos[1]);
					}

					else{
						if(SAL_B[i-1] && !SAL_A[i-1]){	// Si antes se estaba tapando y no llenando
							// No se puede llenar (suceso imposible).
							SAL_A[i] = SAL_A[i-1];
							SAL_B[i] = SAL_B[i-1];
							SAL_C[i] = false;
							accion[i].assign(Acciones[4]);
							evento[i].assign(Eventos[0]);
						}
					}
				}

				else{
					if(Y_tapado[i] && !X_llenado[i]){	// Si se quiere tapar y no llenar
						if(SAL_B[i-1]){	// Si antes se estaba tapando
							// Se esta tapando.
							SAL_A[i] = false;
							SAL_B[i] = true;
							SAL_C[i] = false;
							accion[i].assign(Acciones[1]);
							evento[i].assign(Eventos[1]);
						}

						else{	// Si antes no se estaba tapando
							// No se puede tapar(suceso imposible).
							SAL_A[i] = SAL_A[i-1];
							SAL_B[i] = SAL_B[i-1];
							SAL_C[i] = false;
							accion[i].assign(Acciones[5]);
							evento[i].assign(Eventos[0]);
							if(!SAL_A[i-1] && flag){ // Salvo que antes de moverse se estaba llenado
								// Se está tapando.
								SAL_B[i] = true;
								flag = false;
								accion[i].assign(Acciones[1]);
								evento[i].assign(Eventos[1]);
							}
						}
					}

					else{
						if(Y_tapado[i] && X_llenado[i]){	// Si se quiere llenar y tapar
							if(SAL_B[i-1] && SAL_A[i-1]){	// Si antes se estaba llenando y tapando
								// Se sigue llenando y tapando.
								flag = true;
								SAL_A[i] = true;
								SAL_B[i] = true;
								SAL_C[i] = false;
								accion[i].assign(Acciones[2]);
								evento[i].assign(Eventos[1]);
							}

							else{
								if(!SAL_A[i-1] && SAL_B[i-1]){ // Si antes se estaba tapando pero no llenando
									// No se puede llenar (suceso imposible).
									SAL_A[i] = SAL_A[i-1];
									SAL_B[i] = SAL_B[i-1];
									SAL_C[i] = false;
									accion[i].assign(Acciones[4]);
									evento[i].assign(Eventos[0]);
								}

								else{	// Si antes no se estaba tapando
									//No se puede tapar (suceso imposible).
									SAL_A[i] = SAL_A[i-1];
									SAL_B[i] = SAL_B[i-1];
									SAL_C[i] = false;
									accion[i].assign(Acciones[5]);
									evento[i].assign(Eventos[0]);
									if(!SAL_A[i-1] && flag){	// Salvo que antes de moverse se estaba llenado
										// Se esta llenando y tapando.
										SAL_A[i] = true;
										SAL_B[i] = true;
										flag = false;
										accion[i].assign(Acciones[2]);
										evento[i].assign(Eventos[1]);
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
														//
void Controlador::Mostrar(int sim){						//
	int i, n = inicio.n_eventos;
	cout<<endl;
	cout<<"//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"<<endl;
	cout<<"Resultados de la simulación:  "<<sim<<endl;
	cout<<"------------------------------------------------------------------------------------------------------------------------------"<<endl;
	printf(" CONTROL LLENAR | CONTROL TAPAR | LLENADO(A) | TAPADO(B) | CINTA(C) | Para el estado actual el evento |        Acción\n");
	cout<<"------------------------------------------------------------------------------------------------------------------------------"<<endl;
	for(i = 0; i < n; i++){
		printf("       %*s    |",ANCHO_TEXTO,CONVERTIR(X_llenado[i]));
		printf("       %*s   |",ANCHO_TEXTO,CONVERTIR(Y_tapado[i]));
		printf("     %*s  |",ANCHO_TEXTO,CONVERTIR(SAL_A[i]));
		printf("    %*s  |",ANCHO_TEXTO,CONVERTIR(SAL_B[i]));
		printf("    %*s |",ANCHO_TEXTO,CONVERTIR(SAL_C[i]));
		cout<<"	         "<<evento[i];
		cout<<"	      |  "<<accion[i];
		printf("\n");
	}
	cout<<"//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////"<<endl;
	cout<<endl;
}
														//
Controlador::~Controlador(){							//
	if(inicio.opcion == 1) {
		delete []X_llenado;
		delete []Y_tapado;
		delete []SAL_A;
		delete []SAL_B;
		delete []SAL_C;
		delete []accion;
		delete []evento;
		cout<<"Liberando memoria..."<<endl<<endl;
	}
}
//////////////////////////////////////////////////////////
