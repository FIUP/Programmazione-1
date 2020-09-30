#include<iostream>
using namespace std;

struct nodo{int info; nodo* next;nodo(int a=0, nodo* b=0){info=a; next=b;}};
struct coda{nodo* primo,*ultimo;coda(nodo*a=0){primo=a; ultimo=a;}};

coda push_end(coda x, nodo*p)
{
  p->next=0;
  if(!x.primo)
    x.primo=x.ultimo=p;
     else
    {
      x.ultimo->next=p;
      x.ultimo=p;
    }
  return x;
}

nodo* faiLista()
{
  int x;
  cin>> x;
  if(x==-1) return 0;
  return new nodo(x, faiLista());
}
void stampaL(nodo*L)
 {
   if(L)
     {
       cout<<L->info<<' ';
       stampaL(L->next);
     }
   cout<<endl;

 } 
 
// PRE= (Lista(L) è ben formata, A ha nA elementi strettamente crescenti, vL =L)

coda preleva(nodo*&L, int*A, int nA) {
    coda Q1=0; // Q1 è la coda dei nodi prelevati
    coda Q2=0; // Q2 è la coda dei nodi che devono rimanere in L;
    int i=0;
	/* PRE= (Q1 e Q2 sono due code == 0, nA indica il numero degli elementi dell'array, 
			 L ben formata e i==0 e' il contatore degli indici dei nodi di L) */
    while (nA && L) { 
		/* R1=((lista(L) e' ben formata && nA>=0 && i>=0) && (Q1 e' la coda che contiene i nodi corrispondenti agli 
				indici di A (se ce ne sono) e Q2 i nodi che non sono corrispondenti agli indici di A)) */
        nodo*x=L;
        L=L->next;
        x->next=0;
        if(i==A[0]) {
            Q1=push_end(Q1, x);
            A=A+1;
            nA=nA-1;
        }
        else {
            Q2=push_end(Q2, x);
        }
        i=i+1;
    }
	/* POST=(Q1 contiene TUTTI i nodi prelevati da L corrispondenti agli indici di A (se ce ne sono),
			Q2 contiene i nodi restanti di L (se ce ne sono) fino a nA==0)
	Quindi ho 2 casi: 
	Caso 1 - L e' finita e nA>=0: non faccio niente perche' non ho piu' nodi da prelevare
	Caso 2 - L ha ancora elementi e nA==0: non ho piu' elementi da prelevare pero' 
	devo mettere i restanti elementi di L in Q2
    */
	// PRE=(L e' ben formata (se L non ha piu' elementi allora non entro nel ciclo), nA>=0)
    while(L) { 
// R=((lista(L) e' ben formata) && (Q2 contiene i nodi di L che non corrispondono agli indici di A))
		nodo*x=L;
		L=L->next;
		x->next=0;
		Q2=push_end(Q2, x);
    }
	// POST=((L e' vuota) && (Q2 contiene TUTTI i nodi di L che non corrispondono agli indici di A))
    L=Q2.primo;
    return Q1.primo;
}

/* POST=(restituisce col return una coda che gestisce una lista con i nodi di vL che 
		 corrispondono agli indici in A, L è vL a cui sono tolti i nodi restituiti col return)

/* DIMOSTRAZIONE DI CORRETTEZZA
PRE= (Q1 e Q2 sono due code vuote, nA>0 indica il numero degli elementi dell'array, 
	 L ben formata e i==0 e' il contatore degli indici dei nodi di L)

R1=((nA>=0 && L>=0 && i>=0) && (stacco ciascun nodo di L, x punta al nodo staccato e se 
  l'elemento A[0...nA-1] corrisponde all'i-esimo nodo di L allora il nodo puntato da x 
  viene inserito in Q1, altrimenti viene inserito in Q2.))

POST= (Q1 contiene i nodi prelevati da L corrispondenti agli indici di A (se ce ne sono),
	  Q2 contiene i nodi restanti di L (se ce ne sono))

Per dimostrare la correttezza del programma devo dimostrare le 3 seguenti ipotesi o regole di correttezza:
1) la PRE implica l'invariante R.
2) l'invariante R && la condizione B del while col corpo implicano l'invariante R.
3) l'invariante R && la negazione della condizione (!B) del while implicano la POST.

1) R1 rispetta la condizione iniziale? Si':
- Q1 e Q2 ==0, contengono una i nodi di L corrispondenti agli indici di A, l'altra il resto dei nodi di L. 
Ok, all'inizio sono vuote perche' devono ancora essere riempite attraverso il ciclo; 
- nA>0 ok; 
- L ben formata ok;
- i==0 ok. 

2) R1 rispetta l'invarianza? Sì, all'inizio dell'iterazione stacco il primo nodo di L e posso avere due casi:
- se A[0]==i allora vado a mettere il nodo staccato in Q1 con la funzione push_end;
- se A[0]!=i allora vado a mettere il nodo staccato in Q2 con la funzione push_end;
Nel momento in cui stacco il nodo faccio puntare L al nodo successivo con l'istruzione L=L->next. 
A questo punto incremento i poiche' mi trovo davanti un nuovo nodo, l'i+1-esimo nodo.
Il ciclo va avanti finche' ho nodi da prelevare o elementi nella lista L.
Se L e' finita o nA==0 R rispetta ancora l'invarianza.

3) R1 rispetta la condizione di uscita? Si'.
Usciremo dal ciclo quando L sara' finita o nA==0, allora implica la POST in quanto ho 2 casi: 
- L e' finita e nA>=0
- L ha ancora elementi e nA==0. 
R1 rispetta questa condizione? Sì: 
- nA>=0 ok; 
- L>=0 ok; 
- i>=0 ok; 
La POST ci dice che Q1 conterra' i nodi prelevati da L corrispondenti agli indici di A, 
mentre Q2 i nodi restanti di L (se ce ne sono). 
Vera per R1 che all'ultima iterazione prima di uscire dal ciclo inserisce l'ultimo nodo 
"prelevabile" nella coda corretta. Prelevabile vuol dire che L ha ancora elementi o che nA>0.

*/
main()
{
    cout<<"start"<<endl;
    nodo*K=faiLista();
    int nA;
    cin >>nA;
    int * A= new int[nA];
    for(int i=0; i<nA;i++)
        cin >>A[i];
    coda X=preleva(K,A,nA);
    cout<<"lista prelevata:"<<endl;
    stampaL(X.primo);
    cout<<"lista rimasta:"<<endl;
    stampaL(K);  
    cout<<"end"<<endl;
}