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
 
 
// PRE=(Lista(L) ben formata, A ha nA elementi, vL=L)
nodo* patt_match(nodo*&L, int* A, int nA) {
    if(!nA) {
        nodo* x=L;
        L=0;
        return x;
    }
    if (!L) {
        return 0;
    }
    if (A[0]!=L->info) {
        nodo* p=L;
        L=L->next;
        p->next=0;
		// PRE_ric1=(lista(L->next) e' ben formata, A ha nA elementi, vL->next=L->next)
        p->next=patt_match(L, A, nA);
		/* POST_ric1=(Ho costruito p con i nodi successivi di L, e consiste dei nodi 
		successivi di vL che non matchano con A) */
        return p;
    }
	// PRE_ric2=(A[0]==L->info, L e' ben formata, A ha nA elementi, vL=L)
    return patt_match(L->next, A+1, nA-1);
	// POST_ric2=(L e' la lista dei nodi di vL che matchano con A)
}
/* POST=(L e' la lista che consiste dei nodi di vL che matchano con A e col return 
restituisce la lista degli altri nodi di vL) */

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
