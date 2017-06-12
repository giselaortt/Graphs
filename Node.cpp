#include <stdio.h>
#include "Node.h"
#include "Vertex.h"

	Node::Node() {
		this->left = this->dad = this->right = NULL;
	}

	Node::Node( int key, int parent, double weight ){
		this->left = NULL;
		this->right = NULL;
		this->key = key;
		this->dad = NULL;
		this->descendents = 0;
		this->keyvalue = weight;
		this->parent = parent;
	}

Node::~Node(){}

void Node::swapKey( Node* first ){
	int temp;
	double aux;

	temp = this->key;
	this->key = first->getKey();
	first->setKey( temp );

	temp = this->parent;
	this->parent = first->getParent();
	first->setParent( temp );

	aux = this->keyvalue;
	this->keyvalue = first->getKeyValue();
	first->updateKeyValue( aux );

	return;
}

void Node::setDescendents( int num ){
	this->descendents = num;
}

void Node::setParent( int x ){
	this->parent = x;
}

int Node::getParent(){
	return this->parent;
}

void Node::updateKeyValue( double newvalue ){
	this->keyvalue = newvalue;
}

double Node::getKeyValue(){
	return this->keyvalue;
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

Node* Node::getLeft(){
	return this->left;
}

Node* Node::getDad(){
	return this->dad;
}

Node* Node::getRight(){
	return this->right;
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

int Node::getKey( ) {
	return this->key;
}

void Node::setKey( int mykey ){
	this->key = mykey;
}
