#include<iostream>
#include<fstream>
#include<climits>

using namespace std;



//PRE numeroMatch=()
void numeroMatch(const int *T, const int &lim2, const int &lim3, const int *P, const int &dimP, const int &strato, const int &riga, const int &elem_definiti, int &match){
	
	int indiceT=0;			//per spostare l'indice nella riga di T
	match=0;						//per ogni riga riparto da 0

	while(indiceT<elem_definiti-dimP+1){ //il match è completo solo se gli elementi rimanenti della riga partendo da indiceT sono >=dimP
		
		int indiceP;
		bool stop=false;
		for(indiceP=0; indiceP<dimP && !stop; indiceP++){
			
			if(T[strato*lim2*lim3+riga*lim3+indiceT]!=P[indiceP])
				stop=true;
			indiceT++;
		}
		if(!stop) //l'ultimo confronto è stato un match → match completo e contiguo
			match++;
	}
	
}//POST numeroMatch=(ritorna il numero di match di P nella riga di T)


  
//PRE trova_strato=(T ha i primi n elementi definiti, n<=200, P ha i primi dimP elementi definiti, dimP<=20, n_m>0)
void trova_strato(int* T, int n, int lim1, int lim2, int lim3, int* P, int dimP, int n_m, int &indice_strato){

	int strati_pieni=n/(lim2*lim3);									//numero strati di T con tutti gli elementi definiti
	int righe_ultimo_strato=(n%(lim2*lim3))/lim3;		//numero righe piene nell'eventuale ultimo strato incompleto di T
	int elem_ultima_riga=(n%(lim2*lim3))%lim3;			//numero elementi definiti nell'ultima riga dell'eventuale riga incompleta nell'eventuale starto incompleto di T

	int match=0;

	// ---------- strati pieni ----------
	int k;
	for(k=0; k<strati_pieni && indice_strato==-1; k++){
	//R1=(0<=k<=strati_pieni)&&(indice_strato=k-1 se lo strato k-1 soddifa la condizione; -1 altrimenti)
		for(int i=0; i<lim2; i++){
		//R2=(0<=i<=lim2)
			numeroMatch(T, lim2, lim3, P, dimP, k, i, lim3, match);
			if(match==n_m)
				indice_strato=k;
		}
	}//POST1=(indice_strato è l'indice dello strato che soddifa la condizione)

	// ---------- strato incompleto ----------
	// k (=strati_pieni) è l'indice dell'eventuale strato incompleto
	if(indice_strato==-1 && k==strati_pieni){ //non abbiamo ancora trovato una riga di uno strato che soddifa la condizione
		
		// ---------- righe piene ----------
		int i;
		for(int i=0; i<righe_ultimo_strato && indice_strato==-1; i++){
			numeroMatch(T, lim2, lim3, P, dimP, k, i, lim3, match);
			if(match==n_m)
				indice_strato=k;
		}

		// ---------- riga incompleta ----------
		// i (=righe_ultimo_strato) è l'indice dell'eventuale riga incompleta
		if(indice_strato==-1 && i==righe_ultimo_strato){
			numeroMatch(T, lim2, lim3, P, dimP, k, i, elem_ultima_riga, match);
			if(match==n_m)
				indice_strato=k;
		}
	}
	
}//POST cerca_strato=(se vediamo T come un array a 3 dimensioni X[lim1][lim2][lim3], allora indice_strato ha per R-valore l'indice minimo di uno strato di X che contiene una riga che contiene esattamente n_m match di P[0..dimP-1], NON sovrapposti tra loro; se nessuno strato soddisfa questa condizione allora indice_strato=-1)



main(){
	ifstream INP("input"); 
	ofstream OUT("output"); 

	if(INP && OUT){
		int n, lim1, lim2, lim3, A[200], P[20], dimP, n_m, indice_strato=-1;
		INP>>n;
		for(int i=0; i<96; i++)
			INP>>A[i];
		INP>>lim1>>lim2>>lim3>>dimP;
		for(int i=0; i<dimP;i++){
			INP>>P[i];
		}
		INP>>n_m;
		
		trova_strato(A,n,lim1,lim2,lim3,P,dimP, n_m, indice_strato);
		
		OUT<<indice_strato;
		INP.close();
		OUT.close();
	}else cout<<"problemi con i file";
}
