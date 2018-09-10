//manca la soluzione

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



main()
{
  int dim;
  cin>>dim;
  nodo* L=crea(dim,IN);
  int k, y;
  cin>>k>>y;
  cout<<"start"<<endl;
  stampa(L);
  delastk(L,k,y,0);// da fare 
  stampa(L);
  cout<<"end"<<endl;
}



