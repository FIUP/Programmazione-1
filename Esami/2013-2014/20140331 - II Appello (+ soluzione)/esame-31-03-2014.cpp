#include <iostream>
#include <fstream>

using namespace std;

struct nodo{
	int info1, info2; 
	nodo* next; 
	nodo(int a=0, int c=0, nodo* b=0){
		info1=a; info2=c;	next=b; 
	}
};


nodo* copia(nodo* X){
	if(X)
		return new nodo(X->info1, X->info2, copia(X->next));
	return 0;
}

void crea(nodo*&L, int dim, ifstream & INP, int n){
	int x;
	if(n<dim){
		INP>>x;
		L=new nodo(x,n,0);
		crea(L->next, dim,INP,n+1);
	} else L=0;
}

void crea1(nodo*&L, int dim, ifstream & INP, int n){
	int x,y;
	if(n<dim){
		INP>>x>>y;
		cout<<"x="<<x<<" y="<<y<<endl;
		L=new nodo(x,y,0);
		crea1(L->next, dim,INP,n+1);
	} else L=0;
}

void stampa(nodo* x, ofstream & OUT){
	if(x){
		OUT<<'('<< x->info1<<','<<x->info2<<')';
		if(x->next)
		OUT<<"->";
		//cout<< x->info1<<' '<<x->info2<<' ';
		stampa(x->next, OUT);
	} else{
		OUT<<endl;
		//cout<<endl;
	}
}


//PRE_cercaInizio=(T è una lista corretta e P è definito)
int cercaInizio(nodo *&T, int *P){
	int inizio_match=0;
	while(T && T->info1!=*P){
		T=T->next;
		inizio_match++;
	}
	if(!T) //se ho finito la lista T allora non ci sono altri match con P
		return -1;
	//else : T punta al nodo che fa match con il primo elemento di P
	return inizio_match;
}//POST_cercaInizio=(ritorno il numero di nodi di T saltati per arrivare ad avere un match con il primo elemento di P e T punta a questo nodo; nel caso non si trovi un match del primo elemento di P in T allora ritorna -1 (T punta al nodo successivo all'ultimo della lista))


//PRE_lunghezzaMatch=(T è una lista corretta, P è definito, indiceP e dimP sono interi >=0)
int cercaFine(nodo *&T, int *&P, int &indiceP, int dimP){
	int fine_match=0;
	while(T && indiceP<dimP && T->info1==*P){
		fine_match++;
		T=T->next;
		indiceP++;
		P=P+1; //gli elementi di P precedenti non ci interessano più
	}
	return fine_match;
}//POST_lunghezzaMatch=(restituisce con il return il numero di nodi del match contigui di P[vIndiceP..indiceP] (dove vIndiceP è il vecchio valore) su T; T diventa il nodo successivo all'ultimo nodo che ha fatto match con P[indiceP])


//PRE_costruisciLista=(l_match è una lista corretta non vuota, inizio_match e fine_match sono interi >=0)
void costruisciLista(nodo *l_match, int inizio_match, int fine_match){
	nodo *l_match_aux=l_match;
	while(l_match_aux->next!=0)
		l_match_aux=l_match_aux->next;
	l_match_aux->next=new nodo(inizio_match,fine_match);
	return ;
}//POST_costruisciLista=(aggiunge il nodo (inizio_match,fine_match) alla fine della lista del match di P su T)


