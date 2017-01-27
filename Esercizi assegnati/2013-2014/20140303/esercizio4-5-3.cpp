#include<iostream>
#include<fstream>
using namespace std;

struct nodo{
	int info; 
	nodo *left, *right;
	nodo(int a=0, nodo* b=0, nodo* c=0) {info=a; left=b; right=c;}
};


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
		inserisci(r, dim, x, INP);
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


//PRE_match=(T e P sono alberi corretti)
bool match(nodo *T, nodo *P){

	if(!P)
		return 1;
	if(!T)
		return 0;
	if(T->info!=P->info)
		return 0;
	return match(T->left, P->left)&match(T->right, P->right);

}//POST_match=(restituisce true se c'è match completo di P in T; false altrimenti))

/* PROVA DI CORRETTEZZA: PRE_match <match()> POST_match

	Caso base: !P
---------------
Dato PRE_match, se P è vuoto allora c'è stata una chiamata ricorsiva match() sul nodo precedente, e quindi fino al nodo precedente c'è stato match e per questo ritorna 1 → vale POST_match

	Caso base: !T
---------------
Dato PRE_match, se T è vuoto mentre P non lo è, allora non può esserci match e quindi ritorna 0 → vale POST_match

	Caso base: T->info!=P->info
-----------------------------
Dato PRE_match con T e P non vuoti, se T->info!=P->info allora non c'è match e ritrno 0 → vale POST_match

	Caso ricorsivo: match(T->left, P->left)&&match(T->right, P->right)
--------------------------------------------------------------------
Dato PRE_match con T e P non vuoti, se T->info==P->info invoco le chiamate ricorsive match(T->left, P->left) e match(T->right, P->right), dove T->left, T->right, P->left, P->right sono alberi corretti:
- se c'è match completo dei sottoalberi (T->left con P->left e T->right con P->right) allora ritorna true → vale POST_match
- se non c'è match di almeno uno dei sottoalberi di P (left o right) con i rispettivi sottoalberi di T, allora ritorna false → vale POST_match

*/


//PRE_cerca_match=(T e P alberi corretti, C array con almeno tanti elementi quanta è l'altezza dell'albero)
bool cerca_match(nodo*T, nodo* P, int*C, int & lung){

	if(!T){
		if(!P)
			return 1;
		return 0;
	}
	if(!P)
		return 0;
	if(match(T, P)){
		return 1;
	}
	if(cerca_match(T->left, P, C+1, lung)){
		lung++;
		*C=0;
		return 1;
	}
	if(cerca_match(T->right, P, C+1, lung)){
		lung++;
		*C=1;
		return 1;
	}
	return 0;

}//POST_cerca_match=(restituisce true sse in T esiste un match di P e, in caso ci sia un match, C[0..lung-1] è il cammino per arrivare dalla radice di T alla radice del match minimo di P in T)


/* PROVA DI CORRETTEZZA: PRE_cerca_match <cerca_match()> POST_cerca_match

	Caso base: !T
---------------
Dato PRE_cerca_match, se T è un albero vuoto:
- se anche P è vuoto allora c'è match e restituisco 1 → vale POST_cerca_match
- se P non è vuoto allora non c'è match e restituisco 0 → vale POST_cerca_match

	Caso base: !P
---------------
Dato PRE_cerca_match, se T è un albero non vuoto e P è un albero vuoto, allora non può esserci match di P in T e ritorno 0 → vale POST_cerca_match

	Caso ricorsivo:
-----------------

*/


void stampa(int*T, int dim, ofstream & OUT){
	if(dim){
		cout<<T[0]<<' ';
		stampa(T+1, dim-1, OUT);
	} else cout<<endl;
}


main(){
	try{
		ifstream INP("input");
		ofstream OUT("output");
		if(!INP) throw(0);
		if(!OUT) throw(1);
		int dim1, dim2, C[100], lung=0;
		INP>>dim1>>dim2;
  
		nodo*T=0;
		crea_a(T,dim1,INP);
		//stampa_l(T,OUT);
		nodo*P=0;
		crea_a(P,dim2,INP);
		//stampa_l(P,OUT);
  
		bool b=cerca_match(T,P,C,lung);
		cout<<b<<endl;
		if(b) {
			stampa(C,lung,OUT);
		}
	} catch(int x) {
		switch(x){
			case 0: cout<<"problemi con input"<<endl; break;
			case 1: cout<<"problemi con output"<<endl; break;
		}
	}
}
