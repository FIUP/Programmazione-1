#include<iostream>
using namespace std;
struct nodo{int info; nodo* next;
nodo(int a=0, nodo*b=0){info=a;next=b;}};

nodo* riempi(int k)
{if(!k)
   return NULL;
 return new nodo(k, riempi(k-1));
}

void stampa(nodo*L)
{if(L)
	{cout<<L->info<<" ";
	 stampa(L->next);
	}

}
void F_ric2(nodo*& L, int k, nodo* x)
{if(!k)
  { nodo*acc=L;
    L=x;
    x->next=acc;
  }
else 
F_ric2(L->next,k-1,x);
}

main()
{nodo*inizio, *x=new nodo(99,0);
inizio=riempi(8);
 F_ric2(inizio, 4,x);
 stampa(inizio);
}
