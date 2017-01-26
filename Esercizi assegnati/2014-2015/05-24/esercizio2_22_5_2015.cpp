/*Integrazione sei crediti 
sgranare una lista creandone 2
 che utilizzano alternativamente i nodi di quella originale*/
#include<iostream>
#include<fstream>
using namespace std;

struct nodo{														//solita struttura nodo
	int info; 
	nodo* next; 
	nodo(int a=0, nodo* b=0){info=a; next=b;}
};
	
struct dueL {														//una nuova struttura
	nodo* prima, * seconda; 										//costituita da due puntatori a nodo
	dueL(nodo*a=0, nodo* b=0){prima=a; seconda=b;}					//il suo costruttore
};

nodo* crea(int dim, ifstream & INP){								//crea la lista, come negli es. precedenti
	if(dim){
		int x;
		INP>>x;
	return new nodo(x,crea(dim-1,INP));
	}
	return 0;
}

nodo* clona_rov(nodo*L, nodo* rov){								//crea una nuova lista che è un clone rovesciato della lista d'origine
	if(L){														//L ha ancora elementi
		return clona_rov(L->next,new nodo(L->info,rov));		//ricorsivamente invochiamo clona_rov sul resto della lista, creando un nuovo nodo che ha il precedente nel campo next 
	}															//altrimenti se L è vuota
	return rov;													//ritorniamo
}

void stampa(nodo*L,ofstream & OUT){								//la funzione di stampa, già vista negli es. precedenti
	if(L){
		OUT<<L->info<<' ';
		stampa(L->next,OUT);
	}
	else
		OUT<<endl;
}

int quanti(nodo *L){											//calcola la lunghezza della lista
	if(!L)														//se la lista è vuota
		return 0;												//la sua lunghezza è zero
	return 1+quanti(L->next);									//altrimenti avrà un nodo più i nodi del resto della lista
}

dueL sgrana(nodo*L){											//la prima funzione sgrana dove la lista è passata per valore
	if(!L)														//se la lista è vuota
		return 0;												//ritorniamo un dueL vuoto (0 o null)
	
	if(!L->next)												//se non c'è l'elemento successivo, la lista ha un solo nodo
		return dueL(L,0);										//ritorniamo un dueL con solo la prima lista (quella dei nodi dispari)
																//altrimenti se ha più di un nodo
	dueL z;														//creiamo un nuovo dueL vuoto
		
    z.prima = L;												//alla lista dei dispari aggiungiamo L
    z.seconda = L->next;										//a quella dei pari il successore di L
																//e invochiamo ricorsivamente sgrana sul terzo nodo della lista (che può essere vuoto)
    dueL resto = sgrana(L->next->next);							//assegnamo il valore ritornato in un nuovo dueL di nome resto
																//che ricorsivamente avrà nel primo puntatore un nodo in posizione dispari e nell'altro uno in pari
	z.prima->next = resto.prima;								//quindi colleghiamo alla lista dei dispari il successivo nodo dispari (quello di resto)
    z.seconda->next = resto.seconda;							//e a quella dei pari il successivo nodo pari (sempre di resto)
       
    return z;													//infine restituiamo il dueL completo
}																//Restiisce le due liste in struttura dueL	

nodo* sgrana2(nodo*&L){											//stavolta la lista è passata per riferimento
	if(!L)														//se la lista è vuota
		return 0;												//ritorniamo 0
																//altrimenti almeno un nodo c'è
	if(!L->next){												//se non c'è un successivo
		nodo *p = L;											//facciamo puntare a p la vecchia lista
		L = L->next;											//e la portiamo avanti tramite un'assegnazione (sfruttando il passaggio per riferimento)
		return p;												//e ritorniamo p, unico nodo dispari
	}															//altrimenti c'è un nodo successivo
	
	nodo* L1=L;													//assegnamo ad L1 che conterrà i nodi dispari L
	L=L->next;													//portiamo avanti la lista (sempre tramite assegnazione), ora conterrà un nodo pari
	L1->next=sgrana2(L->next);									//e colleghiamo al ritorno dell'invocazione ricorsiva il valore ritornato dalla funzione sgrana2 
    return L1;													//che sarà sempre un nodo dispari, infine ritorniamo la lista completa
}
//POST = Restituisce L1 (che contiene i nodi dispari) con return e L2 (che contiene quelli pari) per riferimento

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