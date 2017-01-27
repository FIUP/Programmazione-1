#include<iostream>
#include<fstream>
#include<climits>

using namespace std;


//PRE_CercaMatch=(T ha i primi n elementi definiti, P ha i primi dimP elementi definiti, righe_definite è un intero >0)
bool CercaMatch(int *T, int lim3, int *P, int dimP, int i, int j, int righe_definite){
	
	if(i+dimP>righe_definite)
		return 0;
	int match=0;
	for(int iP=0; iP<dimP; iP++){
	//R=(0<=iP<=dimP)&&(0<=match<=dimP)&&(P[0..match-1] matcha in T[0][0..i][j])
		if(*(T+i*lim3+j)==P[iP])
			match++;
		i++;
	}
	if(match==dimP)
		return 1;
	return 0;

}//POST_CercaMatch=(retituisce true se in T c'è un match completo (anche non contiguo) di P; false se non c'è match completo (quindi anche quando non ci sono elementi sufficienti in T))


//PRE=(T ha i primi n elementi definiti, n<lim2*lim3, P ha i primi dimP elementi definiti, n_m>0)

void trova_colonna(int* T, int n, int lim1, int lim2, int lim3, int* P, int dimP, int n_m, int & indice_c){

	int righe_definite=n/lim3;
	int elem_ultima_riga=n%lim3;
	if(elem_ultima_riga)
		righe_definite++;
	indice_c=-1;
	bool trovato=false;
	
	for(int j=0; j<lim3 && !trovato; j++){
	//R1=(0<=j<=lim3)&&(trovato se in T[0][0..righe_definite][0..j-1] la colonna j ha n_m match completi di P (anche sovrapposti); !trovato altrimenti)
		int conta=0;
		if(j<elem_ultima_riga){
			for(int i=0; i<righe_definite; i++){
			//R2=(0<=i<=righe_definite)&&(conta è il numero di match completi (anche sovrapposti) di P in T[0][0..i-1][j])
				//considero le colonne con un elemento denitito nella riga incompleta
				conta+=CercaMatch(T, lim3, P, dimP, i, j, righe_definite);
			}
		} else {
			for(int i=0; i<righe_definite-1; i++){
			//R3=(0<=i<=righe_definite-1)&&(conta è il numero di match completi (anche sovrapposti) di P in T[0][0..i-1][j])
				//cosidero le colonne con soli elementi nelle righe piene
				conta+=CercaMatch(T, lim3, P, dimP, i, j, righe_definite-1);
			}
		}
		if(conta==n_m){
			trovato=true;
			indice_c=j;
		}
	}
	
}

//POST=(se vediamo T come un array a 3 dimensioni X[lim1][lim2][lim3], allora indice_c ha per R-valore l'indice minimo di una colonna di X che contiene esattamente n_m match di P[0..dimP-1], anche sovrapposti tra loro; se nessuna colonna soddisfa questa condizione allora indice_c=-1)


main()
{
  ifstream INP("input1"); 
  ofstream OUT("output"); 

  if(INP && OUT)
{
  int n, lim1, lim2, lim3, A[200], P[20], dimP, n_m, indice_c=-1;
  INP>>n;
  for(int i=0; i<n; i++)
   INP>>A[i];
  INP>>lim1>>lim2>>lim3>>dimP;
  for(int i=0; i<dimP;i++)
   INP>>P[i];
  INP>>n_m;
  trova_colonna(A,n,lim1,lim2,lim3,P,dimP, n_m, indice_c);
  OUT<<indice_c;
  INP.close();
  OUT.close();
}
 else
 cout<<"problemi con i file";
}


/* PROVA DI CORRETTEZZA

	Condizone iniziale: PRE → R1
------------------------------
Dato PRE, se j=0 e trovato=false, non ci sono colonne con un numero di match contigui (anche sovrapposti) di P in T[0][0..righe_definite][0..-1] → vale R1

	Invarianza: R → (j<lim3 && !trovato){} → R
--------------------------------------------
Se non ci sono n_m match completi (anche sovrapposti) di P in T[0][0..righe_definite][j-1] aumento j+1 per controllare nella colonna successiva → vale R perchè j<=lim3 && !trovato

	Condizone di uscita: R && !(j<lim3 && !trovato) → POST
--------------------------------------------------------
- Se j=lim3 && !trovato allora non ci sono n_m match completi (anche sovrapposti) di P in T[0][0..righe_definite][0..lim3-1] → vale POST
- Se j<=lim3 && trovato allora ci sono n_m match completi (anche sovrapposti) di P in T[0][0..righe_definite][j-1] → vale POST

*/
