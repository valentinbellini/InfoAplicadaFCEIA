
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct TipoPunto{
	double abscisa;
	double ordenada;
};
struct TipoCiudad{
	struct TipoPunto situacion;
	char nombre[50];
};
double distanciaEuclidea (struct TipoPunto P1, struct TipoPunto P2){
	double M1 = (P1.abscisa-P2.abscisa)*(P1.abscisa-P2.abscisa);
	double M2 = (P1.ordenada-P2.ordenada)*(P1.ordenada-P2.ordenada);
//	double distancia = sqrt(M1+M2);
	double distancia = M1+M2;
		return distancia;
}
//
void Reordenar (struct TipoCiudad ciudades[],
				int num_ciudades,
				const char nombre_ciudad_referida[]){
	int i,j;
	struct TipoCiudad temp;
	printf("EL nombre de la ciudad referida es: %s\n",nombre_ciudad_referida);
	for(i = 0; i < num_ciudades; i++){
		if(strcmp(ciudades[i].nombre,nombre_ciudad_referida) == 0){
			printf("Se ha encontrado una coincidencia en %d: %s\n\n",i+1,ciudades[i].nombre);
			temp = ciudades[i];
		}
	}
	for(i=0;i<num_ciudades;i++){
		double distancia = distanciaEuclidea(temp.situacion,ciudades[i].situacion);
		int k = i;
			for(j=i+1;j<num_ciudades;j++){
				double distancia2 = distanciaEuclidea(temp.situacion,ciudades[j].situacion);
				if(distancia2 < distancia){
					distancia = distancia2;
					k = j;
				}//fin if
			}//fin for j

			struct TipoCiudad temporal = ciudades[i];
			ciudades[i] = ciudades[k];
			ciudades[k] = temporal;
		}
		for(i = 0; i < num_ciudades; i++){
			if(strcmp(ciudades[i].nombre,nombre_ciudad_referida)!=0){
			double dist = distanciaEuclidea(temp.situacion,ciudades[i].situacion);
			printf("Distancia a %s es: %f km\n",ciudades[i].nombre,dist);
			}
		}
}

int main(void) {
	struct TipoCiudad C1 = {3.0,2.0,"ROMA"};
	struct TipoCiudad C2 = {30,2.1,"PARIS"};
	struct TipoCiudad C3 = {0.0,0.0,"ARGENTINA"};
	struct TipoCiudad C4 = {8.9,0.3,"GRECIA"};
	struct TipoCiudad C5 = {2.89,8.84,"NEW YORK"};
	struct TipoCiudad C6 = {1.54,4.1,"MADRID"};
	struct TipoCiudad C7 = {-3,0,"TULUM"};
	struct TipoCiudad C8 = {-2.5,9.35,"TOKYO"};
	struct TipoCiudad ciudades[8] = {C1,C2,C3,C4,C5,C6,C7,C8};

	Reordenar(ciudades,8,"PARIS");

	return EXIT_SUCCESS;
}
