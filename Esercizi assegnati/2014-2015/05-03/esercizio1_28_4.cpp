/*Integrazione sei crediti*/
#include <iostream>
#include <fstream>
using namespace std;

bool fin(int *x, int i, int *P, int dimP){													//controlliamo effettivamente il match
	if(dimP){																				//se c'è ancora pattern
		if(x[i] != P[0])																	//se l'elemento considerato non coincide con il primo elemento del pattern
			return false;																	//ci fermiamo
		else 																				//altrimenti
			return fin(x, i+1, P+1, dimP-1);												//invochiamo fin, cambiando l'indice di x, quello di P e la dimensione del pattern
	}																						//ora cercheremo un pattern più piccolo finché non lo avremo consumato tutto	
	return true;																			//se lo consumiamo tutto l'abbiamo trovato
}

void match(int *x, int*P, int dim, int dimP, int i, int count_match, ofstream & OUT){		//conta i match
	if(i<dim-dimP+1){																		//se i è una posizione utile
		if(fin(x,i,P,dimP)){																//se c'è match 
			count_match++;																	//incrementiamo il contatore che tiene traccia di quanti sono
			OUT <<"match n." << count_match << " a partire dalla posizione " << i<<endl;	//e stampiamo da dove inizia
		}
		match(x,P,dim,dimP,i+1,count_match,OUT);											//i match possono essere sovrapposti, dunque invochiamo di nuovo
	}																						//match a partire dalla prossima posizione
	else{ 																					//quando usciamo dalle posizioni valide
		OUT <<"fine"<< endl;																//abbiamo finito
		return;
	}
}

int main(){
	ifstream IN("input");
	ofstream OUT("output");
	
	if(IN && OUT){
	int X[400], P[20], n_el, dimP, count_match=0;

	IN >> n_el;

	for(int i=0; i<400; i++)							//carichiamo il solito array di 400 elementi, stavolta a 0
		X[i] = 0;
	
	for(int i=0; i<20; i++)								//inizialiamo a zero pure il pattern
		P[i] = 0;
	
	for(int i=0; i<n_el; i++)							//carichiamo i n_el elementi utili in X
		IN >> X[i];

	IN >> dimP;											//impostiamo la dimensione effettiva del pattern
	for(int i=0; i<dimP; i++)							//carichiamo gli elementi del pattern
		IN >> P[i];										//dal file di input
	
	IN.close();
	
	match(X, P, n_el, dimP, 0, count_match, OUT);		//e invochiamo la funzione ricorsiva match partendo dall'indice 0
	OUT.close();
	}
	else
		cout << "errore coi file"<< endl;
}