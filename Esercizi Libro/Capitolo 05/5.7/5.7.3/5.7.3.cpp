/*Il programma deve calcolare il numero di occorrenze in C di ciascun carattere alfabetico minuscolo*/
#include<iostream>
using namespace std;
main(){
	char C[10];
	int contmin =0, diff =0;
	int arrcontmin[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	char d;
	cout << "Inserire 10 caratteri"<<endl;
	for(int i=0; i<10; i++)		//inizializza l'array
		cin >> C[i];

	for(int i=0; i<10; i++)
		if(C[i] >=97 && C[i]<=122){
			contmin++;
			diff = C[i] -96;	//tolgo dal carattere attuale i primi 96 caratteri inutili
			arrcontmin[diff]++; //incremento l'array nella posizione del carattere corrispondente
			diff =0; 			//resetto diff
		}
		
	cout << endl;
	cout << "Sono stati trovati " << contmin << " caratteri minuscoli" <<endl;
	cout << endl;
	
	for(int i=0; i<26; i++)		//stampo i conteggi
		if(arrcontmin[i] !=0){			
			d= i+96;
			cout << "Il carattere minuscolo " << d << " e' presente "<< arrcontmin[i] << " volte" << endl;
		}
		
	/*Parte utile solo a non far chiudere subito il prompt su windows*/
	cin.clear();
	cin.ignore(255, '\n');
	cin.get();
}