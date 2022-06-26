
#ifndef POINT3D_H_
#define POINT3D_H_

class Point3D {
private:
	int x,y,z;
public:
	Point3D();
	Point3D(int x0,int y0, int z0);
	Point3D(int low, int high);
	int getX() const; //obtener X
	int getY() const; //obtener Y
	int getZ() const; //obtener Z
	void setX(int x);
	void setY(int y);
	void setZ(int z);

	void shiftX(int x1);
	bool equals(Point3D q);
	bool equals(int x1, int y1, int z1);

	double distanceOrigin();
	virtual ~Point3D();
};

#endif /* POINT3D_H_ */
