#include<iostream>
#include<fstream>
using namespace std;

main(){
ifstream in("input");
ofstream out("output");
if(in && out){

		int due = 0 , tre = 0, values = 0, x;
	
		while (	due != 2 && tre != 3 && !in.eof() ) {
			in >> x; 
			if ( x == 2 ) due++;
			if ( x == 3 ) tre++;
			values++;
			cout<<" letto " << x<<"/"<< due <<"/"<<tre<<"/"<<values<<endl;
		}
		if( due == 2 ) { values = values - 2; out<<"2"<<" "<<values; }
		if( tre == 3 ) { values = values - 3; out<<"3"<<" "<<values; }
		in.close();
		out.close();
		} else cout<<"problemi con il file di input / output"<<endl;

}

/*
PRE = "input" contiene una sequenza di valori che soddisfa la condizione richiesta ( sono stati letti due 2 oppure tre tre 


R = 0<=values  ( si potrebbe usare semplice indice n potendo quindi limitare superiormente values " 0<= values < n " con n = values + 1 ) e sono stati letti values valori 

POST = ( "output" deve contenere 2 o 3 a seconda che nella lettura si incontrino prima due 2 o tre 3, rispettivamente , seguito dal numero dei valori letti senza contare i due 2 o i tre 3 che hanno fatto fermare la lettura 



*/
