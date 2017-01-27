#include<iostream>
#include<fstream>

using namespace std;

struct nodo{
	int info; 
	nodo *left, *right; 
	nodo(int a=0, nodo* b=0, nodo* c=0) {info=a; left=b; right=c;}
};


//PRE_match=(T e P sono alberi corretti)
bool match(nodo* T, nodo* P){

	if(!P)
		return 1;
	if(!T)
		return 0;
	if(T->info!=P->info)
		return 0;
	return match(T->left, P->left)&&match(T->right, P->right);

}//POST_match=(ritorna true se c'è match di P su T)

/* PROVA DI CORRETTEZZA: PRE_match <match()> POST_match

	Caso base: !P
---------------
Dato PRE_match, se P è vuoto:
- se T è vuoto allora c'è match e ritorno 1 → vale POST_match
- se T non è vuoto (questo solo nel caso di una chiamata ricorsiva) allora fino al nodo precedente (foglia di P) c'è stato match e quindi ritorna 1 → vale POST_match

	Caso base: !T
---------------
Dato PRE_match con P non vuoto, se T è vuoto allora non può esserci match e quindi ritorno 0 → vale POST_match

	Caso base: T->info!=P->info
-----------------------------
Dato PRE_match con T e P non vuoti, se T->info!=P->info allora non c'è match di P su T e quindi ritorno 0 → vale POST_match

	Caso ricorsivo: match(T->left, P->left)&&match(T->right, P->right)
--------------------------------------------------------------------
Dato PRE_match, se T->info==P->info allora invoco le chiamate ricorsive match(T->left, P->left) e match(T->right, P->right), con di T->left/right e P->left/right sottoalberi corretti:
- se entrambe le chiamate ritornano true, cioè c'è match tra P->left/right e T->left/right, allora ritorno 1 → valgono PRE_match e POST_match
- altrimenti ritorno 0 → valgono PRE_match e POST_match

*/


//PRE_copia=(C e CT hanno n. di elementi sufficienti, 0<=i<lung è i-esimo elemento di C, 0<=lung<=lungct è la lunghezza del cammino del match di P in T (dalla radice di T al primo nodo del match), lungct>=0 è la lunghezza della sequenza di tutti i cammini dei match di P in T)
void copia(int*&C, int*&CT, int i, int lung, int& lungct){
	
	if(i==lung){
		CT[lungct]=-1;
		lungct++;
		return;
	}
	CT[lungct]=C[i];
	lungct++;
	copia(C, CT, i+1, lung, lungct);

}//POST_copia=(scrive di copia C[0..lung-1] su CT[lungct..lungct+lung-1] e arrivato all'ultima posizione di C aggiunge in sulla posizione successiva di CT -1 per indcare la fine del cammino)

/* PROVA DI CORRETTEZZA: PRE_copia <copia()> POST_copia

	Caso base: i==lung
--------------------
Dato PRE_copia, se i==lung allora abbiamo terminato di copiare C[0..i-1] su CT[lungct..lungct+i-1] e quindi indichiamo la fine del cammino inserendo in CT[lungct+i] -1, aumentiamo lungct per il prossimo cammino e terminiamo → vale POST_copia

	Caso ricorsivo: copia(C, CT, i+1, lung, lungct)
-------------------------------------------------
Dato PRE_copia, se i!=lung, allora copiamo il C[i] in CT[lungct], aumentiamo lungct di 1 (in quanto dobbiamo inserire almeno un altro elemento in CT) e invochiamo la chiamata ricorsiva copia(C, CT, i+1, lung, lungct) che copierà C[i+1] in CT[lungct] → valgono PRE_copia e POST_copia

*/


//PRE_cerca_ogni_match=(T e P alberi corretti, C e CT hanno n. di elementi sufficienti, lung e lungct sono >=0 e C[0..lung-1] e CT[0..lungct-1] sono definiti)
bool cerca_ogni_match(nodo*T, nodo*P, int*C, int*CT, int & lung, int & lungct){

	if(!T){
		if(!P){
		//ATTENZIONE: inutile ma per toglierlo dovrei modificare match()
			copia(C, CT, 0, lung, lungct);
			//ATTENZIONE: considero che se !T e !P allora su CT scrivo -1 (sensato!)
			return 1;
		}
		return 0;
	}
	bool m=false;
	if(match(T, P)){	
		copia(C, CT, 0, lung, lungct);
		//ATTENZIONE: lung rimane invariato mentre lungct è la posizione dove inserire il prossimo cammino
		m=true;
	}
	bool sx=false, dx=false;
	if(T->left){
	//ATTENZIONE: facendo questo controllo evitiamo il caso base !T che nel caso di pattern vuoto (!P) troverebbe un match quando T è una foglia
		C[lung]=0;
		lung++;
		sx=cerca_ogni_match(T->left, P, C, CT, lung, lungct);
		lung--;
	}
	if(T->right){
		C[lung]=1;
		lung++;
		dx=cerca_ogni_match(T->right, P, C, CT, lung, lungct);
		lung--;
	}
	return m||sx||dx;	

}//POST_cerca_ogni_match=(la funzione restituisce true sse c'è almeno un match di P in T e in questo caso CT[0..lungct-1] contiene tutti i cammini dei match di P in T elencati in ordine crescente e separati da -1)

