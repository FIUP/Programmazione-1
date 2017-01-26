/*Integrazione sei crediti*/
#include<iostream>
#include<fstream>
using namespace std;

struct nodo{int info; nodo* left,*right; nodo(int a=0, nodo* b=0, nodo* c=0){info=a; left=b; right=c;}};
struct punt{nodo* t; punt* next; punt(nodo*a=0, punt*b =0){t=a; next=b;}};
struct FIFO{
	punt* primo, *fine; 
	FIFO(punt* a=0, punt*b=0){
		primo=a; fine=b;
	}
};

//nodo* f2(FIFO x, int y, ofstream & OUT);

FIFO togli_primo(FIFO x){
	
	if(!x.primo->next){	
		delete x.primo;
		return FIFO();
	}
	
	punt* p = x.primo;
	x.primo = x.primo->next;
	delete p;
	return x;
}

FIFO metti_fondo(FIFO x, nodo*a){
	
	if(!x.fine){
		x.primo = new punt(a);
		x.fine = x.primo;
		return x;
	}
	else {
		x.fine->next = new punt(a);
		x.fine = x.fine->next;
		return x;
	}
}

void stampa_l(nodo *r){
	if(r){
		cout<<r->info<<'(';
		stampa_l(r->left);
		cout<<',';
		stampa_l(r->right);
		cout<<')';
    }
	else
		cout<< '_';
}

void stampa_f(nodo *r, ofstream& out){
	if(r){
		out<<r->info<<'(';
		stampa_f(r->left,out);
		out<<',';
		stampa_f(r->right,out);
		out<<')';
    }
	else
		out<< '_';
}

int conta_n(nodo*r){
	if(!r) return 0;
		else
			return conta_n(r->left)+conta_n(r->right)+1;
}

nodo* insert(nodo*r, int y){
	if(!r) return new nodo(y);
   
	if(conta_n(r->left)<=conta_n(r->right))
		r->left=insert(r->left,y);
	else   
		r->right=insert(r->right,y); 
	return r;
}

nodo* rep_ins(nodo*r, int dim, ifstream & INP){
	if(dim){
		int z;
		INP>>z;
		nodo*x=insert(r,z);
		return rep_ins(x,dim-1,INP);
	}
	return r;
}

FIFO f1(nodo*r){
	punt* p = new punt(r,0);
	FIFO f(p,p);
	return f;
}

nodo*f2(FIFO x, int y, ofstream& OUT){

	if(!x.primo)
		return 0;

	if(x.primo->t->info == y){		
		delete x.primo->next;
		return x.primo->t;
	}
	else{
		OUT<< "nodo:"<< x.primo->t->info << "  ";
		if(x.primo->t->left)
			x = metti_fondo(x,x.primo->t->left);
		if(x.primo->t->right)
			x = metti_fondo(x,x.primo->t->right);		
	}
	FIFO z = togli_primo(x);
	return f2(z,y,OUT);
}

main(){
	ifstream IN("input");
	ofstream OUT("output");
	if(IN && OUT) { 
		int dim,y;
		IN>>dim;
		nodo* R=rep_ins(0,dim,IN);//data
		//stampa_f(R, OUT);
		IN>>y;
		FIFO x=f1(R); //da fare
		nodo* a=f2(x,y,OUT); //da fare
		
		if(a)
			OUT<<"trovato "<<a->info<<endl;
		else
			OUT<<"non trovato"<<endl;
   
		IN.close(); OUT.close(); 
	}
	else
		cout<<"errore con i files";
}