//PRE_M1=(T lista corretta, P è un array di dimP>=0 elementi)
nodo* M1(nodo* T, int*P, int dimP){
	if(!dimP)
		return 0;
	nodo *l_match=0;
	int indiceP=0;
	bool stop=false;	//gestisce le interruzioni del ciclo
	while(T && !stop){
		//R_M1=(se T allora l_match è la lista del primo match di P[0..indiceP] su T, altrimenti l_match è vuota in quanto non possiamo trovare match)&&(se stop=true allora abbiamo trovato un match completo di P[0..dimP-1] su T, altrimenti il match trovato finora non è completo e possiamo continuare a cercare)
		int inizio_match=cercaInizio(T,P);
		//T punta al nodo che fa match con P[indiceP]
		if(inizio_match!=-1){
			int fine_match=cercaFine(T,P,indiceP,dimP);
			//indiceP è l'indice dell'ultimo elemento del quale abbiamo trovato il match (mentre è P a puntare - se esiste - al successivo)
			//T punta al nodo successivo all'ultimo della lista che ha fatto match con P[indiceP] 
			if(!l_match)
				//prima di aggiungere nodi ne dobbiamo creare uno!
				l_match=new nodo(inizio_match,fine_match);
			else costruisciLista(l_match,inizio_match,fine_match);
			if(indiceP==dimP-1) //abbiamo trovato un match completo
				stop=true;
		}else stop=true;
	}
	return l_match;
}//POST_M1=(M1 restituisce col return la lista del match di P in T)


/* PROVA DI CORRETTEZZA: 

	Condizione iniziale: PRE → R_M1
---------------------------------
Dato PRE_M1 e stop=false:
 - se T è una lista corretta non vuota allora l_match è vuota in quanto dobbiamo ancora cominciare a cercare → vale R
 - se T è vuota allora l_match è vuota ed è la lista del primo match più lungo in quanto non abbiamo nodi da cercare → vale R

	Invarianza: R_M1 && (T && !stop) → R_M1
-----------------------------------------
Se T è una lista corretta non vuota e non abbiamo ancora trovato un match completo di P su T, l_match è la lista del primo match di P[0..indiceP] su T e posso ancora cercare altri match di P[indiceP..dimP-1] su T → vale R_M1

	Condizione di uscita: R_M1 && !(T && !stop) → POST_M1
-------------------------------------------------------
 - Se !T allora non ci possono essere altri match di P su T e l_match è la lista completa del match di P[0..dimP-1] (non necessariamente completo) su tutto T → vale POST_M1
 - Se stop=true allora abbiamo trovato un match completo di P su T e l_match è la lista del match di P[0..dimP-1] su T → vale POST_M1

*/


//PRE_saltaNodi=(T è una lista corretta non vuota, info1 è un intero >=0)
nodo *&saltaNodi(nodo *&T, int info1){
	if(T && info1)
		return saltaNodi(T->next,info1-1);
	//o è finita la lista o T è il puntatore al info1-esimo nodo
	return T;
}//POST_saltaNodi=(se all'invocazione la lista aveva nodi sufficienti il puntatore T iniziale punta all'info1-esimo nodo successivo; altrimenti punta al nodo successivo all'ultimo della lista)


//PRE_togliNodi=(T è una lista corretta non vuota, info2 è un intero >0)
nodo *togliNodi(nodo *&T, int info2){
	if(!T || !info2)
		return T;
	nodo *aux=T; //mi ricordo il puntatore per deallocare il nodo
	T=T->next;
	delete aux;
	return togliNodi(T,info2-1);
}//POST_togliNodi=(se all'invocazione T era vuota o info2=0 allora ritorna T (che è vuoto o altrimenti non ci siamo spostati); altrimenti se all'invocazione la lista aveva nodi sufficienti il nodo successivo al puntatore T iniziale punta all'info2-esimo nodo successivo (o a quello successivo all'ultimo della lista) e i nodi tolti sono deallocati)


//PRE_TB=(T e X sono liste corrette, i campi info1 e info2 dei nodi di X (se ci sono nodi) sono tutti maggiori o uguali a 0, T=vT)
void TB(nodo*&T, nodo*X){

	if(!T || !X)
		return ;
	nodo *&aux1=saltaNodi(T,X->info1);
	if(aux1){ //risparmio una chiamata di funzione
		nodo *aux2=togliNodi(aux1,X->info2);
		aux1=aux2; //aux1 è uno dei nodi da togliere!
		if(X->next) //risparmio una chiamata di funzione
			TB(aux1,X->next);
	}

}//POST_TB=(T=(vT-X), i nodi di (X di vT) sono deallocati)


