// soluzione di B.Cosentino
#include<iostream>

#include "code.h"

// PRE = N e' un nodo con campi non definiti.
nodo::nodo(char c, nodo* n){
    chiave = c; next = n;
}
// POST = N e' un nodo con campi definiti.


// PRE = N e' una coda con campi non definiti.
coda::coda(nodo* i, nodo* f){
    inizio=i; fine=f;
}
// POST = N e' una coda con campi definiti.



// PRE = c e' un carattere, Q e' una coda
void push(char c, coda &Q){
    
    if (!Q.inizio){
        Q.inizio=new nodo(c,0);
        Q.fine=Q.inizio;
    } else {
        Q.fine->next=new nodo(c,0);
        Q.fine=Q.fine->next;
    }
}
// POST = Q = vQ @ nodo(c) e' una coda 

/*******************************************************************************
Dimostrazione

Q e' vuota sse Q.inizio=0 -> Q.fine=0. Se Q.inizio=0 allora Q.inizio @ nodo(c) = nodo(c) e Q.fine=nodo(c) -> POST

Se Q non e' vuota Q.inizio = L @ Q.fine, dove L e' una lista. Quindi, Q.fine= vQ.fine @ nodo(c) -> 
-> Q.inizio = L @ Q.fine = L @ vQ.fine @ nodo(c) -> Q.inizio = vQ.inizio @ nodo(c).
Infine, assegno Q.fine = Q.fine->next. Quindi, Q.fine punta a nodo(c) che e' l'ultimo elemento della coda.
Quindi, Q = {Q.inizio = vQ.inizio @ nodo(c), Q.fine = nodo(c)}.
Q = vQ @ nodo(c) e' una coda. -> POST
*******************************************************************************/


// PRE = Q e' una coda non vuota (Q.inizio = nodo(k) @ L)
char pop(coda &Q){
    
    char key=(Q.inizio)->chiave;
    
    nodo* del=Q.inizio;
    
    Q.inizio=(Q.inizio)->next;
    
    if (!Q.inizio) Q.fine=NULL; // se la coda diventa vuota
    
    delete del;

    return key;
}
// POST = restituisce la chiave del primo elemento della coda Q [nodo(k)] ed elimina il nodo corrispondente

/*******************************************************************************
Dimostrazione

PRE -> Q.inizio = nodo(k) @ L. Quindi, key = k e del = nodo(k). 
Assegno Q.inizio = L.
    1) Se L e' una lista vuota allora pongo Q.fine = NULL e avro' Q.inizio = Q.fine = NULL = coda vuota.
    2) Se L e' una lista non vuota Q.fine continua a puntare alla fine della lista L.

Dealloco nodo(k). Restituisco key = k = chiave di nodo(k).

Quindi, Q.inizio = L, Q.fine punta alla fine della lista e ho restituito key = k -> POST
*******************************************************************************/


// PRE = Q e' una coda
bool e_vuota(coda Q){
    return (!Q.inizio);
}
// POST = restituisce true sse Q e' vuota

/*******************************************************************************
Dimostrazione
Q e' vuota sse Q.inizio e' una lista vuota. 
Q vuota -> Q.inizio vuota -> Q.inizio == 0 == false -> restituisco !Q.inizio == true -> POST
Q non vuota -> Q.inizio non vuota -> Q.inizio == true -> restituisco !Q.inizio == false -> POST
*******************************************************************************/
