#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <stdlib.h>

class UnionFind{
private:
	int size;
	int* weights;
	int* parents;
	int groups;

public:
	UnionFind( int size ){
		this->weights = (int*)malloc(sizeof(int*)*size);
		this->parents = (int*)malloc(sizeof(int*)*size);
		this->size = size;
		for( int i=0; i<size; i++ ){
			this->weights[i] = 0;
			this->parents[i] = i;
		}
		this->groups = size;
	}

	int getGroups();

	int find( int index );

	bool merge( int i, int j );

	void clear();

};

#endif
