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

nodo* crea_inv(int dim,ifstream & IN){				//crea la lista nell'ordine inverso rispetto a quello di lettura
	
	if(!dim){										//se la lista è vuota
		return NULL;								//ritorniamo null
	}												//altrimenti
	
	nodo *n= new nodo();							//creiamo un nuovo nodo vuoto
	n->next = crea_inv(dim-1,IN); 					//impostiamo il suo next tramite una chiamata ricorsiva (verrà impostato al ritorno)
	IN >> n->info;									//ci inseriamo il campo info letto dal file di input
	return n;										//e lo ritorniamo
}

void stampa(nodo* L, ofstream& OUT){				//la funzione di stampa, come nell'esercizio precedente
	if(!L)
		OUT << "fine";
	else{
		OUT << L->info << "->";
		stampa(L->next, OUT);
	}
}

main(){
	ifstream IN("input");
	ofstream OUT("output");
	
	if(IN && OUT){
		int dim;
		nodo* L;
	
		IN >> dim;		
		L = crea_inv(dim, IN);						//stavolta creiamo la lista nell'ordine inverso rispetto a quello di lettura
		stampa(L, OUT);
	
		IN.close();
		OUT.close();
	}
	else
		cout << "errore con i file"<< endl;
}
