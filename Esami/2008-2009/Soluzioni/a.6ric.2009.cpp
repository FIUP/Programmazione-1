#include<iostream>
using namespace std;

struct nodo{int info; nodo* next;
nodo(int a=0, nodo*b=0){info=a;next=b;}};

struct coppiaL{nodo* a,*b;
coppiaL(nodo*c=0,nodo*d=0){a=c;b=d;}};


nodo*riempi(int k)
{if(!k)
 return 0;
return new nodo(k, riempi(k-1));
}
void stampa(nodo*L)
{ if(L)
  { cout<<L->info<<" ";
	stampa(L->next);
  }
}
//PRE: L è una lista eventualmente vuota, P[dimP] definito, dimP>=0
//a->L(nodi di L che non fanno match)  b-L(nodo di L che fanno match)
coppiaL F(nodo*L, int*P, int dimP)
{ if(!L || !dimP)
	{coppiaL finale(L,0);
	return finale;
	}
  
  if(L->info==*P)
	{ coppiaL finale(0,L);
	  coppiaL acc=F(L->next,P+1,dimP-1);
	  finale.a=acc.a;
	  finale.b->next=acc.b;
	  return finale;
	}
	 coppiaL finale(L,0);
	 coppiaL acc=F(L->next,P,dimP);
	 finale.a->next=acc.a;
	 finale.b=acc.b;
	 return finale;

}
//POST: restituisce un valore coppiaL che nel suo campo a= a->L e b=b->L
/* caso base1: se L è una lista vuota => non è possibile trovare match quindi restituisce le due liste vuote
	caso base2: se dimP=0 => non ci sono match da cercare quindi restituisce il campo a=a->L e il campo b uguale a 0
	pass. indut: L= A @ L' && dimP>0
				se A->info = P[0] => A viene inserito nel campo b, richiama la funzione che soddisfa la PRE_ric poichè gli invio L' 
									e dimP-1>=0 => 	per l'ipotesi induttiva vale anche la POST_ric poichè restituisco un valore coppiaL 
									contentente a=a->L' e b=b->L' e restituisce a->L'=a->L e A@ b->L'=b->L
				se A->info != P[0] => A viene inserito nel campo a, richiamo la funzione che soddisfa la PRE_ric poichè gli invio L'
									  e dimP rimane invariato => per l'ipotesi induttiva vale anche la POST_ric poichè restituisco un valore
									coppiaL contentente a=a->L' e b=b->L' e restituisce A@ a->L'=a->L e b->L'=b->L
*/
main()
{ int P[3]={2,2,3};
  nodo*inizio=riempi(2);
	stampa(inizio);
cout<<endl;
	coppiaL ciao=F(inizio,P,3);
	stampa(ciao.a);
cout<<endl;
	stampa(ciao.b);
cout<<endl;
}
