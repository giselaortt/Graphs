#ifndef NODE_H
#define NODE_H

#include "Vertex.h"
#include <stdlib.h>

class Node{
private:
	Node* left;
	Node* right;
	Node* dad;
	int descendents;
	double keyvalue;
//	Vertex* key;
//	Vertex* parent;
	int key;
	int parent;

public:

	Node() {
		this->left = this->dad = this->right = NULL;
	}

	Node( int key, int parent, double weight ){
		this->left = NULL;
		this->right = NULL;
		this->key = key;
		this->dad = NULL;
		this->descendents = 0;
		this->keyvalue = weight;
		this->parent = parent;
	}
/*
	Node( int key, int parent, double weight ){
		this->left = NULL;
		this->right = NULL;
		this->key = key;
		this->dad = NULL;
		this->descendents = 0;
		this->keyvalue = weight;
		this->parent = parent;
	}
*/
	void swapKey( Node* first );

	int getDescendents();

	void addDescendent();

	void subDescendent();

	void setDescendents( int );
	
	Node* getLeft();

	Node* getDad();

	Node* getRight();

	void setLeft( Node* n );

	void setRight( Node* n );

	void setDad( Node* d );

//	Vertex* getKey( ) ;

	int getKey( ) ;

	void setKey( int  mykey );
	//void setKey( Vertex* mykey );

	//void setParent( Vertex* );
	void setParent( int );

//	Vertex* getParent();

	int getParent();

	void updateKeyValue( double newvalue );

	double getKeyValue();

	int getIndex();
};

#endif
