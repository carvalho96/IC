#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <fstream>
#include <QString>
#include <list>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "Vertex.h"
#include "Edge.h"
#include "VertexPerson.h"
#include "VertexCaracPeso.h"
#include "VertexCaracLargura.h"
#include "VertexCaracAltura.h"
#include "pprob.h"

#define VARA 0.1
#define VARL 0.1
#define VARP 0.1

using namespace std;

void connect(Vertex* a, Vertex* b){
    Edge* e = new Edge(a,b);
    a->connect(e);

    b->connect(e);

}

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

void probA(list<Vertex*> *g, float altura, list<PProb*> *P){
    list<Edge*>* edge;
    std::list<Vertex*>::iterator A;
    int totalCarac = 0;
    for(std::list<Vertex*>::iterator it = g->begin(); it != g->end(); ++it){

       if( ALT == ((*it))->getVtype()){
               if(altura <= ((VertexCaracAltura*)(*it))->getAltura() + VARA && altura >= ((VertexCaracAltura*)(*it))->getAltura() - VARA){
                   A = it;
                   edge = ((VertexCaracAltura*)(*it))->getEdges();
                    break;
           }
       }
   }

    for(std::list<Edge*>::iterator it = edge->begin(); it != edge->end(); ++it){

        if((((Edge*)(*it))->getA())->getVtype() == PERSON ){
            VertexPerson* V;
            if((((Edge*)(*it))->getA())->getVtype() == PERSON ){

                V = ((VertexPerson*)(((Edge*)(*it))->getA()));

            }else{

                V = ((VertexPerson*)(((Edge*)(*it))->getB()));

            }

            std::list<PProb*>::iterator it2;
            bool flag0 = 0;
            for(std::list<PProb*>::iterator it2 = P->begin(); it2 != P->end(); ++it2){


                if( ((PProb*)(*it2))->getName() == V->getname()){

                    ((PProb*)(*it2))->setpAlt(((Edge*)(*it))->getnivel());
                    totalCarac = totalCarac + ((PProb*)(*it2))->getpAlt();
                    flag0 = 1;
                    break;
                }
            }
            if(flag0 == 0){

                PProb* x = new PProb;
                x->setName(V->getname());
                x->setpAlt(((Edge*)(*it))->getnivel());
                totalCarac = totalCarac + x->getpAlt();
                P->push_back(x);

            }
        }
    }


     for(std::list<PProb*>::iterator it = P->begin(); it != P->end(); ++it){

         if( ((PProb*)(*it))->getpAlt() != 0 ){

             ((PProb*)(*it))->setpAlt( ( ((PProb*)(*it))->getpAlt() / totalCarac ) );

         }
     }
}

void probL(list<Vertex*> *g, float largura, list<PProb*> *P){

    list<Edge*>* edge;
    std::list<Vertex*>::iterator A;
    int totalCarac = 0;
    for(std::list<Vertex*>::iterator it=g->begin(); it != g->end(); ++it){

       if( LARG == ((*it))->getVtype()){
               if(largura <= ((VertexCaracLargura*)(*it))->getlargura() + VARL && largura >= ((VertexCaracLargura*)(*it))->getlargura() - VARL){
                   A = it;
                   edge = ((VertexCaracLargura*)(*it))->getEdges();
                    break;
           }
       }
   }

    for(std::list<Edge*>::iterator it = edge->begin(); it != edge->end(); ++it){

        if((((Edge*)(*it))->getA())->getVtype() == PERSON ){
            VertexPerson* V;
            if((((Edge*)(*it))->getA())->getVtype() == PERSON ){

                V = ((VertexPerson*)(((Edge*)(*it))->getA()));

            }else{

                V = ((VertexPerson*)(((Edge*)(*it))->getB()));

            }
            bool flag0 = 0;
            std::list<PProb*>::iterator it2;
            for( it2 = P->begin(); it2 != P->end(); ++it2){


                if( ((PProb*)(*it2))->getName() == V->getname()){

                    ((PProb*)(*it2))->setpLarg(((Edge*)(*it))->getnivel());
                    totalCarac = totalCarac + ((PProb*)(*it2))->getpLarg();
                    flag0 = 1;
                    break;
                }
            }
            if(flag0 == 0){

                PProb* x = new PProb;
                x->setName(V->getname());
                x->setpLarg(((Edge*)(*it))->getnivel());
                totalCarac = totalCarac + x->getpLarg();
                P->push_back(x);

            }
        }
    }

     for(std::list<PProb*>::iterator it = P->begin(); it != P->end(); ++it){

         if( ((PProb*)(*it))->getpLarg() != 0 ){

             ((PProb*)(*it))->setpLarg( ( ((PProb*)(*it))->getpLarg() / totalCarac ) );

         }
     }

}

