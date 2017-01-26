#include<iostream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};

void stampa(nodo*L){
    if(L){
        cout<<L->info<<' ';
        stampa(L->next);
    }else
        cout<<endl;
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


void leggi(int dim, int* P){
    if(dim){
        cin>>*P;
        leggi(dim-1,P+1);
    }
}

nodo* crea(int dim){
    if(dim){
        int x;
        cin>>x;
        return new nodo(x,crea(dim-1));
    }
    return 0;//forse è meglio con NULL
}

main(){
    
    int dim, dimP, P[20];
    
    cin>>dim;
    nodo* L1=crea(dim);
    
    cin>>dimP;
    leggi(dimP, P);
    
    nodo* L2= match(L1,P, dimP);
    
    stampa(L2);
    stampa(L1);
    cout<<"end"<<endl;
}
