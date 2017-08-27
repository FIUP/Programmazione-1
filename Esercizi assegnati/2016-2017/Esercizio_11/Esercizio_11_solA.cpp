// soluzione di B.Cosentino
#include<iostream>
using namespace std;
//PRE: cin contiene un numero indefinito di interi
int main () {
	int somma=0, min0=0, mag10=0, tra10=0;
	//PRE_while: min0=0 && mag10=0 && tra10=0 && somma=0
	while (min0<5 && mag10<5 && tra10<5) {  //R_while: (min0<=5 && mag10<=5 && tra10<=5 && somma=sommatoria di tutti gli interi prelevati da cin)
		int x;
		cin >> x;
		somma=somma+x;
		if (somma<0){ 
			min0=min0+1;
		} else {
			if (somma<=10) {
				tra10=tra10+1;
			} else {
				mag10=mag10+1;
			}		
		}
	}
	//POST_while: (min0=5 && mag10<5 && tra10<5)  || (mag10=5 && min0<5 && tra10<5) || (tra10=5 && min0<5 && mag10<5)
	cout << "somma < 0 per " << min0 << " volte" << endl;
	cout << "somma tra 0 e 10 per "<< tra10 <<" volte" << endl;
	cout << "somma > 10 per " << mag10 << " volte" << endl;
	cout << "end" << endl;
}
//POST: quante volte somma<0, somma>10, 0=<somma=<10  

// PRE_while -> R_while: (min0=0 && mag10=0 && tra10=0 && somma=0) -> (min0<=5 && mag10<=5 && tra10<=5 && somma=sommatoria di tutti gli interi prelevati da cin, cioe' nessuno)

// R_while && condperm -> R_while: (min0<=5 && mag10<=5 && tra10<=5 && somma=sommatoria di tutti gli interi prelevati da cin) && (min0<5 && mag10<5 && tra10<5) 
//  -> (min0<5 && mag10<5 && tra10<5 && somma=sommatoria di tutti gli interi prelevati da cin)
//  Prelevo da cin un intero e lo sommo ->  somma=sommatoria di tutti gli interi prelevati da cin.
// Se somma<0, allora min0 viene incrementato di 1 e (min0<=5 && mag10<5 && tra10<5). Se somma <= 10, tra10 viene incrementato di 1 e (min0<5 && mag10<5 && tra10<=5).  
// Altrimenti, somma > 10 e mag10 viene incrementato e (min0<5 && mag10<=5 && tra10<5). In ogni caso, (min0<=5 && mag10<=5 && tra10<=5).
// Quindi, R_while valida

// R_while && !condperm -> POST_while: (min0<=5 && mag10<=5 && tra10<=5 && somma=sommatoria di tutti gli interi prelevati da cin) && (min0>=5 || mag10>=5 || tra10>=5) ->
// -> (min0=5 && mag10<5 && tra10<5)  || (mag10=5 && min0<5 && tra10<5) || (tra10=5 && min0<5 && mag10<5) -> POST_while
