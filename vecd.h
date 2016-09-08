#ifndef VECD_H
#define VECD_H
#include "no.h"

class VecD
{
private:
    no* primeiro;
    int total;
public:
    VecD(){
        total = 0;
        primeiro = NULL;
    }
    void push_back(Vertex* a){
        if(primeiro == NULL){
            primeiro = new no;
            primeiro->seta(a);
            primeiro->setprox(NULL);
        }else{
            no* aux = primeiro;
            no* ant;
            while(aux->getprox() != NULL ){
                ant = aux;
                aux = aux->getprox();
            }
            ant->addnewv();
            ant->getprox()->seta(new Vertex);
            ant->getprox()->setprox(NULL);
            cout<<" ";
        }
       total++;
    }
    Vertex* at(int j){
        no* aux = primeiro;
        cout<<"asdsdadsd "<<j;
        for(int i = 0;i = j;i++ ){
            aux = aux->getprox();
        }
        return aux->getvertex();
    }
    int size(){
        return total;
    }



};

#endif // VECD_H
