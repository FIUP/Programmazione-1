#include<iostream>
#include<fstream>

using namespace std;


struct nodo{
	int info; 
	nodo *left, *right; 
	nodo(int a=0, nodo* b=0, nodo* c=0) {info=a; left =b; right=c;}
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
		if(!r)
			r=new nodo(x);
		else {
			if(conta(r->left)<=conta(r->right))
				inserisci(r->left, dim, x, INP);
			else inserisci(r->right, dim, x, INP);
		}
		crea_a(r, dim-1, INP);
	}
	
}//POST_crea_a=(r è vr a cui sono stati aggiunti dim nodi con campi info letti da "input")



//PRE=()
void stampa_l(nodo *r, ofstream &OUT){
	
	if(r){
		OUT<<r->info<<"(";
		stampa_l(r->left, OUT);
		OUT<<",";
		stampa_l(r->right, OUT);
		OUT<<")";
	} else OUT<<"_";

}//POST=()


//PRE_cerca=(r albero corretto, k>=0 e y valore qualsiasi)
bool cerca_cam(nodo*r, int k, int y){
	
	if(!r){
		if(k==0)
			return 1;
		return 0;
	}

	if(r->info==y)
		k=k-1;

	if(!r->left && !r->right){
		if(k==0)
			return 1;
		return 0;
	}	
	
	if(r->left && cerca_cam(r->left, k, y))
		return 1;
	if(r->right && cerca_cam(r->right, k, y))
		return 1;

}//POST_cerca=(restituisce true sse in r esiste un cammino con esattamente k nodi con campo info=y)



/* PROVA DI CORRETTEZZA: PRE_cerca_cam <cerca_cam()> POST_cerca_cam

	caso base: !r 
---------------
Vale PRE_cerca_cam in quanto r è una lista vuota:
	- se k=0, allora retituisce true in quanto in una lista vuota non ci sono 0 nodi con campo info=y → vale POST_cerca_cam
	- se k>0, allora restituisce false in quanto in una lista vuota ci sono al massimo 0 nodi con campo info=y → vale POST_cerca_cam

	caso base: !r->left && !r->right
----------------------------------
Vale PRE_cerca_cam in quanto r è una lista non vuota:
	- se k=0, allora retituisce true in quanto sono arrivato ad una foglia e se ho incontrato un nodo con campo info=y ho decrementato k di 1 → vale POST_cerca_cam
	- se k>0, allora restituisce false in quanto in quel cammino non ho trovato il numero di nodi che cercavo con campo info=y → vale POST_cerca_cam

	passo induttivo: cerca_cam(r->left, k, y)
-------------------------------------------
Per ipotesi induttiva cerca_cam(r->left, k, y) soddisfa PRE.
Se r->left allora non sono ancora arrivato ad una foglia e quindi non ho cercato in tutto il cammino

*/



main(){
	try{
		ifstream INP("input");
		ofstream OUT("output");
		if(!INP) throw(0);
		if(!OUT) throw(1);
		int dim, k, y;
		INP>>k>>y>>dim;
  
		nodo*r=0;
		crea_a(r,dim,INP);//da fare
		stampa_l(r,OUT); //da fare
  
		bool b=cerca_cam(r,k,y); //da fare
		OUT<<endl<<b<<endl;
	} catch(int x) {
		switch(x){
			case 0: cout<<"problemi con input"<<endl; break;
			case 1: cout<<"problemi con output"<<endl; break;
		}
	}
}
