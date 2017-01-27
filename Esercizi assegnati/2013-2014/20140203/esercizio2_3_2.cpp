#include <iostream>
#include <fstream>
#include <climits>

using namespace std;


//PRE fette_H=(A ha almeno lim1*lim2*lim3 elementi definiti, lim1>0, lim2>0 e lim3>0)

void fette_H(int *A, int lim1, int lim2, int lim3, ofstream & OUT){
	for(int i=0; i<lim2; i++) //righe di A[lim1][lim2][lim3]
//R1=(0<=i<=lim2)&&(A[0..lim1][0..i-1][0..lim3] sono elementi delle H-fette 0,..,i-1 contenenti rispettivamenti le righe 0,..,i-1 dello strato k)
		for(int k=0; k<lim1; k++) //strati di A[lim1[lim2][lim3]
//R2=(0<=k<=lim1)&&(A[0..k-1][i][0..lim3] sono gli elementi delle righe 0,..,k-1 delle H-fette contenenti le righe i degli strati)
			for(int j=0; j<lim3; j++) //colonne di A[lim1][lim2][lim3]
//R3=(0<=j<=lim3)&&(A[k][i][0..j-1] sono elementi dell'H-fetta i contenente le righe i dello strato k)
				OUT<<A[(i*lim3)+(k*lim2*lim3)+j]<<" ";
//POST3=("output" contiene tutti gli elementi della riga k dell'H-fetta i)
//POST2=("output" contiene tutte le righe dell'H-fetta i)
//POST1=("output" contiene tutte le H-fette di A)
} 

//POST fette_H=("output" deve contenere gli elementi delle H-fette (in ordine di posizione nella memoria) di A visto come un array a 3 dimensioni int X[lim1][lim2][lim3])


main(){
  ifstream INP("input"); 
  ofstream OUT("output"); 
  if(INP && OUT){
  	int A[100];
	  int n, lim1, lim2, lim3;
	  INP>>n;
	  for(int i=0; i<n; i++)
	    INP>>A[i];		
  	INP>>lim1>>lim2>>lim3;
  	fette_H(A, lim1, lim2, lim3, OUT);
  }
  else
  	cout<<"problemi con i file"<<endl;
}


/* PROVA DI CORRETTEZZA: PRE fette_H < for(iniz; test; incr) C > POST fette_H

	Condizione iniziale: PRE fette_H <iniz> R
----------------------
Dato PRE fette_H, se j=0, A[0][0][0..-1] non contiene elementi in quanto non ci sono elementi da 0..-1 dell'H-fetta 0 contenente le righe 0 dello strato 0 → vale R

	Invarianza: R && (j<lim3) <C; incr> R
-------------
Se j<lim3, A[k][i][0..j] sono elementi dell'H-fetta i contenente le righe i dello strato k; dopo l'incremento, j<=lim3 → vale R

	Condizione di uscita: R && !(j<lim3) → POST3
-----------------------
Se j=lim3, A[k][i][0..lim3] sono tutti gli elementi dell'H-fetta i contenente le righe i dello strato k → vale POST3
*/
