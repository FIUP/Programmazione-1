/*Integrazione sei crediti*/
#include <iostream>
#include <fstream>
using namespace std;

struct nodo{
	int info; 
	nodo* next; 
	nodo(int a=0, nodo* b=0){
		info=a; 
		next=b;}
};

nodo* crea_inv(int dim,ifstream & IN){
	
	if(!dim){
		return NULL;
	}
	
	nodo *n= new nodo();
	n->next = crea_inv(dim-1,IN); 
	IN >> n->info;
	return n;
}

void stampa(nodo* L, ofstream& OUT){
	if(!L)
		OUT << "fine";
	else{
		OUT << L->info << "->";
		stampa(L->next, OUT);
	}
}

main(){
	ifstream IN("input");
	ofstream OUT("output");
	
	if(IN && OUT){
		int dim;
		nodo* L;
	
		IN >> dim;
		L = crea_inv(dim, IN);	
		stampa(L, OUT);
	
		IN.close();
		OUT.close();
	}
	else
		cout << "errore con i file"<< endl;
}
