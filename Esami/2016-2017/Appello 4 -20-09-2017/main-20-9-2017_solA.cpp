// Soluzione di B. Cosentino
#include<iostream>
using namespace std;

struct nodo{int num, info; nodo* next; nodo(int a=0,int b=0, nodo* c=0){num=a; info=b; next=c;}}; // nodo di lista 
struct FIFO{nodo* primo, *ultimo; FIFO(nodo*a=0, nodo*b=0){primo=a; ultimo=b;}};
struct nodoF{FIFO info; nodoF*next; nodoF(FIFO a=FIFO(),nodoF*b=0){info=a; next=b;}}; //nodo di lista con FIFO

FIFO push_end(FIFO a, nodo*b){
    b->next=0;
    if(!a.primo){
        a.primo=a.ultimo=b;
    } else {
        a.ultimo->next=b; 
        a.ultimo=b;
    }
    return a;
}

FIFO push_begin(FIFO a, nodo* b){
    if(!a.primo){
        a.primo=a.ultimo=b; 
        b->next=0; 
        return a;
    } else {
        b->next=a.primo;
        a.primo=b;
        return a;
    }
}

void stampa_L(nodo*L){
    if (L){
        cout<<'['<<L->num<<','<<L->info<<']'<<' '; 
        stampa_L(L->next);
    } else
        cout<<endl;
}

void stampa_F(nodoF* x){
    if(x){
        stampa_L(x->info.primo);
        cout<<endl;
        stampa_F(x->next);
    }
}

nodo* costruisci(int n, int dim){
    if(dim){
        int x; 
        cin>>x; 
        return new nodo(n,x,costruisci(n+1,dim-1));
    }
    return 0;
}

nodo* clone(nodo*a){
    if(a){
        return new nodo(a->num, a->info, clone(a->next));
    }
    return 0;
}
 
// PRE = (lista(L) corretta, vL=L, x e' il campo info dei nodi da eliminare)
FIFO eliminaR(nodo*&L, int x){
    
    if (!L)
        return FIFO();
        
    // L e' non vuota
    FIFO tolti = eliminaR(L->next, x);
    if (L->info == x){
        nodo* temp = L;
        L = L->next;
        tolti = push_begin(tolti, temp);
    }
    
    return tolti;
}
// POST = (L è vL da cui sono stati eliminati tutti i nodi con info=x) && 
// && (viene restituito un valore FIFO che gestisce la lista dei nodi tolti 
// nello stesso ordine che hanno in vL) 


// PRE = (lista(Q) è corretta e ordinata rispetto ai campi info delle liste gestite dai suoi nodi, x gestisce una lista non vuota)
nodoF* insR(nodoF* Q, FIFO x){
    
    // A && B = 0 && ? = 0
    // A || B = 1 || ? 
    
    
    if (!Q || x.primo->info < Q->info.primo->info)
        return new nodoF(x,Q);
        
    // Q e' non vuota e x.primo->info > Q->info.primo->info
    Q->next = insR(Q->next, x);
    
    return Q;
}
// POST = (restituisce Q a cui è stato aggiunto un nodoF che contiene x in modo da mantenere l’ordine dei campi info delle liste gestite dai suoi nodi)


// PRE = (lista(L) è corretta, vL=L)
nodoF* tieni_primo_ric(nodo*& L){
    if (!L)
        return NULL;
        
    // L e' non vuota
    FIFO ripetuti = eliminaR(L->next,L->info);  // elimino dalla lista L i nodi con campi info uguali
    
    // PRE_ric = (lista(L->next) è corretta, vL->next=L->next)
    nodoF* lista_rip = tieni_primo_ric(L->next);    // cerco gli altri nodi ripetuti
    // POST = (L->next contiene tanti nodi quanti sono i diversi campi info di vL->next e per 
    // ogni campo info di vL->next contiene solo il primo nodo con quel valore di info) &&
    // && (la funzione restituisce col return una lista di nodi nodoF i cui nodi 
    // gestiscono i nodi ripetuti di vL->next nel modo spiegato nell’esempio)
    
    
    if (ripetuti.primo)
        return insR(lista_rip, ripetuti); // restituisco la lista nodoF con in nodi ripetuti aggiungengendo la FIFO ottenuta in maniera opportuna
    
    return lista_rip;
}
// POST = (L contiene tanti nodi quanti sono i diversi campi info di vL e per 
// ogni campo info di vL contiene solo il primo nodo con quel valore di info) &&
// && (la funzione restituisce col return una lista di nodi nodoF i cui nodi 
// gestiscono i nodi ripetuti di vL nel modo spiegato nell’esempio)

