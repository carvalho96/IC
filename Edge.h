#pragma once
#include "Vertex.h"
class Vertex;
class Edge
{
private:
    int nivel;
    Vertex *a;
    Vertex *b;
public:
    Vertex* getA();
    Vertex* getB();
    void plus();
	int getnivel();
    Edge(Vertex *A, Vertex *B);
	~Edge();
};

