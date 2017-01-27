
//soluzione by: Leo M.

// Parte di Teoria
/*

Es1:
Cercate di scrivere una PRE ed una POST sensate per il seguente programma ricorsivo:

int M(nodo *R, int *P, int dimP)
{
	if(!dimP || !R)
		return 0;
	
	int z=0;
	
	if(R->info==*P)
	{
		z=1;
		P++;
		dimP--;
	}
	
	int a=M(R->left, P, dimP);
	int b=M(R->right, P, dimP);
	
	if(a>=b)
		return a+z;
	else
		return b+z;
}

SOLUZIONE:
//PRE=(albero(R) corretto, P[0..dimP-1] def, dimP>=0, albero(vR)=albero(R)).
//POST=(detto lung l'intero ritornato, allora il match (possibilmente non contiguo) di lunghezza massima di P[0..dimP-1] su albero(R) ha lunghezza lung e albero(R)==albero(vR)).
//nota: il match è cercato lungo tutti i cammini di albero(R), non sono considerate come parti di un eventuale match "pezzi" che risiedono su cammini diversi;
//in altre parole di volta in volta si sceglie il sottoalbero che contiene più match singoli.
//Pertanto non sono considerati parte dello stesso match (ad esempio) il nodo più in basso a sinistra ed il nodo più in basso a destra.


Es2:
Si supponga che due persone vogliano realizzare contemporaneamente le due parti di un programma: f1.cpp ed f2.cpp.
Una volta accordatisi risulta che f2.cpp userà una funzione (fun1) di f1.cpp e f1.cpp farà uso di una struttura (struct T) di f2.cpp.
a) è possibile per i due programmatori compilare solamente la loro parte?
b) quanti main() ci possono essere in totale tra f1.cpp e f2.cpp?
c) descrivere in che modo è possibile per f2.cpp usare fun1 e per f1.cpp usare la struttura.

SOLUZIONE:
(la soluzione seguente è stringata, e cerca di coprire tutti i punti salienti della risposta "completa";
per una trattazione chiara e dettagliata dell'argomento vedere: "9.7 Compilazione separata e namespace" del libro di testo).
a) sì, ed è comodo poterlo fare per poter individuare al più presto eventuali errori, warning ed indicazioni del compilatore;
   le due parti (f1.cpp) e (f2.cpp) prendono il nome di "unità di compilazione",
   il compilatore permette la compilazione di una singola unità con il comando "g++ -c f1.cpp" (o f2.cpp), il risultato sarà un file compilato f1.o (o f2.o)
   (sarà poi il modulo "linker" del compilatore a "mettere insieme" tutti i file ".o")
b) quando da f1.cpp e f2.cpp si vuole ricavare un eseguibile (.exe/.out) allora è necessario che ci sia uno e un solo main() (in uno tra f1.cpp/f1.o e f2.cpp/f2.o),
   altrimenti la fase di "linking" (tipicamente realizzata tramite l'uso di "makefile", vedi libro di testo) produrrà un errore.
c) il modo migliore sarebbe tramite i file header (.h) (vedi libro di testo); in alternativa (per semplificare):
   - f1.cpp deve contenere un'esatta copia della dichiarazione del tipo strutturato T così come appare anche in f2.cpp
   (ciò viola la regola della dichiarazione singola, ma è accettato dal C++ dato che queste dichiarazioni di tipo non richiedono l'allocazione di memoria
   e quindi non introducono tutti i problemi tipicamente legati alle dichiarazioni multiple, per ulteriori dettagli vedere libro di testo).
   - f2.cpp deve contenere solo il prototipo della funzione fun1 (prima di invocarla), tale prototipo è sufficiente al compilatore per fare il "controllo sui tipi".

*/





// Parte di Programmazione

//Versione 1
#include<iostream>
#include<fstream>

using namespace std;


struct nodo
{
	int info;
	nodo* left, *right;
	nodo(int a=0, nodo* b=0, nodo* c=0)
	{	info=a;
		left=b;
		right=c;
	}
};


struct innesto
{
	bool l, r;
	nodo* N;
	innesto* next;
	innesto(bool a=false, bool b=false, nodo* c=0, innesto* d=0)
	{	l=a;
		r=b;
		N=c;
		next=d;
	}
};


void stampa_l(nodo *r, ofstream &OUT)
{
	if(r)
	{
		OUT<<r->info<<'(';
		stampa_l(r->left,OUT);
		OUT<<',';
		stampa_l(r->right,OUT);
		OUT<<')';
	}
	else
		OUT<<'_';
}


int conta_n(nodo*r)
{
	if(!r)
		return 0;
	else
		return conta_n(r->left)+conta_n(r->right)+1;
}


nodo* insert(nodo* r, int y)
{
	if(!r) return new nodo(y);

	if(conta_n(r->left)<=conta_n(r->right))
		r->left=insert(r->left,y);
	else   
		r->right=insert(r->right,y); 
	return r;
}


nodo* rep_ins(nodo* r, int dim, ifstream &INP)
{
	if(dim)
	{
		int z;
		INP>>z;
		nodo*x=insert(r,z);
		return rep_ins(x,dim-1,INP);
	}
	return r;
}


