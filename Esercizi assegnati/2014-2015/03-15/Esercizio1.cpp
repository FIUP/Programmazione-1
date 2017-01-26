/*Integrazione 6 crediti*/
#include<fstream>
#include<iostream>
using namespace std;
main(){
	int A[2][4][5];								//dichiariamo un array tridimensionale di 2 strati, 4 righe per strato, 5 elementi per riga (5 colonne)
	ifstream IN("input");
	ofstream OUT("output");
/*PRE = input contiene 40 interi, seguiti o dalla coppia "H" x
o dalla coppia "V" y dove x sarà tra 0 e 3 e y tra 0 e 4*/
	
if(IN && OUT){									//se ci sono entrambi i file
	for(int i = 0; i < 2; i++)					//parte il ciclo per caricare l'array per strato
		for(int j=0; j<4; j++)					//riga
			for(int z=0; z<5;z++)				//e colonna
				IN >> A[i][j][z]; 				//prendendo da input
	char c;										//il carattere H o V che indica il tipo di fetta
	int n=-1;									//n è il nostro x o y impostato di defaul a -1 fuori dal range dei valori validi
	IN >> c;									//c viene letto da input
	
	if(c == 'H'){								//se c = H è un H-Fetta
		IN >> n;								//viene letto da input quale H-Fetta è richiesta
		if(n >=0 && n <=3){ 					//individuata h fetta valida
			for(int i = 0; i < 2; i++){			//navigo tra strati
				for(int z=0; z<5;z++)			//e tra le righe di ogni strato
					OUT << A[i][n][z] << " ";	//stampando le righe che compongono l'H-Fetta nel file di output
				OUT << endl;					//andando a capo al termine
			}									//se l'H-Fetta non è valida inseriamo nel file un errore
		} 
		else OUT << "H-fetta non valida, controllare valore di x";	
	}
	if(c == 'V'){								//se c = V è una V-fetta e tutto è come prima tranne per il range
		IN >> n;							
		if(n >=0 && n <=4){ 					//individuata v fetta valida
			for(int i = 0; i < 2; i++){
				for(int j=0; j<4;j++)
					OUT << A[i][j][n] << " ";
				OUT << endl;
			}					
		} 
		else OUT << "V-fetta non valida, controllare valore di y";	
	}
	IN.close();									//chiudiamo il file di input
	OUT.close();								//e quello di output
		//POST = ("output" contiene gli elementi della fetta specificata dalla coppia letta)
} else cout << "Errore con i file";
}