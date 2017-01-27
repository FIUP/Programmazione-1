#include<iostream>
#include<fstream>

using namespace std;
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};


//PRE_cut=(L è una lista corretta, k1 e k2 sono definite e 0<=k1<=k2)
nodo* cut(nodo*&L, int k1, int k2){
	
	if(!L)
		return 0;

	if(k1){
		nodo *n=L;
		L=L->next; //stacco il nodo da L
		n->next=cut(L, k1-1, k2-1);
		return n;
	}

	if(k2){
		return cut(L->next, k1, k2-1); //k1=0
	}
	
	if(!k2){
		nodo *x=L->next;
		L->next=0;
		return x;		
	}
		
}//POST_cut=(F restituisce L_(k1,k2) attraverso il parametro L passato per riferimento e restituisce L_(0,k1-1)@L_(k2+1,U) col return)


void stampa(nodo* x, ofstream & OUT){
	if(x){
		OUT<< x->info<<' ';
		stampa(x->next, OUT);
	}
}


void stampa1(nodo* x){
	if(x){
		cout<< x->info<<' ';
		stampa1(x->next);
	}
}


void crea(nodo*& L,int dim, ifstream & INP){
	if(dim){
		int x;
		INP>>x;
		L=new nodo(x);
		crea(L->next,dim-1,INP);
	} else L=0;
}


main(){
	ifstream INP("input2");
	ofstream OUT("output2");
	int dim, k1,k2;
	INP>>dim>>k1>>k2;
  
	nodo* inizio;
	crea(inizio,dim,INP); //fatta
    
	nodo* y=cut(inizio, k1, k2);//da fare
	stampa(y, OUT); //fatta
	OUT<<endl;
	stampa(inizio,OUT);//fatta
	INP.close();
	OUT.close();
}


/* PROVA DI CORRETTEZZA: PRE_cut <cut(){}> POST_cut

	caso base: !L
---------------
Dato PRE_cut, se L è una lista vuota allora, L_(k1,k2)=0; restituisce 0 col return e 0 con L → vale POST_cut

	caso base: k1==0 && k2==0
---------------------------
Dato PRE_cut, L_(k1,k2)=L_(0,0) quindi L->next è il prossimo nodo della lista da ritornare col return, e per questo me lo salvo in x, poi faccio puntare L->next a 0 in quanto L è l'ultimo nodo della lista che deve essere su L e alla fine ritorno x (la lista L_(k2+1,U)) che andrà collegata alla lista L_(0,k1-1) → vale POST_cut

	caso ricorsivo: k1>0
----------------------
Dato PRE_cut, mi salvo in x il nodo L, tolgo dalla lista il nodo L perchè dovrà rimanere solo L_(k1,k2), e a x->next assegno il risultato della chiamata ricorsiva cut(L, k1-1, k2-1) che per ipotesi induttiva resituisce restituisce L_(0,k1-1-1)@L_(k2-1+1,U) col return e L_(k1-1,k2-1) attraverso L → valgono PRE_cut e POST_cut

	caso ricorsivo: k1==0 && k2>0
-------------------------------
Dato PRE_cut, devo ricostruire L_(k1,k2)=L_(0,k2) con L e L_(k2+1,U) col return, quindi ritorno la lista L_(k2+1,U) tramite la chiamata ricorsiva cut(L->next, k1, k2-1) che per ipotesi induttiva restituisce L->next_(k2-1+1,U) col return e L_(k1,k2-1)=L_(0,k2-1) attraverso L->next → valgono PRE_cut e POST_cut

*/
