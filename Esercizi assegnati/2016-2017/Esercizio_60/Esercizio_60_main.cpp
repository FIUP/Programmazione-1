#include<iostream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}}; // nodo di lista 
struct FIFO{nodo* primo, *ultimo;FIFO(nodo*a=0, nodo*b=0){primo=a; ultimo=b;}};
struct nodot{int info; nodot* left, *right; nodot(int a=0, nodot* b=0, nodot* c=0){info=a; left=b; right=c;}};//nodo di albero
FIFO push_end(FIFO a, nodo*b)
{
  if(!a.primo)
  {a.primo=a.ultimo=b;}
  else
   {a.ultimo->next=b; a.ultimo=b;}
  return a;
}

void stampa_L(nodo*L)
{
 if (L)
  {cout<<L->info<<' '; stampa_L(L->next);}
 else
   cout<<endl;

}
nodo* costruisci(int dim)
{
 if(dim)
   {int x; cin>>x; return new nodo(x,costruisci(dim-1));}
 return 0;
}
 nodo* clone(nodo*a)
 {
  if(a)
  {return new nodo(a->info, clone(a->next));}
  return 0;
 }
main()
{
  
   int dim;
   
   cin>>dim;
   nodo*C=costruisci(dim);
   nodo* D=clone(C);
   cout<<"Lista costruita"<<endl;
   stampa_L(C);
   FIFO a =tieni_ultimo_ric(C);
   cout<<"soluzione ricorsiva"<<endl<<"nodi tolti:"<<endl;
   
   stampa_L(a.primo);
   cout<<"lista rimanente:"<<endl;
   stampa_L(C);
   FIFO b=tieni_ultimo_iter(D);
   cout<<"soluzione iterativa"<<endl<<"nodi tolti:"<<endl;
   stampa_L(b.primo);
   cout<<"lista rimanente:"<<endl;
   stampa_L(D);
   cout<<"end";
}
