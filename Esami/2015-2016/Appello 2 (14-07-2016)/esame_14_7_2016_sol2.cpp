/*
TEORIA
PRE: albero corretto e eventualmente vuoto
POST: ritorna il numero di rami t.c. il loro padre abbia solo un ramo destro oppure un ramo sinistro, ma non entrambi.
Non e` il massimo, pensaci su.
*/
#include<iostream>
using namespace std;
#include<fstream>
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}}; // nodo di lista 
struct FIFO{nodo* primo, *ultimo;FIFO(nodo*a=0, nodo*b=0){primo=a; ultimo=b;}};
struct nodot{int info; nodot* left, *right; nodot(int a=0, nodot* b=0, nodot* c=0){info=a; left=b; right=c;}};//nodo di albero

//PRE: b punta a nodo (mai a NULL); FIFO corretta e eventualmente vuota
FIFO push_begin(FIFO x, nodo* b)
{
	if(!x.primo)
	{x.primo= x.ultimo=b;}
	else
	{
		b->next= x.primo;
		x.primo= b;
	}
	return x;
}


FIFO push_end(FIFO a, nodo*b)
{
  if(!a.primo)
  {a.primo=a.ultimo=b;}
  else
   {a.ultimo->next=b; a.ultimo=b;}
  return a;
}

void stampa_L(nodo*L)
{
 if (L)
  {cout<<L->info<<' '; stampa_L(L->next);}
 else
   cout<<endl;

}
nodo* costruisci(int dim, ifstream & in)
{
 if(dim)
   {int x; in>>x; return new nodo(x,costruisci(dim-1,in));}
 return 0;
}
 nodo* clone(nodo*a)
 {
  if(a)
  {return new nodo(a->info, clone(a->next));}
  return 0;
 }



bool cerca(nodo* n, int val)
{
	if(!n) return false; // lista finita = val non trovato
	if(n->info==val) return true; //match = val trovato
	return cerca(n->next,val); // cerca nei nodi successivi
}




// cerca iterativamente
bool seek(nodo* n, int v)
{
	while(n) //finche ho nodi
	{
		if(n->info==v) // ho ridondanza => ricerca riuscita
			return true;
		n= n->next; // sposta avanti ptr
	}

	return false; // ricerca fallita
}


// PRE: L(q) lista corretta; vL(q)= L(q)
FIFO tieni_ultimo_ric(nodo* &q)
{
	if(!q)
		return FIFO();
	
	
	
	// else, esiste q
	
	//scorri fino in fondo
	FIFO ris= tieni_ultimo_ric(q->next);
	
	// se ho almeno un nodo successivo al corrente, cerco i match
	if(q->next) // ho almeno un nodo seguente
	{
		// controllo i seguenti
		if(cerca(q->next,q->info)==true)
		{
		
			nodo*sav= q; // salvo
			q=q->next; // sfilo il nodo dalla lista
			sav->next=0; // cancello il campo next del nodo da ins in FIFO
			return push_begin(ris,sav);
		}
  }
  
  // se non ho match, ritorno la FIFO che avevo gia`
  return ris;
  
}
// POST: L(q) ottenuta da vL(q) eliminando nodi ripetuti eccetto l'ultimo e mantenendo l'ordine relativo in vL(q). Ritorna su FIFO i nodi eliminati.



FIFO tieni_ultimo_iter(nodo* &q)
{
 
	// costru due fifo vuote. Una per i nodi ridondanti, l'altra per i buoni
  FIFO tenuti= FIFO();
  FIFO tolti= FIFO();
	
	//ma posso ritornarne una sola! l'altra la ritorno per rifer. usando q, vedi (~.~)

  
  if(!q) // lista vuota in input(che schifo!), nessuna operazione
  	return FIFO();
  	
  //else, ho almeno un nodo nella lista
  
  while(q) //finche ho nodi
  {
  	
  	if(seek(q->next,q->info)) // aggiungo a tolti
  	{	tolti= push_end(tolti,q); }
  	
  	else // aggiungo a tenuti
			tenuti= push_end(tenuti,q);
			
  	q= q->next; //sfilo da lista iniziale
  }

	tenuti.ultimo->next=0;
	tolti.ultimo->next= 0; // setto a null la fine delle fifo
	
	//	(~.~) qui sotto
	q= tenuti.primo; // reimposto q sulla lista non ridondante, furbetto
	
	return tolti; // ritorno la fifo dei tolti
  
}// END FUN
 
main()
{
	ifstream in("input");
	if(in)
	{
		int dim;

		in>>dim;
		nodo*C=costruisci(dim,in);
		nodo* D=clone(C);
		cout<<"Lista costruita"<<endl;
		stampa_L(C);
		FIFO a =tieni_ultimo_ric(C);
		cout<<"soluzione ricorsiva"<<endl<<"nodi tolti:"<<endl;

		stampa_L(a.primo);
		cout<<"lista rimanente:"<<endl;
		stampa_L(C);
		FIFO b=tieni_ultimo_iter(D);
		cout<<"soluzione iterativa"<<endl<<"nodi tolti:"<<endl;
		stampa_L(b.primo);
		cout<<"lista rimanente:"<<endl;
		stampa_L(D);
		cout<<"end"; 
	}
	else cout<<"errore files\n";
	
}
