#include<iostream>
#include<fstream>
using namespace std;
/*
PRE_CC=(X è array 10x10 con i primi dim elementi definiti, dim>0) && (c è una colonna di X che
sicuramente contiene qualche elemento definito)
*/
int CC(int X[][10],int dim,int c){
  int contael,r=0,diversi=0;
  bool cdiversi=true;
  contael=c;
  while(contael<dim){
    for(int i=0;i<r && cdiversi;i++){
      if(X[i][c]==X[r][c])
	cdiversi=false;
    }
    if(cdiversi)
      diversi++;

    cdiversi=true;
    contael+=10;
    r++;
  }
  return diversi;
}
/*
POST_CC=( CC restituisce il numero di valori distinti contenuti nella colonna c di X (considerando
solo gli elementi definiti di c))
*/


//PRE_F=(A è array 10x10 con i primi dim elementi definiti, dim>0)
int F(int A[][10],int dim,int & kol){
  bool colvuota=false;
  int v=dim,val;
  for(int i=0;i<10 && !colvuota;i++){//R1
    if(i<dim){
	val=CC(A,dim,i);
	if(val<v){
	  v=val;
	  kol=i;
	}
    }
    else
      colvuota=true;
  }//POST1
  return v;
}
/*
POST_F=F restituisce un intero v col return e un altro intero kol, passato per riferimento, questi
due valori restituiti sono tali che: (la colonna kol di A ha un numero pari a v di valori distinti e
nessuna altra colonna di A ha un n. inferiore a v di valori distinti).
*/
main()
{
  ifstream INP("input1");
  ofstream OUT("output1");
  if(!INP || !OUT)
    cout<<"ERRORE nei FILE"<<endl;
  else
    {
      int A[10][10],dim, *p=*A,kol=-1;
      //lettura di dim e di A
      INP>>dim;
      for(int i=0;i<dim;i++)
	INP>>p[i];

      int k=F(A,dim,kol); // funzione da fare e che chiama CC

      OUT<<k<<' '<<kol<<endl;
      INP.close();
      OUT.close();
    }
}
/*
R1
(0<=i<=10) &&
colvuota vera --> i-1 e' una colonna vuota --> A e' un array formato da una sola riga e i-1 elementi &&
colvuota falsa --> la colonna i-1 ha almeno un elemento

POST1
(i=10 && !colvuota) --> ogni colonna ha almeno un elemento &&
(i=10 && colvuota) --> la colonna di indice 9 e' vuota &&
(i<10 && colvuota) --> la colonna di indice i-1 e' vuota &&
*/


/*
CORRETTEZZA DI F
-Condizione iniziale:
i=0 assumendo per ipotesi che dim>0 la funzione viene richiamata e il ciclo for all'interno eseguito almeno la prima volta, avendo come v e kol i valori della prima colonna

-Invarianza:
La funzione si sviluppa con il ciclo for,dopo aver verificato le condizioni di ingresso nel ciclo cioe' R1, controlla se la riga osservata ha almeno un elemento prima di richiamare CC (che preveve da PRE_CC che le colonne a lei inviate non siano vuote),
se la colonna e' vuota CC non viene richiamata e colvuota viene reinizializzata a TRUE, al prossimo controllo del ciclo for non si entrera'
se la colonna non e' vuota, CC viene richiamata.
CC restituisce i valore val (numero di elementi differenti su quella colonna),
se val e' inferiore al minore finora trovato (v), il suo valore verra' copiato in v e kol assumera' l'indice della colonna attualmente osservata,
se val non e' inferiore si avanza col ciclo

-Condizione di uscita:
la funzione F termina con il ciclo for al suo interno cioe' quando e' verificata la POST 1
quando sono state controllate tutte le 10 colonne oppure quando si e' trovata una colonna vuota
*/


/*
Domanda di teoria
char X[5][10][10][10]               i char occupano 1 byte

X e' di tipo char(*)[10][10][10]

*(X[-4]+2)-3

    TIPO:    char(*)[10]
    DIMENSIONE: punta ad un oggetto di dimensione 10*(1byte)
    VALORE:  X[-4]+2 equivale a (*X-4)+2 = *X-2 = X-2*10*10*1byte
             **X-3 = X-3*10*1
             quindi l'espressione equivale a:
	     X-2*10*10*1-3*10*1

X[-2][-2]+2
    TIPO:    char(*)[10]
    DIMENSIONE: punta ad un oggetto di dimensione 10*(1byte)
    VALORE:  equivale a (*(*X-2)-2)+2 = *(*X-2) = X-2*10*10*1
*/
