/*Integrazione sei crediti*/
#include <iostream>
#include <fstream>
using namespace std;

struct nodo{
	int info1, info2; 
	nodo* next; 
	nodo(int a=0, int c=0, nodo* b=0){
		info1=a; info2=c; next=b; 
	}
};


nodo* copia(nodo* X){
	if(X)
		return new nodo(X->info1, X->info2, copia(X->next));
	return 0;
}

void crea(nodo*&L, int dim, ifstream & INP, int n){
	int x;
	if(n<dim){
		INP>>x;
		L=new nodo(x,n,0);
		crea(L->next, dim,INP,n+1);
	} 
	else L=0;
}

void crea1(nodo*&L, int dim, ifstream & INP, int n){
	int x,y;
	if(n<dim){
		INP>>x>>y;
		L=new nodo(x,y,0);
		crea1(L->next, dim,INP,n+1);
	} 
	else L=0;
}

void stampa(nodo* x, ofstream & OUT){
	if(x){
		OUT<<'('<< x->info1<<','<<x->info2<<')';
		if(x->next)
			OUT<<"->";
		stampa(x->next, OUT);
	} 
	else
		OUT<<endl;
}

int cercaInizio(nodo *&T, int *P){
	int inizio_match=0;
	while(T && T->info1!=*P){
		T=T->next;
		inizio_match++;
	}
	if(!T)
		return -1;
	return inizio_match;
}

int cercaFine(nodo *&T, int *&P, int &indiceP, int dimP){
	int fine_match=0;
	while(T && indiceP<dimP && T->info1==*P){
		fine_match++;
		T=T->next;
		indiceP++;
		P++; 
	}
	return fine_match;
}

void costruisciLista(nodo *l_match, int inizio_match, int fine_match){
	nodo *l_match_aux=l_match;
	while(l_match_aux->next!=0)
		l_match_aux=l_match_aux->next;
	l_match_aux->next=new nodo(inizio_match,fine_match);
	return ;
}

nodo* M1(nodo* T, int*P, int dimP){
	if(!dimP)
		return 0;
	nodo *l_match=0;
	int indiceP=0;
	bool stop=false;	
	while(T && !stop){
		int inizio_match=cercaInizio(T,P);
		if(inizio_match!=-1){
			int fine_match=cercaFine(T,P,indiceP,dimP);
			if(!l_match)
				l_match=new nodo(inizio_match,fine_match);
			else 
				costruisciLista(l_match,inizio_match,fine_match);
			if(indiceP==dimP-1) 
				stop=true;
		}
		else 
			stop=true;
	}
	return l_match;
}

nodo *&saltaNodi(nodo *&T, int info1){
	if(T && info1)
		return saltaNodi(T->next,info1-1);
	return T;
}

nodo *togliNodi(nodo *&T, int info2){
	if(!T || !info2)
		return T;
	nodo *aux=T; 
	T=T->next;
	delete aux;
	return togliNodi(T,info2-1);
}

void TB(nodo*&T, nodo*X){
	if(!T || !X)
		return ;
	
	nodo *&aux1=saltaNodi(T,X->info1);
	if(aux1){ 
		nodo *aux2=togliNodi(aux1,X->info2);
		aux1=aux2; 
		if(X->next) 
			TB(aux1,X->next);
	}
}

nodo* TC(nodo*&T, nodo*X){
	if(!T || !X)
		return 0;
	
	if(X->info1){
		X->info1--;
		return TC(T->next,X);
	}
	else{ 
		if(X->info2){
			X->info2--;
			nodo *aux=T;
			T=T->next;
			return new nodo(aux->info1,aux->info2,TC(T,X));
			delete aux; 
		}
		else 
			return TC(T,X->next);
	}
}

main(){
	try{
		ifstream INP("input");
		ofstream OUT("output");
		if(!INP) throw(0);
		if(!OUT) throw(1);
		int P[100],dimP,dim,dimX;
		INP>>dim>>dimP>>dimX;
  
		nodo*L=0;
		crea(L,dim,INP,0);
  
		for(int i=0;i<dimP ; i++)
			INP>>P[i];
		nodo*z=M1(L,P,dimP);    
		if(!z)
			OUT<<"nessun match"<<endl;
		else stampa(z,OUT);
		OUT<<endl;

		nodo* X=0;
		crea1(X,dimX,INP,0);
     
		nodo*L1=copia(L);
  
		TB(L1,X);        
		stampa(L1,OUT);
		cout<<endl;
		nodo* z1=TC(L,X); 
		//stampa(L,OUT);
		cout<<endl;
		stampa(z1,OUT);
		cout<<endl;

	} catch(int x){
		switch(x){
			case 0: cout<<"problemi con input"<<endl; break;
			case 1: cout<<"problemi con output"<<endl; break;
		}
	}
}
