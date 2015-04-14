/*Integrazione 6 crediti - Correttezza non richiesta*/
#include<iostream>
#include<fstream>
using namespace std;
 // struttura input:
 // n_el n_el elementi dims dimr dimc 
 // se dims = 4, dimr = 5 e dimc = 8  Y ES1
 // se dims = 3, dimr = 3 e dimc = 10 Z ES2
 // se dims = 2, dimr = 5 e dimc = 5  W ES 3
 // altri modi di vederlo
 // stampa su output come da esempio usando due funzioni
 // una per stampare riga e una per strato
 //
 
 //PRE = r punta al primo elemento della riga da stampare, dimR, dimC non nulli
void stampaRiga(int *r, int dimR, int dimC, int& elemst, int nel, ofstream& out){
	for(int i =0; i<dimC && elemst <= nel; i++){
		out << *(r+i) << " ";
		elemst++;
	}
	out << endl <<endl; 
}
 //POST = su out son stati stampati gli elementi della riga puntata da r
 
 //PRE = s punta al primo elemento dello strato da stampare, dimS, dimr, dimc, non nulli
void stampaStrato(int * s, int dimS, int dimr, int dimc, int& elemst, int nel, ofstream& out){
	int * pr=s;
	for(int j=0; j<dimr && elemst <= nel; j++){
		out << "r" << j << ":";
		stampaRiga(pr, dimr,dimc, elemst, nel, out);
		pr +=dimc;
	}	
}
//POST = su out vengono stampati gli elementi dello strato puntato da s
 
main(){
  int X[400], *p=X, *q=p, n_el;
  ifstream IN("input");
  ofstream OUT("output");
  
if(IN && OUT){
  IN >>n_el;
  if(n_el >0 && n_el < 401){
	  for (int i=0;i<n_el;i++)
		IN>>X[i];					//All'uscita X ha n_el elementi definiti
  int dims=-1, dimr=-1, dimc=-1;	//valori delle tre dimensioni convenzionalmente impostati a -1
  IN >> dims >> dimr >> dimc;		//vedo un array P[dims][dimr][dimc]
  IN.close();
  int elemstamp=1;
  for(int i =0; i<dims && elemstamp <= n_el; i++){
	OUT << "strato " << i << endl << endl;
	stampaStrato(q, dims, dimr, dimc, elemstamp, n_el, OUT); 
    q +=(dimr*dimc);
  }
  OUT.close();
  } else OUT << "Errore n_el non valido"; 
  } else cout << "Errore con i file";
}