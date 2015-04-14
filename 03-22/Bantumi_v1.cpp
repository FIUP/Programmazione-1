/*Integrazione sei crediti*/ 
#include<iostream>
#include<fstream>
using namespace std;

void stampa(int (*B)[7], ofstream & OUT){
	cout<<"("<<B[0][6]<<")\t";
	OUT<<B[0][6]<<" ";
	for(int j=5; j>=0; j--){
		cout<<B[0][j]<<"\t";
		OUT<<B[0][j]<<" ";
		 }
	cout<<endl;
	for(int j=0; j<6; j++){
		cout<<B[1][j]<<"\t";
		OUT<<B[1][j]<<" ";
	 }
	cout<<"("<<B[1][6]<<")"<<endl;
	OUT<<B[1][6];
 }

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
