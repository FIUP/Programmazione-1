//PRE=("input" contiene (almeno) 50 interi)

#include<iostream>
#include<fstream>
using namespace std;

main(){
	ifstream IN("input");
	ofstream OUT("output");
	if(IN){
		int A[4][5], B[5][6], C[4][6];
		for(int i=0; i<4; i++)
//R1=(0<=i<=4)&&(A[0..i-1][0..5] e` definita)
			for(int j=0; j<5; j++)
//R2=(0<=j<=5)&&(A[0..i][0..j-1] e` definita)
				IN>>A[i][j];
		for(int i=0; i<5; i++)
//R3=(0<=i<=5)&&(B[0..i-1][0..6] e` definita)
			for(int j=0; j<6; j++)
//R4=(0<=j<=6)&&(B[0..i][0..j-1] e` definita)
				IN>>B[i][j];
		for(int i=0; i<4; i++)
//R5=(0<=i<=4)&&(C[0..i-1][0..5] e` definita)
			for(int j=0; j<6; j++){
//R6=(0<=j<=6)&&(C[0..i][0..j-1] e` definita)
				int c=0;
				for(int k=0; k<5; k++){
//R7=(0<=k<=5)&&(c e` il risultato della sommatoria del prodotto della riga [0..k-1] di A e della colonna [0..k-1] di B)
					int a=A[i][k], b=B[k][j];
					c=c+(a*b);
				 }
				C[i][j]=c;
			 }
		for(int i=0; i<4; i++){
//R8=(0<=i<=4)&&(C[0..i-1][0..6] e` presente su "output")
			for(int j=0; j<6; j++)
//R9=(0<=i<=6)&&(C[0..i-1][0..j-1] e` presente su "output")
				OUT<<C[i][j]<<"\t";
			OUT<<"\n";
		 }
	 }
	else
		cout<<"Errore nell'apertura del file"<<endl;
 }

//POST=("output" contiene il valore di tutti gli elementi di C=A*B (scritti per riga))

/* PROVA DI CORRETTEZZA

	condizione iniziale: PRE -> R ?
-----------------------
Dato PRE, k=0 e c e` il risultato della sommatoria del prodotto della riga [0..-1] di A e colonna [0..-1] di B, cioe` 0 -> vale R

	invarianza: R && (k<5) -> R
--------------
Se k<5 allora aggiungo a c il prodotto di A[i][k] e B[k][j]
al ritorno del ciclo k<=5 e c e` il risultato della sommatoria del prodotto della riga [0..k-1] di A e della colonna [0..k-1] di B -> vale R

	condizione di uscita: R && !(k<5) -> POST
------------------------
Quando k=5 su output e` presente il prodotto di A[4][5] e B[5][6] -> vale POST
*/
