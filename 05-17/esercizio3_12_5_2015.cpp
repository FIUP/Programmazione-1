/*Integrazione sei crediti*/
#include <iostream>
#include <fstream>
using namespace std;

struct nodo{
	int info; 
	nodo* next; 
	nodo(int a=0, nodo* b=0){
		info=a; 
		next=b;}
};

nodo* crea(int dim,ifstream & IN){							//crea la lista come nell'es. 1 di questa settimana
	
	if(!dim)
		return NULL;
	
	int x;
	IN >> x;
	return new nodo(x, crea(dim-1,IN));
	
}

nodo* del_z(nodo* n, int z){								//elimina dalla lista tutti i nodi con campo info = z
	
	if(!n)													//se la lista è vuota
		return NULL;										//non possiamo eliminare niente e ritorniamo null
															//altrimenti 
	if(n->info == z){										//se il campo info è uguale a z
		nodo *p = n;										//creiamo un puntatore al nodo che deve essere eliminato
		n = del_z(n->next,z);								//portiamo avanti ricorsivamente la lista (riassegnando il valore ritornato alla lista stessa)
		delete p;											//eliminiamo il nodo puntato da p
	}														
	else													//altrimenti, se info non è uguale a z
		n->next = del_z(n->next,z);							//il nodo va tenuto e assegnamo al suo campo next il risultato dell'invocazione ricorsiva sul resto della lista
	return n;												//e ritorniamo la lista 
}
void stampa(nodo* L, ofstream& OUT){						//stampa la lista come negli es. precedenti
	if(!L)
		OUT << "fine"<<endl ;
	else{
		OUT << L->info << "->";
		stampa(L->next, OUT);
	}
}

main(){
	ifstream IN("input");
	ofstream OUT("output");
	
	if(IN && OUT){
		int dim,z;
		nodo* L;
	
		IN >> dim;
		L = crea(dim, IN);	
		//stampa(L,OUT);
		IN >> z;
		L = del_z(L,z);
		stampa(L, OUT);
	
		IN.close();
		OUT.close();
	}
	else
		cout << "errore con i file"<< endl;
}
