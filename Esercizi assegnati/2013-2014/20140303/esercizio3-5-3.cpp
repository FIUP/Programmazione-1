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


//PRE_cerca=(r albero corretto, C ha almeno tanti elementi quant'è l'altezza di r)
bool cerca_cam(nodo*r, int*C, int &lung, int k, int y){

	if(!r)
		return 0;
	
	if(r->info==y){
		k=k-1;
	}

	if(!r->left && !r->right){
		if(k==0)
			return 1;
		lung=0;
		return 0;
	}

	if(r->left){
		*C=0;
		if(cerca_cam(r->left, C+1, lung, k, y)){
			lung=lung+1;
			return 1;
		}
	}

	if(r->right){ 
		*C=1;
		if(cerca_cam(r->right, C+1, lung, k, y)){
			lung=lung+1;
			return 1;
		}
	}
	
}//POST_cerca=(restituisce true sse in r esiste un cammino con esattamente k nodi con campo info=y, se restituisce true allora C[0..lung-1] contiene il cammino minimo che soddisfa questa proprietà)


//PRE_stampa=()
void stampa(int*T, int dim, ofstream & OUT){
	if(dim){
		OUT<<T[0]<<' ';
		stampa(T+1, dim-1, OUT);
	}
  OUT<<endl;
}//POST_stampa=()


main(){
	try{
		ifstream INP("input");
		ofstream OUT("output");
		if(!INP) throw(0);
		if(!OUT) throw(1);
		int dim, k, y, C[100], lung=0;
		INP>>k>>y>>dim;
  
		nodo*r=0;
		crea_a(r,dim,INP);
		//stampa_l(r,OUT);
  
		bool b=cerca_cam(r,C,lung,k,y);//da fare
		cout<<b<<' '<<endl;
		if(b) 
			stampa(C,lung,OUT);
	} catch(int x) {
		switch(x){
			case 0: cout<<"problemi con input"<<endl; break;
			case 1: cout<<"problemi con output"<<endl; break;
		}
	}
}


