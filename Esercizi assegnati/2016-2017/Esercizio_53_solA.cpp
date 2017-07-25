// soluzione di B.Cosentino
#include<iostream>
using namespace std;


struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};



nodo* crea(int dim)
{
 if(dim)
  {
    int x;
    cin>>x;
    return new nodo(x,crea(dim-1));
  }
 return 0;
}

void stampa(nodo*L)
{
  if(L)
  {
    cout<<L->info<<' ';
    stampa(L->next);
  }
 else
    cout<<endl;
}

void leggi(int dim, int*P)
{
  if(dim)
   {
    cin>>*P;
    leggi(dim-1,P+1);
   }

}


// PRE=(L(T) è corretta, dimP>0, P ha dimP elementi definiti)
nodo* match (nodo* & T, int * P, int dimP){
    
    if (!T)
        return 0;
    
    if (T->info == *P){
        if (dimP==1){
            nodo *s=T;  // creo un puntatore al nodo
            T=T->next;  // collego vT->next al nodo successivo
            s->next=0;  // s = nodo(vT->info) @ 0
            return s;
        }
        
        // dimP >= 2
        
        // PRE_ric1 = (L(T->next) è corretta, dimP-1>0, P+1 ha dimP-1 elementi definiti)
        nodo* x = match(T->next, P+1, dimP-1);
        // POST_ric1 = (c’è un match in L(T->next) -> la funzione restituisce la lista del match e T->next = lista restante) & 
        //      & (non esiste match -> restituisce 0 col return e T->next = vT->next)
        if(x){
            nodo *s=T;  // creo un puntatore al nodo
            T=T->next;  // collego vT->next al nodo successivo
            s->next=x;  // s = nodo(vT->info) @ x = match(T->next, P+1, dimP-1)
            return s;   
        } else
            return 0;
        
    } else 
        // PRE_ric2 = (L(T->next) è corretta, dimP>0, P ha dimP elementi definiti)
        return match(T->next, P, dimP);
        // POST_ric2 = (c’è un match in L(T->next) -> la funzione restituisce la lista del match e T->next = lista restante) & 
        //      & (non esiste match -> restituisce 0 col return e T->next = vT->next)
}
//POST=(c’è un match -> la funzione restituisce la lista del match e T = lista restante) & 
//      & (non esiste match -> restituisce 0 col return e T = vT)

/*******************************************************************************
Dimostrazione

Casi base:
    1) Dalla PRE so che dimP > 0. Quindi, se la lista e' vuota (e non puo' esserci 
        match di un pattern lungo almeno 1), restituisco 0. 
    
    2) Dalla PRE so che dimP > 0 -> dimP >= 1. Se dimP = 1 e T->info == *P, allora
        ho trovato il pattern ed e' il primo nodo di T. Quindi, nodo* s punta a T
        e faccio iniziare la lista T dal successivo elemento.
        Infine, s->next = 0 -> s = vT - vT->next = nodo(vT->info).
        s e' il match e viene restituito mentre T adesso e' la lista senza il pattern.
        
Casi induttivi:
    
    Dalla PRE si apprende che la lista T non e' vuota.
    1) Se T->info == *P e dimP >= 2. 
        T non vuota -> esiste T->next lista corretta
        dimP >= 2 -> dimP-1 >=1 -> dimP-1 > 0 -> P+1 ha dimP-1 elementi definiti.
        Quindi, vale PRE_ric1
        <x = match(T->next, P+1, dimP-1)> e vale POST_ric1
        2 sottocasi:
            # Se c'e' match in L(T->next) x = lista del match e T->next e' la lista restante.
                Quindi, inizializzo s = nodo(T) e faccio iniziare la lista T da T->next che e' 
                la lista restante. Infine, s = nodo(T) @ x, ovvero concateno la lista del
                match e la restituisco.
                Ricapitolando, T = lista restante e s = lista del match <return s> POST.
                
            # Se non c'e' match in L(T->next) (e quindi non c'e' neanche in L(T)), x = 0 
                e T->next = vT->next -> T = nodo(T) @ T->next = nodo(T) @ vT->next = vT (T = vT)
                e restituisco 0 -> POST

    
    2) Se T->info != *P allora cerco il pattern a partire da T->next. 
        L(T) non vuota -> L(T->next) e' una lista corretta. dimP > 0 e P ha dimP elementi
        definiti -> PRE_ric2 <match(T->next, P, dimP)> POST_ric2.
        Se esiste un match in L(T->next) -> esiste un match in L(T) e lo restituisce.
        T->next = lista restante -> T = nodo(T) @ T->next -> T= lista restante ->
        -> POST
        Se non esiste un match in L(T->next) -> non esiste neanche in L(T) e restituisce 0.
        T->next = vT->next. T = nodo(T) @ T->next = nodo(T) @ vT->next = vT -> POST
        
*******************************************************************************/


main()
{
  int dim, dimP;
  int P[20];
  cin>>dim;
  nodo* L1=crea(dim);
  cin>>dimP;
  leggi(dimP, P);
  cout<<"start"<<endl;
  nodo* L2 = match(L1,P, dimP);
  if(L2)
    stampa(L2);
  else
    cout<<"Lista del match vuota"<<endl;
   if(L1)
     stampa(L1);
   else
     cout<<"Lista restante vuota"<<endl;
   cout<<"end"<<endl;
}
