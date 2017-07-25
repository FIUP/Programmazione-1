// soluzione di B.Cosentino
#include<iostream>
using namespace std;


struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};
struct doppialista{nodo* listamatch, * restante; doppialista(nodo*a=0, nodo* b=0){listamatch=a; restante=b;}};



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


// PRE = (L(T) è corretta, dimP>=0, P ha dimP elementi definiti)
doppialista* match2(nodo* T, int* P, int dimP){
    if(!dimP)
        return new doppialista(0,T);
    
    // dimP > 0
    if (!T)
        return 0;
    
    // dimP > 0 & L(T) e' non vuota  
    if (T->info == *P){  // devo giustapporre il nodo alla lista del match
        // PRE_ric1 = (L(T->next) è corretta, dimP-1>=0, P ha dimP elementi definiti)
        doppialista* D = match2(T->next, P+1, dimP-1);
        // POST_ric1 = (esiste match di P+1 in L(T->next) -> restituisce un puntatore a doppialista(listamatch(T->next), restante(T->next)))
        //              & (non esiste match di P+1 in L(T->next) -> restituisce 0 e L(T->next) resta inalterata)
        if (D){
            T->next = D->listamatch;
            D->listamatch = T;
            return D;
        }
        
        return 0;
    }
    
    // dimP > 0 & L(T) e' non vuota & T->info != *P
    
    // PRE_ric2 = (L(T->next) è corretta, dimP>=0, P ha dimP elementi definiti)
    doppialista* D = match2(T->next,P,dimP);
    // POST_ric2 = (esiste match di P in L(T->next) -> restituisce un puntatore a doppialista(listamatch(T->next), restante(T->next)))
    //              & (non esiste match di P in L(T->next) -> restituisce 0 e L(T->next) resta inalterata)
    
    if (D){ // devo giustapporre il nodo alla lista restante
        T->next = D->restante;
        D->restante = T;
        return D;
    }
    
    return 0;
}

// POST = (esiste match di P in L(T) -> match2 restituisce il puntatore X ad un valore di tipo doppialista
//    tale che X->listamatch sia la lista del match trovato e X->restante sia la lista restante) &
//    & (non esiste match in L(T) -> restituisce il puntatore 0 e L(T) resta inalterata)

/*******************************************************************************
Dimostrazione
Casi base:
    - Se dimP == 0 allora, esiste un match in albero(r) ed e' una lista vuota.
      La lista restante e' la lista originale (L(T)=vL(T)).
      Quindi, la funzione restituisce new doppialista(0,T) -> POST
      
    - So che dimP > 0. Se T e' vuoto, allora non esiste match. La funzione 
      restituisce 0 -> POST
      
Casi induttivi:
    - So che dimP > 0 e L(T) e' non vuota. Se T->info == *P cerco un match di P+1 
      a partire da T->next. 
      L(T) non vuota -> esiste L(T->next) corretta
      dimP > 0 -> dimP >= 1 -> dimP-1 >= 0
      P ha dimP elementi definiti -> P+1 ha dimP-1 elementi definiti.
      Quindi, vale PRE_ric1.
      Quindi, PRE_ric1 <match2> POST_ric1 e D e' un puntatore a un doppialista 
      opportuno se esiste match, altrimenti D = 0.
      
      2 casi:
        # Se D = 0 (ovvero se non esiste match di P+1 a partire da nodo(T->next), 
          allora la funzione restituisce 0 -> POST
        # Se D != 0, D = {L(listamatch(T->next)), L(restante(T->next))},  
          allora effettuo la concatenazione nodo(T) @ L(listamatch(T->next)), 
          dato che nodo(T) appartiene al match, e impongo che la D->listamatch 
          punti a nodo(T), che e' l'inizio del match. 
          Dal momento che la nodo(T) appartiene al match, la lista restante
          e' la stessa di quella di T->next.
          Restituisco D -> POST
          
    - So che dimP > 0, L(T) e' non vuota e T->info != *P. Cerco un match di P a partire
      da T->next.
      L(T) non vuota -> esiste L(T->next) corretta
      dimP > 0 -> dimP >= 0
      P ha dimP elementi definiti
      Quindi, vale PRE_ric2. 
      Quindi, PRE_ric2 <match2> POST_ric2 e D e' un puntatore a un doppialista 
      opportuno se esiste match, altrimenti D = 0.
      
      2 casi:
        # Se D = 0 (ovvero se non esiste match di P a partire da nodo(T->next), 
          allora la funzione restituisce 0 -> POST
        # Se D != 0, D = {L(listamatch(T->next)), L(restante(T->next))}, allora 
          effettuo la concatenazione nodo(T) @ L(restante(T->next)), dato che
          nodo(T) non appartiene al match, e impongo che D->restante punti a 
          nodo(T), che e' l'inizio della lista restante.
          Dal momento che la nodo(T) appartiene alla lista restante, il match e'
          lo stesso di quello di T->next.
          Restituisco D -> POST.
*******************************************************************************/


main()
{
   int dim, dimP, P[20];
   cin>>dim;
   
   nodo* L1=crea(dim);
   
   cin>>dimP;
   leggi(dimP, P);
   
   cout<<"start"<<endl;
   
   doppialista* D = match2(L1,P, dimP); //da fare
   
    if(!D){
        cout<<"no match"<<endl;
        cout<<"Lista T e':";
        stampa(L1);
    } else {
        stampa(D->listamatch);
        if(D->restante)
            stampa(D->restante);
        else
            cout<<"Lista restante vuota"<<endl;
    }
    cout<<"end"<<endl;
}


