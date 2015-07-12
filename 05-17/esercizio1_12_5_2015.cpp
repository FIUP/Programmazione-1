/*Integrazione sei crediti*/
#include <iostream>
#include <fstream>
using namespace std;
	
struct nodo{											//La struttura nodo essenziale per creare una lista
	int info; 											//è composta da un campo che contiene l'informazione vera e propria
	nodo* next; 										//e da un puntatore al nodo successivo
	nodo(int a=0, nodo* b=0){							//qui troviamo il costruttore
		info=a; 										
		next=b;}
};

nodo* crea(int dim,ifstream & IN){						//crea una lista di dim nodi prendendo i valori dal file di input
	
	if(!dim)											//se la dimensione è zero
		return NULL;									//ritorna una lista vuota (null)
	
	int x;												//altrimenti creiamo un intero 
	IN >> x;											//dove mettere il valore letto da input
	return new nodo(x, crea(dim-1,IN));					//allochiamo un nuovo nodo con new che tramite il costruttore costruirà
}														//un nodo con campo info = x e campo next che punta al nodo successivo della lista
														//notare che la lista che creeremo con l'invocazione ricorsiva sarà più corta di un nodo
														
void stampa(nodo* L, ofstream& OUT){					//stampa una lista su file  
	if(!L)												//se la lista è finita
		OUT << "fine";									//abbiamo finito
	else{												//altrimenti
		OUT << L->info << " ";							//stampiamo il campo info di quel nodo
		stampa(L->next, OUT);							//e invochiamo ricorsivamente stampa sul nodo successivo
	}
}

main(){
	ifstream IN("input");
	ofstream OUT("output");
	
	if(IN && OUT){
		int dim;
		nodo* L;										//creiamo il nodo di partenza
	
		IN >> dim;										//leggiamo la domensione della lista
		L = crea(dim, IN);								//creiamo la lista tramite la funzione ricorsiva crea 
		stampa(L, OUT);									//e la stampiamo tramite la funzione stampa
	
		IN.close();
		OUT.close();
	}
	else
		cout << "errore con i file"<< endl;
}
