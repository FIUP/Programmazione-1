
//soluzione by: Federico S. B.

/*Integrazione 6 crediti*/

#include<iostream>
#include<fstream>
using namespace std;
struct nodo{int info; nodo* left,*right; nodo(int a=0, nodo* b=0, nodo*c=0){info=a; left=b;right=c;}};
struct innesto{ bool l, r; nodo* N; innesto* next; innesto(bool a=false, bool b=false, nodo* c=0, innesto* d=0){l=a;r=b;N=c;next=d;}};

bool leaf (nodo *r){
	if(!r->left && ! r->right)
		return true;
	else return false;
}

void stampa_l(nodo *r, ofstream & OUT){
	if(r){
		OUT<<r->info<<'(';
		stampa_l(r->left,OUT);
		OUT<<',';
		stampa_l(r->right,OUT);
		OUT<<')';
	}
	else
		OUT<< '_';
}
int conta_n(nodo*r){
	if(!r) 
		return 0;
	else
		return conta_n(r->left)+conta_n(r->right)+1;
}

nodo* insert(nodo*r, int y){
	if(!r) 
		return new nodo(y);
   
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

void stampa(innesto* a, ofstream & OUT){
	if(a){
		OUT<<"left="<<a->l<<" right="<<a->r<<" nodo="<<a->N->info<<endl;
		stampa(a->next,OUT);}
	else
		OUT<<endl;
}

innesto * conc(innesto* a, innesto *b){
	if(!a)
		return b;
	a->next = conc(a->next,b);
	return a;
}

innesto* f0(nodo*r){
	if(!r)
		return 0;

	innesto* a = f0(r->left);
	innesto *b = f0(r->right);
  
	if(r->left && r->right)
		return conc(a,b);
  
	if(r->left && !r->right)//innesto destro
		return conc(a,new innesto(0,1,r,b));
  
	if(!r->left && r->right)
		return conc(a,new innesto(1,0,r,b));
       
	if(leaf(r))//r e' foglia ritorno l'innesto
		return new innesto(1,1,r,0);
}

void dealloca(innesto* & Inn){

	innesto *p = Inn->next;
	delete Inn;
	Inn = p;
}
//POST = dealloca l'innesto corrente, se non è più innesto

//innesto = l,r,nodo N, innesto next

int f1(innesto*& Inn, ifstream & INP){
	if(!Inn)
		return 0;
	
	int y;
	INP >> y;
	
	if(y ==-2)
		return 0;
	
	if(Inn->l ==true){
		Inn->N->left = new nodo(y);
		Inn->l = false;
		return 1+ f1(Inn,INP);
	}
	if(Inn->r == true){
		Inn->N->right = new nodo(y);
		Inn->r = false;
		dealloca(Inn);
		return 1 + f1(Inn,INP);
	}	
}

main(){
	ifstream IN("input");
	ofstream OUT("output");
	if(IN && OUT){ 
		int dim;
		IN>>dim;
		nodo* R=rep_ins(0,dim,IN);//data
		stampa_l(R,OUT);//data
		OUT<<endl;
		innesto* x=f0(R);//da fare
		stampa(x,OUT); //data
		int a=f1(x,IN); //da fare
		OUT<<"n. innesti="<<a<<endl;
		stampa_l(R,OUT); //data
		OUT<<endl;
		stampa(x,OUT); //data
		IN.close(); OUT.close(); 
	}
	else
	cout<<"errore con i files";
}
