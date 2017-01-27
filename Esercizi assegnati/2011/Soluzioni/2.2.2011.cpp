#include<iostream>
#include<fstream>
using namespace std;
//PRE: C[7][8] inizializzato da file, C=C_ 
main(){
	int C[7][8],B[7][8],A[7],a,somma; //inizializzazione da file
	ifstream in ("input.txt");
	for(int i=0; i<7; i++){  //R: 0<=i<=7
		for(int j=0; j<8; j++){ //R: 0<=j<=8, C[i][0..7] = (i*8+j)° numero del file
			in>>C[i][j];
	
			cout << C[i][j] <<"\t";
		}
		cout << endl;
	}
	in.close();
	cout << endl;
	for(int i=0; i<7; i++){ //R: 0<=i<=7, A[i-1] = somma degli elementi della riga i-1
		somma = 0;
		for(int j=0; j<8; j++){  //R: 0<=j<=8 somma = somma degli elementi della riga i fino all'elemento j-1 dell'array C
			somma=somma+C[i][j]; // somma delle varie righe
		}
		A[i]=somma;
	}
	
	for(int i=0; i<7; i++){  //R: 0<=i<=7
		for(int j=0; j<8; j++){  //R: 0<=j<=8, B[i][j-1] = A[i] - C[i][j-1]
			B[i][j]=A[i] - C[i][j];
			cout << B[i][j]<< "\t";
		}
		cout<< endl;
	}

}
//POST: C=C_, B[i][j]= C[i] - C[..][j]
