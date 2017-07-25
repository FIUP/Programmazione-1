#include<iostream>

#include "code.h"


nodo::nodo(int c, nodo* n){
    chiave = c; next = n;
}

coda::coda(nodo* i, nodo* f){
    inizio = i; fine = f;
}

void push(int c, coda &Q){
    
    if (!Q.inizio){
        Q.inizio = new nodo(c,0);
        Q.fine = Q.inizio;
    } else {
        Q.fine->next = new nodo(c,0);
        Q.fine = Q.fine->next;
    }
}

int pop(coda &Q){
    
    int key = (Q.inizio)->chiave;
    
    //come faccio a deallocare il vecchio Q->inizio?
    nodo* del = Q.inizio;
    
    Q.inizio = (Q.inizio)->next;
    
    delete del;
    
    if (!Q.inizio) Q.fine=NULL;
    
    return key;
}

bool e_vuota(coda Q){
    return (!Q.inizio);
}