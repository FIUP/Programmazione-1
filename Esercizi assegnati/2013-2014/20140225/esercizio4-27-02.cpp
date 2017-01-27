#include<iostream>
#include<fstream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};


//PRE_crea=("input" contiene (almeno) dim interi a_1,..,a_dim, dim>=0)
nodo* crea(int dim, ifstream & INP){
	
	if(!dim)
		return 0;
	int n;
	INP>>n;
	return new nodo(n, crea(dim-1, INP));

}//POST_crea=(la funzione restituisce una lista corretta di dim nodi tali che il primo nodo contiene nel campo info a_1, il secondo nodo contiene a_2, e l'ultimo contiene a_dim)


bool match(nodo*L, int*P, int dimP){
	
	if(!dimP)
		return true;
	if(L->info==*P)
		match(L->next, P+1, dimP-1);
	else return false;
	
}


//PRE_F=( L è lista corretta e L=vL, P ha dimP elementi definiti con dimP>=0)
nodo* F(nodo*L, int*P, int dimP){
	
	if(!dimP)
		return L;
	if(L){
		if(match(L, P, dimP)){
			return F(L->next, P+1, dimP-1);
		} else {
			L->next=F(L->next, P, dimP);
			return L;
		}
	} else return 0;
		

}//POST_F=(F restituisce col return (vL-P) )


void stampa(nodo* x, ofstream & OUT){
	if(x){
		OUT<< x->info<<' ';
		//cout<< x->info<<' ';
		stampa(x->next, OUT);
	} else OUT<<endl;
}


main(){
	try{
		ifstream INP("input");
		ofstream OUT("output");
		if(!INP) throw(0);
		if(!OUT) throw(1);
		int dim, dimP, P[20],x;
		INP>>dim;
  
		nodo*L;
		L=crea(dim,INP);
		//stampa(L,OUT);
  
		INP>>dimP;
  
		for(int i=0; i<dimP; i++)
    	INP>>P[i];

		nodo* y=F(L, P, dimP);
		if(y)
			stampa(y, OUT);
		else OUT<<"(L-P) vuota";
		OUT<<endl;
	}
	catch(int x){
		switch(x){
			case 0: cout<<"problemi con input"<<endl; break;
			case 1: cout<<"problemi con output"<<endl; break;
		}
	}
}
