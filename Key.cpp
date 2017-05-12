#include <stdio.h>

#include "Key.h"

int Key::getValue(){
	return this->value;
}
void Key::setValue( int value ){
	this->value = value;
}
bool Key::operator < ( Key b )  {
	if(this->value < b.value ) return true;
	return false;
}
void Key::print(){
	printf("%d ", this->value );
}
