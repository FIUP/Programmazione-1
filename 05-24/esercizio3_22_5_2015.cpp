/*Integrazione sei crediti*/
#include<iostream>
#include<fstream>
using namespace std;

struct nodo{int info; nodo* left,*right; nodo(int a=0, nodo* b=0, nodo*c=0){info=a; left=b;right=c;}};

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
}//Stampa l'albero su input standard

void stampa_lf(nodo *r, ofstream& out){
	if(r){
		out<<r->info<<'(';
		stampa_lf(r->left,out);
		out<<',';
		stampa_lf(r->right,out);
		out<<')';
    }
	else
		out<< '_';
}//Stampa l'albero su file

int conta_n(nodo*r){
	if(!r) 
		return 0;
	else
		return conta_n(r->left)+conta_n(r->right)+1;
}//Conta i nodi

nodo* insert(nodo*r, int y){
	if(!r) 
		return new nodo(y);
   
	if(conta_n(r->left)<=conta_n(r->right))
		r->left=insert(r->left,y);
	else   
		r->right=insert(r->right,y); 
	return r;
}//Costruisce l'albero

nodo* rep_ins(nodo*r, int dim, ifstream & INP){
	if(dim){
		int z;
		INP>>z;
		nodo*x=insert(r,z);
		return rep_ins(x,dim-1,INP);
	}
	return r;
}//Ripete l'inserimento

void sc(int*C, ofstream & OUT){
	if(*C!=-1){
		OUT<<*C<<' '; 
		sc(C+1,OUT);}
	else
		OUT<<"fine cammino"<<endl;
}//Stampa cammino

bool leaf(nodo*x){
	if(!x->left && !x->right)
		return true;
	else return false;
}

/*PRE_cerca=(albero(r) è corretto e non vuoto, k>=0 e y valore qualsiasi, C ha almeno tanti elementi quanta è
l'altezza di albero(r))*/
bool cerca_cam(nodo*r, int k, int y, int *C){
	int cont = conta_n(r);
		
	if(cont <k)
		return false;
	
	if(r->info ==y)
		k--;

	if(k==0 && leaf(r)){
		*C=-1;
		return true;
	}

	if(r->left && cerca_cam(r->left, k,y,C+1)){
		*C =0;
		return true;
	}
	
	if(r->right && cerca_cam(r->right, k,y,C+1)){
		*C=1;
		return true;
	}

}
/*POST_cerca=(restituisce true sse in r esiste un cammino da r ad una foglia con esattamente k nodi con
campo info=y e false altrimenti, in caso restituisca true, C contiene una sequenza (anche vuota) di 0/1 che
termina con -1 e che individua il cammino più a sinistra in albero(r) con esattamente k y).*/

main(){
	ifstream IN("input");
	ofstream OUT("output");
	if(IN && OUT) { 
		int dim,k,y;
		IN>>dim;
		nodo* R=rep_ins(0,dim,IN);//data
      
		IN>>k>>y;
		//stampa_lf(R,OUT);
		int C[30];
		bool b=cerca_cam(R,k,y,C);//da fare
		if(b){
			OUT<<"true con cammino="; 
			sc(C,OUT); OUT<<endl;
		} //sc data
		else
			OUT<<"nessun cammino con "<<k<<" valori="<<y<<endl;
			IN.close(); OUT.close(); 
	}
	else
		cout<<"errore con i files";
}