void stampa(innesto* a, ofstream &OUT)
{
	if(a)
	{
		OUT<<"left="<<a->l<<" right="<<a->r<<" nodo="<<a->N->info<<endl;
		stampa(a->next,OUT);
	}
	else
		OUT<<endl;
}


innesto *conc(innesto *a, innesto *b)
{	//PRE(lista(a) e lista(b) corrette).
	if(!a)
		return b;
		
	a->next=conc(a->next, b);  //fa un po' di "riattacchi" inutili
	return a;
}	//POST(ritorna lista(c) tale che lista(c)=lista(a)@lista(b)).


// Versione 1 (aderisce alla dimostrazione di correttezza, ce ne sono altre in fondo commentate)
innesto* f0(nodo *R)
{	//PRE=(albero(R) corretto).
	if(!R)	//finito l'albero
		return 0;	//ritorno lista vuota
    
	innesto *L2=f0(R->left);	//esploro a sx
	innesto *L3=f0(R->right);	//esploro a dx
  
	innesto *L1=0;
	if(!R->left && !R->right)	//liberi entrambi
		L1= new innesto(true, true, R, 0);
	if(!R->left && R->right)	//libero solo il sinistro (e non il destro)
		L1= new innesto(true, false, R, 0);
	if(R->left && !R->right)	//libero solo il destro (e non il sinistro)
		L1= new innesto(false, true, R, 0);
	
	//altrimenti NON ha punti d'innesto, non va messo in lista
	if(L1)
		return conc(conc(L2,L1),L3);
	else
		return conc(L2,L3);
}	//POST=(restituisce la lista dei punti d'innesto di albero(R) in ordine infisso).


/* PRE_ric_left=(albero(R->left) corretto).
 * 
 * PRE_ric_right e' analoga a PRE_ric_left
 * 
 * POST_ric_left=(se L e' quanto restituito, allora lista(L) e' la lista dei punti d'innesto di albero(R->left) in ordine infisso).
 * 
 * POST_ric_right e' analoga a POST_ric_left
 * 
 * 
 *
 * DIMOSTRAZIONE INDUTTIVA:
 * 
 *
 * => caso base (l'albero e' vuoto):
 * l'albero vuoto non ha nodi, non avendo nodi di certo non ha punti di innesto, pertanto e' giusto che la lista di questi punti sia vuota (infatti ritorna 0, la lista vuota).
 * 
 *
 * => caso ricorsivo (l'albero non e' vuoto):
 *
 * dalla PRE so che albero(R) è corretto ed essendo l'albero non vuoto (altrimenti sarei nel caso base) ha almeno un nodo;
 * pertanto albero(R->left) ed albero(R->right) sono corretti (e possibilmente vuoti) quindi PRE_ric_left e PRE_ric_right sono verificate;
 * posso procedere alle invocazioni ricorsive
 * 
 * f0(R->left) mi restituira' lista(L2) per cui vale POST_ric_left
 * f0(R->right) mi restituira' lista(L3) per cui vale POST_ric_right
 * 
 * il nodo attuale (essendo di un albero corretto e non vuoto) ha dei possibili innesti sse ha (almeno) uno dei figli "libero" (!R->left || !R->right):
 *  nel caso li avesse liberi entrambi (!R->left && !R->right) allora il nodo della lista che lo identifichera' sara' del tipo: (l=true, r=true, nodo, 0) ed e' cio' che viene costruito
 *  se avesse libero solo il sinistro (e non il destro) (!R->left && R->right) [...] del tipo: (l=true, r=false, nodo, 0) ed e' cio' che viene costruito
 *  se avesse libero solo il destro (e non il sinistro) (R->left && !R->right) [...] del tipo: (l=false, r=true, nodo, 0) ed e' cio' che viene costruito
 * se il nodo attuale (dell'albero) ha dato luogo alla costruzione di un nodo "utile" per la lista degli innesti, allora questo nodo (lista) e' l'unico componente della lista L1
 *  altrimenti L1==0;
 * 
 * essendo richiesto l'ordine infisso ritorno la concatenazione (vedi PRE & POST della funz conc) di:
 * risultato sotto-albero sinistro (L2)
 * seguito da: risultato nodo attuale (L1) (se di interesse, altrimenti L1=0)
 * seguito da: risultato sotto-albero destro (L3)
 * 
 * cio' avviene restituiendo una lista (diciamo L) tale che:
 *  se L1!=0 allora L=L2@L1@L3
 *  altrimenti: L=L2@L3
 * ed e' quindi costruita secondo l'ordine infisso come richiede la POST (che cosi' sara' valida).
 */


