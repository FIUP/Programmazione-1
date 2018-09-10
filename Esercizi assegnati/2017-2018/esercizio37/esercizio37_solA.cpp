//Soluzione di S.Righetto


//code .h

#ifndef CODE_H
#define CODE_H

#include<iostream>


struct nodo {
    int chiave;
    nodo *next;
    
    nodo(int k=0, nodo* n=NULL);
};

struct coda {
    nodo *inizio;
    nodo *fine;
    
    coda();
};

void push(int k, coda &Q);
int pop(coda &Q);
bool e_vuota(coda Q);


#endif


//code.cpp

#include<iostream>

#include "code.h"

coda::coda(){inizio=0;fine=0;}
nodo::nodo(int c, nodo*n){chiave=c; next=n;}

void push(int k, coda &Q){ //inserisce una nuova persona alla fine della coda 
    if(e_vuota(Q)){
       Q.inizio=new nodo(k,0);
       Q.fine=Q.inizio;
   } else {
        Q.fine->next= new nodo (k,0);
        Q.fine=Q.fine->next;}
}

int pop(coda &Q){ // estrae l’elemento all’inizio della coda Q,lo rimuove dalla coda e ne ritorna la chiave
    int c= Q.inizio->chiave;
    nodo* a= Q.inizio;
    Q.inizio=Q.inizio->next;
    if(e_vuota(Q)) Q.fine=NULL;
    delete a;
    return c;
}

bool e_vuota(coda Q){ //ritorna true se e solo se la coda Q è vuota
    if(!Q.inizio) return true;
    else return false;
}

//main.cpp

#include <iostream>
#include "code.h"

using namespace std;


int main() {
    coda Q;
    cout << "start" << endl;
    int n,k;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        push(i,Q);
        }
    int i =k;
    //Q.inizio=Q.fine puntano allo stesso nodo, soppravissuto
    while( Q.inizio != Q.fine ){
        if(i>1){ 
            //cout << Q.inizio->chiave;
            i--;
            int c=pop(Q);
            push(c,Q);
            //pop e push cambio l inizio della coda
        }
        else {
            //pop della persona eliminata
            cout << pop(Q) << " eliminata" <<endl;
            i=k;
        }
    }
    cout << Q.inizio->chiave << " sopravvive"<<endl;
    cout << "end" << endl;
}



