#include <bits/stdc++.h>
#include "Node.h"
#include "Key.h"

// vai sempre ordenar por ordem crescente
class Heap{
private:
	Node* root;
	int size;

public:
	Heap( ){
		this->root = NULL;
		this->size = 0;
	}

	static int getHeight( int x ){
		return floor( log2( (double)(x+1) ) );
	}

	int getSize();

	void dump();

	void push( Key* k );

	void push( Node* novo );

	Node* insert( Node* novo, Node* current );

	Node* getRoot();

	void dumpin( Node* no );

	Key* pop();

	Key* top();

	void clear( Node* mynode );

	void clear( );

	void fixUp( Node* mynode );

	void fixDown( Node* mynode );

	Node* findLast( Node* mynode );

	Node* findLast( );
};


