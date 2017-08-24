#include <iostream>
#include "code.h"

using namespace std;


// PRE = Q e' una coda non vuota, Q.inizio = nodo(0) @ nodo(1) @ ... @ nodo(n) e Q.fine = nodo(n), count >= 1
void elim(int count, coda &Q){
    
    if (count==1){  // allora Q.inizio = nodo(count-1) @ L = nodo(0) @ L
        
        cout << pop(Q) << " eliminata" << endl;
        
    } else {    // count >= 2    
    
        push(pop(Q),Q);     // elimino dall'inizio di Q nodo(0) e lo rimetto in coda a Q
        
        //Q.inizio = vQ.inizio->next @ nodo(pop(Q)) e Q.fine = new nodo(pop(Q), 0)
        
        // PRE_ric = Q e' una coda non vuota, Q.inizio = nodo(1) @ ... @ nodo(n) @ nodo(0) e Q.fine = nodo(0), count-1 >= 1
        elim(count-1, Q);
        // POST_ric = Stampa nodo(count-2) e Q.inizio = nodo(count-1) @ nodo (count) @ ... @ nodo(n) @ nodo(0) @ ... @ nodo(count-3)
    }
}
// POST = Stampa nodo(count-1) e Q.inizio = nodo(count) @ nodo (count+1) @ ... @ nodo(n) @ nodo(0) @ ... @ nodo(count-2)
 
/*******************************************************************************
Dimostrazione

Caso base:
    Q.inizio = nodo(0) @ L = nodo(1-1) @ L = nodo(count-1) @ L. 
    Se count == 1 la persona da eliminare e' in prima posizione. 
    Stampo la chiave di nodo(0) e la elimino usando pop -> 
    -> Q.inizio = nodo(1) @ nodo(2) ... @ nodo(n) -> POST
    
Caso induttivo:
    Se count != 1 -> count >= 2 -> la persona da eliminare si trova in una posizione
    successiva alla prima.
    So dalla PRE che Q.inizio = nodo(0) @ nodo(1) @ ... @ nodo(n) e Q.fine = nodo(n)
    Sposto il nodo in prima posizione e la metto alla fine.
    Q.inizio = nodo(1) @ ... @ nodo(n) @ nodo(0) e Q.fine = nodo(0) e il nodo da 
    eliminare si trovera' in posizione count-2.
    count >= 2 -> count-1 >= 1. Q e' una coda non vuota poiche' non ho tolto niente.
    Q e' una coda non vuota, Q.inizio = nodo(1) @ ... @ nodo(n) @ nodo(0) e 
    Q.fine = nodo(0), count-1 >= 1 -> PRE_ric -> POST_ric -> 
    -> Q.inizio = nodo(count-1) @ nodo (count) @ ... @ nodo(n) @ nodo(0) @ ... @ nodo(count-3) ->
    -> Q.inizio = vQ.inizio = nodo(count) @ nodo (count+1) @ ... @ nodo(n) @ nodo(0) @ ... @ nodo(count-2) ->
    -> POST
*******************************************************************************/

// PRE = n>=1, k>=1 e Q e' una coda non vuota con n elementi
void gius(int n, int k, coda &Q){
    
    if (n>1){
        
        elim(k,Q); // elimina il nodo(k-1) e lo stampa
        // PRE_ric = n-1 >= 1, k >= 1 e Q e' una coda non vuota con n-1 elementi
        gius(n-1,k,Q); 
        // POST_ric = elimina n-2 nodi, uno ogni k posizioni e Q e' una coda con un solo elemento
    }
}
// POST = elimina n-1 nodi, uno ogni k posizioni, e Q e' una coda con un solo elemento

/*******************************************************************************
Dimostrazione
Caso base:
    Se n==1, allora la coda contiene 1 solo elemento ed e' il sopravvissuto -> 
    -> elimino 0 nodi -> Q ha un solo elemento -> POST

Caso induttivo:
    Se n>1, allora n>=2 -> n-1 >= 1. k >= 1. Vale la PRE di elim() -> 
    -> POST di elim() = stampa nodo(k-1) e Q.inizio = nodo(k) @ nodo(k+1) @ nodo(n) @ 
        @ nodo(0) @...@nodo(k-2) -> Q ha n-1 elementi (ed e' non vuoto) e inizia da nodo(k)
    n-1 >= 1, k >= 1 e Q e' una coda non vuota di n-1 elementi -> PRE_ric -> POST_ric ->
    -> vengono eliminati n-2 elementi ogni k posizioni piu' quello eliminato in posizione k da elim() e 
    Q ha un solo elemento -> sono stati eliminati n-1 elementi ogni k posizioni e 
    Q ha un solo elemento -> POST
*******************************************************************************/


int main() 
{
    coda Q;
    
    int n,k;
    cin >> n >> k;
    
    cout << "start" << endl;
    
    int count=1;
    
    for (int i=0; i<n; i++)
        push(i,Q);
    
    /*
    while (n>1){
        
        elim(k, Q);
        n--;
    }
    */
    
    gius(n,k,Q);
    
    cout << Q.inizio->chiave << " sopravvive";
    
    cout << endl << "end" << endl;
}