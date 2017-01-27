//Matteo Gazzato 594140  ESERCITAZIONE DEL 13/3/2013 SETTIMANA 8
/*
TEORIA

(i)
Le due funzione f e g differiscono poiché richiedono in ingresso un parametro “a” che
rispettivamente in f è passato per riferimento e in g è passato per valore.
Si noti però che il parametro “a” della funzione f dovrebbe essere a tutti gli effetti un alias di X; ciò
comporta delle complicazioni.

(ii)
Il C ha un solo cast, della forma (type)expression (dove type è il tipo in cui si vuole convertire
expression); tale operatore si basa sulla filosofia fondante del C ovvero “il programmatore sa cosa
sta facendo”; per tale motivo il cast alla C viene sempre eseguito a prescindere dall'obbrobrio o
meno che esso può comportare, il compilatore se ne lava le mani.
Il C++ mette a disposizione più tipi di cast, essi sono più limitati e più controllati dal compilatore.
Tutto ciò al fine di costringere il programmatore a riflettere bene su ciò che vuole ottenere con
quella precisa richiesta di cast e poi di richiederla in modo esplicito, se la richiesta apparirà non
coerente al compilatore esso la segnalerà obbligando il malcapitato ad un'ulteriore riflessione su
cosa stia combinando.

(iii)
Fondamentalmente si tratta di accorgersi che c'è una ed una sola variabile “i” e dunque sia il blocco
del main() (che la inizializza con int i=10;) sia il blocco del ciclo for (che al primo ingresso la
azzera con i=0) utilizzano la stessa “i”.
Un eventuale errore di interpretazione è causato dalle istruzioni che seguono il for, nello specifico
non è (int i=0; i<4; i++) ma semplicemente (i=0; i<4; i++).
Il programma compila e stampa 0 1 1.
*/
#include <iostream>
#include <fstream>
using namespace std;

struct nodo {int info; nodo* next;nodo(int a=0, nodo* b=0){info=a; next=b;}};

void stampa(nodo *x, ofstream &OUT)
{
  if(x)
    {
      OUT<< x->info<<' ';
      stampa(x->next, OUT);
    }
}

void crea(nodo *&L, int dim, ifstream &INP)
{
  if(!dim) //caso base
	{L=0;return;}
  int k; 
  INP>>k;
  L=new nodo(k); 
  crea(L->next, dim-1, INP);//passo induttivo
}//fine crea

nodo* match(nodo *&L, int *P, int dimP)
{
  if(!L) //caso base: match incompleto e lista finita=>non modifico L
    return 0; 
  if (L->info==P[0])//passo induttivo: se arrivo qui la lista non è 
  {					//ancora finita, se c'è un match 
      if (dimP==1) //ho trovato un match completo, perchè questo 
	  {//nodo combacia con l'ultimo elemento di P e devo modificare L
	  		nodo *X=L; 
	  		L=L->next; 
	  		X->next=0; 
	  		return X; 
	  }
      else 
//ho trovato un match tra un nodo della lista ed il p-esimo elemento 
//di P,con 0<=p<dimP-1
	  {		
			//vedo se tale match è completo o incompleto 
	  		nodo *Y=match(L->next,P+1,dimP-1);
	  		if(Y)//il match è risultato completo e devo modificare L
	    	{   
	      		nodo *Z=L; 
	      		L=L->next; 
	      		Z->next=Y; 
	      		return Z; 
	    	}
	  	else//il match è risultato incompleto e non devo modificare L
	    	return 0;
		}
   }
  else//se non c'è match esamino il prossimo elemento 
    return match(L->next, P, dimP); 
}//fine match

main()
{
  ifstream INP("input1"); 
  ofstream OUT("output1");

  if(!INP || !OUT)
  	cout<<"Errori con i file de input o output"<<endl;
  else
  {
      int dim; 
      INP>>dim;
      
      nodo *inizio=0;
      crea(inizio, dim, INP);
      
      int dimP, P[20]; 
      INP>>dimP;
      for(int i=0; i<dimP; i++)
		INP>>P[i];
      
      nodo *y=match(inizio, P, dimP); 

      stampa(y, OUT); 
      OUT << endl;
      stampa(inizio, OUT);
      
      INP.close(); 
      OUT.close();
    }
}//fine main

/*
PRE_crea=(L è una lista corretta,dim è il numero di elementi da 
aggiungere alla lista L,INP è il file di input valido da cui
devo leggere i dim elementi) 

POST_crea=(L è una lista corretta di dim elementi letti dal file di 
inupt INP )

PRE_match=(L è una lista corretta, L=vL, P ha dimP elementi definiti
con dimP>0).

POST_match(se match restituisce col return un valore R diverso da 0, 
allora esiste un match completo di P in L e R è R(vL,P) e il 
valore di L è vL-P) && (se match restituisce 0 allora non c’è alcun 
match di P in L e il valore di L è vL).

CORRETTEZZA match: NB,con vdimP indico il valore iniziale di dimP

caso base: L è una lista vuota=> non possono esistere match completi 
		  di P in L,ritorno 0 && L non viene modificata,quindi L=vL 
			=>POST
			
passo induttivo: verifichiamo PRE_RIC dell'invocazione ricorsiva.
				PRE_RIC=(L->next è una lista corretta e mancano 
				dimP-1 match di P in L per avere un match completo e 
				sull'attuale nodo ho trovato un match) che è vera 
				poichè se L era corretta rispetto a PRE_match allora 
				lo è anche L->next rispetto PRE_RIC e se sono arrivato 
				a questo punto significa che ho già trovato dei match 
				di P in L,in particolare ne ho trovati vdimP-dimP. 
				Quindi assumiamo che anche POST_RIC=(viene ritornato 
				un valore diverso da 0 nel caso in cui ci sia stato 
				un match completo dei rimanenti dimP-1 elementi di P 
				in L) sia vera.
				Se ho ottenuto un match completo sui rimanenti dimP-1
				elementi di P => L deve essere modificata in modo da 
				rimuovere l'attuale nodo su cui è stato fatto match 
				e a cui vanno attaccati i rimanenti dimP-1 nodi di L 
				che hanno fatto match=> viene ritornato un volore R 
				diverso da 0 tale che R è R(vL,P) ed il valore di L 
				è vL-P =>POST
				Se non ho ottenuto un match completo sui rimanenti 
				dimP-1 elementi di P => non devo modificare L e viene
				ritornato un valore R pari a 0 =>POST

*/
