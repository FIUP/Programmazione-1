#include<iostream>
using namespace std;

struct nodo{int info; nodo* next;nodo(int a=0, nodo* b=0){info=a; next=b;}};

nodo* faiLista()
{
  int x;
  cin>> x;
  if(x==-1) return 0;
  return new nodo(x, faiLista());
}
void stampaL(nodo*L)
 {
   if(L)
     {
       cout<<L->info<<' ';
       stampaL(L->next);
     }
   cout<<endl;

 } 
 

main() {
  cout<<"start"<<endl;
  nodo*K=faiLista();
  int nA;
  cin >>nA;
  int * A= new int[nA];
  for(int i=0; i<nA; i++)
    cin >>A[i];
  nodo* X=patt_match(K,A,nA);
  cout<<"lista del match:"<<endl;
  stampaL(K);
  cout<<"lista rimasta:"<<endl;
   stampaL(X);  
   cout<<"end"<<endl;
}
