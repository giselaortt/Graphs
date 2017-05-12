#include <bits/stdc++.h>
#include "Heap.h"
#include "Node.h"
#include "Key.h"

using namespace std;

int Heap::getSize(){
	return this->size;
}

Node* Heap::getRoot(){
	return this->root;
}

void Heap::clear( Node* mynode ){
	if( mynode == NULL ) return;
	if( mynode->getLeft() != NULL )clear( mynode->getLeft() );
	if( mynode->getRight() != NULL )clear( mynode->getRight() );
	delete( mynode->getKey() );
	delete( mynode );
	return;
}

void Heap::clear( ) {
	if( this->root == NULL ) return;
	clear( this->root );
	this->root = NULL;
	return;
}

void Heap::push( Key* k ){
	Node* mynode = new Node(k);
	this->size++;
	if( this->root != NULL ){
		Node* temp = insert( mynode, this->root );
		mynode->subDescendent();
		fixUp( mynode );
	}
	else this->root = mynode;
}

void Heap::push( Node* novo ){
	this->size++;
	if( this->root == NULL )
		this->root = novo;
	else fixUp( insert( novo, this->root ) );
}

void Heap::fixUp( Node* mynode ){
	if( mynode == NULL) return;
	mynode->addDescendent();
	if( mynode->getDad() != NULL && mynode->getKey()->getValue() > mynode->getDad()->getKey()->getValue() ){
		mynode->swapKey( mynode->getDad() );
	}
	fixUp( mynode->getDad() );
}

Node* Heap::insert( Node* novo, Node* curr ){

	if(curr == NULL) return NULL;

	if(curr->getLeft() == NULL ) {
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

// retorna o ultimo no da heap
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

Key* Heap::top(){
	return this->root->getKey();
}

Key* Heap::pop(){
	if( this->root == NULL ) return NULL;

	if( this->size == 1 ){
		Key* temp = this->root->getKey();
		Node* aux = this->root;
		this->root = NULL;
		delete( aux );
		size = 0;
		return temp;
	}

	this->size--;
	Key* ans = this->root->getKey();
	Node* ntemp = this->findLast();
	this->root->swapKey( ntemp );
	Node* d = ntemp->getDad();
	if( d->getRight() == ntemp ) d->setRight( NULL );
	else d->setLeft( NULL );
	delete( ntemp );

	while( d != NULL ){
		d->subDescendent();
		d = d->getDad();
	}

	fixDown( this->root );
	return ans;
}

// precisa disso? hmmm acho q nao...
void Heap::fixDown( Node* mynode ){
	if( mynode == NULL || mynode->getLeft() == NULL ) return;
	Node* aux;

	if( mynode->getRight() == NULL ) aux = mynode->getLeft();

	else{
		if( mynode->getLeft()->getKey()->getValue() > mynode->getRight()->getKey()->getValue() )
			aux = mynode->getLeft();
		else
			aux = mynode->getRight();
	}
	if(aux->getKey()->getValue() > mynode->getKey()->getValue()){
		aux->swapKey( mynode );
		fixDown(aux);
	}
}
