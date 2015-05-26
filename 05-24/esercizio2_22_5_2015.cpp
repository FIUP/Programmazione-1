/*Integrazione sei crediti 
sgranare una lista creandone 2
 che utilizzano alternativamente i nodi di quella originale*/
#include<iostream>
#include<fstream>
using namespace std;

struct nodo{
	int info; 
	nodo* next; 
	nodo(int a=0, nodo* b=0){info=a; next=b;}
};
	
struct dueL {
	nodo* prima, * seconda; 
	dueL(nodo*a=0, nodo* b=0){prima=a; seconda=b;}
};

nodo* crea(int dim, ifstream & INP){
	if(dim){
		int x;
		INP>>x;
	return new nodo(x,crea(dim-1,INP));
	}
	return 0;
}

nodo* clona_rov(nodo*L, nodo* rov){
	if(L){
		return clona_rov(L->next,new nodo(L->info,rov));
	}
	return rov;
}

void stampa(nodo*L,ofstream & OUT){
	if(L){
		OUT<<L->info<<' ';
		stampa(L->next,OUT);
	}
	else
		OUT<<endl;
}

int quanti(nodo *L){
	if(!L)
		return 0;
	return 1+quanti(L->next);
}

dueL sgrana(nodo*L){
	if(!L)
		return 0;
	
	if(!L->next)
		return dueL(L,0);
	
	dueL z;
       
    z.prima = L;
    z.seconda = L->next;
       
    dueL resto = sgrana(L->next->next);
       
	z.prima->next = resto.prima;
    z.seconda->next = resto.seconda;
       
    return z;
}//Restiisce le due liste in struttura dueL

nodo* sgrana2(nodo*&L){
	if(!L)
		return 0;
	
	if(!L->next){
		nodo *p = L;
		L = L->next;
		return p;
	}	
	
	nodo* L1=L;
	L=L->next;
	L1->next=sgrana2(L->next);
    return L1;
}
//POST = Restituisce L1 con return e L2 per riferimento

main(){
	ifstream IN("input");
	ofstream OUT("output");
	if(IN && OUT) { 
		int dim;
		IN>>dim;
		
		nodo* L1=crea(dim,IN); 
		nodo*L2= clona_rov(L1,0);
		
		dueL W=sgrana(L1); 
		nodo*L3=sgrana2(L2);
		stampa(W.prima,OUT);
		stampa(W.seconda,OUT);
		
		stampa(L3,OUT);
		stampa(L2,OUT);    
		
		IN.close(); OUT.close(); 
	}
	else
		cout<<"errore con i files";
}