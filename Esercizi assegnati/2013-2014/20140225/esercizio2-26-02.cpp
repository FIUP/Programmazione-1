#include<iostream>
#include<fstream>
using namespace std;

struct nodo {
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


//PRE_G=( L è lista corretta e L=vL, P ha dimP elementi definiti con dimP>=0)
nodoG* G(nodo*&L, int*P, int dimP){

	if(!dimP)
		return 0;
	if(L){
		if(L->info==*P){
			nodo* nL(L);
			L=L->next;
			return new nodoG(nL, G(L, P+1, dimP-1));
		} else G(L->next, P, dimP);
	}
	
}//POST_G=(G restituisce col return Comp(vL-P) e (vL-P) attraverso il parametro L passato per riferimento)


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

		nodo*L=0; //crea il nodo L
		
		crea(L,dim,INP); //crea la lista L
		//stampa(L,OUT); //stampa la lista L
  	
		INP>>dimP;
		cout<<dimP<<endl;
	
		for(int i=0; i<dimP; i++){
			INP>>P[i];
			cout<<P[i]<<endl;
		}
		
		nodoG* y=G(L, P, dimP); //crea il nodoG y

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
