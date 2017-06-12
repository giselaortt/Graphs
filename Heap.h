#ifndef _HEAP_H
#define _HEAP_H

#include <stdlib.h>
#include "Node.h"
#include "Vertex.h"

class Heap{
private:
	Node* root;
	int size;

public:
	Heap( );

	~Heap();

	static int getHeight( int x );

	int getSize();
	
	void dump();
	
	void setRoot(Node *);
	
//	void swapNode2( Node* a, Node* b );

	void swapNode( Node* a, Node* b );

	void push( Node* novo );

	Node* insert( Node* novo, Node* current );

	Node* getRoot();

	void dumpin( Node* no );

	Node* pop();

	Node* top();

	void clear( Node* mynode );

	void clear( );

	void fixUp( Node* mynode );

	void fixDown( Node* mynode );

	Node* findLast( Node* mynode );

	Node* findLast( );

	void updateKeyValue( Node*, int );

	double getValue( int index );

	void updateParent( Node*, Vertex* );

	Node* getNode( int index );
};

#endif
