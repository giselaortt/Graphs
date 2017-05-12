#include "Key.h"

#ifndef NODE_H
#define NODE_H

class Node{
private:
	Node* left;
	Node* right;
	Node* dad;
	Key* key;
	int numOfKids;
	int descendents;

public:
	Node( Key* key ){
		this->left = NULL;
		this->right = NULL;
		this->key = key;
		this->dad = NULL;
		this->numOfKids = 0;
		this->descendents = 0;
	}
	void swapKey( Node* first );

	int getDescendents();

	void addDescendent();

	void subDescendent();
	
//	Not working
//	bool operator > ( Node* n ) const;

	Node* getLeft();

	Node* getDad();

	Node* getRight();

	int getNumOfKids();

	void setLeft( Node* n );

	void setRight( Node* n );

	void setDad( Node* d );

	Key* getKey( ) ;

	void setKey( Key* mykey );

};

#endif
