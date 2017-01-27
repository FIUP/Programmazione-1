#include<iostream>
#include<fstream>
using namespace std;

main(){
	ifstream IN("input");
	ofstream OUT("output");
	if(IN){
//PRE=("input" contiene una sequenza di valori)
		int n;
		IN>>n;
		
		if(n>2){
			int min1, min2, min3, a, b, c;
			IN>>a>>b>>c;
			if(a<=b){
				if(a<=c){
					min1=a;
					if(b<=c){
						min2=b;
						min3=c;
					}else{ //c<b
						min2=c;
						min3=b;
					}
				}else{ //c<a
					min1=c;
					min2=a;
					min3=b;
				}
			}else{ //b<a
				if(b<=c){
					min1=b;
					if(a<=c){
						min2=a;
						min3=c;
					}else{ //c<a
						min2=c;
						min3=a;
					}
				}else{ //c<b
					min1=c;
					min2=b;
					min3=a;
				}
			}
			
			int i=3;
			while(i<n){
//R=(3<=i<=n)&&(min1 è il valore più piccolo, min2 è il secondo valore più piccolo e min3 è il terzo valore più piccolo di quelli letti)
				int x;
				IN>>x;
				i++;
				if(x<min1){
					min3=min2;
					min2=min1;
					min1=x;
				 }
				else{
					if(x<min2){
						min3=min2;
						min2=x;
					 }
					else{
						if(x<min3)
							min3=x;
					 }
				 }
			 }
			OUT<<n<<" "<<min3;
		 }
		else OUT<<n<<" problema impossibile";
/* POST=("output" contiene n, seguito da:
i) se n<=2, la stringa "problema impossibile"
ii) se n>2, il terz'ultimo valore de gli n letti) */
	 }
	else cout<<"Errore nell'aperture del file input";
	IN.close();
	OUT.close();
 }

/* PROVA DI CORRETTEZZA
 
	condizione iniziale: PRE → R ?
-----------------------
Dato PRE, se i=3 e min1, min2, min3 sono rispettivamente il più piccolo, il secondo più piccolo e il terzo più piccolo dei valori letti → vale R

	invarianza: R && (i<n){} → R
--------------
se i<n → R è valido
leggo il prossimo valore e lo confronto con i minimi precedenti → al ritorno min1, min2, min3 saranno rispettivamente il più piccolo, il secondo più piccolo e il terzo più piccolo dei valori letti che sono diventati i+1 → R è ancora valido 
NB: infatti anche se i=n-1, dopo il ciclo i=n-1+1=n che soddisfa R

	condizione d'uscita: R && !(i<n) → POST
-----------------------
se i=n (già letto l'ultimo valore) → R non è valido
output contiene min1, min2, min3 che sono rispettivamente il più piccolo, il secondo più piccolo e il terzo più piccolo dei primi n valori presenti in input dopo il valore n → vale POST
*/
