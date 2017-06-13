#include "Vertex.h"
#include "Graph.h"
#include "UnionFind.h"
#include "Edge.h"
#include "Node.h"
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <climits>
#include <list>
#include <limits>
#include <cstddef>

#define infinity INT_MAX

using namespace std;

Graph::Graph(){
	this->numOfVert = 0;
	this->numOfEdges = 0;
}

Graph::Graph( vector< Vertex* > v ){
	this->vertices.reserve( v.size() );
	for( int i=0; i<v.size(); i++ )
		this->vertices[i] = v[i]->copy();
}

Graph::~Graph(){
	this->clear();
}

vector<Edge*> Graph::kruskall( int clusters ){
	vector<Edge*>ans;
	sort( this->edges.begin(), this->edges.end(), Edge::compare );
	UnionFind u( this->numOfVert );
	
	for( int i=0; i < this->numOfEdges && u.getGroups() != clusters ; i++){
		//printf("%d\n", u.getGroups() );
		if( u.merge( this->edges[i]->getFirst(), this->edges[i]->getSecond() ) )
			ans.push_back( edges[i] );
	}
	u.clear();
	return ans;
}

void Graph::clearAdjacencyList(){
	for( int i=0; i<this->adjlist.size(); i++ )
		this->adjlist[i].clear();
	this->adjlist.clear();
}

void Graph::clear() {
	for(int i=0; i < this->edges.size(); i++ ){
		delete( this->edges[i] );
	}
	for( int i=0; i< this->vertices.size(); i++ ){
		delete( this->vertices[i] );
	}
	this->edges.clear();
	this->vertices.clear();
	this->clearAdjacencyList();
}

int Graph::getNumOfVertex(){
	return this->numOfVert;
}

void Graph::addVertex( double a, double b ){
	this->vertices.push_back( new Vertex( a, b, this->numOfVert ) );
	this->numOfVert++;
	this->adjlist.push_back( list< Vertex* >() );
}

void Graph::addVertex( FILE* source ){
	double a, b;
	while( fscanf( source, "%lf %lf", &a, &b ) == 2 ){
		vertices.push_back( new Vertex( a, b, this->numOfVert ) );
		this->adjlist.push_back( list< Vertex* >() );
		this->numOfVert++;
	}
}

void Graph::addEdge( int ind, int ind2 ){
	if( ind > this->numOfVert || this->numOfVert < ind2 ) return;
	Vertex* aux1 = this->vertices[ind];
	Vertex* aux2 = this->vertices[ind2];
	this->edges.push_back( new Edge( ind, ind2, aux1->getDistance( aux2 ) ) );
	this->adjlist[ ind ].push_back( aux2 );
	this->adjlist[ ind2 ].push_back( aux1 );
	this->numOfEdges++;
}

void Graph::addEdge( Vertex* one, Vertex* two ){
	this->adjlist[ one->getIndex() ].push_back( two );
	this->adjlist[ two->getIndex() ].push_back( one );
	this->edges.push_back( new Edge( one->getIndex(), two->getIndex(), one->getDistance( two ) ) );
	this->numOfEdges++;
}

void Graph::addEdge( vector< Edge* > vet ){
	for( int i=0; i < vet.size(); i++ ){
		this->addEdge( vet[i]->getFirst(), vet[i]->getSecond() );
	}
}

void Graph::dfs( Vertex* vert, int color ){
	if( vert->getColor( ) == color ) return;
	vert->setColor( color );
	int atual = vert->getIndex();
	for( list<Vertex*>::iterator it = this->adjlist[ atual ].begin(); it != this->adjlist[ atual ].end(); ++it)
		dfs( *it, color );
}

int Graph::color(){
	int ctd = 0;
	for( int i=0; i<numOfVert; i++ )
		if( this->vertices[ i ]->getColor() == 0 )
			dfs( this->vertices[i], ++ctd );
	return ctd;
}

void Graph::printColors(){
	for( int i=0; i< this->numOfVert; i++ )
		printf("%d\n", this->vertices[i]->getColor() );
}

void Graph::printColors( FILE* fp ){
	for( int i=0; i<this->numOfVert; i++ )
		fprintf(fp, "%lf %lf %d\n", this->vertices[i]->getx(), this->vertices[i]->gety(),this->vertices[i]->getColor());
}

vector< Edge* > Graph::prim(){
	Heap* heap = new Heap();
	vector< Edge* > mst;
	list< Vertex* >::iterator it;
	bool included[ this->numOfVert ];
	double prices[ this->numOfVert ];

	for( int i=0; i < this->numOfVert; i++ ){
		prices[i] = infinity;
		included[i] = false;
	}

	int sum = 0;
	Node* no;
	int atual = 0;
	prices[0] = 0;
	included[0] = true;

	for( it = this->adjlist[0].begin(); it != this->adjlist[0].end(); it++ ){
		double distance = this->vertices[0]->getDistance( (*it) );
		heap->push( new Node( (*it)->getIndex(), atual, distance ) );
		prices[ (*it)->getIndex() ] = distance;
	}
	while( mst.size() < this->numOfVert - 1 && heap->getSize() ){
		no = heap->pop();
		atual = no->getKey();
		if( included[ atual ] == false ){
			included[ atual ] = true;
			prices[ atual ] = no->getKeyValue();
			mst.push_back( new Edge(no->getKeyValue(), atual, no->getParent() ) );

			for( it = this->adjlist[0].begin(); it != this->adjlist[0].end(); it++ ){
				double distance = this->vertices[ atual ]->getDistance( (*it) );
				if( included[ (*it)->getIndex() ] == false || prices[ (*it)->getIndex() ] > distance ){
					heap->push( new Node( (*it)->getIndex(), atual, distance ) );
					prices[ (*it)->getIndex() ] = distance;
				}
			}
		}
		delete(no);
	}
	heap->clear();
	delete(heap);
	return mst;
}

