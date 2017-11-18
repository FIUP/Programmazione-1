// Soluzione di B. Cosentino
#include<iostream>
using namespace std;
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}}; // nodo di lista 
struct FIFO{nodo* primo, *ultimo;FIFO(nodo*a=0, nodo*b=0){primo=a; ultimo=b;}};
struct nodot{int info; nodot* left, *right; nodot(int a=0, nodot* b=0, nodot* c=0){info=a; left=b; right=c;}};//nodo di albero




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
nodo* costruisci(int dim)
{
 if(dim)
   {int x; cin>>x; return new nodo(x,costruisci(dim-1));}
 return 0;
}
 nodo* clone(nodo*a)
 {
  if(a)
  {return new nodo(a->info, clone(a->next));}
  return 0;
 }


FIFO push_begin(FIFO x , nodo* b){
	if(!x.primo){
		x.primo=x.ultimo=b;
	} else { // x e' una lista non vuota
		b->next=x.primo;
		x.primo=b;
	}
	return x;
}


bool presente_ric(nodo* Q, int chiave){
	
	if (!Q)
		return false;
	
	if (Q->info==chiave)
		return true;
		
	return presente_ric(Q->next,chiave);
}



//PRE=(L(Q) è una lista corretta e vL(Q)=L(Q))
FIFO tieni_ultimo_ric(nodo* &Q){
	if (!Q)
		return FIFO(NULL,NULL);
	
	// PRE_ric = (L(Q->next) è una lista corretta e vL(Q->next)=L(Q->next))
	FIFO tolti = tieni_ultimo_ric(Q->next);
	// POST_ric = (L(Q->next) è ottenuta da vL(Q->next) eliminando i nodi con info ripetuto mantenendo solo 
	// l'ultimo nodo per ciascun campo info e mantenendo l'ordine relativo che questi nodi 
	// hanno in vL(Q->next). Inoltre restituisce un valore FIFO f tale che f.primo è la lista 
	// dei nodi eliminati nello stesso ordine relativo che essi hanno in vL(Q->next))
		
	nodo* tolto;
	if (presente_ric(Q->next,Q->info)){
		tolto = Q;
		Q = Q->next;
		tolto->next = 0;
		tolti = push_begin(tolti,tolto);	
	}
	// tolto e' il nodo eliminato
	
	return tolti;
}
// POST=(L(Q) è ottenuta da vL(Q) eliminando i nodi con info ripetuto mantenendo solo 
// l'ultimo nodo per ciascun campo info e mantenendo l'ordine relativo che questi nodi 
// hanno in vL(Q). Inoltre restituisce un valore FIFO f tale che f.primo è la lista 
// dei nodi eliminati nello stesso ordine relativo che essi hanno in vL(Q))

/**********************************************************************************
DIMOSTRAZIONE
Caso Base:
	Se L(Q) e' vuota, allora non e' possibile togliere nodi e viene restituita una 
	FIFO(NULL,NULL) -> POST

Caso Induttivo:
	So dal caso base che L(Q) e' non vuota. Segue che L(Q->next) e' corretta, 
	ovvero vale PRE_ric. Dopo tieni_ultimo_ric(Q->next), tolti gestisce la lista
	dei nodi eliminati da L(Q->next) e L(Q->next) e' ottenuta da vL(Q->next) 
	eliminando i nodi con info ripetuto e mantenendo l'ultimo nodo per ciascun 
	campo info.
	Se Q->info e' presente in L(Q->next), allora lo separo da Q e lo inserisco in 
	tolti. Alla fine restituisco tolti -> POST
**********************************************************************************/
bool presente_iter(nodo* Q, int chiave){
	
	bool pres=false;
	while (Q && !pres){
		pres = (Q->info==chiave);
		
		Q = Q->next;
	}
	return pres;
}


FIFO tieni_ultimo_iter(nodo*& Q){
	FIFO tolti;
	nodo* start;
	nodo* prec=NULL; // contiene il nodo precedente della lista rimanente
	while(Q){
		nodo* succ=Q->next;
		if (presente_iter(Q->next,Q->info)){
			tolti=push_end(tolti,Q);
			Q->next=0;		
			
		} else { // Q non e' presente piu' di una volta allora imposto nodo precedente = Q 
			if (prec)
				prec->next=Q;  // eseguo il "taglio"
			else
				start=Q;  // se e' la prima volta che non devo togliere un nodo allora imposto l'inizio della lista dei nodi restanti
			
			prec=Q;
		}
		Q=succ;
	}
	Q=start;
	return tolti;
}
// POST=(L(Q) è ottenuta da vL(Q) eliminando i nodi con info ripetuto mantenendo solo 
// l'ultimo nodo per ciascun campo info e mantenendo l'ordine relativo che questi nodi 
// hanno in vL(Q). Inoltre restituisce un valore FIFO f tale che f.primo è la lista 
// dei nodi eliminati nello stesso ordine relativo che essi hanno in vL(Q))

/*******************************************************************
INVARIANTE
R = (Q lista corretta) && (start contiene vL(Q) dove sono stati tolti tutti i nodi 
	con campo info ripetuto fino al nodo precedente a Q e inseriti in tolti)
*******************************************************************/

/*******************************************************************
TEORIA
PRE=(albero(r) corretto e non vuoto)
POST=(restituisce il numero di nodi con un solo figlio)
*******************************************************************/

main()
{
  
   int dim;
   
   cin>>dim;
   nodo*C=costruisci(dim);
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
