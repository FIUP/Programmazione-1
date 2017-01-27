#include<iostream>
#include<fstream>
#include<climits>

using namespace std;



//PRE cercaMatch=(indiceT<righe_piene, P ha dimP elementi definiti)
bool cercaMatch(int *T, const int &lim3, int *P, const int &dimP, int indiceT, int j, int indiceP, int dim_colonna, const int &elem_ultima_riga){
	if(j<elem_ultima_riga)
		dim_colonna++; //considero anche l'elemento della colonna nella riga incompleta

	while(indiceP<dimP && indiceT<dim_colonna){
	//R1=(0<=indiceP<=dimP)&&(0<=indiceT<=dim_colonna)
		if(T[indiceT*lim3+j]==P[indiceP]){
			indiceT++;
			indiceP++;
		}else return 0; //non c'è match contiguo
	}//POST1=(ci sono indiceP match singoli di P negli elementi [indiceT..indiceT+indiceP] della colonna j di T)

	// ----- controllo se c'è stato match (contiguo) completo -----
	if(indiceP==dimP) //siamo usciti dal while per indiceP=dimP → match completo
		return 1;
	else return 0; //siamo usciti per indiceT=dim_colonna (ma indiceP!=dimP), cioè abbiamo finito gli elementi definiti ma non il match → non può esserci match completo
}//POST cercaMatch=(ritorna 0 se non c'è match contiguo e completo; 1 altrimenti)



//PRE=(T ha i primi n elementi definiti, n<lim2*lim3, P ha i primi dimP elementi definiti, n_occ>0)
void trova_colonna(int* T, int n, int lim1, int lim2, int lim3, int* P, int dimP, int n_occ, int & indice_c){
  
	int righe_piene=n/lim3;				//numero righe piene nello strato 0
	int elem_ultima_riga=n%lim3;	//numero elementi nell'eventuale riga incompleta dello strato 0
	bool stop=false;							//utile per fermare la ricerca se la condizione viene soddisfatta o abbiamo terminato gli elementi definiti (caso righe_piene=0)

	indice_c=-1;

	for(int j=0; j<lim3 && !stop; j++){
	//R=(0<=j<=lim3)&&(stop se ho trovato un numero di match pari a n_occ o ho terminato gli elementi definiti; !stop altrimenti)

		int match=0;								//variabile necessaria per contare il numero di occorrenze di P per ogni colonna j di T

		// ---------- righe piene ----------
		// la colonna j ha almeno righe_piene-1 elementi definiti
		// cerco il match da riga(0)..riga(righe_piene-dimP+1); non ci possono essere match completi se rimangono meno di dimP elementi definiti nella colonna j
		int i;
		for(i=0; i<righe_piene; i++){
		//R2=(0<=i<=righe_piene)&&(match è il numero di match contigui, completi e sovrapposti di P negli elementi [0..i-1] della colonna j di T)
			match+=cercaMatch(T, lim3, P, dimP, i, j, 0, righe_piene, elem_ultima_riga);
		}//POST2=(match è il numero di match completi, contigui e sovrapposti di P negli elementi definiti della colonna j di T)

		// ---------- riga incompleta ----------
		// i (=righe_piene) e` l'indice dell'evetuale riga incompleta
		// eventuali altri match contigui e completi si verificano solo se dimP==1 (infatti devo controllare solo un elemento)
		if(i==righe_piene && j<elem_ultima_riga){ //se stiamo considerando un elemento definito della riga incompleta

			if(dimP==1){ //altrimenti inutile cercare match completo
				match+=cercaMatch(T, lim3, P, dimP, i, j, 0, righe_piene, elem_ultima_riga);
			}

		}else{ //j==elem_ultimo_strato e nel caso n<lim3 (solo una riga e incompleta) allora ho finito gli elementi definiti di T → stop 
			if(righe_piene==0) 
				stop=true; // non devo considerare altri elementi
		}

		// ----- verifica condizione -----
		// match è il numero di match completi, contigui e sovrapposti di p negli elementi definiti della colonna j di T
		if(indice_c==-1 && match==n_occ){ //è la prima volta che match==n_occ
			indice_c=j;
			stop=true;
		}

	}

}//POST=(se vediamo T come un array a 3 dimensioni X[lim1][lim2][lim3], allora indice_c ha per R-valore l'indice minimo di una colonna di X che contiene esattamente n_m match di P[0..dimP-1], anche sovrapposti tra loro; se nessuna colonna soddisfa questa condizione allora indice_c=-1)



main(){
	ifstream INP("input"); 
	ofstream OUT("output"); 

	if(INP && OUT){
		int n, lim1, lim2, lim3, A[200], P[20], dimP, n_occ, indice_c=-1;
		INP>>n;
		for(int i=0; i<96; i++)
			INP>>A[i];
		INP>>lim1>>lim2>>lim3>>dimP;
		for(int i=0; i<dimP;i++){
			INP>>P[i];
		}
		INP>>n_occ;
		
		trova_colonna(A,n,lim1,lim2,lim3,P,dimP, n_occ, indice_c);
		
		OUT<<indice_c;
		INP.close();
		OUT.close();
	}else cout<<"problemi con i file";
}
