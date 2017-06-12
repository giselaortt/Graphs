#ifndef _EDGE_H
#define _EDGE_H
 
#include "Vertex.h"

using namespace std;

class Edge{
	private:
	double value;
	Vertex* first;
	Vertex* second;

	public:
	Edge( double value, Vertex* f, Vertex* s );

	Edge( Vertex* f, Vertex* s );

	~Edge();

	static bool compare( Edge* one, Edge* two );

	int getIndex();

	Edge* copy();

	double getValue();

	void setValue( double value );

	bool operator < ( const Edge& b ) const; 

	void setFirst( Vertex* f );

	void setSecond( Vertex* f );

	Vertex* getFirst();

	Vertex* getSecond();

	void print();
};

#endif
