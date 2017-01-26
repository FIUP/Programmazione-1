/*Integrazione sei crediti
sgranaresgranare una lista creandone 2
che utilizzano alternativamente i nodi 
di quella originale*/
#include<iostream>
#include<fstream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};

nodo* crea(int dim, ifstream & INP){						//solita funzione per creare la lista
	if(dim){												//come negli esercizi precedenti
		int x;
		INP>>x;
		return new nodo(x,crea(dim-1,INP));
	}
	return 0;
} 

void stampa(nodo*L,ofstream & OUT){							//funzione per stampare la lista, già vista
	if(L){
		OUT<<L->info<<' ';
		stampa(L->next,OUT);
	}
	else
		OUT<<endl;
}

void leggi(int dim, int*P, ifstream & INP){					//carica il pattern da cercare ricorsivamente
	if(dim){												//se dim>0
		INP>>*P;											//tramite il puntatore P assegniamo il valore letto dal file di input
		leggi(dim-1,P+1,INP);								//invochiamo ricorsivamente leggi scalando dim di uno e aumentando di uno il valore di P
	}														//per essere pronti ad inserire il prossimo elemento
}

bool fin(nodo *x, int *P, int dimP){						//controlla se c'è un match completo e contiguo
	if(!dimP) 												//se abbiamo finito il pattern da cercare
		return true;										//c'è il match
	
	if(!x)													//se abbiamo finito la lista, dove cerchiamo
		return false;										//il match non c'è
		
	if(x->info != P[0])										//se il campo info del nodo x è diverso dall'elemento del pattern che stiamo matchando
		return false;										//ci fermiamo e non c'è match completo
															//altrimenti l'elemento matcha
	return fin(x->next, P+1, dimP-1);						//e controlliamo i rimanenti tramite un'invocazione ricorsiva di fin sui parametri aggiustati
}

//PRE=(L è una lista corretta, P ha dimP elementi, chiamiamo vL=L)
nodo* match(nodo *&L, int *P, int dimP){					//L viene passata per riferimento
	if(!L || !dimP)											//se abbiamo finito L oppure abbiamo finito il pattern
		return 0;											//ritorniamo 0
															//altrimenti
	if(!fin(L,P,dimP))										//se non c'è match
		return match(L->next,P,dimP);						//ritorniamo il valore ritornato dall'invocazione ricorsiva di match sul resto della lista
															//altrimenti, il match c'è
	nodo* z=L;												//con un nuovo puntatore puntiamo alla vecchia lista
    L=L->next;												//che scorre in avanti (per riferimento di fatto eliminiamo il nodo)
	z->next=match(L,P+1,dimP-1);							//e colleghiamo alla nuova lista il valore ritornato dall'invocazione ricorsiva di match
    return z;												//ritorniamo la lista privata del match
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
		nodo* L2= match(L1,P, dimP); 						//L2 contiene il match, L1 il resto della lista originale
		stampa(L2,OUT); 									//0 se non c'è match, L2 contiene il match
		stampa(L1,OUT);										//L1 contiene gli elementi rimanenti
		IN.close(); OUT.close(); 
	}
	else
		cout<<"errore con i files";
}