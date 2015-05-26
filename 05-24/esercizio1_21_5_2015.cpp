/*Integrazione sei crediti
sgranaresgranare una lista creandone 2
che utilizzano alternativamente i nodi 
di quella originale*/
#include<iostream>
#include<fstream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};

nodo* crea(int dim, ifstream & INP){
	if(dim){
		int x;
		INP>>x;
		return new nodo(x,crea(dim-1,INP));
	}
	return 0;
} //genera la lista

void stampa(nodo*L,ofstream & OUT){
	if(L){
		OUT<<L->info<<' ';
		stampa(L->next,OUT);
	}
	else
		OUT<<endl;
}

void leggi(int dim, int*P, ifstream & INP){
	if(dim){
		INP>>*P;
		leggi(dim-1,P+1,INP);
	}
}//carica l'array col pattern da cercare

bool fin(nodo *x, int *P, int dimP){
	if(!dimP) 
		return true;
	
	if(!x)
		return false;
	
	if(x->info != P[0])
		return false;
	
	return fin(x->next, P+1, dimP-1);
}

//PRE=(L è una lista corretta, P ha dimP elementi, chiamiamo vL=L)
nodo* match(nodo *&L, int *P, int dimP){
	if(!L || !dimP)
		return 0;
	
	if(!fin(L,P,dimP))
		return match(L->next,P,dimP);
	
	nodo* z=L;
    L=L->next;
	z->next=match(L,P+1,dimP-1);
    return z;
}
//POST=(la funzione restituisce col return match(vL,P[0..dimP-1]) e L=resto_mach(vL,P[0..dimP-1]))
main(){
	ifstream IN("input");
	ofstream OUT("output");
	if(IN && OUT){ 
		int dim, dimP, P[20];
		IN>>dim;
		nodo* L1=crea(dim,IN);
		IN>>dimP;
		leggi(dimP, P, IN);
		nodo* L2= match(L1,P, dimP); // L2 contiene il match, L1 il resto della lista originale
		stampa(L2,OUT); //0 se non c'è match
		stampa(L1,OUT);	//
		IN.close(); OUT.close(); 
	}
	else
		cout<<"errore con i files";
}