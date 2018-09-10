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