
#include <iostream>
#include "Point3D.h"
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));
	int a = 10, b = 8, c = 5;
	int min = 5, max = 95;
	Point3D p1; //invocamos al constructor sin argumentos
					// asignando 0 a los tres campos
	Point3D p2(a,b,c);
	Point3D p3(min,max);
	cout << "el punto p1 tiene x = " << p1.getX() << "; y = " << p1.getY() << "; z = " << p1.getZ() << "\n";
	cout << "el punto p2 tiene x = " << p2.getX() << "; y = " << p2.getY() << "; z = " << p2.getZ() << "\n";
	cout << "el punto p3 tiene x = " << p3.getX() << "; y = " << p3.getY() << "; z = " << p3.getZ() << "\n";
	p1.shiftX(59);
	cout << "Desplazando p1 en 59 unidades...\n";
	cout << "ahora el punto p1 tiene x = " << p1.getX() << "; y = " << p1.getY() << "; z = " << p1.getZ() << "\n";
	if(p1.equals(p3))
		cout << "p1 y p3 son iguales\n";
	else
		cout << "p1 y p3 son diferentes\n";

	p2.distanceOrigin();
	cout << "La distancia al origen de p2 es: " << p2.distanceOrigin() << "\n";

	return 0;
}
