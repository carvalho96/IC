#include "Vertex.h"

int Vertex::getVtype(){
    return Vtype;
}

Vertex::Vertex(){
    Vtype = -1;
}
void Vertex::setVtype(int type){
    Vtype = type;
}
void Vertex::connect(Edge *E){
    edges.push_back(E);
}
list<Edge*>* Vertex::getEdges(){
    return &edges;
}
bool Vertex::iscc(Vertex *B){
    for(std::list<Edge*>::iterator it=edges.begin(); it != edges.end(); ++it){
        if(((Edge*)(*it))->getA() == B){
            ((Edge*)(*it))->plus();
            return true;
        }
        if(((Edge*)(*it))->getB() == B){
            ((Edge*)(*it))->plus();
            return true;
        }
    }
    /*for(unsigned i=0; i<edges.size(); i++){
        if((edges.at(i))->getA() == B){
            (edges.at(i))->plus();
            return true;
        }
        if((edges.at(i))->getB() == B){
            (edges.at(i))->plus();
            return true;
        }
    }*/
    return false;
}
