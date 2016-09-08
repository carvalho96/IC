#include "Edge.h"

void Edge::plus()
{
    nivel = nivel + 1;
}

int Edge::getnivel()
{
	return nivel;
}

Vertex* Edge::getA(){
    return a;
}

Vertex* Edge::getB(){
    return b;
}

Edge::Edge(Vertex*A,Vertex*B)
{
	nivel = 1;
    a = A;
    b = B;
}


Edge::~Edge()
{
}
