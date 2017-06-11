#ifndef KEY_H
#define KEY_H
 
#include "Vertex.h"

class Key{
	public:
	int value;
	Vertex* vert;
	Vertex* parent;

	Key( int value, Vertex* f, Vertex* s = NULL ){
		this->value = value;
		this->first = f;
		this->parent = s;
	}

	int getValue();
	void setValue( int value );
	Key* copyOf();
	bool operator < ( Key b ) ;
	void print();
};

#endif
