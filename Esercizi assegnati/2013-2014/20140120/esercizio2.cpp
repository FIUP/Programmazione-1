#include<iostream>
#include<fstream>
using namespace std;

main(){
	ifstream IN("input");
	ofstream OUT("output");
//PRE=("input" contiene una sequenza di valori che soddisfa "sono stati letti due 2 oppure tre 3")
	if(IN){
		int n=0, conta2=0, conta3=0;
		while(conta2!=2 && conta3!=3){
//R=(conta2<=2 && conta3<=3)&&(se conta2==2 allora n è il numero di elementi letti a parte i due 2; se conta3==3 allora n è il numero di elementi letti a parte i tre 3; altrimenti n è il numero di elementi finora letti)
			int x;
			IN>>x;
			if(x==2)
				conta2++;
			if(x==3)
				conta3++;
			n++;
			if(conta2==2 || conta3==3){
				if(conta2==2){
					n=n-2;
					OUT<<2<<" "<<n;
				 }
				else{
					n=n-3;
					OUT<<3<<" "<<n;
				 }
			 }
		 }
	 }
//POST=("output" deve contenere 2 o 3 a seconda che nella lettura si incontrino prima due 2 o tre 3, rispettivamente, seguito dal numero dei valori letti senza contare i due 2 o i tre 3 che hanno fatto fermare la lettura)
	else
		cout<<"Errore nell'apertura del file"<<endl;
	IN.close();
	OUT.close();
 }

/* PROVA DI CORRETTEZZA

	condizione iniziale: PRE → R ?
-----------------------
Dato PRE, poichè n=0 non sono stati letti valori, conta2!=2 e conta3!=3 quindi stop=false → vale R

	invarianza: R && (conta2!=2 && conta3!=3){} → R
--------------
se conta2<2 e conta3<3:
- se leggiamo un 2 allora aumento il numero di conta2 e il numero di elementi letti → al ritorno del ciclo vale R
- se leggiamo un 3 allora aumento il numero di conta3 e il numero di elementi letti → al ritorno del ciclo vale R
- altrimenti aumento il numero di valori letti → al ritorno del ciclo vale R

	condizione di uscita: R && !(conta2!=2 && conta3!=3) → POST
------------------------
- se conta2=2 → diminuiamo n (il numero di elementi letti finora) di 2 (gli elementi che hanno fatto fermare il ciclo) → vale POST
- se conta3=3 → diminuiamo n (il numero di elementi letti finora) di 3 (gli elementi che hanno fatto fermare il ciclo) → vale POST */