void probP(list<Vertex*> *g, float peso, list<PProb*> *P){



    list<Edge*>* edge = NULL;
    std::list<Vertex*>::iterator A;
    int totalCarac = 0;
    for(std::list<Vertex*>::iterator it=g->begin(); it != g->end(); ++it){

       if( PESO == ((*it))->getVtype()){
               if(peso <= ((VertexCaracPeso*)(*it))->getPeso() + VARP && peso >= ((VertexCaracPeso*)(*it))->getPeso() - VARP){
                   A = it;
                   edge = ((VertexCaracPeso*)(*it))->getEdges();
                   break;
           }
       }
   }
   if(edge == NULL){
       return;
   }
    for(std::list<Edge*>::iterator it = edge->begin(); it != edge->end(); ++it){

        if((((Edge*)(*it))->getA())->getVtype() == PERSON ){
            VertexPerson* V;
            if((((Edge*)(*it))->getA())->getVtype() == PERSON ){

                V = ((VertexPerson*)(((Edge*)(*it))->getA()));

            }else{

                V = ((VertexPerson*)(((Edge*)(*it))->getB()));

            }
            bool flag0 = 0;
            std::list<PProb*>::iterator it2;
            for( it2 = P->begin(); it2 != P->end(); ++it2){


                if( ((PProb*)(*it2))->getName() == V->getname()){

                    ((PProb*)(*it2))->setpPeso(((Edge*)(*it))->getnivel());
                    totalCarac = totalCarac + ((PProb*)(*it2))->getpPeso();
                    flag0 = 1;
                    break;
                }
            }
            if(flag0 == 0){

            PProb* x = new PProb;
            x->setName(V->getname());
            x->setpPeso(((Edge*)(*it))->getnivel());
            totalCarac = totalCarac + x->getpPeso();
            P->push_back(x);

            }
        }
    }

     for(std::list<PProb*>::iterator it = P->begin(); it != P->end(); ++it){

         if( ((PProb*)(*it))->getpPeso() != 0 ){

             ((PProb*)(*it))->setpPeso( ( ((PProb*)(*it))->getpPeso() / totalCarac ) );
         }

     }
}


string searchbycarac(list<Vertex*> *g, float altura, float largura, float peso){

    list<PProb*> P;


    string nome = "Ninguem Encontrado!";
    float maior = 0;
    probA(g,altura, &P);
    probL(g,largura, &P);
    probP(g,peso, &P);
    cout<<"Probabilidades: \n";
    float pgeral = 0;
    float pgeraltotal = 0;
    for(std::list<PProb*>::iterator it = P.begin(); it != P.end(); ++it){

        pgeraltotal += 1 - ( (1 - ((PProb*)(*it))->getpAlt() )*(1 - ((PProb*)(*it))->getpLarg())*(1 - ((PProb*)(*it))->getpPeso()) );

    }
    for(std::list<PProb*>::iterator it = P.begin(); it != P.end(); ++it){

        cout<<((PProb*)(*it))->getName()<<endl;
        cout<<"Altura: "<<((PProb*)(*it))->getpAlt()<<endl;
        cout<<"Largura: "<<((PProb*)(*it))->getpLarg()<<endl;
        cout<<"Peso: "<<((PProb*)(*it))->getpPeso()<<endl;
        pgeral = (1 - ( (1 - ((PProb*)(*it))->getpAlt() )*(1 - ((PProb*)(*it))->getpLarg())*(1 - ((PProb*)(*it))->getpPeso()) )) / pgeraltotal;
        if(maior < pgeral){
            nome = ((PProb*)(*it))->getName();
            maior = pgeral;
        }
        cout<<"Prob: "<<pgeral<<endl;
        cout<<"-------------\n";
    }

    cout<<endl;
    cout<<"*******************************\n";
    cout<<"Resposta: "<<nome<<endl;
    cout<<"Prob:"<<maior<<endl;
    cout<<"*******************************\n\n";

    return nome;

}

Vertex* addLargura(list<Vertex*> *g, float largura){

    for(std::list<Vertex*>::iterator it=g->begin(); it != g->end(); ++it){

       if( LARG == (*it)->getVtype()){
               if(largura <= ((VertexCaracLargura*)(*it))->getlargura() + VARL && largura >= ((VertexCaracLargura*)(*it))->getlargura() - VARL ){
                   return (*it);

           }
       }
   }

   VertexCaracLargura *a = new VertexCaracLargura;
   a->setLargura(largura);
   g->push_back(a);
   return a;
}

