/*Federico Silvio Busetto 1026925
Integrazione 6 crediti*/
#include<iostream>
#include<fstream>
using namespace std;
//PRE = ("input" contiene almeno 48 interi)
main(){
	int A[6][8];									//Dichiaro un array di interi bidimensionale 6x8 (6righe x 8colonne)
	bool B[6][8];									//e uno di bool
	
	ifstream IN("input");
	ofstream OUT("output");
	
	if(IN && OUT){									//se ci sono entrambi i file
		for(int i=0; i<6; i++)						//parte il ciclo per righe
			for(int j=0;j<8;j++)					//e per ogni riga, per colonne
				IN >> A[i][j];						//inseriamo l'elemento letto da input
		IN.close();									//chiudiamo il file di input
	} else cout << "Errore con i file";				//se non c'è il file di input, stampa un errore
	
/*prendiamo due elementi interi di A da confrontare X, Y con X = A[i][k] e Y = A[z][j] dove i,k indicano 
rispettivamente righe e colonne di X e z,j indicano rispettivamente righe e colonne di Y allora:*/
	for(int i=0; i<6; i++)							// si posizione nella riga di X
		for(int j=0; j<8; j++){ 					// si posiziona nella colonna di Y
			bool trovato=true;						// dichiariamo un bool di default a true per segnare se va a segno o no il confronto
			for(int k=0; k<8 && trovato; k++){		// determina la posizione di X all'interno della riga i, cercando su colonne
				trovato = false;					// 
				for(int z=0; z<6 && !trovato; z++)	// determina la posizione di Y nella colonna j, cercando su righe
					if(A[i][k] == A[z][j])			// se gli elementi coincidono
						trovato = true;				// trovato = true
			}
			B[i][j] = trovato;						// inseriamo nella matrice bool il risultato di trovato
		}
/*POST = ("output" contiene i 48 valori 0/1 (stampati per riga) che per ogni i in [0...5] e j in [0...7], B[i][j] = 1 se e solo se tutti
		 gli elementi della riga A[i] sono presenti anche nella colonna A[][j])*/
		
	for(int i=0; i<6; i++){							//con un ultimo for scriviamo il file di output per righe
		for(int j=0;j<8;j++)						//e per ogni riga, a colonne
			OUT << B[i][j] << " ";					//inseriamo in out il valore della matrice booleana letto
			OUT << endl;							//e andiamo a capo per ogni riga
	}
		OUT.close();								//chiudiamo il file di output
	
}