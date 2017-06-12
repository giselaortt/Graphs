#include <stdio.h>
#include <iostream>
#include "Vertex.h"
#include "Edge.h"

using namespace std;

Edge::Edge( double value, Vertex* f, Vertex* s ){
	this->value = value;
	this->first = f;
	this->second = s;
}

Edge::Edge( Vertex* f, Vertex* s ){
	this->first = f;
	this->second = s;
	this->value = f->getDistance( s );
}

Edge::~Edge(){}

bool Edge::compare( Edge* one, Edge* two ){
	if( one->getValue() < two->getValue() )
		return true;
	return false;
}

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
