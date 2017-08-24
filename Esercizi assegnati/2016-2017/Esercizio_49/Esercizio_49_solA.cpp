// soluzione di B.Cosentino
#include <iostream>

using namespace std;

struct nodo {
    int chiave;
    nodo *next;
    nodo(int a=-1, nodo* b=NULL){
        chiave=a;
        next=b;
    }
};

// PRE = (L è una lista ordinata in modo crescente)
nodo* inserisci_in_ordine(int k, nodo *L){
   
    if (!L) // se L e' vuota inserisco un nuovo nodo
        return new nodo(k,NULL);
    
    // L e' non vuota
    
    if (k<(L->chiave)){ // se k e' minore di L costruisco il nodo k e pongo L come suo successivo. Infine, collego il precedente nodo a k
        //L = new nodo(k,L);
        //return L; // restituisco la lista aggiornata
        return new nodo(k,L);
    
    }
    
    // k >= L->chiave
    // vado al nodo successivo che avra' campo chiave maggiore o uguale al campo chiave del nodo attuale poiche' L e' ordinata
    
    // PRE_ric = (L->next è una lista ordinata in modo crescente)
    L->next = inserisci_in_ordine(k,L->next);  // se k >= L->chiave allora inserisco k a partire dal nodo successivo (L->next)
    // POST_ric = (inserisce k in L->next mantenendo l'ordine e ritorna la lista aggiornata)
    
    return L;  // restituisco la lista aggiornata
    
    
}
// POST = (inserisce k in L mantenendo l'ordine e ritorna la lista aggiornata)

/*************************************************************************************
DIMOSTRAZIONE

Casi base:
    Caso 1
    L è una lista ordinata in modo crescente.
    Se L e' vuota, allora inserisco il primo nodo (return new nodo(k,NULL) -> POST
    
    Caso 2
    L è una lista ordinata in modo crescente non vuota. Se k < L->chiave, cioe' del primo
    elemento della lista, allora restituisco nodo(k) @ L, cioe' la lista aggiornata -> POST

Caso induttivo:
    L è una lista ordinata in modo crescente non vuota e k>=L->chiave ->
    -> L->next è una lista ordinata in modo crescente -> PRE_ric -> POST_ric ->
    -> L->next = nodo(k) @ vL->next con l'ordine mantenuto -> L e' la lista aggiornata -> POST

*************************************************************************************/

nodo* costr(nodo* L){
    int k;
    cin >> k;
    
    if (k==-1)
        return L;
    
    L = inserisci_in_ordine(k,L);
    
    return costr(L);
    
}

void stampa(nodo* x){
 	
 	if(x){
     	cout << x->chiave << ' ';
    	stampa(x->next);
 	}
}

int main() 
{
    cout << "start" << endl;

    nodo* L=NULL;
    /*
    int k;
    cin>>k;
    
    while (k!=-1){
        
        L=inserisci_in_ordine(k,L);
        cin >> k;
    }
    */
    L = costr(L);
    
    stampa(L);

    cout << endl << "end" << endl;
}
