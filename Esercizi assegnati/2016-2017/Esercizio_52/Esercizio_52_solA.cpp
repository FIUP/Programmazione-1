#include<iostream>
using namespace std;
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};
nodo* crea(int dim) {
    if(dim) {
        int x;
        cin>>x;
        return new nodo(x,crea(dim-1));
    }
    return 0;
}

void leggi(int dim, int*P) {
    if(dim){
        cin>>*P;
        leggi(dim-1,P+1);
    }
}

// PRE = L(n) e' una lista corretta, P e' un array e dimP la sua dimensioni, ok == true 
nodo* pattern(nodo* &n, int P[], int dimP, bool &ok){
    
    if (!dimP)  // se il pattern e' vuoto esiste un match e non devo fare niente
        return 0;
    
    // dimP >= 1
    if (!n){    // se la lista e' vuota (e il pattern no), allora non esiste match
        ok=false;  // segnalo che non c'e' match
        return 0;
    }
    
    // dimP >= 1 & n non e' vuota
    if (n->info != *P){     // se n->info!= P[0] allora non c'e' match
        ok=false;   // segnalo che non c'e' match
        return 0;
    }
    
    // dimP >= 1 & n non e' vuota & n->info == *P
    nodo *x = pattern(n->next,P+1,dimP-1,ok);   // x sara' il match in caso esista, altrimenti sara' 0;
    if (ok){
        
        nodo* s = n;
        n = n->next;
        s->next = x;
        
        return s;
    } else  // se il pattern non esiste
        return 0;
}
// POST = (ok == true sse esiste il match a partire da n) & 
//        & (ok == true -> restituisce la lista del match a partire da n e L(n) e' la lista restante) &
//        & (ok == false -> restituisce 0 e L(n) resta immutata).


// PRE=(L(n) è una lista corretta, P ha dimP elementi, chiamiamo vL(n)=L(n))
nodo* match (nodo* &n, int P[], int dimP){
    
    if (!n)
        return 0;
    
    bool ok = true;
    
    // ok == true, n e' non vuota
    nodo* M = pattern(n,P,dimP,ok);
    
    if (ok)  // se esiste P in n
        return M;
    else // se non esiste P in n
        // PRE_ric = (L(n->next) è una lista corretta, P ha dimP elementi)
        return match(n->next,P,dimP);
        // POST_ric = (c’è un match di P in L(n->next) -> la funzione restituisce col return match(vL(n->next),P[0..dimP-1]) e L(n->next)=resto_match(vL(n->next),P[0..dimP-1])) & 
//      & (non c’è il match L(n->next) -> la funzione restituisce 0 e L(n->next)=vL(n->next))
}

// POST=(c’è un match di P in L(n) -> la funzione restituisce col return match(vL(n),P[0..dimP-1]) e L(n)=resto_match(vL(n),P[0..dimP-1])) & 
//      & (non c’è il match in L(n) -> la funzione restituisce 0 e L(n)=vL(n))

/*******************************************************************************
Dimostrazione

Caso base:
    Se L(n) e' una lista vuota, non c'e' match e restituisce 0. L(n) = vL(n) -> POST
    
Caso induttivo:
    Viene inizializzato bool ok=true.
    La PRE di pattern e' verificata: infatti, dalla PRE di match sappiamo che 
    L(n) è una lista corretta, P ha dimP elementi -> 
    ->  L(n) e' una lista corretta, P e' un array e dimP la sua dimensione, ok == true ->
    -> PRE di pattern <pattern> POST di pattern
    -> (ok == true sse esiste il match a partire da n) & 
        & (ok == true -> M = lista del match a partire da n e L(n) e' la lista restante) &
        & (ok == false -> M = 0 e L(n) resta immutata).
    
    2 casi:
        1) se ok == true -> M = lista del match a partire da n e L(n) e' la lista restante.
            Restituisco M -> POST
        2) se ok == false -> M = 0 e L(n) resta immutata e non esiste match a partire da n.
            Cerco a partire da n->next.
            Sappiamo da PRE che L(n) e' una lista non vuota per cui L(n->next) esiste ed e' corretta.
            Inoltre, P ha ancora dimP elementi -> PRE_ric <match(n->next,P,dimP)> POST_ric.
            
            2 sottocasi:
                # Se c'e' un match in L(n->next) allora c'e' anche in L(n) e viene restituito 
                  con L(n->next) = resto_match(vL(n->next),P[0..dimP-1])). L(n) = nodo(n) @ L(n->next) ->
                  -> L(n) = resto_match(vL(n),P[0..dimP-1])) -> POST
                
                # Se non c'e' un match in L(n->next) allora non c'e' neanche in L(n). 
                  Quindi, la funzione restituisce 0 e L(n->next) = vL(n->next)
                  L(n) = nodo(n) @ L(n->next) = nodo(n) @ vL(n->next) = vL(n) -> POST
                
*******************************************************************************/
void stampa (nodo * L){
    if (L){
        cout << L->info << " ";
        stampa(L->next);
    }
}


main(){
    int dim, dimP, P[20];
    
    cout<<"start"<<endl;
    cin>>dim;
    
    nodo* L1 = crea(dim);
   
    cin>>dimP;
    leggi(dimP, P);
   
    nodo* L2 = match(L1,P, dimP);//da fare
    
    stampa(L2); //da fare
    cout << endl;
    stampa(L1);
    
    
    cout << endl <<"end"<<endl;
}
