#include<iostream>
#include<fstream>
using namespace std;


//PRE torta_max=(n_torte>0, X[n_torte][3][4][5] è completamente definito, p_max punta ad una variabile max del main)

void torta_max(int X[][3][4][5], int n_torte, int *p_max){
	int somma_max=0, *pX=***X, somma=0;
	*p_max=0;
	for(int i=0; i<4*5; i++)
		somma_max+=pX[i];
	for(int i=4*5; i<n_torte*3*4*5; i++){
//R=(4*5<=i<=n_torte*3*4*5)&&(somma_max è la somma dei valori massima di almeno uno degli strati della torta *p_max di X[0..(i/(3*4*5))-1][0..((i%(3*4*5))/(4*5))-1][0..(((i%(3*4*5))%(4*5))/5)-1][0..((((i%(3*4*5))%(4*5))%5))-1])
		somma+=pX[i];
		if((i+1)%(4*5)==0){
			if(somma>somma_max){
				somma_max=somma;
				*p_max=i/(3*4*5);
			}
			somma=0;
		}
	}
//POST=(*p_max contiene l'indirizzo di memoria del primo elemento della torta tra tutte le torte di X che contiene lo stato con somma massima maggiore)
}

//POST torta_max=(la funzione inserisce in max l'indice della torta di A che contiene lo strato con somma massima) 


main(){
  ifstream IN("input");
  ofstream OUT("output");
  if(IN){
    int A[3][3][4][5], max, *p=***A;
    for(int i=0; i<3*3*4*5; i++)
      IN>>p[i];

  torta_max(A, 3, &max);

	OUT<<max<<endl;
	IN.close();
	OUT.close();
  }
  else
    cout<<"Errore nell'apertura del file"<<endl;
}


/* 
PROVA DI CORRETTEZZA: PRE torta_max < for(iniz; test; incr) C > POST torta_max

	Condizione iniziale: PRE torta_max <iniz> R
----------------------
Dato PRE torta_max, se i=4*5, somma_max è la somma dei valori massima dello strato 0 della torta *p_max=0 di X[0][0][0..4][0..5])

	Invarianza: R && (i<n_torte*3*4*5) <C; incr> R
-------------
se i<n_torte*3*4*5 → R è valido
sommo a somma X[0..(i/(3*4*5))][0..((i%(3*4*5))/(4*5))][0..(((i%(3*4*5))%(4*5))/5)][0..((((i%(3*4*5))%(4*5))%5))]) e se (i%(3*4*5))==0 allora ho finito una torta e confronto il valore di somma con somma_max: se somma>somma_max allora la nuova somma massima è somma e l'indice della torta è (i/(3*4*5)); alla fine riporto somma a 0 ed aumento l'indice per cercare la somma della prossima torta

	Condizione d'uscita: R && !(i<n_torte*3*4*5) → POST
----------------------
se i=n_torte*3*4*5 → R non è valido
somma_max è la somma dello strato della torta *p_max di X[0..2][0..2][0..3][0..4] → vale POST 
*/
