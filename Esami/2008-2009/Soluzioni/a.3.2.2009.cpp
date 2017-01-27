#include<iostream>
using namespace std;

struct nodo{char info; nodo*next;
nodo(char a='0',nodo*b=0){info=a;next=b;}};

struct doppio{nodo*L1;nodo*L2;
doppio(nodo*c=0,nodo*d=0){L1=c;L2=d;}};


void stampa(nodo*L)
{if(L)
 { cout<<L->info<< " ";
	stampa(L->next);
 }
}

nodo*crea(int k)
{if(!k)
  return 0;
 char x;
 cin>>x;
 return new nodo(x,crea(k-1));

}
//PRE: x è una lista eventualmente vuota, P[dimP] è un array definito, dimP>=0
doppio PM(nodo*x, char*P, int dimP)
{if(!x)
	return doppio();

 if(!dimP)
	return doppio (x);

 if(x->info==P[0])
  { doppio LX;
	LX.L2=x;
    doppio acc=PM(x->next,P+1,dimP-1);
	LX.L1=acc.L1; 
    LX.L2->next=acc.L2;
	return LX;
  }
doppio LX;
LX.L1=x;
doppio acc= PM(x->next,P,dimP);
LX.L1->next=acc.L1;
   LX.L2=acc.L2;
return LX;
}
//POST: ritono LX che contiene i puntatori a due liste, una contenente i nodi del match (L2), l'altra x-L2
main()
{nodo*inizio=crea(10);
 char P[4]={'c','i','a','o'};
 stampa(inizio);
 cout<<endl;
 doppio LX= PM(inizio,P,4);
 stampa(LX.L1);
 cout<<endl;
 stampa(LX.L2);
 cout<<endl;
}
/*
caso base1: x=0, x è una lista vuota quindi banalmente restituisce due liste vuote
caso base2: dimP=0, non ci sono elementi nel pattern quindi ancora più banalmente restituisce L1 =x e L2 lista vuota
passo induttivo: x=a @ x', dimP>0.
				- se a->info!=P[0] inserisce nella lista L1 il nodo a, l'invocazione ricorsiva soddisfa la PRE_ric poichè
				 x->next = x' che è una lista eventualmente vuota quindi per l'ipotesi induttiva restituisce la lista L2 e L1'
				 quindi la lista L1 diventa a@ L1' e restituisce L1 e L2 come da post
				- se a->info=P[0] inserisce nela lista L2 il nodo a, l'invocazione ricorsiva soddisfa la PRE_ric poichè
				 x->next = x' che è una lista eventualmente vuota e dimP-1>=0 quindi per l'ipotesi induttiva restituisce le liste
				 L1 e L2', quindi la lista L2 diventa a@ L2' e restituisce L1 e L2 come da post 

*/

