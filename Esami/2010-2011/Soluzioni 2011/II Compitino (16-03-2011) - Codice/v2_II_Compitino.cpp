#include <iostream>

using namespace std;


struct nodo{
	char info;
	nodo *next;
	nodo(char a='0', nodo *b=0){info=a;next=b;}
};


void stampa(nodo *x){
	if(x){
		cout<< x->info;
		stampa(x->next);
	}
}


//PRE_F=(L è una lista corretta possibilmente vuota, P è un array di dimP>=0 elementi definiti)
nodo *F(nodo *&L,char *P,int dimP){
	if(!dimP || !L)
		return new nodo();
	if(L->info==*P){
		nodo *x=L; //mi salvo il nodo
		L=L->next; //stacco il nodo
		x->next=F(L,P+1,dimP-1);
		return x;
	}else	return F(L->next,P,dimP);
}//POST_F=(la funzione restituisce con il return la lista dei nodi di L che hanno trovato match (anche non completo) con P, mentre restituisce la lista L, alla quale sono stati tolti i nodi che hanno fatto match, attraverso il parametro formale)

/* PROVA DI CORRETTEZZA: PRE_F < F() > POST_F

	Caso base: dimP==0 || !L
--------------------------
Dato PRE_F:
 - se dimP=0 allora non ci può essere match con L (in realtà ci può essere ma solo se L è una lista vuota - in ogni caso il risultato non cambia) e ritorniamo con il return un nodo vuoto che rappresenta la lista del match di P su L, mentre con il return vL (la vecchia lista) in quanto non abbiamo tolto nessun nodo → vale POST_F
 - se L è una lista vuota allora non ci può essere match di P su L e ritorniamo un nodo vuoto che rappresenta la lista del match di P su L, mentre L è la vecchia lista vuota → vale POST_F

	Caso ricorsivo: dimP!=0 && L->info==*P
----------------------------------------
Dato PRE_F, se dimP!=0 e L->info==*P allora stacco il nodo dalla lista (L=L->next) e me lo salvo in x (alla fine dovrò restituire la lista dei nodi stccati); come nodo successivo ad x assegno il risultato della chiamata ricorsiva F(L,P+1,dimP-1), con dimP>=0 e P con dimP elementi definiti: la chiamata ricorsiva restituirà la lista dei nodi di L che hanno trovato match con P ed L è la vecchia lista alla quale sono stati tolti i nodi della lista del match → valgono PRE_F e POST_F

	Caso ricorsivo: dimP!=0 && L->info!=*P
----------------------------------------
Dato PRE_F, se dimP!=0 e L->info!=*P allora non devo staccare alcun nodo ed invoco la chiamata ricorsiva F(L->next,P,dimP), la quale restituirà la lista dei nodi di L che hanno trovato match con P ed L è la vecchia lista alla quale sono stati tolti i nodi della lista del match → valgono PRE_F e POST_F

*/


int main(){
	nodo *e=new nodo('c',0);
	nodo *d=new nodo('b',e);
	nodo *c=new nodo('a',d);
	nodo *b=new nodo('x',c);
	nodo *a=new nodo('a',b);
	nodo *L=new nodo('c',a);
	char P[4]={'c','b','a','b'};
	int dimP=4;
	cout<<"Lista iniziale"<<endl;
	stampa(L);
	cout<<endl;
	cout<<endl;

	nodo *x=F(L,P,dimP);
	
	cout<<"Lista estratti"<<endl;
	stampa(x);
	cout<<endl;
	cout<<"Lista rimasti"<<endl;
	stampa(L);
}