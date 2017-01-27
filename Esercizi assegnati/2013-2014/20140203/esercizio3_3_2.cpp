#include <iostream>
#include <fstream>

using namespace std;


//PRE fette_V=(A ha i primi n elementi definiti, n, lim1, lim2, lim3 sono tutti positivi)

void fette_V(int *A, int lim1, int lim2, int lim3, int n, ofstream &OUT){
	
	if(n>(lim1*lim2*lim3)) //considero solo nei limiti dell'array
		n=lim1*lim2*lim3;

	int strati_pieni=n/(lim2*lim3);
	int righe_ultimo_strato=(n%(lim2*lim3))/lim3;
	int elem_ultima_riga=(n%(lim2*lim3))%lim3;
	
	for(int j=0; j<lim3; j++){
		
		// ---------- strati pieni ----------
		int k;
		for(k=0; k<strati_pieni; k++)
			for(int i=0; i<lim2; i++)
			//R=(0<=i<=lim2)&&(la riga k della V-fetta j è composta dagli elementi A[j+(k*lim2*lim3)+(0*lim3)],..,A[j+(k*lim2*lim3)+((i-1)*lim3)])
						OUT<<A[(j)+(k*lim2*lim3)+(i*lim3)]<<" ";
			//POST=("output" contiene gli elementi dello strato i completo della V-fetta j)
		//POST=("output" contiene gli elementi degli strati completi della V-fetta j)	
		
		// ---------- strati incompleti ----------
		//k è l'indice dell'eventuale strato incompleto
		if(n%(lim2*lim3)!=0){ //esiste uno strato incompleto
				
			// ---------- righe piene ----------
			int i=0;
			for(i=0; i<righe_ultimo_strato; i++)
					OUT<<A[(j)+(k*lim2*lim3)+(i*lim3)]<<" ";
			//POST=("output" contiene gli elementi delle righe complete dello strato incompleto della V-fetta i)
			
			// ---------- riga incompleta ----------
			//k è l'indice dello strato incompleto
			//i è l'indice dell'eventuale riga incompleta
			if(elem_ultima_riga!=0 && j<elem_ultima_riga)//esiste una riga incompleta
			//consideriamo gli elem_ultima_riga solo alle V-fette interessate
				OUT<<A[(j)+(k*lim2*lim3)+(i*lim3)]<<" ";
		}
	}
}

//POST=("output" deve contenere gli elementi definiti (in ordine di posizione in memoria) delle V-fette di A visto come X[lim1][lim2][lim3])


main(){
  ifstream INP("input"); 
  ofstream OUT("output"); 
  if(INP && OUT){
	  int A[100];
  	int n, lim1, lim2, lim3;
  	INP>>n;
  	for(int i=0; i<n; i++)
  	  INP>>A[i];
		INP>>lim1>> lim2 >> lim3;
  	fette_V(A, lim1, lim2, lim3, n, OUT);
	}
  else
  	cout<<"problemi con i file"<<endl;
}


/* PROVA DI CORRETTEZZA: PRE fetta_V < for(iniz; test; incr) C > POST

	Condizione iniziale: PRE fetta_V <iniz> R
----------------------
Dato PRE fetta_V, se i=0 la riga k della V-fetta 0 non ha alcun elemento, infatti è composta dagli elementi A[j+(k*lim2*lim3)+(0*lim3)],..,A[j+(k*lim2*lim3)+(-1*lim3)] → vale R

	Invarianza: R && (i<lim2) <C; incr> R
-------------
Se i<lim2 → R è valido
l'elemento A[(j)+(k*lim2*lim3)+(i*lim3)] fa parte della V-fetta j
i=i+1 e quindi i<=lim2 → vale R

	Condizione di uscita: R && !(i<lim2) → POST
-----------------------
Se i=lim2 allora la riga k della V-fetta i è composta dagli elementi A[j+(0*lim2*lim3)+(0*lim3)],..,A[j+(0*lim2*lim3)+((lim2-1)*lim3)],..,A[j+(k*lim2*lim3)+(0*lim3)],..,A[j+(k*lim2*lim3)+((lim2-1)*lim3)] → vale POST
*/
