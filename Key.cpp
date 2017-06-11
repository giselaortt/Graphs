#include <stdio.h>

#include "Key.h"
#include "Vertex.h"

int Key::getValue(){
	return this->value;
}
void Key::setValue( int value ){
	this->value = value;
}
bool Key::operator < ( Key* b )  {
	if(this->value < b->value ) return true;
	return false;
}
void Key::print(){
	printf("%d ", this->value );
}

int Key::getIndex(){
	return this->index;
}
