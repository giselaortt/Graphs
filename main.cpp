#include "Heap.h"
#include "Node.h"
#include "Graph.h"
#include "UnionFind.h"
#include "Vertex.h"
#include "Edge.h"
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main(){
	FILE* vert = fopen("data.txt", "r");
	FILE* kruskall = fopen("kruskall.txt", "w+");
	FILE* prim = fopen("prim.txt", "w+");

	int clusteres = 7;

	Graph *g = new Graph();
	Graph *k = new Graph();
	Graph *p = new Graph();

	g->addVertex( vert );
	rewind( vert );
	k->addVertex( vert );
	rewind( vert );
	p->addVertex( vert );

	for( int i = 0; i < g->getNumOfVertex(); i++)
		for( int j = i + 1; j < g->getNumOfVertex(); j++ )
			g->addEdge( i, j );

	vector<Edge*> mstk = g->kruskall( clusteres );
	vector<Edge*> mstp = g->prim();
	sort( mstp.begin(), mstp.end(), Edge::compare );
	for( int i=0; i<clusteres-1; i++ )
		mstp.pop_back();

	k->addEdge( mstk );
	p->addEdge( mstp );

	printf("%d %d\n", k->getNumOfEdges(), k->getNumOfVertex() );
	printf("%d %d\n", p->getNumOfEdges(), p->getNumOfVertex() );

	k->color();
	p->color();
	k->printColors( kruskall );
	p->printColors( prim );

	g->clear();
	k->clear();
	p->clear();

	delete( g );
	delete( k );
	delete( p );

	fclose(prim);
	fclose(kruskall);
	fclose(vert);

return 0;
}
