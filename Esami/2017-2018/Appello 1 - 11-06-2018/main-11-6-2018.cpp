#include<iostream>
using namespace std;
struct nodo{int info ; nodo* next; nodo(int a=0, nodo*b=0){info=a; next=b;}};
struct coda{nodo* primo,* ultimo;coda(nodo*a=0,nodo*b=0){primo=a; ultimo=b;}};
coda push_beg(coda x, nodo*a)
{
  if(!x.primo)
    {
      x.primo=x.ultimo=a;
      a->next=0;
      return x;
    }
  a->next=x.primo;
  x.primo=a;
  return x;
}
coda push_end(coda x, nodo*a)
{
  if(!x.primo)
    {
      x.primo=x.ultimo=a;
      a->next=0;
      return x;
    }
  x.ultimo->next=a;
  x.ultimo=a;
  a->next=0;
  return x;
}

nodo* buildlist(int m)
{
  if(m>0)
    {
      int x;
      cin >> x;
      return new nodo(x,buildlist(m-1));
    }
  return 0;
}
nodo* clone(nodo*L)
{
  if(L)
    return new nodo(L->info,clone(L->next));
  return 0;
}
void stampaL(nodo*L)
{
  if(L)
    {
      cout<< L->info<<' ';
      stampaL(L->next);
    }
  else
    cout<<endl;
}
main()
{
  int  n;
  cout<<"start"<<endl;
  cin>> n;
  nodo*L=buildlist(n);
  stampaL(L);
  nodo*L1=clone(L);
  cout<<endl;
  nodo*L2=0;
  ordric(L,L2);
  stampaL(L2);
  nodo*y=orditer(L1);
  stampaL(y);
  cout<<"end"<<endl;
}

