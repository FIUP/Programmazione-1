/*Integrazione sei crediti*/
#include <iostream>
#include <fstream>

using namespace std;

bool match(int *x, int *P, int dimP, int lim3){						
	bool ok=true;													//usiamo un bool
	for(int i=0; i<dimP && ok; i++)									//finché c'è pattern da cercare e il match è contiguo
			if(x[i*lim3]!=P[i])										//confrontiamo l'elemento con quello del pattern
				ok=false;											//se non sono uguali ci fermiamo
	return ok;														//e ritorniamo il bool
}

int contaMatch(int *x, int lung, int lim3, int *P, int dimP){		//lung rappresenta la dimensione della v-fetta
	int n_match=0, jump=0;											//n_match conta i match, jump imposta la dimensione da saltare (i match sono non sovrapposti)
	for(int i=0; i<lung-dimP+1; i=i+jump)							//l'ultima posizione valida è quella data da lung-dimP+1, l'incremento varia
		if(match(x, P, dimP, lim3)){								//controllo se c'è un match contiguo tramite l'invocazione di match
			n_match++;												//se c'è incrementiamo il numero di match di uno
			x=x+dimP*lim3;											//spostiamo il puntatore di dimP*lim3 posizioni (occhio che siamo su v-fette)
			jump=dimP;												//l'incremento sarà di dimP, visto che i match non sono sovrapposti e uno l'abbiamo trovato
		}	
		else{														//se non c'è match
			x=x+lim3;												//spostiamo il puntatore al prossimo elemento della v-fetta
			jump=1;													//e l'incremento sarà di uno soltanto
		}
		return n_match;												//restituisce il numero di match contenuti nella v-fetta
}	

int main(){
	ifstream IN("input");
	ofstream OUT("output");
	
	if(IN && OUT){
	int X[400], *x = X, P[50], lim1, lim2, lim3; 
	int n_el, dimP, match=0, vfmax=0;

	IN >> lim1 >> lim2 >> lim3 >> n_el;

	for(int i=0; i<400; i++)										//carichiamo di default tutto X a -1
		X[i] = -1;
	
	for(int i=0; i<n_el; i++)										//inserimo in x solo n_el elementi presi da input
		IN >> x[i];

	IN >> dimP;														//carichiamo la dimensione del pattern da matchare

	for(int i=0; i<dimP; i++)										//carichiamo il pattern sempre da input
		IN >> P[i];

	if(n_el<lim3)													//se il numero di elementi è minore della terza dimensione
		vfmax = n_el;												//la dimensione massima della v-fetta è n_el
	else vfmax=lim3;												//altrimenti è lim3
	
	IN.close();
		
	int nsp = n_el/(lim2*lim3);										//nsp numero di strati pieni
	int	nrp, rim;													//nrp numero di righe piene, rim rimanenti
	if(nsp >=lim1){													//se il numero di strati pieni è uguale o eccede il massimo degli strati
		nrp=lim1*lim2;												//abbiamo lim1*lim2 righe piene 
		rim =0;														//e nessun elemento rimanente (nessuno strato è riempito parzialmente)
	}
	else  {															//altrimenti
		nrp=n_el/lim3;												//la parte intera della divisione ci dà il numero di righe piene
		rim = n_el%lim3;											//e il modulo (che restituisce il resto) ci da quanti elementi rimanenti
	}
	
	int lung = nrp;													//la lunghezza base coincide con il numero di righe piene, stiamo lavorando su v-fette
	
	for(int i=0; i < vfmax; i++){									//navighiamo tra le v-fette
		if(i<rim)													//se i è minore di rim
			lung++;													//la lunghezza della v-fetta aumenta
		match = contaMatch(x+i,lung,lim3,P,dimP);					//invochiamo contaMatch
		OUT << "V-fetta " << i << " = " << match << " match" << endl;
		match=0;
		lung = nrp;
	}

	}
	else
		cout << "errore coi file"<< endl;
}