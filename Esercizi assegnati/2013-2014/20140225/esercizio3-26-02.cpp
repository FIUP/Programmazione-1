#include<iostream>
#include<fstream>
using namespace std;

struct nodo{
	int info; 
	nodo* next; 
	nodo(int a=0, nodo* b=0){info=a; next=b;}
};

struct nodoG{
	nodo*N; 
	nodoG* next; 
	nodoG(nodo* a=0, nodoG* b=0){N=a; next=b;}
};


//PRE=("input" contiene (almeno) dim interi a_1,..,a_dim, dim>=0)
void crea(nodo* &L, int dim, ifstream & INP){

	if(dim!=0){
		int n;
		INP>>n;
		L=new nodo(n);
		crea(L->next, dim-1, INP);
	} else L=0;

}//POST=(la funzione restituisce nella variabile L, passata per riferimento, una lista corretta di dim nodi tali che il primo nodo contiene nel campo info a_1, il secondo nodo contiene a_2, e l'ultimo contiene a_dim)


//PRE_GC=( L è lista corretta e L=vL, P ha dimP elementi definiti con dimP>=0)
nodoG* GC(nodo*&L, int*P, int dimP, bool &match){

	if(!dimP){
		match=true;
		return 0;
	}

	if(L){
		if(L->info==*P){
			nodo* nL(L);
			nodoG* nnL(GC(L->next, P+1, dimP-1, match));
			if(match){
				L=L->next;
				return new nodoG(nL, nnL);
			} else return 0;
						
		} else GC(L->next, P, dimP, match);
	}

}//POST_GC=(se c'è un match completo (non necessariamente contiguo) di P in L, allora GC restituisce col return Comp(vL-P) e (vL-P) attraverso il parametro L passato per riferimento, se invece non c'è un match completo di P in L, allora GC restituisce la lista vuota col return e la lista originale col parametro)


void stampa(nodo* x, ofstream & OUT){
	if(x){
		OUT<< x->info<<' ';
		//cout<< x->info<<' ';
		stampa(x->next, OUT);
	} else {
		cout<<endl; 
		OUT<<endl;
	}
}


void stampaG(nodoG* x, ofstream & OUT){
	if(x){
		OUT<< x->N->info<<' ';
		//cout<< x->N->info<<' ';
		stampaG(x->next,OUT);
	} else {
		cout<<endl; 
		OUT<<endl;
	}
}


main(){
	try{
		ifstream INP("input");
		ofstream OUT("output");
		if(!INP) throw(0);
		if(!OUT) throw(1);
		int dim, dimP, P[20],x;
		INP>>dim;
		cout<<dim<<endl;
		nodo*L=0;
		crea(L,dim,INP);
  
		INP>>dimP;
		cout<<dimP<<endl;

		for(int i=0; i<dimP; i++){
			INP>>P[i];
			cout<<P[i]<<endl;
		}
		
		bool match=false;
		nodoG* y=GC(L, P, dimP, match);
		if(y)
			stampaG(y, OUT);
		else OUT<<"Comp(L-P) vuoto";
		OUT<<endl;
		if(L)
			stampa(L,OUT);
		else OUT<<"(L-P) vuoto";
		OUT<<endl;
	}
	catch(int x){
		switch(x){
			case 0: cout<<"problemi con input"<<endl; break;
			case 1: cout<<"problemi con output"<<endl; break;
		}
	}
}
