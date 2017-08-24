// soluzione di B.Cosentino
#include<iostream>

struct nodo {
    char chiave;
    nodo *next;
    
    nodo(char c='\0', nodo* n=NULL);
};

struct coda {
    nodo *inizio;
    nodo *fine;
    
    coda(nodo* i=NULL, nodo* f=NULL);
};

void push(char c, coda &Q);
char pop(coda &Q);
bool e_vuota(coda Q);