int f1(innesto *&Inn, ifstream &INP)
{	/* PRE=(lista(Inn) e' corretta, in particolare ciascun nodo punta ad un corrispondente punto d'innesto di un albero;
			INP contiene "m" interi seguiti dalla sentinella -2, 0<=m, sia vInn il valore iniziale di lista(Inn)). */

	if(!Inn)	//se ho finito gli innesti possibili
		return 0;
      
	int x; INP>>x;	//recupera 1 intero
	if(x==-2)	//ho finito gli interi "utili"
		return 0;	//non ho fatto nessun innesto
      
	if(Inn->l && Inn->r)	//possibile innesto doppio
	{
		Inn->N->left=new nodo(x);	//innesto il nuovo nodo come figlio sx del nodo puntato da Inn->N
		INP>>x;	//recupero il prossimo intero per inserirlo a dx
		if(x==-2)	//se non e' un intero "utile" non posso innestare anche a dx come vorrei
		{
			Inn->l=false;	//mi segno che ho innestato a sx
			return 1;	//ritorno che ho fatto un solo innesto (quello a sx)
		}
		else	//ho un intero valido per innestare anche a dx
		{
			Inn->N->right=new nodo(x);	//innesto il nuovo nodo come figlio dx del nodo puntato da Inn->N
			innesto *temp=Inn;	//backup
			Inn=Inn->next;	//bypass
			delete temp;	//cancello nodo attuale della lista dei nodi di innesto (l'ho usato tutto)
			return 2+f1(Inn,INP);	//ritorno che ho fatto due innesti piu' (possibili) altri successivi dato che non ho ancora finito gli interi "utili"
		}
	}
	else	//innesto singolo
	{
		if(Inn->l)	//a sx
			Inn->N->left=new nodo(x);	//innesto a sx
		else	//a dx
			Inn->N->right=new nodo(x);	//innesto a dx
		
		//il nodo attuale puntato da Inn è stato usato, lo posso rimuovere
		innesto *temp=Inn;	//backup
		Inn=Inn->next;	//bypass
		delete temp;	//cancello nodo attuale della lista dei nodi di innesto (dato che ho fatto l'innesto che indica)
		return 1+f1(Inn,INP);	//ritorno che ho fatto un innesto piu' (possibili) altri successivi dato che non ho ancora finito gli interi "utili"
	}
}	/* POST=(se vInn contiene "n" campi l/r a true, allora vengono letti x=min(m,n) valori da INP e aggiunti "x" nuovi nodi all'albero usando i punti di innesto di vInn in ordine;
			 in caso resti una parte di vInn non usata (succede quando n>m), Inn puntera' a questa lista rimasta; la parte di vInn che e' usata viene deallocata). */



main()
{
	ifstream IN("input");
	ofstream OUT("output");
	if(IN && OUT) 
	{ 
		int dim;
		IN>>dim;
		nodo* R=rep_ins(0,dim,IN);	//data
		
		stampa_l(R,OUT);	//data
		OUT<<endl;
		
		innesto* x=f0(R);	//da fare
		stampa(x,OUT);	//data
		
		int a=f1(x,IN);	//da fare
		OUT<<"n. innesti="<<a<<endl;
		stampa_l(R,OUT);	//data
		OUT<<endl;
		stampa(x,OUT);	//data

		IN.close();
		OUT.close(); 
	}
	else
		cout<<"errore con i files";
}



 
 
/* Versione 2 (di f0):
innesto* f0(nodo *R)
{	//PRE=(albero(R) corretto).
	if(!R)
		return 0;	//finito l'albero
	innesto *L2=f0(R->left);	//esploro a sx
	innesto *L3=f0(R->right);	//esploro a dx

	innesto *L1=0;
	if(!R->left) //se il nodo attuale ha un posibile innesto a sx
	{
		if(!R->right) //e ne ha anche uno a dx
			L1= new innesto(true, true, R, 0);
		else //ce l'ha SOLO a sx
			L1= new innesto(true, false, R, 0);
	}
	else
	{
		if(!R->right) //se il nodo attuale ha un posibile innesto SOLO a dx
			L1= new innesto(false, true, R, 0);
	}
	
	//altrimenti NON ha punti d'innesto, non va messo in lista
	if(L1)
		L2=conc(L2,L1);

	return conc(L2,L3);
}	//POST=(restituisce la lista dei punti d'innesto di albero(R) in ordine infisso).
*/



/* Versione 3 (di f0):
innesto* f0(nodo *R)
{	//PRE=(albero(R) corretto).
	if(!R)
		return 0;	//finito l'albero
	innesto *L2=f0(R->left);	//esploro a sx
	innesto *L3=f0(R->right);	//esploro a dx

	innesto *L1=0;
	if(!R->left) //se il nodo attuale ha un posibile innesto a sx
	{
		if(!R->right) //e ne ha anche uno a dx
			L1= new innesto(true, true, R, 0);
    	else //ce l'ha SOLO a sx
			L1= new innesto(true, false, R, 0);
	}
	else
	{
		if(!R->right) //se il nodo attuale ha un posibile innesto SOLO a dx
			L1= new innesto(false, true, R, 0);
	}
	
	//altrimenti NON ha punti d'innesto, non va messo in lista
	if(L1)
		L2=conc(L2,L1);

	return conc(L2,L3);
}	//POST=(restituisce la lista dei punti d'innesto di albero(R) in ordine infisso).
*/
