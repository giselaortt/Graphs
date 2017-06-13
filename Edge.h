#ifndef _EDGE_H
#define _EDGE_H
 
#include "Vertex.h"

using namespace std;

class Edge{
	private:
	double value;
//	Vertex* first;
//	Vertex* second;

	int first;
	int second;

	public:
	Edge( double value, int f, int s );

//	Edge( Vertex* f, Vertex* s );
	Edge( int f, int s );

	~Edge();

	static bool compare( Edge* one, Edge* two );

//	int getIndex();

	Edge* copy();

	double getValue();

	void setValue( double value );

	bool operator < ( const Edge& b ) const; 

	void setFirst( int f );
	//void setFirst( Vertex* f );

	//void setSecond( Vertex* f );
	void setSecond( int f );

	int getFirst();
	//Vertex* getFirst();

	//Vertex* getSecond();
	int getSecond();

	void print();
};

#endif
