
//soluzione by: Federico S. B.

/*Integrazione 6 crediti*/

#include<iostream>
#include<fstream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};
struct FIFO{nodo* primo, *fine; FIFO(nodo*a=0, nodo*b=0){primo=a; fine=b;}}; 

FIFO metti_fondo(FIFO a, nodo*b){
  if(!a.fine){							//se coda vuota
    a.primo =b;							//primo punta al nodo da pushare
    a.fine = a.primo;					//fine e primo coincidono, c'è un unico nodo
    return a;							//ritorniamo la coda
  }
  else{									//altrimenti se la coda non è vuota
    a.fine->next = b;					//pushiamo in fondo il nuovo nodo 
    a.fine = a.fine->next;				//spostiamo il puntatore alla fine della coda all'ultimo nodo
    return a;							//ritorniamo la  testa della coda
  }
} 

//PRE=(lista(C) è corretta e y è definito)
nodo* togli(nodo*C, int y){
	FIFO F;								//creiamo una coda vuota
	while(C){							//finché c'è roba nella lista C
        if(C->info==y){					//Se il campo info del nodo è uguale a y
            nodo* p=C;					//creiamo un puntatore al nodo da eliminare
            C=C->next;					//portiamo avanti la lista C (per confrontare il prossimo nodo)
            delete p;					//eliminiamo il nodo puntato da p
        }
        else{							//se C->info non è uguale a y
            F=metti_fondo(F,C);			//pushiamo C in fondo alla coda 
            C=C->next;					//e portiamo avanti la lista
        }								//una volta passata tutta la lista, la coda sarà in ordine
	}
	if(F.fine)							//se il puntatore al fondo coda non è vuoto
		F.fine->next=0;					//ci assicuriamo che punti all'ultimo elemento troncando gli altri
	return F.primo;						//ritorniamo la testa della coda 
}
/*POST=(restituisce la lista che resta eliminando da C i nodi con campo info=y che vengono deallocati. Nessun
nodo nuovo rispetto a C è allocato)
PRE=(lista(C) è corretta)*/
nodo* no_rip(nodo*C){
	if(!C)									//lista vuota niente da togliere
		return 0;
	
	C->next=no_rip(C->next);	   			//ricollego la lista a C
	nodo* resto=togli(C->next,C->info);		//tolgo dalla lista tutti i nodi con campo info = C->info
	if(resto){								//se resta qualche nodo								
		C->next=resto;						//lo collego alla lista d'origine C
		return C;							//e la ritorno
		}
	else{									//altrimenti abbiamo eliminato tutto
		if(C->next)							//se la lista continua, saranno tutti elementi da scartare
			C->next=0;						//chiudiamo C
		return C;							//e ritorniamo
	}
} 
/*POST=(restituisce quello che resta di C mantenendo solo il primo nodo con un dato campo info ed
eliminando i nodi successivi con lo stesso campo info. I nodi tolti da C sono deallocati. Nessun nuovo nodo
rispetto a C è allocato)
PRE = T, C liste corrette eventualmente vuote*/
void elim(nodo*&T, nodo*C){
	while(T && C){
	T=togli(T,C->info);
	C=C->next;
	}
}


void stampa_L(nodo* x,ofstream& OUT){
	if(x){
	  OUT<<x->info<<' '; 
	  stampa_L(x->next,OUT);
	}
	else
		OUT<<endl;
}

nodo* costruisci(int dim, ifstream & IN){
	if(dim){
		int x;
		IN>>x;
		return new nodo(x,costruisci(dim-1,IN));
	}
	else
		return 0;
}

main(){
	ifstream IN("input");
	ofstream OUT("output");
	if(IN && OUT){ 
		int dimT, dimC;
   
		IN>>dimC;
		nodo*C=costruisci(dimC,IN);//data
   
		stampa_L(C,OUT); //data
		nodo*Y=no_rip(C);//da fare, essa usa togli (che usa FIFO)
		stampa_L(Y,OUT);

		IN>>dimT;
		nodo* T=costruisci(dimT,IN);
		stampa_L(T,OUT);
   
		elim(T,Y); //da fare, esercizio finale
   
		stampa_L(T,OUT);
   
		IN.close(); OUT.close(); 
	}
	else
		cout<<"errore con i files";
}