Vertex* addPeso(list<Vertex*> *g, float peso){

    for(std::list<Vertex*>::iterator it=g->begin(); it != g->end(); ++it){

       if( PESO == ((*it))->getVtype()){
               if(peso <= ((VertexCaracPeso*)(*it))->getPeso() +VARP && peso >= ((VertexCaracPeso*)(*it))->getPeso() - VARP){
                   return *it;

           }
       }
   }

   VertexCaracPeso *a = new VertexCaracPeso;
   a->setPeso(peso);
   g->push_back(a);
   return a;
}

Vertex* addAltura(list<Vertex*> *g, float altura){

     for(std::list<Vertex*>::iterator it=g->begin(); it != g->end(); ++it){

        if( ALT == (*it)->getVtype()){
            if(altura <= ((VertexCaracAltura*)(*it))->getAltura() +VARA && altura >= ((VertexCaracAltura*)(*it))->getAltura() - VARA){
                    return *it;

            }
        }
    }

    VertexCaracAltura *a = new VertexCaracAltura;
    a->setAltura(altura);
    g->push_back(a);
    return a;
}

void addPerson(list<Vertex*> *g, string name, float largura, float peso, float altura){

    for(std::list<Vertex*>::iterator it=g->begin(); it != g->end(); ++it){
        if( PERSON == (*it)->getVtype()){
            if (name == ((VertexPerson*)(*it))->getname()){


                {
                     Vertex* ind = addAltura(g,altura);


                    if(((VertexPerson*)(*it))->iscc(ind)){

                    }
                    else{
                        connect((*it),ind);
                    }

                }

                {
                    Vertex* ind = addLargura(g,largura);

                    if(((VertexPerson*)(*it))->iscc(ind)){

                    }
                    else{
                        connect((*it),ind);
                    }

                }

                {
                    Vertex* ind = addPeso(g,peso);

                    if(((VertexPerson*)(*it))->iscc(ind)){

                    }
                    else{
                        connect((*it),ind);
                    }

                }

                return;

            }
        }
    }

    VertexPerson* p = new VertexPerson;
    p->setname(name);
    g->push_back(p);
    Vertex* ind;

    ind = addAltura(g, altura);
    connect(p,ind);

    ind = addLargura(g,largura);
    connect(p,ind);

    ind = addPeso(g,peso);
    connect(p,ind);
}

void carregar(list<Vertex*> *g, int *total){
    ifstream myfile ("Database.txt");
    string line;

    if (myfile.is_open())
    {
    while(getline(myfile,line)){
        string nome, altura, largura, peso;
        int i = 0;
        string a;
        while(line[i]!=','){
            a = line[i];
            a[1] = '\0';
            nome.append(a);
            i++;
        }
        i++;
        while(line[i]!=','){
            a = line[i];
            a[1] = '\0';
            altura.append(a);
            i++;
        }
        i++;

        while(line[i]!=','){
            a = line[i];
            a[1] = '\0';
            largura.append(a);
            i++;

        }
        i++;

        while(line[i]!='\0'){
            a = line[i];
            a[1] = '\0';
            peso.append(a);
            i++;
        }

        QString l,al,p;
        double xa,xl,xp;
        l = QString::fromStdString(largura);
        xl = l.toFloat();
        al = QString::fromStdString(altura);
        xa = al.toFloat();
        p = QString::fromStdString(peso);
        xp = p.toFloat();

        addPerson(g,nome,xl,xp,xa);

    }
    myfile.close();
    }
    else cout << "No file to open!";
}

