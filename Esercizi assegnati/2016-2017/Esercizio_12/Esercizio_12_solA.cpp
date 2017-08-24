// soluzione di B.Cosentino
#include<iostream>
using namespace std;
//PRE: cin contiene un numero indefinito di interi
int main () {
	int somma=0, min0=0, mag10=0, tra10=0;
	//PRE_while: min0=0 && mag10=0 && tra10=0 && somma=0
	while (min0<5 && mag10<5 && tra10<5) { 
    //R_while: ((min0<=5 && mag10=0 && tra10=0) || (min0=0 && mag10=0 && tra10<=5) || (min0=0 && mag10<=5 && tra10=0)) 
    //          && somma=sommatoria di tutti gli interi prelevati da cin)
		int x;
		cin >> x;
		somma=somma+x;
		if (somma<0){
			min0=min0+1;
			mag10=0;
			tra10=0;
		} else {
			if (somma<=10) {
				tra10=tra10+1;
				min0=0;
				mag10=0;
			} else {
				mag10=mag10+1;
				min0=0;
				tra10=0;
			}		
		}
	}	
	//POST_while: (min0=5 && mag10=0 && tra10=0) || (min0=0 && mag10=0 && tra10=5) || (min0=0 && mag10=5 && tra10=0)
	if (min0==5) {
	    cout << "somma < 0 per 5 volte consecutive" << endl;
	} else {
	   if (tra10==5) {
	       cout << "somma tra 0 e 10 per 5 volte consecutive" << endl;
	   } else {
	        cout << "somma > 10 per 5 volte consecutive" << endl;
	   } 
	}   
	cout << "end" << endl;
}
//POST: mostra somma<0 consecutivamente 5 volte oppure somma>10 consecutivamente 5 volte
//      oppure 0<=somma<=10 consecutivamente 5 volte


// PRE_while -> R_while: (min0=0 && mag10=0 && tra10=0 && somma=0) -> (min0<=5 && mag10<=5 && tra10<=5 && somma=sommatoria di tutti gli interi prelevati da cin, cioe' nessuno) ->
//    -> ((min0<=5 && mag10=0 && tra10=0) || (min0=0 && mag10=0 && tra10<=5) || (min0=0 && mag10<=5 && tra10=0)) && somma=sommatoria di tutti gli interi prelevati da cin

// R_while && condperm -> R_while: ((min0<=5 && mag10=0 && tra10=0) || (min0=0 && mag10=0 && tra10<=5) || (min0=0 && mag10<=5 && tra10=0) &&
// && somma=sommatoria di tutti gli interi prelevati da cin) && (min0<5 && mag10<5 && tra10<5) ->
// -> ((min0<5 && mag10=0 && tra10=0) || (min0=0 && mag10=0 && tra10<5) || (min0=0 && mag10<5 && tra10=0) && somma=sommatoria di tutti gli interi prelevati da cin)
// Prelevo da cin un intero e lo sommo ->  somma=sommatoria di tutti gli interi prelevati da cin.
// Se somma<0, allora min0 viene incrementato di 1 e mag10=tra10=0 e (min0<=5 && mag10=0 && tra10=0). 
// Se somma <= 10, tra10 viene incrementato di 1 e min0=mag10=0 (min0=0 && mag10=0 && tra10<=5).  
// Altrimenti, somma > 10 e mag10 viene incrementato e min0=tra10=0 e (min0=0 && mag10<=5 && tra10=0). 
// In ogni caso, (min0<=5 && mag10=0 && tra10=0) || (min0=0 && mag10=0 && tra10<=5) || (min0=0 && mag10<=5 && tra10=0).
// Quindi, R_while valida

// R_while && !condperm -> POST_while: ((min0<=5 && mag10=0 && tra10=0) || (min0=0 && mag10=0 && tra10<=5) || (min0=0 && mag10<=5 && tra10=0) 
// && somma=sommatoria di tutti gli interi prelevati da cin) && (min0>=5 || mag10>=5 || tra10>=5) ->
// -> (min0=5 && mag10=0 && tra10=0)  || (mag10=5 && min0=0 && tra10=0) || (tra10=5 && min0=0 && mag10=0) -> POST_while
