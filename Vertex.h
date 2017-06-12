#ifndef _VERTEX_H
#define _VERTEX_H

#include <math.h>

class Vertex{
private:
	double x;
	double y;
	int index;
	int color;
public:
	Vertex( double a, double b, int i = 0, int c = 0 );

	~Vertex();

	int getColor();

	void setColor( int color );

	double getx();

	double gety();

	double getDistance( Vertex* dois );

	int getIndex();

	void print();

	Vertex* copy();
};

#endif
