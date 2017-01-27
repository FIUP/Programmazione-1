#include<iostream>
#include<fstream>

using namespace std;

struct nodo{
	int info1, info2; 
	nodo* next; 
	nodo(int a=0, int c=0, nodo* b=0) {info1=a; info2=c; next=b;}
};


//PRE_F1=(L è una lista corretta, y e v sono interi qualsiasi, mentre k>0, L=vL)
nodo* F1(nodo*&L, int y, int k, int & v){

	if(!L){
		return 0;
	}
	
	if(L->info1==y){
		v=v+1;
		nodo *x=new nodo(L->info1, L->info2, F1(L->next, y, k, v));
		if(v<k && !x->next)
			return 0;
		if(v>k)
			v=k;
		if(v>0){
			v=v-1;
			L=L->next;
			return x;
		}
		return x->next;
	}
	return F1(L->next, y, k, v);	

}//POST_F1=(se vL contiene meno di k nodi con campo info=y, allora L=vL e F1 restituisce 0, altrimenti, L è la lista ottenuta da vL togliendo da vL gli ultimi (per posizione) k nodi con campo info1=y, mentre F1 restituisce la lista dei nodi tolti da vL in ordine di posizione in vL.....è possibile che sia anche necessario aggiungere qualcosa su v)


//PRE_F2=(L è una lista corretta, y e v sono interi qualsiasi, mentre k>0, L=vL)
nodo* F2(nodo*&L, int y, int k, int & v){
	
	if(!L){
		return 0;
	}
	
	if(L->info1==y){
		v=v+1;
		nodo *x=new nodo(L->info1, L->info2, F2(L->next, y, k, v));
		if(v==k){
			L=L->next;
			return x;
		}
		if(v>k)
			v=v-1;
		return 0;
	}
	return F2(L->next, y, k, v);	

}//POST_F2==(se vL contiene meno di k nodi con campo info=y, allora L=vL e F2 restituisce 0, altrimenti, L è la lista ottenuta da vL togliendo da vL gli i primi (per posizione) k nodi con campo info1=y, mentre F2 restituisce la lista dei nodi tolti da vL in ordine di posizione in vL.....è possibile che sia anche necessario aggiungere qualcosa su v)


nodo* copia(nodo*L){
	
	if(L)
		return new nodo(L->info1, L->info2, copia(L->next));
	else return 0;

}


void crea(nodo*&L, int dim, ifstream & INP, int n){
	
	if(dim){
		int x;
		INP>>x;
		L=new nodo(x, n);
		crea(L->next, dim-1, INP, n+1);
	} else L=0;

}


void stampa(nodo* x, ofstream & OUT){
	if(x){
		OUT<< x->info1<<' '<<x->info2<<' ';
		stampa(x->next, OUT);
	} else OUT<<endl;
}


main(){
	try{
		ifstream INP("input");
		ofstream OUT("output");
		if(!INP) throw(0);
		if(!OUT) throw(1);
		int dim, k, y, v;
		INP>>k>>y>>dim;
 
		nodo*L1=0;
		crea(L1,dim,INP,0);
  
		nodo*L2=0;
		L2=copia(L1);
  
		v=0;
		nodo* x1=F1(L1,y,k,v);
		stampa(x1,OUT);
		stampa(L1,OUT);

		v=0; //va rifatta
		nodo* x2=F2(L2,y,k,v);
		stampa(x2,OUT);
		stampa(L2,OUT);

		OUT<<endl;
	}	catch(int x) {
		switch(x){
			case 0: cout<<"problemi con input"<<endl; break;
			case 1: cout<<"problemi con output"<<endl; break;
		}
	}
}
