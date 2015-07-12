/*Integrazione sei crediti*/
#include <iostream>
#include <fstream>

using namespace std;

int qdista(int strato, int rim, int hfetta, int lim2, int lim3){					//calcola la distanza dell'elemento dall'inizio
	int distanza = strato*(lim2*lim3) + hfetta*lim3 + rim;
	return distanza;
}

bool match(int *x, int *P, int dimP, int distanza, int lim2, int lim3){				//controlla se c'è un match completo e contiguo
	bool ok=true;																	//tramite un bool
	int dist = distanza;															//setta la distanza dell'elemento da considerare
	for(int i=0; i<dimP && ok; i++){												//finché c'è pattern da cercare
		if(x[dist]!=P[i])															//se l'elemento considerato non coincide col pattern
			ok=false;																//ci fermiamo, non c'è match
		else{																		//altrimenti
			if((dist+1)%lim3 ==0 )													//se il prossimo elemento è sull'altro strato
				dist += (lim2-1)*lim3+1;											//aggiustiamo la distanza per saltare nella riga posta sull'altro strato
			else dist++;															//altrimenti incrementiamo normalmente di uno
		}
	}
	return ok;
}

int contaMatch(int *x, int fetta, int lung, int lim2, int lim3, int *P, int dimP){	//lung è la lunghezza dell'h-fetta, x punta all'inizio di X
	int n_match=0, jump=1, distanza = 0, strato=0, rim=0;							//distanza indica quanto dista l'elemento considerato dall'inizio di X
	for(int i=0; i<lung-dimP+1; i=i+jump){											//vediamo l'h-fetta come array monodimensionale
		strato = i/lim3;															//lo strato è determinato da lim3
		rim= i%lim3;																//gli elementi rimanenti dal resto della divisione
		//OUT << "i " << i << endl;													
		distanza = qdista(strato, rim, fetta, lim2, lim3);							//calcoliamo la distanza tramite qdista
		//OUT << "i: " << i << " distanza: " << distanza <<endl;
		if(match(x, P, dimP, distanza, lim2, lim3)){								//se c'è match completo e contiguo
			n_match++;																//incrementiamo il numero di match
			//OUT << "match va";
			jump=dimP;																//impostiamo il salto (i match sono non sovrapposti)
			//OUT << " jump :" <<jump << endl;
		}
		else{																		//altrimenti, se non c'è match
			//OUT << "match non va ";
			jump=1;																	//aumentiamo solo di uno
			//OUT << " jump : " <<jump << endl;
		}
	}
	return n_match;																	//ritorniamo il numero totale di match dell'h-fetta
}

int main(){
	ifstream IN("input");
	ofstream OUT("output");
	
	if(IN && OUT){
	int X[400], *x = X, P[50], lim1, lim2, lim3, n_el, dimP, match=0, hfmax=0;

	IN >> lim1 >> lim2 >> lim3 >> n_el;

	for(int i=0; i<400; i++)														//inizializza tutti gli elementi di X a -1
		X[i] = -1;
	
	for(int i=0; i<n_el; i++)														//carica in X n_el elementi
		IN >> x[i];

	IN >> dimP;																		//la dimensione del pattern viene presa dal file di input

	for(int i=0; i<dimP; i++)														//carica il pattern P
		IN >> P[i];
	
	IN.close();
	
	if(n_el > lim1*lim2*lim3)														//se ci sono più elementi di quelli che ci possono stare
		n_el = lim1*lim2*lim3;														//non vengono considerati
	
	int nsp = n_el/(lim2*lim3);														//strati pieni
	int nrimus= n_el%(lim2*lim3);													//rimanenti ultimo strato
	int nrpus = nrimus/lim3;														//righe piene ultimo strato
	int	nrp = n_el/lim3;															//nrp = righe piene, rim = rimanenti
	int rim= nrimus%lim3;															//rimanenti ultima riga
	
	if(n_el<=lim3)																	//se manco una riga è completa
			hfmax = 1;																//c'è solo un h-fetta
	else{																			//altrimenti
		if(nrp<lim2)																//se il numero di righe piene è minore del numero di righe
			hfmax = nrp;															//abbiamo nrp h-fette
		else hfmax = lim2;															//altrimenti abbiamo lim2 h-fette
	} 
		
	int lung = nsp*lim3;															//la lunghezza base di un h-fetta è data dal numero di strati pieni
																					//per gli elementi di una riga
	for(int i=0; i < hfmax; i++){													//navighiamo tra h-fette
		if(i<nrpus)																	//se i è minore del numero di righe piene dell'ultimo strato
			lung=lung+lim3;															//(quello parz. definito), l'h-fetta ha una riga in più 
		else if(i ==nrpus)															//altrimenti se è uguale
			lung = lung+rim;														//l'ultima h-fetta ha rim elementi in più
		match = contaMatch(x, i, lung,lim2, lim3,P,dimP);							//contiamo i match dell'h-fetta invocando contaMatch
		OUT << "H-fetta " << i << " = " << match << " match" << endl;				//stampiamo il risultato sul file di output
		match=0;																	//riportiamo match a 0 per partire col calcolo della prossima
		lung = nsp*lim3;															//e reimpostiamo la dimensione base di un h-fetta
	}
	}
	else
		cout << "errore coi file"<< endl;
}