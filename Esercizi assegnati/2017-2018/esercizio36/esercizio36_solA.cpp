//Soluzione di S.Righetto

//code .h 

#ifndef CODE_H
#define CODE_H

#include<iostream>
struct nodo {
    char chiave;
    nodo *next;
    nodo(char c='\0', nodo* n=NULL);   
};

struct coda {
    nodo *inizio;
    nodo *fine;
    coda();
};

void push(char c, coda &Q);
char pop(coda &Q);
bool e_vuota(coda Q);

#endif

//code.cpp

#include<iostream>

#include "code.h"

coda::coda(){inizio=0;fine=0;}
nodo::nodo(char c, nodo*n){
    chiave=c; next=n;}

void push(char c, coda &Q){ // aggiunge un nuovo elemento con chiave == c alla fine della coda Q
    if(e_vuota(Q)){
   Q.inizio=new nodo(c,0);
   Q.fine=Q.inizio;
   } else {
    Q.fine->next= new nodo (c,0);
    Q.fine=Q.fine->next;}
}

char pop(coda &Q){ // estrae l’elemento all’inizio della coda Q,lo rimuove dalla coda e ne ritorna la chiave
    char c= Q.inizio->chiave;
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
    char c;
    cin >> c;
    while(c != '.'){
        if(c == '*' ) {
            if(e_vuota(Q)) cout << " vuota ";
            else
                cout << pop(Q) << ' ';
        }
        else push(c,Q);
        cin >> c;
    }
    cout << "end" << endl;
}



