#include <stdio.h>
#include <iostream>
#include "Edge.h"

using namespace std;

/*
static bool Edge::compare( Edge* one, Edge* two ){
	if(  one->getValue() < two->getValue() )
		return true;
	return false;
}
*/
void Edge::print(){
	this->first->print();
	cout << "--->";
	this->second->print();
	cout << "w = " << this->value;
	cout << endl;
}

double Edge::getValue(){
	return this->value;
}

Edge* Edge::copy(){
	Edge* e = new Edge( this->value, this->first, this->second );
	return e;
}

int Edge::getIndex(){
	return this->getFirst()->getIndex();
}

void Edge::setValue( double value ){
	this->value = value;
}
/*
bool Edge::&operator < ( const Edge& b ) const {
	if(this->value < b.value ) return true;
	return false;
}
*/
void Edge::setFirst( Vertex* f ){
	this->first = f;
}

void Edge::setSecond( Vertex* f ){
	this->second = f;
}

Vertex* Edge::getFirst(){
	return this->first;
}

Vertex* Edge::getSecond(){
	return this->second;
}
