#include<iostream>
#include<fstream>
using namespace std;

main(){

ifstream in("input");
ofstream out("output");
	if(in && out){			//PRE
	
		int A[4][5] , B[5][6] , C[4][6] , n = 50, somma = 0;
	
		for(int i = 0; i<4 ; i++){		//R1A
			for(int j = 0; j<5; j++){		//R1B
				in >> A[i][j];	 
			}
		}
		for(int i = 0; i<5 ; i++){		//R2A
			for(int j = 0; j<6; j++){		//R2B
				in >> B[i][j];	
			}
		}
		for(int i = 0; i<4;i++){		//R3A
			for(int j = 0; j<6; j++){		//R3B
				somma = 0;
				for(int a = 0; a < 5; a++){		//R3C
					somma += A[i][a] * B[a][j];
				}		//POSTC
				C[i][j] = somma;
			}		//PSOT3B
		}		//POST3A
		
		for(int i = 0; i<4; i++){		//R4A
			for(int j = 0; j<6; j++){		//R4B
				out<<C[i][j]<<" ";		
			} out<<"\n";		//POST4B
		}		//POST4A
	}
	out.close();
	in.close();
}		//POST


/*
PRE=("input" contiene (almeno) 50 interi)

POST1A = ( A[i][j] definito per la riga i-esima con j € [0..5]
POST1B = ( A[i][..] definito per la i-esima con i € [ 0..4] 
R1A = ( 0<=i<4 && restano da definire ancora 4 - (i+1) righe 
R1B = ( 0<=j<5 && restano da definire ancora 5 - (j+1) colonne

POST2A = ( B[i][j] definito per la riga i-esima con j € [0..6]
POST2B = ( B[i][..] definito per la i-esima con i € [ 0..5] 
R2A = ( 0<=i<5 && restano da definire ancora 5 - (i+1) righe 
R2B = ( 0<=j<6 && restano da definire ancora 6 - (j+1) colonne

POST3A = ( C[i][j] è definito per ogni i € [0..4] ed j € [0..6]
POST3B = ( C[..][j] è definito per ogni j € [0..6] sulla riga i-esima
POST3C = ( C[i][j] += A[i][a] * B[a][j] per ogni a € [0..5]
R3A = ( 0<=i<4 && restano da definire 4 - (i+1) righe di C
R3B = ( 0<=j<6 && restanno da definire 6 - (j+1) colonne di C[i][j] della riga i-esima 
R4B = ( 0<=a<5 && A[i][j] è pari alla somma di A[i][a] * B[a][j] 

POST4A = ( output contiene i valori sino alla i-esima con i € [0..4]
POST4B = ( output contiene i valori sino alla colonna j-esima con j € [0..6] della riga i-esima raggiunta
R4A = ( 0<=i<4 && output contiene i*6 valori 
R4B = ( 0<=j<6 && output contiene (i*6) + (j+1) valori

POST=("output" contiene il valore di tutti gli elementi di C=A * B (scritti per riga))

*/
