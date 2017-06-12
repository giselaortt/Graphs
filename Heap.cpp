#include "Heap.h"
#include "Vertex.h"
#include "Node.h"
#include <stdlib.h>
#include <stdio.h>

using namespace std;

	Heap::Heap( ){
		this->root = NULL;
		this->size = 0;
	}

Heap::~Heap(){}

int Heap::getHeight( int x ){
	return floor( log2( (double)(x+1) ) );
}

int Heap::getSize(){
	return this->size;
}

Node* Heap::getRoot(){
	return this->root;
}

void Heap::clear( Node* mynode ){
	if( mynode == NULL ) return;
	if( mynode->getLeft() != NULL ) clear( mynode->getLeft() );
	if( mynode->getRight() != NULL ) clear( mynode->getRight() );
	delete( mynode );
	return;
}

void Heap::clear( ) {
	if( this->root == NULL ) return;
	clear( this->root );
	this->root = NULL;
	return;
}

void Heap::push( Node* novo ){
	this->size++;
	if( this->root == NULL )
		this->root = novo;
	else{
		Node* aux = insert( novo, this->root );
		Node* temp = aux->getDad();
		while(temp != NULL) {
			temp->addDescendent();
			temp = temp->getDad();
			
		}
		fixUp( aux );
	}
}

void Heap::setRoot(Node *crr) {
	this->root = crr;
}
/*
void Heap::swapNode(Node *a, Node *b) {
	if(a == NULL || b == NULL) return;
		
	Node *t = a->getDad();
	a->setDad(b->getDad());
	b->setDad(t);

	t = a->getRight();
	a->setRight(b->getRight());
	b->setRight(t);

	t = a->getLeft();
	a->setLeft(b->getLeft());
	b->setLeft(t);
	
	//if(a == this->getRoot()) this->setRoot(b);
		
//	a->swapKey(b);

}
*/	

/*
// please obey direction
void Heap::swapNode( Node* a, Node* b ){
	Node* temp; int aux;
	if( b->getDad() == a ){
		if( a->getRight() == b ) {
			temp = b->getRight();
			b->setRight( a );
			a->setRight( temp );
			if( temp != NULL ) temp->setDad( a );

			temp = a->getLeft();
			a->setLeft( b->getLeft() );
			b->setLeft( temp );

	/		if( temp != NULL ) temp->setDad( b );
			if( a->getLeft() != NULL ) a->getLeft()->setDad( a );

		} else {	
			printf("entrou\n");
			temp = b->getLeft();
			b->setLeft( a );
			a->setLeft( temp );
			if( temp != NULL ) temp->setDad( a );
			
			temp = a->getRight();
			a->setRight( b->getRight() );
			b->setRight( temp );
			if( temp != NULL ) temp->setDad( b );
			if( a->getRight() != NULL ) a->getRight()->setDad( a );

		}
		
		if( a->getDad() != NULL ){
			if( a->getDad()->getLeft() == a ) a->getDad()->setLeft( b );
			else a->getDad()->setRight( b );
		} else {
			this->root = b;
		}
		b->setDad( a->getDad() );
		a->setDad( b );
		aux = b->getDescendents();
		b->setDescendents( a->getDescendents() );
		a->setDescendents( aux );

	} else {

		temp = (a)->getDad();
		(a)->setDad( (b)->getDad() );
		(b)->setDad( temp );

		temp = (a)->getRight();
		(a)->setRight( (b)->getRight() );
		(b)->setRight( temp );

		temp = (a)->getLeft();
		(a)->setLeft( (b)->getLeft() );
		(b)->setLeft( temp );

		if( this->root == a ) this->root = (b);
		else if ( this->root == b ) this->root = (a);

		aux = (a)->getDescendents();
		(a)->setDescendents( (b)->getDescendents() );
		(b)->setDescendents( aux );

		if( a->getDad() != NULL ){
//			printf("io\n");
			if( (a)->getDad()->getLeft() == (a) ) (a)->getDad()->setLeft( b );
			else if( (a)->getDad()->getRight() == (a) ) (a)->getDad()->setRight( b );
		}

		if( (a)->getLeft() != NULL ) (a)->getLeft()->setDad( a );
		if( (a)->getRight() != NULL ) (a)->getRight()->setDad( a );

		if( b->getDad() != NULL ){
//			printf("oi\n");
			if( (b)->getDad()->getLeft() == (b) ) (b)->getDad()->setLeft( a );
			else if( (b)->getDad()->getRight() == (b) ) (b)->getDad()->setRight( a );
		}
		if( (b)->getRight() != NULL ) (b)->getRight()->setDad( b );
		if( (b)->getLeft() != NULL ) (b)->getLeft()->setDad( b );
	}
}
*/

void Heap::swapNode( Node* a, Node* b ){
	(a)->swapKey( (b) );
/*	Node** temp = a;
	a = b;
	b = temp;
*/
}
/*
void Heap::fixUp( Node* no ){
	if( no == NULL || no->getDad() == NULL || no == this->root ) return;
	if( no->getDad() == NULL ) printf("noo");
	Node* aux = no->getDad();
	char c;
	if( no->getKeyValue() < aux->getKeyValue() ){
		this->swapNode( aux, no );
		aux = no;
	}
	return fixUp( aux );
}
*/


