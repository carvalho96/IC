#pragma once
#include <list>
#include <iostream>                  // for std::cout
#include "Edge.h"
#define PERSON 0
#define ALT 1
#define LARG 2
#define PESO 3
class Edge;
using namespace std;
class Vertex
{
    private:
        int Vtype;
        list<Edge*> edges;
    public:
        void connect(Edge* E);
        bool iscc(Vertex* B);
        list<Edge *>* getEdges();
        int getVtype();
        void setVtype(int);
        Vertex();

};

