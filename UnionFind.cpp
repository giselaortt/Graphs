#include "UnionFind.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int UnionFind::find( int index ){
	if( index >= size )
		return -1;
	if( this->parents[index] != index ){
		this->parents[index] = this->find( this->parents[index] );
		return this->parents[index];
	}
	return index;
}

bool UnionFind::merge( int i, int j ){
	int a = find( i ), b = find(j);

	// if we have invalid arguments
	if( a == -1 || b == -1 ) return -1;
	if( a == b ) return false;
	if( this->weights[a] > this->weights[b] ) this->parents[b] = a;
	else if( this->weights[a] < this->weights[b] ) this->parents[a] = b;
	if( this->weights[a] == this->weights[b] ){
		this->parents[a] = b;
		this->weights[b]++;
	}
//	printf("%d\n", this->groups );
	this->groups = this->groups-1;
//	printf("%d\n", this->groups );
//	char c; scanf("%d", &c );
	return true;
}

int UnionFind::getGroups(){
	return this->groups;
}

void UnionFind::clear(){
	free( this->weights );
	free( this->parents );
}
