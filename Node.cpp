#include <stdio.h>
#include "Node.h"
#include "Key.h"

void Node::swapKey( Node* first ){
	Key* temp = this->key;
	this->key = first->getKey();
	first->setKey( temp );
	return;
}

int Node::getDescendents(){
	return this->descendents;
}

void Node::addDescendent(){
	this->descendents++;
}

void Node::subDescendent(){
	this->descendents--;
}

/*
// BUGS on this opetator
bool Node::operator > ( Node *n ) const {
	if( this->key > n->key ) return true;
	return false;
}
*/

Node* Node::getLeft(){
	return this->left;
}

Node* Node::getDad(){
	return this->dad;
}

Node* Node::getRight(){
	return this->right;
}

int Node::getNumOfKids(){
	return this->numOfKids;
}

void Node::setLeft( Node* n ){
	this->left = n;
}

void Node::setRight( Node* n ){
	this->right = n;
}

void Node::setDad( Node* d ){
	this->dad = d;
}

Key* Node::getKey( ) {
	return this->key;
}

void Node::setKey( Key* mykey ){
	this->key = mykey;
}
