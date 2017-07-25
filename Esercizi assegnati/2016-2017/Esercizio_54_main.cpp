
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

main()
{
   int dim, dimP, P[20];
   cin>>dim;
   nodo* L1=crea(dim);
   cin>>dimP;
   leggi(dimP, P);
   cout<<"start"<<endl;
   doppialista* D= match(L1,P, dimP); //da fare
   if(!D)
     {
       cout<<"no match"<<endl;
       cout<<"Lista T e':";
       stampa(L1);
     }
   else
     {
       stampa(D->listamatch);
       if(D->restante)
	 stampa(D->restante);
       else
	 cout<<"Lista restante vuota"<<endl;
     }
   cout<<"end"<<endl;
}


