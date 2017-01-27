#include<iostream>
#include<fstream>
using namespace std;

struct nodo{
	int info; 
	nodo *left, *right; 
	nodo(int a=0, nodo* b=0, nodo* c=0) {info=a; left=b; right=c;}
};



// *** inizio_cam VERSIONE RICORSIVA ***
//PRE_inizio_cam=(C contiene n cammini (sequenze possibilmente vuote di 0 e 1), ogni cammino termina con -1 e dopo l'ultimo cammino (che termina, come tutti i cammini, con -1) c'è la sentinella -2, n >= 0, i >= 0)
int inizio_cam(int*C, int i){

	if(*C==-2)
		return -2;

	if(!i)
		return 0;
	
	if(*C==-1)
		i=i-1;
	if(inizio_cam(C+1, i)==-2) 
		return -2;
	return 1+inizio_cam(C+1, i);
	

}//POST_inizio_cam=(se i in [0..n-1] allora inizio_cam restituisce l'indice di C in cui inizia il cammino i, altrimenti, inizio_cam restituisce -2)


/*PROVA DI CORRETTEZZA: PRE_inizio_cam <inizio_cam()> POST_inizio_cam

	Caso base: *C==-2
-------------------
Dato PRE_inizio_cam, se *C==-2 allora abbiamo già trovato gli n cammini (non ne dobbiamo cercare altri) e restituiamo con il return -2 → vale POST_inizio_cam

	Caso base: i==0 && *C!=-2
---------------------------
Dato PRE_inizio_cam, se i==0 allora *C==-1 e i è la posizione dell'inizio dell cammino → vale POST_inizio_cam

	Caso ricorsivo: inizio_cam(C+1, i)==-2 && *C!=-2 && i!=0
----------------------------------------------------------
Dato PRE_inizio_cam, invoco la chiamata ricorsiva inizio_cam(C+1, i), con C+1 definito in quanto *C!=-2 (non stavamo considerando l'ultima posizione) e i>=0: se la funzione ritorna -2 allora abbiamo trovato tutti gli n cammini e ritorniamo -2 → valgono PRE_inizio_cam e POST_inizio_cam

	Caso ricorsivo: 1+inizio_cam(C+1, i) && *C!=-2 && i!=0 && inizio_cam(C+1, i)!=-2
----------------------------------------------------------------------------------
Dato PRE_inizio_cam, se non ho già considerato tutti gli n cammini, invoco la chiamata ricorsiva inizio_cam(C+1, i), con C+1 definito in quanto *C!=-1, *(C+1)!=-2 e
i>=0: la funzione retituirà indice dell'inizio del cammino -1 partendo da C+1 al quale verrà sommato 1 per avere l'indice dell'inizio del cammino partendo da C → valogno PRE_inizio_cam e POST_inizio_cam

*/


/*
// *** inizio_cam VERSIONE ITERATIVA ***
//PRE_inizio_cam=(C contiene n cammini (sequenze possibilmente vuote di 0 e 1), ogni cammino termina con -1 e dopo l'ultimo cammino (che termina, come tutti i cammini, con -1) c'è la sentinella -2, n >= 0, i >= 0)
int inizio_cam(int*C, int i){

	int indice=0;
	while(i){
	//R=(0<=i<=n)&&(indice è l'indice di inizio del cammino i-esimo; se C[indice]==-2 allora abbiamo già trovato tutti gli n cammini)
		if(C[indice]==-1)
			i=i-1;
		indice++;
		if(C[indice]==-2)
			return -2;
	}
	return indice;
	
}////POST_inizio_cam=(se i in [0..n-1] allora inizio_cam restituisce l'indice di C in cui inizia il cammino i, altrimenti, inizio_cam restituisce -2)
*/



//PRE_add_ric=(C[0...] contiene una sequenza w di 0 e 1 (possibilmente vuota) seguita da -1, r è un albero corretto, INP contiene almeno un intero che chiamiamo x, r=vr)
void add_ric(int* C, nodo*& r, ifstream & INP, ofstream & OUT){

	int x;
	if(*C==-1){
  	INP>>x;
  	if(r){
  		OUT<<"cammino troppo corto "<<x<<endl;
  		return;
  	}
  	r=new nodo(x);
  	return;
  }
  if(!r){
  	INP>>x;
  	OUT<<"cammino troppo lungo "<<x<<endl;
		return;
  }
  if(*C==0){
  	add_ric(C+1, r->left, INP, OUT);
  	return;
  }
  if(*C==1){
  	add_ric(C+1, r->right, INP, OUT);
  	return;
  }

}//POST_add_ric=(se w è troppo corto o troppo lungo rispetto a vr, allora v resta uguale a vr e su "output" verrà scritto "cammino troppo corto" oppure "cammino troppo lungo" seguito da x, altrimenti r è un albero corretto che si ottiene da vr aggiungendogli un nuovo nodo tale che il cammino dalla radice di r al nuovo nodo sia w e tale che il suo campo info sia x)


