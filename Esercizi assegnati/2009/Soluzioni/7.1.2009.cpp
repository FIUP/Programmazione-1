#include <iostream>
using namespace std;

struct nodo{ int info; nodo* next;
	nodo (int a=0, nodo* b=0) { info=a; next=b;}
};

void stampa(nodo*L){
	if(L){
		cout<<L->info<<" ";
		stampa(L->next);
	}
}

nodo* crea(int k){
	if(!k)
		return 0;
  return new nodo(k, crea(k-1));

}

//PRE: L punta al primo nodo di una lista non vuota, k definito, definito
nodo * F_iter(nodo* L, int k, nodo* x){
	int i=1; bool esci=false;
	if(k==0){
		x->next=L;
		L=x;
	}
	else{	
		nodo *Z=L;
		while(i<=k && !esci){
			nodo*j=Z;
			if(i==k){
				x->next=Z->next;
				j->next=x;
				esci=true;
			}
			Z=Z->next;
			i++;
		}
	}
	return L;
}
//POST: restituisco il puntatore al primo nodo della lista L alla cui posizione a(k) è stato aggiunto il nodo x
//		L = a(0) @ a(1) @ ... @ a(n) , la nuova L sarà = a(0) @ ... @ a(k-1) @ x @ a(k+1) @... @ a(n) 
main(){
	nodo* inizio, *Q;
	nodo *x= new nodo(99,0);
	inizio=crea(10);
	stampa(inizio); cout << endl;
	inizio=F_iter(inizio, 3, x);
	stampa(inizio); cout << endl;
}
