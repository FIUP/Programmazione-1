/*Federico Silvio Busetto 1026925
Integrazione 6 crediti*/
#include<iostream>
#include<fstream>
using namespace std;
//PRE = ("input" contiene almeno 48 interi)
main(){
	int A[6][8];
	bool B[6][8];
	
	ifstream IN("input");
	ofstream OUT("output");
	
	if(IN && OUT){
		for(int i=0; i<6; i++)
			for(int j=0;j<8;j++)
				IN >> A[i][j];
		IN.close();
	} else cout << "Errore con i file";
	
	/*prendiamo due elementi interi di A da confrontare X, Y con X = A[i][k] e Y = A[z][j]
	dove i,k indicano rispettivamente righe e colonne di X e 
	z,j indicano rispettivamente righe e colonne di Y allora:*/
		for(int i=0; i<6; i++)							// si posizione nella riga di X
			for(int j=0; j<8; j++){ 					// si posiziona nella colonna di Y
				bool trovato=true;
				for(int k=0; k<8 && trovato; k++){		// determina la posizione di X all'interno della riga i, cercando su colonne
					trovato = false;
					for(int z=0; z<6 && !trovato; z++)	// determina la posizione di Y nella colonna j, cercando su righe
						if(A[i][k] == A[z][j])
							trovato = true;
				}
				B[i][j] = trovato;
			}
		/*POST = ("output" contiene i 48 valori 0/1 (stampati per riga) che 
		 per ogni i in [0...5] e j in [0...7], B[i][j] = 1 se e solo se tutti
		 gli elementi della riga A[i] sono presenti anche nella colonna A[][j])*/
		
	for(int i=0; i<6; i++){
		for(int j=0;j<8;j++)
			OUT << B[i][j] << " ";
			OUT << endl;
	}
		OUT.close();
	
}