/* PROVA DI CORRETTEZZA: PRE_add_ric <add_ric> POST_add_ric

	Caso base: *C==-1
-------------------
Dato PRE_add_ric, se *C==-1 allora siamo arrivati alla fine del cammino, dove dovremmo aggiungere il nodo con campo info x (letto da "input"):
- se r allora non inseriamo alcun nodo in quanto c'è già un nodo alla fine di quel cammino nell'albero, quindi scriviamo su "output" "cammino troppo corto" seguito da x → vale POST_add_ric
- se !r allora inseriamo il nodo con campo info x in quella posizione → vale POST_add_ric

	Caso base: !r && *C!=-1
-------------------------
Dato PRE_add_ric, se !r e non siamo ancora arrivati alla fine del cammino allora non potremmo aggiungere quel nodo con campo info (x) letto da "input" e quindi scriviamo su "output" "cammino troppo lungo" seguito da x → vale POST_add_ric

	Caso ricorsivo: add_ric(C+1, r->left, INP, OUT) && *C==0 && r
---------------------------------------------------------------
Dato PRE_add_ric, se *C==0 invoco una chiamata ricorsiva add_ric(C+1, r->left, INP, OUT), dove C+1 è definita, sul sottoalbero sinistro di r che potrà inserire un nodo oppure scriverà su output "cammino troppo corto" o "cammino troppo lungo" → vale POST_add_ric

	Caso ricorsivo: add_ric(C+1, r->right, INP, OUT) && *C==1 && r
----------------------------------------------------------------
Dato PRE_add_ric, se *C==1 invoco una chiamata ricorsiva add_ric(C+1, r->right, INP, OUT), dove C+1 è definita, sul sottoalbero destro di r che potrà inserire un nodo oppure scriverà su output "cammino troppo corto" o "cammino troppo lungo" → vale POST_add_ric

*/



//PRE_add_iter=(C[0...] contiene una sequenza w di 0 e 1 (possibilmente vuota) seguita da -1, r è un albero corretto, INP contiene almeno un intero che chiamiamo x, r=vr)
void add_iter(int* C, nodo*& r, ifstream & INP, ofstream & OUT){

	int x;
  INP >> x;

	int i=0;
	nodo *n=r;
	while(C[i]!=-1){
		if(!n){
			OUT<<"cammino troppo lungo "<<x<<endl;
			return;
		}
		
		if(C[i]==0){
			if(C[i+1]==-1){
				if(!n->left){
					n->left=new nodo(x);
					return;
				}
				OUT<<"cammino troppo corto "<<x<<endl;
				return;
			}
			n=n->left;
		}
		if(C[i]==1){
			if(C[i+1]==-1){
				if(!n->right){
					n->right=new nodo(x);
					return;
				}
				OUT<<"cammino troppo corto "<<x<<endl;
				return;
			}
			n=n->right;
		}
		i++;
	}
	
	//arrivo a questo punto solo nel caso di cammino -1!!
	if(!r){
		r=new nodo(x);
	} else {
		OUT<<"cammino troppo corto "<<x<<endl;
	}	

}//POST_add_iter=(se w è troppo corto o troppo lungo rispetto a vr, allora v resta uguale a vr e su "output" verrà scritto "cammino troppo corto" oppure "cammino troppo lungo" seguito da x, altrimenti r è un albero corretto che si ottiene da vr aggiungendogli un nuovo nodo tale che il cammino dalla radice di r al nuovo nodo sia w e tale che il suo campo info sia x)



nodo* build_ric(int*C, nodo* r, ifstream & INP, ofstream & OUT){
	bool fine=false;
	for(int i=0; !fine ; i++){
		int j=inizio_cam(C,i);
    if(j==-2)
			fine=true;
		else add_ric(C+j, r, INP, OUT);
	}
	return r;
}



nodo* build_iter(int*C, nodo*r, ifstream & INP, ofstream & OUT){
	bool fine=false;
	for(int i=0; !fine; i++){
		int j=inizio_cam(C,i);
		if(j==-2)
			fine=true;
		else add_iter(C+j, r, INP, OUT);
  }
	return r;
}



nodo* costruz(){
	nodo* x2=new nodo(2);
	nodo* x3=new nodo(3);
	nodo* x4=new nodo(4);
  nodo* x1=new nodo(1,x2,x3);
	x2->right=x4;
	return x1;
}



void stampa_l(nodo *r, ofstream & OUT){
	if(r){
		OUT<<r->info<<'(';
		stampa_l(r->left,OUT);
		OUT<<',';
		stampa_l(r->right,OUT);
		OUT<<')';
	} else OUT<< '_';
}



main(){
	try{
		ifstream INP("input");
		ofstream OUT("output");
		if(!INP) throw(0);
		if(!OUT) throw(1);
		int C[200],x;
		INP>>C[0];

		for(int i=1; C[i-1]!=-2; i++)
			INP>>C[i];
  
		nodo* X=costruz();
		nodo*r = build_ric(C,X,INP, OUT);
		stampa_l(r,OUT);
		OUT<<endl;

		r=build_ric(C,0,INP,OUT);
		stampa_l(r,OUT);
		OUT<<endl;

		X=costruz();
		r=build_iter(C,X,INP,OUT);
		stampa_l(r,OUT);
		OUT<<endl;

		r=build_iter(C,0,INP,OUT);
		stampa_l(r,OUT); 
		OUT<<endl;

	} catch(int x) {
		switch(x){
			case 0: cout<<"problemi con input"<<endl; break;
			case 1: cout<<"problemi con output"<<endl; break;
		}
	}
}
