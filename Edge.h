#ifndef _EDGE_H
#define _EDGE_H
 
#include "Vertex.h"

using namespace std;

class Edge{
	private:
	double value;
	int first;
	int second;

	public:
	Edge( double value, int f, int s );

	Edge( int f, int s );

	~Edge();

	static bool compare( Edge one, Edge two );

	Edge* copy();

	double getValue();

	void setValue( double value );

	bool operator < ( const Edge& b ) const; 

	void setFirst( int f );

	void setSecond( int f );

	int getFirst();

	int getSecond();

	void print();
};

#endif
