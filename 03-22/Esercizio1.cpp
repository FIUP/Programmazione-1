/*Integrazione 6 crediti - Correttezza non richiesta*/
#include<iostream>
#include<fstream>
using namespace std;
 // struttura input:
 // n_el n_el elementi dims dimr dimc 
 // se dims = 4, dimr = 5 e dimc = 8  Y ES1
 // se dims = 3, dimr = 3 e dimc = 10 Z ES2
 // se dims = 2, dimr = 5 e dimc = 5  W ES3
 // altri modi di vederlo
 // stampa su output come da esempio usando due funzioni
 // una per stampare riga e una per strato
 //Si tratta di vedere un'array di 400 elementi come fosse un'array tridimensionale
 
 //PRE = r punta al primo elemento della riga da stampare, dimR, dimC non nulli
 //r puntatore al primo elemento della riga
 //dimR dimensione di una riga
 //dimC elementi di una riga
 //elemst elementi dello strato
 //nel elementi in totale
 //out flusso di output su file
void stampaRiga(int *r, int dimR, int dimC, int& elemst, int nel, ofstream& out){
	for(int i =0; i<dimC && elemst <= nel; i++){				//se i è minore del numero di elementi della riga & ci sono ancora elementi
		out << *(r+i) << " ";									//stampiamo partendo dal primo elemento della riga, tutti gli elementi della riga
		elemst++;												//usando l'aritmetica dei puntatori ed incrementiamo il puntatore
	}
	out << endl <<endl; 										//dopo ogni riga andiamo a capo e separiamo con una riga vuota
}
 /*POST = su out son stati stampati gli elementi della riga puntata da r
 
 PRE = s punta al primo elemento dello strato da stampare, dimS, dimr, dimc, non nulli*/
void stampaStrato(int * s, int dimS, int dimr, int dimc, int& elemst, int nel, ofstream& out){
	int * pr=s;													//pr punta al primo elemento di ogni riga dello strato
	for(int j=0; j<dimr && elemst <= nel; j++){					//stessa logica di sopra, stavolta per righe
		out << "r" << j << ":";									//stampiamo il numero di riga
		stampaRiga(pr, dimr,dimc, elemst, nel, out);			//e i suoi elementi invocando stampaRiga
		pr +=dimc;												//incrementiamo il puntatore pr che punterà alla riga successiva
	}	
}
//POST = su out vengono stampati gli elementi dello strato puntato da s
 
main(){
  int X[400], *p=X, *q=p, n_el;									//X è l'array vero e proprio, p il puntatore che usiamo per accedere ad X
  ifstream IN("input");											//q il puntatore per accedere ai vari strati
  ofstream OUT("output");
  
if(IN && OUT){
  IN >>n_el;
  if(n_el >0 && n_el < 401){							
	  for (int i=0;i<n_el;i++)									//carichiamo n_el elementi nell'array
		IN>>X[i];												//All'uscita X ha n_el elementi definiti
  int dims=-1, dimr=-1, dimc=-1;								//valori delle tre dimensioni convenzionalmente impostati a -1
  IN >> dims >> dimr >> dimc;									//vedo un array P[dims][dimr][dimc]
  IN.close();
  int elemstamp=1;												//gli elementi già stampanti
  for(int i =0; i<dims && elemstamp <= n_el; i++){				//stessa logica di sopra
	OUT << "strato " << i << endl << endl;						//stampiamo il numero dello strato
	stampaStrato(q, dims, dimr, dimc, elemstamp, n_el, OUT); 	//e i suoi elementi invocando stampaStrato
    q +=(dimr*dimc);											//q punta al primo elemento dello strato, lo aggiustiamo per puntare allo
  }																//strato successivo, incrementandolo di dimr*dimc elementi (gli elementi di uno strato)
  OUT.close();
  } else OUT << "Errore n_el non valido"; 
  } else cout << "Errore con i file";
}