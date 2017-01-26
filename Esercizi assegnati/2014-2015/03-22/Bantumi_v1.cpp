/*Integrazione sei crediti*/ 
#include<iostream>
#include<fstream>
using namespace std;
	
void stampa(int (*B)[7], ofstream & OUT){
	cout<<"("<<B[0][6]<<")\t";						//stampa a video il granaio del player 0
	OUT<<B[0][6]<<" ";								//e su file output
	for(int j=5; j>=0; j--){						//tramite for stampiamo a video e su file gli elementi rimanenti
		cout<<B[0][j]<<"\t";
		OUT<<B[0][j]<<" ";
		 }
	cout<<endl;										//andiamo a capo a video
	for(int j=0; j<6; j++){							//e stampiamo alla rovescia gli elementi dell'altro giocatore
		cout<<B[1][j]<<"\t";
		OUT<<B[1][j]<<" ";
	 }
	cout<<"("<<B[1][6]<<")"<<endl;					//chiudendo con il suo granaio
	OUT<<B[1][6];
 }
/*POST stampa = Stampa la tavola */
main(){
	ifstream IN("input");
	ofstream OUT("output");
	if(IN){
		int B[2][7];
		for(int i=0; i<2; i++)
			for(int j=0; j<7; j++)
				IN>>B[i][j];
		stampa(B, OUT);
	 }
	else
		cout<<"Errore nell'apertura del file"<<endl;
	IN.close();
	OUT.close();
 }
