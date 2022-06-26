
using namespace std;
#include <math.h>
#include "Point3D.h"

Point3D::Point3D(){
	x = 0;
	y = 0;
	z = 0;
}
Point3D::Point3D(int x0, int y0, int z0){
	x = x0;
	y = y0;
	z = z0;
}

Point3D::Point3D(int low, int high){
	x = low + ((double)rand() / RAND_MAX * (high-low));
	y = low + (rand()/RAND_MAX)*(high-low);
	z = low + (rand()*1.0 / RAND_MAX * (high-low));
}

int Point3D::getX() const{return x;}
int Point3D::getY() const{return y;}
int Point3D::getZ() const{return z;}

void Point3D::setX(int x1){x = x1;}
void Point3D::setY(int y1){x = y1;}
void Point3D::setZ(int z1){x = z1;}

void Point3D::shiftX(int x1){x += x1;}

bool Point3D::equals(Point3D q){
	return (x == q.x && this->y == q.y && z == q.z);
}

double Point3D::distanceOrigin(){
	double distance = x*x+y*y+z*z;
	return distance;

}

Point3D::~Point3D() {
	// TODO Auto-generated destructor stub
}