void test(list<Vertex*> *g, string info){

        string nome, altura, largura, peso;
        int i = 0;
        string a;
        while(info[i]!=','){
            a = info[i];
            a[1] = '\0';
            nome.append(a);
            i++;
        }
        i++;
        while(info[i]!=','){
            a = info[i];
            a[1] = '\0';
            altura.append(a);
            i++;
        }
        i++;

        while(info[i]!=','){
            a = info[i];
            a[1] = '\0';
            largura.append(a);
            i++;

        }
        i++;

        while(info[i]!='\0'){
            a = info[i];
            a[1] = '\0';
            peso.append(a);
            i++;
        }

        QString l,al,p;
        double xa,xl,xp;
        l = QString::fromStdString(largura);
        xl = l.toFloat();
        al = QString::fromStdString(altura);
        xa = al.toFloat();
        p = QString::fromStdString(peso);
        xp = p.toFloat();

        string resp = searchbycarac(g, xa, xl, xp);

        cout<<"Resposta "<<resp<<endl;
}
void aprendizagem(list<Vertex*> *g){
    string y = "y";
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
       error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));

    portno = atoi("50005");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
            error("ERROR on binding");

    while(y == "y" || y == "Y" || y == "s"){


        listen(sockfd,5);
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

        if (newsockfd < 0)
             error("ERROR on accept");

        bzero(buffer,256);
        n = read(newsockfd,buffer,255);

        if (n < 0) error("ERROR reading from socket");

        printf("\nReceive message: %s\n",buffer);


            string data,nome, altura, largura, peso;
            int i = 0;
            string a;
            data = buffer;
            while(data[i]!=','){
                a = data[i];
                a[1] = '\0';
                nome.append(a);
                i++;
            }
            i++;
            while(data[i]!=','){
                a = data[i];
                a[1] = '\0';
                altura.append(a);
                i++;
            }
            i++;

            while(data[i]!=','){
                a = data[i];
                a[1] = '\0';
                largura.append(a);
                i++;

            }
            i++;

            while(data[i]!='\0'){
                a = data[i];
                a[1] = '\0';
                peso.append(a);
                i++;
            }
            QString l,al,p;
            double xa,xl,xp;
            l = QString::fromStdString(largura);
            xl = l.toFloat();
            al = QString::fromStdString(altura);
            xa = al.toFloat();
            p = QString::fromStdString(peso);
            xp = p.toFloat();
            cout<<"Qual o nome? ";
            cin>>nome;
            cout<<"\n\nlalal: "<<nome<<" "<<xl<<" "<<xp<<" "<<xa<<endl;
            addPerson(g,nome,xl,xp,xa);
            string X;
            X = nome;
            X.append(",");
            X.append(altura);
            X.append(",");
            X.append(largura);
            X.append(",");
            X.append(peso);
            cout <<X <<endl;
            ofstream fileOUT("Database.txt", ios::app);

            fileOUT <<X<< endl;

            fileOUT.close();

            cout<<"Data adicionada! Continuar?(y/n)";
            n = write(newsockfd,"I got your message",18);

            if (n < 0) error("ERROR writing to socket");

            cin>>y;
}
    close(newsockfd);
    close(sockfd);

}
void inferencia(list<Vertex*> *g){


    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
       error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));

    portno = atoi("50005");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");


    while(1){
            listen(sockfd,5);
            clilen = sizeof(cli_addr);
            newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

            if (newsockfd < 0)
                 error("ERROR on accept");

            bzero(buffer,256);
            n = read(newsockfd,buffer,255);

            if (n < 0) error("ERROR reading from socket");


                string data,nome, altura, largura, peso;
                int i = 0;
                string a;
                data = buffer;
                while(data[i]!=','){
                    a = data[i];
                    a[1] = '\0';
                    nome.append(a);
                    i++;
                }
                i++;
                while(data[i]!=','){
                    a = data[i];
                    a[1] = '\0';
                    altura.append(a);
                    i++;
                }
                i++;

                while(data[i]!=','){
                    a = data[i];
                    a[1] = '\0';
                    largura.append(a);
                    i++;

                }
                i++;

                while(data[i]!='\0'){
                    a = data[i];
                    a[1] = '\0';
                    peso.append(a);
                    i++;
                }
                QString l,al,p;
                double xa,xl,xp;
                l = QString::fromStdString(largura);
                xl = l.toFloat();
                al = QString::fromStdString(altura);
                xa = al.toFloat();
                p = QString::fromStdString(peso);
                xp = p.toFloat();
                searchbycarac(g,xa,xl,xp);
                printf("\nReceive message: %s\n",buffer);

                n = write(newsockfd,"I got your message",18);
                if (n < 0) error("ERROR writing to socket");
            }
            close(newsockfd);
            close(sockfd);

}



int main()
{
         list<Vertex*> g;
         int total = 0;
         carregar(&g, &total);
         while(1){
         char a;
         cout<<"\n0-Aprendizagem\n1-Inferencia"<<endl;
         cin>>a;
         switch (a) {
         case '0':
               aprendizagem(&g);
             break;
         case '1':
               inferencia(&g);
             break;

         default:
             break;
         }
    }
     //cout<<"Acertou: "<<test(&g,infoRecv)<<"%\n";


     addPerson(&g,"Jão",45,45,45);
     addPerson(&g,"Jão",45,45,45);
     addPerson(&g,"Bruno",45,30,45);
     searchbycarac(&g,45,45,45);

     return 0;
}

