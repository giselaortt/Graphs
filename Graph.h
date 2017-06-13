#ifndef _GRAPH_H
#define _GRAPH_H

#include "Graph.h"
#include "Vertex.h"
#include "UnionFind.h"
#include "Edge.h"
#include "Heap.h"
#include "Node.h"
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <list>

using namespace std;

class Graph{
	private:
	int numOfVert;
	int numOfEdges;

	// usado no algoritimo de kruskall
	vector< Edge* > edges;

	// usado no algoritmo de prim
	vector< Vertex* > vertices;

	// used to color the subgraphs and on prims algoritm
	vector< list< Vertex* > > adjlist;
	
	public:

	Graph();

	Graph( vector< Vertex* > v );

	~Graph();

	//Add all the vertex written in the sousce file
	void addVertex( FILE* source );

	//Receives coordinates of a point and add a single vertex.
	void addVertex( double a, double b );

	//Receives index of two vertex and add an edge between than. Since it does not get the edge's weight
	//it puts the distance as weight
	void addEdge( int ind, int ind2 );

	void addEdge( Edge* );

	//Returns number os vertices created
	int getNumOfVertex();

	int getNumOfEdges(){ return this->numOfEdges; }

	private:
	//Uses dfs as a way to color all the vertex. Its keept as private since its an auxiliary method for color method.
	void dfs( Vertex* vert, int color );

	public:
	//Pinta os componentes conexos do grafo com "cores" diferentes
	int color();

	void clearAdjacencyList();

	//Print colors(classes) from all vertex.
	void printColors();

	void printColors(FILE* fp );

	//Creates minimim spanning tree acording to kruskall's algorithm
	vector<Edge*> kruskall( int );

	//Creates minimim spanning tree acording to prim's algorithm
	vector<Edge*> prim();

	double primsum();

	// rebuilds graph acording to a new list od edges
	void addEdge( vector<Edge*> vet );

	//bool compare( Edge* first, Edge* sec );

	void addEdge( Vertex*, Vertex* );
	
	void clear();

	// auxiliary function from rebuildAdjacency
	bool contains( vector<Edge*> v, Edge* ed );

	int connectedComponents();
};

#endif
