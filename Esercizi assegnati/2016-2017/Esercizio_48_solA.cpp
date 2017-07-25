// soluzione di B.Cosentino
#include <iostream>

using namespace std;

struct nodo {
    int chiave;
    nodo *next;
    nodo(int a=0, nodo* b=0){
        chiave=a; next=b;
    }
};

nodo* costr_lista(){
    
    int key;  // leggo il valore chiave
    cin>>key;
    
    if (key==-1){ // se e' il valore chiave e' -1 la lista ha un solo nodo (-1,NULL)
        return new nodo(key,0);
    } 
    
    nodo* n = new nodo(key);
    n->next = costr_lista(); // inserisco alla fine di L il nodo
    
    return n;
    
    // return new nodo(key, costr_lista());
}


// PRE = (L = L_0, L_1, ... è una lista di interi)
int cerca(int k, nodo *L){
    
    if (L->chiave==-1)  // se la lista contiene solo -1
        return -1;
        
    if (L->chiave==k)
        return 0;
    
    
    // PRE_ric = (L->next = L_1, ... è una lista di interi)
    int x=cerca(k,L->next);
    // POST_ric = (ritorna il più piccolo indice i in L->next tale che L_i.chiave == k, oppure -1 se non esiste)
    if (x==-1) return -1;
    
    return x+1;
};
// POST = (ritorna il più piccolo indice i tale che L_i.chiave == k, oppure -1 se non esiste)

/******************************************************
DIMOSTRAZIONE

Casi base:
    Caso 1
    L = L_0, L_1, ... è una lista di interi. Se L->chiave=L_0.chiave=-1 la lista contiene solo -1 e restituisco -1.
    
    Caso 2
    L = L_0, L_1, ... è una lista di interi con almeno due elementi. Se L->chiave=L_0.chiave=k allora 
    restituisco la posizione di L_0, cioe' 0 -> POST
    
Caso induttivo:
    L = L_0, L_1, ... è una lista di interi con almeno due elementi e k non e' in L_0->
    -> L->next = L_1, ... è una lista di interi -> PRE_ric -> POST_ric ->
    -> x = il più piccolo indice i in L->next tale che L_i.chiave == k, oppure -1 se non esiste
    
    Caso 1
    Se x==-1 allora non esiste L_i.chiave == k in L->next e, sapendo che L_0.chiave != k ->
    -> non esiste L_i.chiave in L -> si restituisce -1
    
    Caso 2 
    Se x!=-1 -> x = il più piccolo indice i in L->next tale che L_i.chiave == k.
    x = il più piccolo indice i in L->next tale che L_i.chiave == k ->
    -> x+1 = il più piccolo indice i in L tale che L_i.chiave == k ->
    -> si restituisce x+1;

******************************************************/


int main() 
{
    cout << "start" << endl;
    nodo* L= costr_lista();

    int val;
    cin >> val;
    
    int pos=cerca(val, L);

    if (pos==-1)
        cout << "Il valore " << val << " non si trova nella lista" << endl;
    else
        cout << "Il valore " << val << " si trova in posizione " << pos << endl;
    
    cout << "end" << endl;
}
