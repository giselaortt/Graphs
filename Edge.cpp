#include <stdio.h>
#include <iostream>
#include "Vertex.h"
#include "Edge.h"

using namespace std;

Edge::Edge( double value, int f, int s ){
	this->value = value;
	this->first = f;
	this->second = s;
}
/*
Edge::Edge( int f, int s ){
	this->first = f;
	this->second = s;
	this->value = f->getDistance( s );
}
*/
Edge::~Edge(){}

bool Edge::compare( Edge one, Edge two ){
	if( one.getValue() < two.getValue() )
		return true;
	return false;
}
/*
void Edge::print(){
	this->first->print();
	cout << "--->";
	this->second->print();
	cout << "w = " << this->value;
	cout << endl;
}
*/
double Edge::getValue(){
	return this->value;
}

Edge* Edge::copy(){
	Edge* e = new Edge( this->value, this->first, this->second );
	return e;
}
/*
int Edge::getIndex(){
	return this->getFirst()->getIndex();
}
*/
void Edge::setValue( double value ){
	this->value = value;
}

void Edge::setFirst( int f ){
	this->first = f;
}

void Edge::setSecond( int f ){
	this->second = f;
}

int Edge::getFirst(){
	return this->first;
}

int Edge::getSecond(){
	return this->second;
}
