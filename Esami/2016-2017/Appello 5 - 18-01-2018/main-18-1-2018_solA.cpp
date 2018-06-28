/*
Soluzione by:
Alessandro Spreafico, Francesco Drago e Sara Righetto
Aggiustata by:
Marco Marchesin

Sembra essere corretta, ma non diamo garanzie.
La prova di correttezza non abbiamo voglia di farla.
*/

#include<iostream>
using namespace std;

struct nodo{int info; nodo*next; nodo(int a=0, nodo*b=0){info=a; next=b;}};
struct FIFO {nodo* primo, *ultimo; int dim; FIFO(nodo*a=0,nodo*b=0,int c=0){primo=a; ultimo=b; dim=c;}};
struct nodoFIFO{FIFO info; nodoFIFO* next; nodoFIFO(FIFO a=FIFO(), nodoFIFO*b=0){info=a; next=b;}};

  
void stampa(nodoFIFO*Q,int i)
{
  if(Q)
    {
      cout<<"nella FIFO n."<< i<<" ci sono "<<Q->info.dim<<" valori, il primo e l'ultimo seguono:"<<endl;
      cout<<"primo="<<Q->info.primo->info<<", ultimo="<<Q->info.ultimo->info<<endl;
      stampa(Q->next,i+1);
    }
}

FIFO addord(FIFO x, nodo*N)
{
  if(x.primo->info>=N->info)
    {
      N->next=x.primo;
      x.primo=N;
      x.dim++;
      return x;
    }
  nodo * a=x.primo;
  while(a->next && a->next->info<N->info)
    a=a->next;
  if(!a->next)
    x.ultimo=N;
  N->next=a->next;
  a->next=N;
  x.dim++;
  return x;
}

nodo* poplast(FIFO& x)
{
  nodo * a=x.primo;
  if(x.ultimo==x.primo)
    {
      x.ultimo=x.primo=NULL;
      x.dim=0;
      return x.primo;
    }
  while(a->next!=x.ultimo)
    a=a->next;
  nodo *temp=a->next;
  x.ultimo=a;
  a->next=NULL;
  x.dim--;
  return temp;
}

nodoFIFO* addtolist(nodoFIFO*Q, nodo*N, int m)
{
  if(!Q)
    {
      FIFO x;
      x.primo=x.ultimo=N;
      x.dim=1;
      Q=new nodoFIFO(x, NULL);
      return Q;
    }
  if(Q->info.dim<m)
    {
      Q->info=addord(Q->info, N);
      return Q;
    }
  if(Q->info.dim==m)
    {
      Q->info=addord(Q->info, N);
      nodo * temp=poplast(Q->info);
      Q->next=addtolist(Q->next, temp, m);
      return Q;
    }  
}

main()
{
  int n, m,a;
  cin>>n>>m;
  nodoFIFO* Q=0;
  for(int i=0; i<n; i++)
    {
      cin >>a;
      nodo*N=new nodo(a);
      Q=addtolist(Q,N,m);
    }
  cout<<"start"<<endl;
  stampa(Q,0);
  cout<<"end"<<endl;
}