/*******************************************************************************
DIMOSTRAZIONE

Caso base:
    Se lista(L) e' vuota, allora la lista di nodoF sara' vuota (NULL) e lista(L) non  
    subisce variazioni -> POST

Caso induttivo:
    Escluso il caso base, sappiamo che Lista(L) e' non vuota. 
    ripetuti contiene una FIFO che gestisce i nodi tolti a partire da L->next.
    Quindi, lista(L) e' ancora non vuota e corretta. Vale la PRE_ric.
    Dopo l'invocazione ricorsiva, lista_rip e' una lista di nodoF opportuna per 
    lista(vL->next) e lista(vL->next) contiene nodi con campi info tutti diversi
    tra loro.
    Se ripetuti non e' vuota, allora bisogna restituire lista_rip con la FIFO 
    ripetuti inserita opportunamente -> POST
    Altrimenti, bisogna restituire solo lista_rip -> POST
*******************************************************************************/


// PRE = (lista(Q) è corretta e ordinata rispetto ai campi info delle liste gestite dai suoi nodi, x gestisce una lista non vuota)
nodoF* insI(nodoF*Q,FIFO x){
    
    if (!Q || Q->info.primo->info > x.primo->info)  // se Q e' vuota o se x deve essere inserita come primo elemento di Q
        return new nodoF(x,Q);
    
    // x va inserita a partire dal secondo posto in poi (con le assegnazioni evito un primo controllo sul primo elemento di Q)
    nodoF* start = Q;
    nodoF* prec = Q;
    Q = Q->next;
    
    
    // !(!Q || x.primo->info < Q->info.primo->info) = Q && x.primo->info > Q->info.primo->info
    while (Q && x.primo->info > Q->info.primo->info){
        prec = Q;
        Q = Q->next;
    }    
    // x.primo->info < Q->info.primo->info
    prec->next = new nodoF(x,Q);
        
    return start;
}
// POST = (restituisce Q a cui è stato aggiunto un nodoF che contiene x in modo da mantenere l’ordine dei campi info delle liste gestite dai suoi nodi)


// PRE = (lista(L) è corretta, vL=L)
nodoF* tieni_primo_iter(nodo*& L){
    
    nodo* start = L;
    nodoF* ripetuti = NULL;
    
    while (L) { 
    // R = (L e' una lista corretta) && (ripetuti e' la lista di nodi nodoF i cui nodi gestiscono i nodi ripetuti di vL da nodo(vL) a nodo(L) escluso) 
    // && (start contiene tanti nodi quanti sono i diversi campi info di vL fino a nodo(L) escluso e per ogni campo info di vL fino a nodo(L) escluso contiene solo il primo nodo con quel valore di info)
        FIFO rip = eliminaR(L->next, L->info);
        
        if (rip.primo)
            ripetuti = insI(ripetuti, rip);
        
        L = L->next;
    }
    
    L = start;
    return ripetuti;
}
// POST = (L contiene tanti nodi quanti sono i diversi campi info di vL e per 
// ogni campo info di vL contiene solo il primo nodo con quel valore di info) &&
// && (la funzione restituisce col return una lista di nodi nodoF i cui nodi 
// gestiscono i nodi ripetuti di vL nel modo spiegato nell’esempio)

main()
{
  int dim;
  cout<<"start"<<endl;
  cin>>dim;
  nodo*C=costruisci(0,dim);
  nodo* D=clone(C);
  cout<<"Lista costruita"<<endl;
  stampa_L(C);
  nodoF* a =tieni_primo_ric(C); //da fare
  cout<<"soluzione ricorsiva"<<endl<<"nodi tolti:"<<endl;
   
  stampa_F(a);
  cout<<"lista rimanente:"<<endl;
  stampa_L(C);
  nodoF* b=tieni_primo_iter(D); //da fare
  cout<<"soluzione iterativa"<<endl<<"nodi tolti:"<<endl;
  stampa_F(b);
  cout<<"lista rimanente:"<<endl;
  stampa_L(D);
  cout<<"end";
}
