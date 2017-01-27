//PRE=("input" contiene almeno 48 interi)

#include<iostream>
#include<fstream>
using namespace std;

main(){
	ifstream IN("input");
	ofstream OUT("output");
	if(IN){
		int A[6][8];
		for(int i=0; i<6; i++)
			for(int j=0; j<8; j++)
				IN>>A[i][j];
		bool B[6][8];
		for(int i=0; i<6; i++){
			for(int j=0; j<8; j++){
				int c, r;
				bool match=true;
				c=0;
				while(match && c<8){
//finchè ci sono elementi e c'è stato match fino a prima
//R1=(0<=c<=8)&&(se match allora c'è corrispondenza tra gli elementi A[i][0..c-1] e A[0..7][j]; se !match l'elemento A[i][c] non ha nessuna corrispondenza in A[0..5][j]
					r=0;
					int trovato=false;
					while(!trovato && r<6){
//finchè ci sono elementi e non ho trovato una corrispondenza
//R2=(0<=r<=6)&&(se !trovato non ci sono corrispondenze tra A[i][c] e A[0..r-1][j]; se trovato allora A[i][c]==A[r][j] ed è la prima corrispondenza
						if(A[i][c]==A[r][j])
							trovato=true;
//se c'è corrispondenza mi fermo
						else r++;
//altrimenti cerco nell'elemento della colonna sucessiva
					 }
					if(!trovato)
						match=false;
//se non ho trovato corrispondenza su tutta la riga allora mi fermo
					else{
						match=true;
						c++;
					 }
//altrimenti continuo con il prossimo elemento della colonna j
				 }
				if(match)
					B[i][j]=1;
				else B[i][j]=0;
				OUT<<B[i][j]<<" ";
//se alla fine vale match allora c'è match completo
			 }
			OUT<<endl;
		 }
	 }
	else
		cout<<"Errore nell'apertura del file"<<endl;
        IN.close();
        OUT.close();
 }

//POST=("output" contiene i 48 valori 0/1 di B (stampati per riga) che rispettano la condizione specificata prima)

//CONDIZIONE: B[i][j]=true se e solo se la riga A[i] ha tutti gli elementi contenuti nella colonna A[][j]