void Heap::fixUp( Node* no ){
	if( no == NULL ) return;
	Node* aux;
	if( no->getDad() !=  NULL && no->getKeyValue() < no->getDad()->getKeyValue() ){
		aux = (no->getDad());
		this->swapNode( no, aux );
	}
	return fixUp( no->getDad() );
}

Node* Heap::insert( Node* novo, Node* curr ){
	if( novo == NULL || curr == NULL) return NULL;

	if( curr->getLeft() == NULL ) {
		curr->setLeft( novo );
		novo->setDad( curr );
		return curr->getLeft();
	}

	if(curr->getRight() == NULL) {
		curr->setRight( novo );
		novo->setDad( curr );
		return curr->getRight();
	}

	if( ( 1 << (getHeight( curr->getDescendents()) +1) ) - 2 > curr->getDescendents() &&
	curr->getDescendents() >= ( 1 << (getHeight( curr->getDescendents()) +1) ) - 2 - (1 << (getHeight( curr->getDescendents()) -1) ) ) 
		return insert(novo, curr->getRight());

	return insert( novo, curr->getLeft() );
}

Node* Heap::findLast( Node* mynode ){
	if( mynode == NULL ) return NULL;
	if( mynode->getLeft() == NULL ) return mynode;
	if( mynode->getRight() == NULL ) return ( mynode->getLeft() );
	int h = getHeight( mynode->getDescendents() );
	if((1 << h+1) -2 -(1<<(h-1)) < mynode->getDescendents() && mynode->getDescendents() <= (1 << h+1) -2 )
		return findLast( mynode->getRight() );
	else 
		return findLast( mynode->getLeft() );
}

Node* Heap::findLast( ){
	return findLast( this->root );
}

Node* Heap::top(){
	return this->root;
}
/*
Node* Heap::pop(){
	if( this->root == NULL ) return NULL;

	if( this->size == 1 ){
		Node* aux = this->root;
		this->root = NULL;
		this->size = 0;
		return aux;
	}

	this->size--;
	Node* a = this->findLast();
	Node* b = this->root;

	printf("%.2f\n %.2f\n %.2f\n", this->root->getKeyValue(), this->root->getLeft()->getKeyValue(), this->root->getRight()->getKeyValue());
	this->swapNode( b, a );
	printf("%.2f\n %.2f\n %.2f\n", this->root->getKeyValue(), this->root->getLeft()->getKeyValue(), this->root->getRight()->getKeyValue());
	Node* d = b->getDad();
	
	
	if( b->getDad()->getLeft() == b )
		 b->getDad()->setLeft( NULL );
	else {
		 b->getDad()->setRight( NULL );
	}
	do { 
		d->subDescendent();
		d = d->getDad();
	} while( d != NULL );


	//fixDown( this->root );

	printf("saiu");
	return b;
}
*/

Node* Heap::pop(){
	if( this->root == NULL ) return NULL;

	if( this->size == 1 ){
		Node* aux = this->root;
		this->root = NULL;
		this->size = 0;
		return aux;
	}

	this->size--;
	Node* a = this->findLast();
	Node* b = this->root;
	this->swapNode( a, b );

	Node* d = a->getDad();
	if( a->getDad()->getLeft() == a )
		 a->getDad()->setLeft( NULL );
	else
		 a->getDad()->setRight( NULL );

	while( d != NULL ){
		d->subDescendent();
		d = d->getDad();
	}

	fixDown( this->root );
	return a;
}

void Heap::dumpin( Node* no ){
        if( no == NULL ) return;
        dumpin( no->getLeft() );
        if( no->getLeft() == NULL ) printf("NULL ");
        else printf("%f ",  no->getLeft()->getKeyValue() );
        if( no->getRight() == NULL ) printf("NULL ");
        else printf("%f ", no->getRight()->getKeyValue() );
        if( no->getDad() == NULL ) printf("dad = NULL ");
        else printf("dad = %f ", no->getDad()->getKeyValue() );
        printf(" descendents = %d value =  %f\n", no->getDescendents(), no->getKeyValue() );
        dumpin( no->getRight() );
}
/*
void Heap::fixDown( Node* mynode ){
	if( mynode == NULL || mynode->getLeft() == NULL ) return;
	Node* aux;
	if( mynode->getRight() == NULL ) aux = mynode->getLeft();

	else{
		if( mynode->getLeft()->getKeyValue() < mynode->getRight()->getKeyValue() )
			aux = mynode->getLeft();
		else
			aux = mynode->getRight();
	}
	printf("%.2f\n", mynode->getKeyValue());
	if(aux->getKeyValue() < mynode->getKeyValue()){
		this->swapNode( mynode, aux );
		fixDown(mynode);

	} else {
		return;
	}
}
*/
void Heap::fixDown( Node* mynode ){
	if( mynode == NULL || mynode->getLeft() == NULL ) return;

	Node* aux;
	if( mynode->getRight() == NULL ) aux = mynode->getLeft();

	else{
		if( mynode->getLeft()->getKeyValue() < mynode->getRight()->getKeyValue() )
			aux = mynode->getLeft();
		else
			aux = mynode->getRight();
	}
	if(aux->getKeyValue() < mynode->getKeyValue()){
		this->swapNode( aux,mynode );
		fixDown(aux);
	}
}

void Heap::updateKeyValue( Node* mynode, int newvalue ){
	mynode->updateKeyValue( newvalue );

	if( mynode->getDad()->getKeyValue() > mynode->getKeyValue() )
		fixUp( mynode );
	else
		fixDown( mynode );
}
