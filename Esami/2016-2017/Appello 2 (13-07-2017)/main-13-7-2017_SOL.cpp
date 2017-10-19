//Soluzione by F. De Filippis
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

nodo* conc(nodo*L1, nodo*L2)
{
  if(!L1) return L2;
  if(!L2) return L1;
  nodo* x=L1;
  while(x->next)
    x=x->next;
  x->next=L2;
  return L1;
}

nodo* concric(nodo* L1, nodo* L2){
    if(!L1) return L2;
    if(!L2) return L1;
    if(!L1->next){
        L1->next = L2;
        return L1;
    }
    L1->next = concric(L1->next,L2);
    return L1;
}

nodo* taglia(nodo*&L, int n){
    if(!n) return 0;
    nodo* d = 0;
    while(n>0 && L){
        nodo* c = L;
        L = L->next;
        c->next = 0;
        d = conc(d,c);
        n--;
    }
    return d;
}

nodo* tagliaric(nodo*& L, int n){
    nodo* d = 0;
    if(!n || !L) return d;
    nodo* c = L;
    L = L->next;
    c->next = 0;
    d = tagliaric(L,n-1);
    return conc(c,d);
}

void Fiter(nodo*L, nodoD* D, nodo*& lasciati, nodo*& tolti){
    while(D){
        lasciati = conc(lasciati,taglia(L,D->lascia));
        tolti = conc(tolti,taglia(L,D->togli));
        D = D->next;
    }
    lasciati = conc(lasciati,L);
}

doppioN Fric(nodo* L,nodoD*D){
    doppioN dd = doppioN();
    if(!D){
        dd.La = conc(dd.La,L);
        return dd;
    }
    nodo* l = tagliaric(L,D->lascia);
    nodo* t = tagliaric(L,D->togli);
    dd = Fric(L,D->next);
    dd.La = concric(l,dd.La);
    dd.To = concric(t,dd.To);
    return dd;
}

nodo*clone(nodo*L)
{
  if(!L) return 0;
  return new nodo(L->info,clone(L->next));
}

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
