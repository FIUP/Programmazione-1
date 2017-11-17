#include<iostream>
using namespace std;
struct nodo{int info; nodo* next; nodo(int a=0, nodo*b=0){info=a; next=b;}};
struct nodoD{int lascia,togli; nodoD* next; nodoD(int a=0, int b=0,  nodoD*c=0){lascia=a; togli=b;  next=c;}};
struct doppioN{nodo*  La, *To; doppioN(nodo*a=0,nodo*b=0){La=a; To=b;}};

nodo* build(int n)
{
  if(n)
    {
      int x;
      cin>>x;
      return new nodo(x,build(n-1));
    }
  return 0;
}
nodoD* buildD(int n)
{
  if(n)
    {
      int x,y;
      cin>>x>>y;
      return new nodoD(x,y,buildD(n-1));
    }
  return 0;
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
void stampaD(nodoD*L)
{
  if(L)
    {
      cout<<'['<<L->lascia<<','<<L->togli<<']'<<' ';
      stampaD(L->next);
    }
  else
    cout<<endl;
}

nodo* conc(nodo* L1, nodo* L2)
{
  if(!L1) return L2;
  if(!L2) return L1;
  nodo* x=L1;
  while(x->next)
    x=x->next;
  x->next=L2;
  return L1;
}

nodo*clone(nodo* L)
{
  if(!L) return 0;
  return new nodo(L->info,clone(L->next));
}
// inizio

// PRE = (Lista(L) è corretta, n>=0, vL=L)
nodo* taglia(nodo* &L, int n){
    if (!L) return NULL;
    if (!n) return NULL;
    
    nodo* tolti = L;
    nodo* fine = L;
    while (n>1 && fine->next){
        fine = fine->next;
        n--;
    }
    L = fine->next;
    fine->next = NULL;
    return tolti;
}
// POST = (la funzione restituisce col return i primi n nodi di vL se ci sono, 
//        altrimenti restituisce quello che c’è; L diventa quello che resta di vL 
//        una volta tolto il prefisso restituito col return)


// PRE = (Lista(L), Lista(D), Lista(lasciati) e Lista(tolti) sono corrette, vL=L, 
//      vlasciati=lasciati e vtolti=tolti)
void Fiter(nodo* L, nodoD* D, nodo*& lasciati, nodo*& tolti){
   
    while (D){ 
        // R = (lasciati e tolti sono vlasciati e vtolti a cui sono state appese 
        //     le liste ottenute da Lista(L) come indicato dai nodi di Lista(vD) 
        //     fino a nodo(D) escluso) && 
        //     && (Lista(D) e' una lista corretta)
        lasciati = conc(lasciati, taglia(L, D->lascia));
        tolti = conc(tolti, taglia(L, D->togli));
        
        D = D->next;
    }
    lasciati = conc(lasciati,L);
}
// POST = (lasciati e tolti sono vlasciati e vtolti a cui sono state appese le 
//          liste ottenute dallo smembramento di vL come indicato dai nodi di D)


nodo* concric(nodo* L1, nodo* L2){
    if (!L1) return L2;
    
    // L1 ha almeno un elemento
    L1->next = concric(L1->next,L2);
    return L1;
}

// PRE = (Lista(L) è corretta, n>=0, vL=L)
nodo* tagliaric(nodo* &L, int n){
    if (!L) return NULL;
    if (!n) return NULL;
    // lista(L) non vuota e n>0
    
    nodo* tolti = L; 
    L = L->next;
    // PRE_ric = (Lista(L) è corretta, n-1>=0, vL=L)
    tolti->next = tagliaric(L, n-1);
    // POST_ric = (la funzione restituisce col return i primi n nodi di vL se ci sono, 
    //        altrimenti restituisce quello che c’è; L diventa quello che resta di vL 
    //        una volta tolto il prefisso restituito col return)
    return tolti;
}
// POST = (la funzione restituisce col return i primi n nodi di vL se ci sono, 
//        altrimenti restituisce quello che c’è; L diventa quello che resta di vL 
//        una volta tolto il prefisso restituito col return)

/*******************************************************************************
DIMOSTRAZIONE

Casi base:
    - Se la lista e' vuota, allora non puo' esser tolto alcun nodo. 
      Per cui la funzione restituisce una lista vuota -> POST
    - Se n == 0, allora non bisogna togliere nodi a Lista(L) e, quindi, la
      funzione restituisce una lista vuota senza cambiare Lista(L)

Caso induttivo:
    Una volta esclusi i casi base, sappiamo che lista(L) e' non vuota e n>0.
    La lista dei nodi da togliere inizia da nodo(L) (lista(tolti) contiene nodo(L)) e 
    lista(L) = lista(vL) - lista(L) = lista(vL->next) che e' una lista corretta,
    poiche' lista(vL) era non vuota. Inoltre, n>0 -> n>=1 --> n-1 >= 0.
    Vale PRE_ric. Quindi, lista(tolti) viene concatenata con la lista degli n-1
    nodi tolti a partire dalla nuova lista(L). Infine, viene restituita 
    lista(tolti)-> POST

*******************************************************************************/

// PRE = (Lista(L) e Lista(D) sono corrette, vL=L)
doppioN Fric(nodo* L,nodoD* D){
    if (!D) return doppioN(L);
    if (!L) return doppioN();
    // lista(D) e' non vuota e lista(L) non vuota
    
    nodo* lasciati = tagliaric(L, D->lascia);
    nodo* tolti = tagliaric(L, D->togli);
    
    // PRE_ric = (Lista(L) e Lista(D->next) sono corrette, vL=L)
    doppioN doppia = Fric(L, D->next);
    // POST_ric = (restituisce col return un valore struttura doppioN che è una coppia di 
    //        valori nodo* che sono le liste lasciati e tolti in cui viene smembrata 
    //        vL secondo quanto prescritto da D->next)
    
    doppia.La = concric(lasciati, doppia.La);
    doppia.To = concric(tolti, doppia.To);
    
    return doppia;
}
// POST = (restituisce col return un valore struttura doppioN che è una coppia di 
//        valori nodo* che sono le liste lasciati e tolti in cui viene smembrata 
//        vL secondo quanto prescritto da D)

/*******************************************************************************
DIMOSTRAZIONE

Caso base:
    - Se lista(D) e' vuota, allora non va tolto alcun nodo. Quindi, la funzione
      restituisce un doppioN con campo La = Lista(L). -> POST
    - Se lista(L) e' vuota, allora non posso togliere nodi. Quindi, la funzione
      restituisce un doppioN dove La e To sono liste vuote. -> POST
Caso induttivo: 
    Una volta esclusi i casi base, allora vengono effettuati i due tagli come 
    prescritto da nodo(D). Vale, poi, PRE_ric, perche' lista(L) e' corretta 
    secondo la PRE e lista(D) non vuota implica lista(D->next) corretta.
    Vale, dunque, POST_ric e doppia e' un doppioN con 
    La = lista dei nodi lasciati come prescritto da lista(D->next)
    To = lista dei nodi tolti come prescritto da lista(D->next).
    Infine, lista(doppia.La) = lista(lasciati) @ lista(vdoppia.La) e
    lista(doppia.To) = lista(tolti) @ lista(vdoppia.To). 
    Quindi, lista(doppia.La) e' la lista dei nodi lasciati come prescritto da
    lista(D) e lista(doppia.To) e' la lista dei nodi tolti come prescritto da 
    lista(D). Infine, viene restituita doppia -> POST
 
*******************************************************************************/
// fine
main()
{
  int dimL, dimD;
  cin>> dimL>>dimD;
  nodo* L= build(dimL);//data
  nodoD* D=buildD(dimD);//data
  nodo*L1=clone(L);//data
  cout<<"start"<<endl;
  stampaL(L); //data
  stampaD(D);//data
  nodo* lasciati=0, *tolti=0;
  Fiter(L,D, lasciati, tolti); //da fare
  stampaL(lasciati);
  stampaL(tolti);
  doppioN y=Fric(L1,D); //da fare
  stampaL(y.La);
  stampaL(y.To);
  cout<<"end"<<endl;
}