/* PROVA DI CORRETTEZZA: PRE_cerca_ogni_match <cerca_ogni_match()> POST_cerca_ogni_match

	Caso base: !T
---------------
Dato PRE_cerca_ogni_match con T vuoto:
- se anche P è vuoto allora invoco copia(C, CT, 0, lung, lungct) che scriverà su CT solo -1 e incrementa lungct di 1, quindi alla fine CT[0..lungct-1]=CT[0..(1-1)] conterrà solo -1 → vale POST_cerca_ogni_match
- se P non è vuoto allora non ci possono essere match e restituisco 0 → vale POST_cerca_ogni_match

	Caso ricorsivo: sx=cerca_ogni_match(T->left, P, C, CT, lung, lungct)
----------------------------------------------------------------------
Dato PRE_cerca_ogni_match con T non vuoto, se T->left allora in C[lung] inserisco 0, aumento lung di 1 (per l'elemento successivo) e invoco la chiamata ricorsiva cerca_ogni_match(T->left, P, C, CT, lung, lungct) che se c'è match di P nel sottoalbero sinistro di T allora ritornerà true (e in CT saranno presenti gli eventuali cammini), altrimenti false; in ongi caso riporta lung (l'indice di C) alla posizione corretta (per controllare il sottoalbero destro) → valgono PRE_cerca_ogni_match e POST_cerca_ogni_match

	Caso ricorsivo: dx=cerca_ogni_match(T->right, P, C, CT, lung, lungct)
-----------------------------------------------------------------------
Dato PRE_cerca_ogni_match con T non vuoto, se T->right allora in C[lung] inserisco 0, aumento lung di 1 (per l'elemento successivo) e invoco la chiamata ricorsiva cerca_ogni_match(T->right, P, C, CT, lung, lungct) che se c'è match di P nel sottoalbero sinistro di T allora ritornerà true (e in CT saranno presenti gli eventuali cammini), altrimenti false; in ongi caso riporta lung (l'indice di C) alla posizione corretta → valgono PRE_cerca_ogni_match e POST_cerca_ogni_match

*/


//PRE_conta=()
int conta(nodo *r){
	
	if(!r)
		return 0;
	else return 1+conta(r->left)+conta(r->right);

}//POST_conta=()


//PRE_inserisci=()
void inserisci(nodo *&r, int dim, int x, ifstream & INP){

	if(!r){
		r=new nodo(x);
		return;
	}
	if(!r->left){
		r->left=new nodo(x);
		return;
	}
	if(!r->right){
		r->right=new nodo(x);
		return;
	}
	if(conta(r->left)<=conta(r->right))
		inserisci(r->left, dim, x, INP);
	else inserisci(r->right, dim, x, INP);
	
}//POST_inserisci=()


//PRE_crea_a=(r è un albero corretto, dim>=0, r=vr)
void crea_a(nodo*&r, int dim, ifstream & INP){

	if(dim){
		int x;
		INP>>x;
		if(!r)
			r=new nodo(x);
		else {
			if(conta(r->left)<=conta(r->right)){
				inserisci(r->left, dim, x, INP);
			} else inserisci(r->right, dim, x, INP);
		}
		crea_a(r, dim-1, INP);
	}

}//POST_crea_a=(r è vr a cui sono stati aggiunti dim nodi con campi info letti da "input")


//PRE_stampa_l=()
void stampa_l(nodo *r, ofstream &OUT){

	if(r){
		OUT<<r->info<<"(";
		stampa_l(r->left, OUT);
		OUT<<",";
		stampa_l(r->right, OUT);
		OUT<<")";
	} else OUT<<"_";

}//POST_stampa_l=()


void stampa(int*T, int dim, ofstream & OUT){
	if(dim){
		cout<<T[0]<<' ';
		stampa(T+1, dim-1, OUT);
		} else cout<<endl;
}


main()
{
  try{
  ifstream INP("input");
  ofstream OUT("output");
  if(!INP) throw(0);
  if(!OUT) throw(1);
  int dim1, dim2, C[100], CT[100], lung=0, lungct=0;
  INP>>dim1>>dim2;
  
  nodo*T=0;
  crea_a(T,dim1,INP);
  //stampa_l(T,OUT);
  nodo*P=0;
  crea_a(P,dim2,INP);
  //stampa_l(P,OUT);
  
  bool b=cerca_ogni_match(T,P,C,CT,lung,lungct);
  cout<<b<<endl;
  if(b) 
    stampa(CT,lungct,OUT);
  
 }
 catch(int x)
{
   switch(x)
  {
   case 0: cout<<"problemi con input"<<endl; break;
   case 1: cout<<"problemi con output"<<endl; break;
  }
}
}
