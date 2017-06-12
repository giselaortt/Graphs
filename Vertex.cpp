#include <math.h>
#include "Vertex.h"
#include <stdio.h>

Vertex::Vertex( double a, double b, int i, int c ){
	this->x = a;
	this->y = b;
	this->index = i;
	this->color = c;
}

Vertex::~Vertex(){}

double Vertex::getx(){
	return this->x;
}

double Vertex::gety(){
	return this->y;
}

double Vertex::getDistance( Vertex* dois ){
	return sqrt( (this->x - dois->x)*(this->x - dois->x) + (this->y - dois->y)*(this->y - dois->y) );
}

int Vertex::getIndex(){
	return this->index;
}

int Vertex::getColor(){
	return this->color;
}

void Vertex::setColor( int color ){
	this->color = color;
}

void Vertex::print(){
	printf("%f\t%f i = %d", this->x, this->y, this->index );
}

Vertex* Vertex::copy(){
	Vertex* v = new Vertex( this->x, this->y, this->index );
	return v;	
}
