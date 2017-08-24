// soluzione di B.Cosentino
#include<iostream>
using namespace std;

int main(){

	int A[6][8];
	bool B[6][8];
	for(int i=0; i<6; i=i+1){
		for(int j=0; j<8; j=j+1)
			cin>>A[i][j];
	}
 
	for(int i=0; i<6; i=i+1){ // R1 = (0<=i<=6) && (l'array B e' stato riempito correttamente fino alla riga i-1)
		for(int j=0; j<8; j=j+1){ // R2 = (0<=j<=8) && (la riga i dell'array B e' stata riempita correttamente fino alla posizione j-1)
			
			bool OK = true;
		
			for (int k=0; k<8 && OK; k=k+1){ // R3 = (0<=k<=8) && (OK==true sse i primi k-1 elementi della riga i diversi dall'incrocio non sono contenuti colonna j)
				if (A[i][k]!=A[i][j]){
					for (int l=0; l<6 && OK; l=l+1){ // R4 = (0<=l<=6) && (OK==true sse A[i][k] non e' tra i primi l-1 elementi della colonna j)
					    if (A[i][k]==A[l][j])
					        OK=false;
					}
				}			
			}
			B[i][j] = OK;
		}
	}
	
	cout<<"start"<<endl;
	for(int i=0; i<6; i=i+1){
		for(int j=0; j<8; j=j+1)
			cout<<B[i][j]<<' ';
	cout<<endl;
	}
	cout<<"end"<<endl;
}