/* PROVA DI CORRETTEZZA: PRE_TB < TB() > POST_TB 

	Caso base: !T || !X
---------------------
Dato PRE_TB:
 - se T è una lista vuota allora non posso saltare o staccare nessun nodo → vale POST_TB
 - se X è una lista vuota allora T rimane invariato → vale POST_TB

	Caso ricorsivo: aux && X->next && TB(aux1,X->next)
----------------------------------------------------
Dato PRE_TB, invoco la chiamata ricorsiva TB(aux1,X->next), con aux1 nodo definito e X->next definito: la funzione salterà i X->next->info1 nodi e staccherà i X->next->info2 nodi → valgono PRE_TB e POST_TB
  	
*/


//PRE_TC=(T e X sono liste corrette, i campi info1 e info2 dei nodi di X (se ci sono nodi) sono tutti maggiori o uguali a 0, T=vT)
nodo* TC(nodo*&T, nodo*X){
	if(!T || !X)
		return 0;
	if(X->info1){ //salto i nodi
		X->info1--;
		return TC(T->next,X);
	}else{ //stacco i nodi
		if(X->info2){
			X->info2--;
			nodo *aux=T;
			T=T->next;
			return new nodo(aux->info1,aux->info2,TC(T,X));
			delete aux; //pulizia
		}else return TC(T,X->next);
	}
}//POST_TC=( T=(vT-X), e restituisce (X di vT) con il return)

/* PROVA DI CORRETTEZZA: PRE_TC < TC() > POST_TC

	Caso base: !T || !X
---------------------
Dato PRE_TC:
 - se T è una lista vuota allora non posso saltare o staccare nessun nodo → vale POST_TC
 - se X è una lista vuota allora T rimane invariato → vale POST_TC

	Caso ricorsivo: X->info1!=0 && TC(T->next,X)
-------------------------------------------
Dato PRE_TC, se X->info1!=0 allora diminuiamo di 1 il valore di X->info1 ed invochiamo la chiamata ricorsiva TC(T->next,X), con T->next lista corretta: la funzione restituirà (X di vT) con il return → valgono PRE_TC e POST_TC

	Caso ricorsivo: X->info1==0 && X->info2!=0 && new nodo(aux->info1,aux->info2,TC(T,X))
---------------------------------------------------------------------------------------
Dato PRE_TC, se X->info1==0 e X->info2!=0 allora diminuiamo il valore di X->info2, avanziamo nella lista ed invochiamo la chiamata ricorsiva in new nodo(aux->info1,aux->info2,TC(T,X)), con T lista corretta: la funzione restituirà (X di vT) con il return → valgono PRE_TC e POST_TC

*/

main(){
	try{
		ifstream INP("input");
		ofstream OUT("output");
		if(!INP) throw(0);
		if(!OUT) throw(1);
		int P[100],dimP,dim,dimX;
		INP>>dim>>dimP>>dimX;
  
		nodo*L=0;
		crea(L,dim,INP,0);//data
  
		for(int i=0;i<dimP ; i++)
			INP>>P[i];
		nodo*z=M1(L,P,dimP);    //da fare
		if(!z)
			OUT<<"nessun match"<<endl;
		else stampa(z,OUT);//data
		OUT<<endl;

		nodo* X=0;
		crea1(X,dimX,INP,0);//data
     
		nodo*L1=copia(L);//data
  
		TB(L1,X);        //da fare
		stampa(L1,OUT);
		cout<<endl;
		nodo* z1=TC(L,X); //da fare 
		stampa(L,OUT);
		cout<<endl;
		stampa(z1,OUT);
		cout<<endl;

	} catch(int x){
		switch(x){
			case 0: cout<<"problemi con input"<<endl; break;
			case 1: cout<<"problemi con output"<<endl; break;
		}
	}
}
