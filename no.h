#ifndef NO_H
#define NO_H
#include "Vertex.h"

class no
{
private:
    Vertex* a;
    no* prox;
public:
    no();
    Vertex* getvertex(){
        return a;
    }
    no* getprox(){
        return prox;
    }
    void seta(Vertex* b){
        a = b;
    }
    void setprox(no* p){
        prox = p;
    }
    void addnewv(){
        prox = new no;
    }
};

#endif // NO_H
