#include <iostream>
using namespace std;

struct nodo{ int info; nodo*next;
	nodo(int a=0, nodo*b=0){info=a; next=b;}
};

nodo* stacca_ric(nodo*&L1,nodo*&L2,int k){
if(!L1 || !k)
	{nodo*acc=L1;
	L1=L2;
	L2=acc;	
	return L1;
	}
else{	
 return stacca_ric(L1->next,L2,k-1);
  }
}

nodo* fuse_ric(nodo*L1, nodo*L2, int k){
  if(!L2)
	return L1;
	nodo*acc =stacca_ric(L1,L2,k);
	fuse_ric(acc,L2,k);
   return L1;
}

nodo *riempi(int k)
{ if(!k)
	return NULL;
  return new nodo(k,riempi(k-1));

}

void stampa(nodo*L)
{if(L)
  {cout<<L->info<<" ";
   stampa(L->next);
  }
}

main(){
nodo* inizio, *secondo, *L;
inizio=riempi(1); secondo=riempi();
stampa(inizio);
cout<<endl;
stampa(secondo);
cout<<endl;
L=fuse_ric(inizio, secondo,3 );
stampa(L);
cout<<endl;
}
