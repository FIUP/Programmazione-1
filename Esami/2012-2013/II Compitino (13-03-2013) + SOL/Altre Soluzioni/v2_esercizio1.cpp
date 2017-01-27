#include<iostream>
#include<fstream>
using namespace std;
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};

void stampa(nodo* x, ofstream & OUT)
{
  if(x)
    {
      cout<< x->info<<' ';
      stampa(x->next, OUT);
    }
}

//	PRE=(L e' una lista corretta, dim>=0, INP e' il flusso di input)
void crea(nodo*& L,int dim,ifstream& INP){
	if(dim){
		int i;
		INP>>i;
		L=new nodo(i,0);
		crea(L->next,dim-1,INP);
	}//dim
}//crea
//	POST=(L e' una lista corretta che contiene dim nodi con campi info letti da INP)

nodo* match(nodo*& L,int* P,int dimP){
	if(!L) return 0;
	
	if(L->info==P[0]){
		nodo* x=L,*y;
		if(dimP-1==0){
			x->next=0;
			L=L->next;
			return x;
		}//if
		y=match(L,P+1,dimP-1);
		if(y){
			L=L->next;
			x->next=y;
			return x;
		}//if
		return 0;
	}//if
	return match(L->next,P,dimP);
}//match
/*
Dimostrazione match:
	Caso base: 1) se L e' vuota ritorno 0 perche' significa che non c'e' match. Questo soddisfa la POST perche' L=vL. 2) se sono arrivato alla fine di P (dimP-1==0)
					sposto L al prossimo elemento (che non fara' parte del match), chiudo la lista da ritornare e la ritorno. In questo modo si ha che R(L,P) contiene
					il match di P in L e L-P contiene i nodi non matchati.
	Passo induttivo: 1) se L->info==P[0] significa che sto analizzando un possibile match. In questo caso salvo il nodo corrente e richiamo ricorsivamente match spostando
					il puntatore a P e riducendo la dimensione. Questo e' corretto perche' dimP-1>0, quindi la PRE e' soddisfatta e match ritorna (per ipotesi induttiva)
					la lista R(L,P). Se questa lista e' vuota non faccio nulla e ritorno 0 per segnalare che la lista e' vuota, altrimenti sposto avanti di una posizione
					L e collego a x la lista R(L,P), ritornando x. Quindi L contiene un puntatore al prossimo nodo non matchato e x la lista R(L,P). Questo soddisfa la POST.
					2) se non sto analizzando un possibile match passo al nodo successivo richiamando match con L->next. Questo e' corretto 
					perche' L non e' vuota, quindi L->next e' una lista corretta. Posso assumere la POST e ritorno il risultato di match. La funzione e' corretta.
*/

main()
{
  ifstream INP("input");
  ofstream OUT("output");
  int dim, dimP, P[20];
  INP>>dim;
  
  nodo* inizio=0;
  crea(inizio,dim,INP);//da fare
  
  INP>>dimP;
  for(int i=0; i<dimP;i++)
    INP>>P[i];
  
  nodo* y=match(inizio,P,dimP);//da fare
  stampa(y, OUT);
  cout<<endl;
  stampa(inizio,OUT);
}
