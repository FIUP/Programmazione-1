#include <iostream>
#include <fstream>

using namespace std;


//PRE calcola=(A ha i primi n elementi definiti, Tass ha 400 elementi, n>0, lim1>0, lim2>0, lim3>0, lim1*lim2*lim3<=200)

void calcola(int *A, int Tass[][2], int &etass, int n, int lim1, int lim2, int lim3, int z){

	if(n>(lim1*lim2*lim3)) //considero nei limiti dell'array A[lim1][lim2][lim3]
		n=lim1*lim2*lim3;

	int strati_definiti=n/(lim2*lim3);
	int righe_ultimo_strato=(n%(lim2*lim3))/lim3;
	int elem_ultima_riga=(n%(lim2*lim3)%lim3);
	bool confronto=true;
	
	int minori=0, maggiori=0; //elementi minori/maggiori di z nel tassello
	etass=0;

		for(int i=0; i<lim2; i++){
		//R1=(0<=i<=lim2)&&(R2)
			for(int j=0; j<lim3; j++){
			//R2=(0<=j<=lim3)&&(R3)
			//elementi di Tass[etass][2] ordinati per righe di A[lim1][lim2][lim3]
				
				confronto=false;

				// ---------- strati definiti ----------
				int k;
				for(k=0; k<strati_definiti; k++){
				//R3=(0<=k<=strati_definiti)&&(mirori/maggiori è il numero di elementi definiti minori/maggiori di z in A[0..k-1][i][j])
					if(A[k*lim2*lim3+i*lim3+j]!=z){
						if(A[k*lim2*lim3+i*lim3+j]<z)
							minori++;
						else
							maggiori++;
					}
					confronto=true;
				}//POST=(minori/maggiori è il numero di elementi minori/maggiori di z in A[0..strati_definiti][i][j])
			
				// ---------- strato incompleto ----------
				//k è l'indice dello strato incompleto
				if(k==strati_definiti){ //solo se sono nello strato incompleto ed entro solo se ci sono elementi definiti del tassello
					if(n%(lim2*lim3)!=0){ //esiste uno strato incompleto

						// ---------- righe definite ----------
						if(i<righe_ultimo_strato){
							if(A[k*lim2*lim3+i*lim3+j]!=z){
								if(A[k*lim2*lim3+i*lim3+j]<z)
									minori++;
								else
									maggiori++;
							}
							confronto=true;
						}

						// ---------- riga incompleta -----------
						else 
							if(i==righe_ultimo_strato){ //solo se sono nella riga incompleta
								if(j<elem_ultima_riga){ // if(elem_ultima_riga!=0) inutile!!
									if(A[k*lim2*lim3+i*lim3+j]!=z){
										if(A[k*lim2*lim3+i*lim3+j]<z)
											minori++;
										else
											maggiori++;
									}
									confronto=true;
								}
							}
					}
				}
				
				//minori/maggiori è il numero di elem maggiori/minori del tassello (i;j)
				//riempio Tass[][]
				if(minori==maggiori && confronto){ //se è stato fatto almeno un confronto
					Tass[etass][0]=i;
					Tass[etass][1]=j;
					etass++;
				}
			
				minori=0;
				maggiori=0;
		
			}//POST=(Tass[0..etass-1][0..1] contiene (i;0..lim3) se minori==maggiori)
		}//POST=(Tass[0..etass-1][0..1] contiene (0..lim2;0..lim3) se minori==maggiori)
}

//POST calcola=(le coppie di elementi di Tass, (Tass[0][0], Tass[0][1]), (Tass[1][0], Tass[1][1]),..,(Tass[etass-1][0], Tass[etass-1][1])) contengono le coordinate di tutti i tasselli di X[lim1][lim2][lim3] tali che le loro parti definite contengano un uguale numero di valori minori di z e di valori maggiori di z (i valori uguali a z non contano). Inoltre questi tasselli sono in Tass in ordine crescente rispetto all'ordine definito nell'Esempio)


main(){
  ifstream INP("input"); 
  ofstream OUT("output"); 
  if(INP && OUT){
	  int A[200];
  	int n, lim1, lim2, lim3, lim4, etass, z;
  	INP>>n;
  	for(int i=0; i<n && i<500; i++)
  	  INP>>A[i];
  	INP>>lim1>>lim2>>lim3>>z;
  	int Tass[200][2]; 
  
		calcola(A, Tass, etass, n, lim1, lim2, lim3, z);

  	for(int i=0; i<etass; i++)
  		OUT<<Tass[i][0]<<' '<<Tass[i][1]<<endl;
	}
  else
    cout<<"problemi con i file"<<endl;
}


/* PROVA DI CORRETTEZZA: PRE calcola < calcola() > POST calcola

	Condizione iniziale:
----------------------
Dato PRE calcola, se i=j=k=0 il numero degli elementi definiti finora è 0 e quindi minori/maggiori=0 → vale R3-R2-R1

	Invarianza:
-------------
Se k<strati_definiti → vale R3 
controlla se il k-esimo elemento del tassello di coordinate (i;j) è minore/maggiore di z; successivamente k<=strati_definiti → vale R3

	Condizione di uscita:
-----------------------
Se k=strati_definiti e non c'è uno strato incompleto allora Tass[etass-1][0..1] contiene le coppie di coordinate (0..lim2-1;0..lim3-1) tali che minori=maggiori → vale POST
Nel caso ci fosse uno strato incompleto, sucessivamente controlla se c'è un elemento che appartenente al tassello di coordinate (i;j) e controlla se è minore/maggiore; nel caso minori=maggiori allora aggiunge in Tass[etass][0..1] (i;j) → vale POST
*/
