#include<iostream>
#include<fstream>
using namespace std;
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}}; // nodo di lista 
struct FIFO{nodo* primo, *ultimo;FIFO(nodo*a=0){primo=a; ultimo=a;}};

FIFO push_end(FIFO a, nodo*b)
{
  if(!a.primo)
  {a.primo=a.ultimo=b;}
  else
   {a.ultimo->next=b; a.ultimo=b;}
  return a;
}


struct nodoF {FIFO fi; nodoF* next;nodoF(FIFO a=FIFO(),nodoF*b=0){fi=a; next=b;}};

//funzioni ausiliarie

  void stampa_L(nodo*L)
{
 if(L)
  {cout<<L->info<<' '; stampa_L(L->next);}
 else
   cout<<endl;

}
 void stampa_F(nodoF* a)
{
  if(a)
   {stampa_L(a->fi.primo); 
    cout<<endl;
    stampa_F(a->next);
   }
  else
   cout<<endl;
}

nodo* costruisci(int dim)
{
 if(dim)
   {int x; cin>>x; return new nodo(x,costruisci(dim-1));}
 return 0;
}
 
nodoF* inserisci(nodoF* W, nodo* a) {
	if(!W)
		return new nodoF(FIFO(a), 0);
	if(W->fi.primo->info == a->info) {
		FIFO f = W->fi;
		f = push_end(f, a);
		W->fi = f;
		return W;
	}
	if(W->fi.primo->info > a->info) {
		nodoF* nf = new nodoF(FIFO(a), W);
		return nf;
	}
	if(W->next) {
		if(W->fi.primo->info < a->info && W->next->fi.primo->info > a->info) {
			W->next = new nodoF(FIFO(a), W->next);
			return W;
		}
	}
	W->next = inserisci(W->next, a);
	return W;
}

nodoF* smembra(nodo* q) {
	if(!q)
		return NULL;
	nodoF* nodof = 0;
	while(q) {
		nodo* TEMP = q;
		q = q->next;
		TEMP->next = 0;
		nodof = inserisci(nodof, TEMP);
	}
	return nodof;
}

nodo* LO(nodoF* W) {
	if(!W)
		return 0;
	if(W->next) {
		W->fi = push_end(W->fi, W->next->fi.primo);
	}
	LO(W->next);
	return W->fi.primo;
}
main()
{
   int dim;
   
   cin>>dim;
   nodo*C=costruisci(dim);
  
   cout<<"Lista costruita"<<endl;
   stampa_L(C);
   nodoF* a=smembra(C);
   cout<<"Liste uniformi:"<<endl;
   stampa_F(a);
   
   nodo* b=LO(a);
   cout<<"Lista ordinata"<<endl;
   stampa_L(b);
   cout<<"end";
}
