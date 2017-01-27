#include<iostream>
using namespace std;

//mancano invarianti
struct nodo {int info; nodo * next;
nodo(int a=0,nodo*b=0){info=a;next=b;}};


void stampa(nodo*L)
{if(L)
	{ cout<<L->info<<" ";
	 stampa(L->next);
	}
} 

nodo* crea(int k)
{ if(!k)
	return 0;
  return new nodo(k, crea(k-1));

}
//PRE: L1 e L2  sono liste eventualmente vuote
nodo* fuse_iter(nodo*L1,nodo*L2)
{ if(!L1)
	return L2;
 if(!L2)
	return L1;
  nodo*inizio=L1;
  while(L1->next)
	{ nodo*acc=L1->next;
	  L1->next=L2;
	  L2=acc;
	  L1=L1->next;
	}
L1->next=L2;
 return inizio;
}
//POST: restituisce una lista formata dai nodi di L1 e L2 in modo alterno
main()
{ nodo*L1=crea(5); 
  nodo*L2=crea(0);
	L1=fuse_iter(L1,L2);
 stampa(L1);

}
