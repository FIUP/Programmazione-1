#include<iostream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a =0, nodo* b=0){info=a; next=b;}};
struct doppioN{nodo*inizio,* fine; int lung; doppioN(nodo* a =0, nodo* b=0, int c=0){inizio=a; fine=b;lung=c;}};


nodo* build(int n)
{
  if(n>0)
    {
      int x;
      cin>>x;
      return new nodo(x,build(n-1));
      }
  else
    return 0;
}
void stampa_DN(doppioN A)
{
  cout<<"valore DN:"<<A.inizio->info<<' '<<A.fine->info<<" lung="<<A.lung<<endl;

}
void stampaL(nodo*L)
{
  if(L)
    {
      cout<<L->info<<' ';
      stampaL(L->next);
    }
  else
    cout<<endl;

}
nodo*clone(nodo*L)
{
  if(L)
    return new nodo(L->info,clone(L->next));
  else
    return 0;
}

// PRE = (lista(L) corretta)
doppioN Fiter(nodo* L){
    
    if (!L)
        return doppioN();
    
    // L non è vuota
    doppioN listamax = doppioN(L,L,1);    
    while (L != NULL){ 
        // R = (lista(L) corretta) && (listamax descrive la sottolista crescente di massima lunghezza di lista(vL) fino a nodo(L) escluso)
        doppioN listatemp = doppioN(L,L,1);     // la sottolista che inizia da nodo(L) e finisce a nodo(L) è di lunghezza 1 
        while (listatemp.fine->next && listatemp.fine->info <= listatemp.fine->next->info){
            listatemp.fine = listatemp.fine->next;
            listatemp.lung++;
        }
        
        if (listatemp.lung > listamax.lung)
            listamax = listatemp;
        
        L = listatemp.fine->next;
        
    }
    return listamax;   
}
// POST = (restituisce il valore doppioN che rappresenta la sottolista crescente di lunghezza massima di L)

// PRE = (lista(L) corretta e non vuota)
doppioN Aux(nodo*L){
    if (!L->next)
        return doppioN(L,L,1);
    // L ha almeno due elementi
    if (L->next->info < L->info)
        return doppioN(L,L,1);
        
    // L ha almeno due elementi e nodo(L->next) >= nodo(L) 
    
    // PRE_ric = (lista(L->next) corretta e non vuota)
    doppioN lista_succ = Aux(L->next);
    // POST_ric = (restituisce il valore doppioN che rappresenta la sottolista di L->next crescente di lunghezza massima che inizia col primo nodo di L->next)
    
    return doppioN(L,lista_succ.fine,lista_succ.lung+1);
    
}
// POST = (restituisce il valore doppioN che rappresenta la sottolista di L crescente di lunghezza massima che inizia col primo nodo di L)

/*******************************************************************************
DIMOSTRAZIONE

Casi base:
    - Se lista(L->next) e' vuota, allora la sottolista crescente di maggior 
      lunghezza che parte da L e' quella che contiene solo L (la cui lunghezza e' uguale a 1).
      Viene restituito, dunque, doppioN(L,L,1) -> POST
    - Altrimenti lista(L) ha almeno due elementi. Se nodo(L->next) < nodo(L), 
      allora la sottolista crescente di maggior lunghezza che parte da L e' 
      quella che contiene solo nodo(L). Viene restituito doppioN(L,L,1) -> POST

Caso induttivo:
    Una volta esclusi i casi base, sappiamo che lista(L) ha almeno due elementi
    (e quindi lista(L->next) e' non vuota) e nodo(L) <= nodo(L->next). 
    Vale, percio', PRE_ric. lista_succ, secondo POST_ric, descrive la sottolista 
    crescente di maggior lunghezza che parte da L->next. 
    Dato che nodo(L) <= nodo(L->next), la sottolista crescente di maggior 
    lunghezza che parte da L e' proprio L @ lista_ succ. Viene restituito, infatti, 
    doppioN(L,lista_succ.fine,lista_succ.lung+1) -> POST

*******************************************************************************/

// PRE = (lista(L) corretta)
doppioN Frec(nodo* L){
    if (!L)
        return doppioN();
        
    // L non è vuota
    doppioN lista1 = Aux(L);
    
    // PRE_ric = (lista(lista1.fine->next) corretta)
    doppioN lista2 = Frec(lista1.fine->next);
    // POST_ric = (restituisce il valore doppioN che rappresenta la sottolista crescente di lunghezza massima di lista1.fine->next)
    
    if (lista1.lung < lista2.lung)
        return lista2;
    else
        return lista1;
    
    }
// POST = (restituisce il valore doppioN che rappresenta la sottolista crescente di lunghezza massima di L)

/*******************************************************************************
DIMOSTRAZIONE
Caso base:
    Se lista(L) e' vuota, allora l'unico doppioN valido e' doppioN(0,0,0).
    Viene restituito doppioN() -> POST

Caso induttivo: 
    Lista(L) non e' vuota. Secondo la POST di Aux, lista1 e' un doppioN che
    descrive la sottolista crescente di massima lunghezza a partire da nodo(L).
    Quindi, esiste nodo(lista1.fine), ovvero lista(lista1.fine) e' non vuotaì.
    Cio' implica che lista(lista1.fine->next) e' corretta. Vale, dunque, PRE_ric.
    Secondo la POST_ric lista2 e' un doppioN  che descrive la sottolista crescente
    di massima lunghezza di lista(lista1.fine->next).
    Infine, viene restituita la piu' lunga tra lista1 e lista 2. -> POST

*******************************************************************************/

// PRE = (lista(L) corretta, A di tipo doppioN individua una sotto lista di L, vL=L)
nodo* Giter(nodo*& L, doppioN A){
    nodo* start = L;
    nodo* prec = NULL;
    while (start != A.inizio){
        prec = start;
        start = start->next;
    }
    if (prec)
        prec->next = A.fine->next;
    else
        L = A.fine->next;
    
    A.fine->next = NULL;
    return A.inizio;
}
// POST = (Giter restituisce col return la sottolista di vL individuata da A e il valore di L diventa vL senza la sottolista restituita col return)


// PRE = (lista(L) corretta, A di tipo doppioN individua una sottolista di L, vL=L)
nodo* Grec(nodo*& L, doppioN A){
        
    if (!L)
        return NULL;
    
    if (L == A.inizio){
        L = A.fine->next;
        A.fine->next = NULL;
        return A.inizio;  
    }
    
    if (L->next == A.inizio){
        L->next = A.fine->next;
        A.fine->next = NULL;
        return A.inizio;   
    }
    
    // L->next != A.inizio
    
   return Grec(L->next, A);
    
}
// POST = (Grec restituisce col return la sottolista di vL individuata da A e il valore di L diventa vL senza la sottolista restituita col return)

main()
{
  int n;
  cin>>  n;
  cout<<"start"<<endl;
  nodo*L=build(n);
  stampaL(L);
  
  nodo* L1=clone(L);
  doppioN A=Fiter(L);//da fare
  doppioN B=Frec(L1);//da fare
  stampa_DN(A);
  stampa_DN(B);
  nodo*K=Giter(L,A);//da fare
  nodo*K1=Grec(L1,B); //da fare
  stampaL(K);
  stampaL(L);
  stampaL(K1);
  stampaL(L1);
  cout<<"end"<<endl;
}
