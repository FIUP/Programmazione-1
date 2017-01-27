#include<iostream>
#include<fstream>
using namespace std;

struct nodo{
	int info; 
	nodo *left, *right; 
	nodo(int a=0, nodo* b=0, nodo* c=0) {info=a; left=b; right=c;}
};


//PRE_level=(r è albero corretto, dim >=0, lev>=0, r=vr, INP contiene almeno dim interi)
int level(nodo*&r, int dim, int lev, ifstream & INP){

	if(!lev){
		if(!r && dim>0){
			int x;
			INP>>x;
			r=new nodo(x);
			return dim-1;
		} 
		return dim;
	}
	
	if(!r){
		return dim;
	}

	if(dim>0)
		dim=level(r->left, dim, lev-1, INP);
	if(dim>0)
		return level(r->right, dim, lev-1, INP);
	return 0;

}//POST_level=(r è ottenuto da vr aggiungendo a vr min(Offre(vr,lev), dim) nodi a livello lev da sinistra a destra, la funzione deve restituire col return dim-Offre(vr,lev) qualora questa quantità fosse positiva e altrimenti deve restituire 0; i nodi (eventualmente) aggiunti a vr devono ricevere il loro campo info da letture effettuate su "input")


/* PROVA DI CORRETTEZZA: PRE_level <level()> POST_level

	Caso base: !lev
-----------------
Dato PRE_level:
- se r è un albero vuoto e posso aggiungere almeno un altro nodo, allora aggiungo un nodo con campo info letto da input, e restituisco dim-1, gli elementi da inserire sull'albero → vale POST_level
- se r non è un albero vuoto allora in quel livello non posso inserire nodi e quindi ritorno dim (che può essere anche 0), gli elementi che mi mancano da insire sull'albero → vale POST_level

	Caso base: !r && lev>0
------------------------
Dato PRE_level, se lev>0 e r è un albero vuoto, allora non posso inserire nodi ai livelli successivi e quindi ritorno dim, il numero di nodi da inserire sull'albero → vale POST_level

	Caso ricorsivo: level(r->left, dim, lev-1, INP) && lev>0 && r && dim>0
------------------------------------------------------------------------
Dato PRE_level, assegno a dim il risultato (>=0) della chiamata ricorsiva level(r->left, dim, lev-1, INP), dove r->left è un albero corretto, dim>0, e lev>=0 → valgono PRE_level e POST_level

	Caso ricorsivo: level(r->rigth, dim, lev-1, INP) && lev>0 && r && dim>0
-------------------------------------------------------------------------
Dato PRE_level, assegno a dim il risultato (>=0) della chiamata ricorsiva level(r->right, dim, lev-1, INP), dove, r->right è un albero corretto, dim>0, e lev>=0 → valgono PRE_level e POST_level

*/


//PRE_build=(r albero corretto, dim>=0, lev>=0, INP contiene almeno dim interi, r=vr, dim=vdim)
nodo* build(nodo*r, int dim, int lev, ifstream & INP){

	if(dim){
		dim=level(r, dim, lev, INP);
		return build(r, dim, lev+1, INP);
	}
	return r; 

}//POST_build=(r è ottenuto da vr aggiungendo a vr dim nuovi nodi (con campo info letto da INP e tali che questi nodi siano inseriti a partire dal primo livello l tale che Offre(vr,l) >0 , poi al livello l+1, l+2 e così via, fino ad esaurire i dim valori che sono su INP; per ogni livello i nodi vanno inseriti da sinistra a destra)


void stampa_l(nodo *r, ofstream & OUT){
	if(r){
		OUT<<r->info<<'(';
		stampa_l(r->left,OUT);
		OUT<<',';
		stampa_l(r->right,OUT);
		OUT<<')';
	} else OUT<< '_';
}


nodo* costruz(){
	nodo*x2=new nodo(2);
	nodo* x3=new nodo(3);
	nodo* x4=new nodo(4);
	nodo*x1=new nodo(1,x2,x3);
	x2->right=x4;
	return x1;
}


main(){
	try{
		ifstream INP("input");
		ofstream OUT("output");
		if(!INP) throw(0);
		if(!OUT) throw(1);
		int dim0,dim1,dim2,x;

		INP>>dim0>>dim1>>dim2;
		nodo*X=costruz();
		cout<<endl;

		int z=level(X,dim0,2,INP);// da fare

		stampa_l(X,OUT);
		OUT<<endl<<z<<endl;
		for(int i=0; i<z;i++)//serve per eliminare da input i valori non usati da level
			INP>>x;
		X=costruz();

		X=build(X,dim1,0,INP);  //da fare

		stampa_l(X,OUT);
		OUT<<endl;
		nodo*R=0;

		R=build(R,dim2,0,INP);// da fare

		stampa_l(R,OUT);
		OUT<<endl;
	} catch(int x) {
		switch(x){
			case 0: cout<<"problemi con input"<<endl; break;
			case 1: cout<<"problemi con output"<<endl; break;
		}
	}
}
