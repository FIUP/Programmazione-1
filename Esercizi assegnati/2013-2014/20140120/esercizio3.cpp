/*PRE=(il file "input" contiene un intero n (maggiore o uguale a 0), ma, dopo questo primo valore, "input" dovrà soddisfare una delle seguenti due condizioni:
i) contiene una sequenza di almeno n interi tale che tra i primi n non compaiono due valori 0 consecutivi;
ii) contiene una sequenza di interi che ha un prefisso di al più n valori e in cui compaiono due valori 0 consecutivi)*/

#include<iostream>
#include<fstream>
using namespace std;

main(){
	ifstream IN("input");
	ofstream OUT("output");
	if(IN){
		int n;
		IN>>n;
		OUT<<n<<" ";
		int i=0;
		bool uno0=false, due0=false;
		while(i<=n && !due0){
			int x;
			IN>>x;
			i++;
			if(x==0){
				if(!uno0){
					uno0=true;
					if(i==n)
						OUT<<x;
				 }
				else
					due0=true;
			 }
			else{
				if(uno0){
					uno0=false;
					OUT<<0<<" ";
				 }
				OUT<<x<<" ";
			 }
		 }
	 }
	else
		cout<<"Errore nell'apertura del file input"<<endl;
	IN.close();
	OUT.close();
 }

/*POST=(:
a) nel caso PRE (i), "output" deve contenere n seguito dagli n valori letti,
b) nel caso PRE (ii), "output" deve contenere n seguito dai valori letti prima di trovare la prima sentinella*/
