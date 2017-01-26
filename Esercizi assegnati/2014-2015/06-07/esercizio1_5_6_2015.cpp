/*Integrazione sei crediti
svolto in aula il 05/06/2015*/
#include<iostream>
#include<fstream>
using namespace std;

struct nodo{int info1,info2; nodo* next; nodo(int a=0, int b=0, nodo* c=0){info1=a; info2=b; next=c;}};
struct cop{nodo* N; int num; cop(nodo* a=0, int b=0){N=a; num=b;}};


nodo* costruisci(int n, int dim, ifstream & IN){
	if(n==dim)
		return 0;
	int x;
	IN>>x;
	return new nodo(x,n,costruisci(n+1, dim, IN));
}

/*PRE = x definito, Lista(L) è corretta, eventualmente vuota
*/
cop salta(nodo *L, int x, int n){ //n contatore di quanti nodi saltare
	if(!L)
		return cop();
	if(L->info1 !=x)
		return salta(L->next,x,n+1);
	else
		return cop(L,n);	
}
/*POST = (restituisce z di tipo cop, se z.N = 0 allora ho finito
la lista senza trovare match di x. Altrimenti z.N | z.N->info1 == x
e z.num = quanti nodi sono da saltare da L per arrivare a z.N e questi
non matchano x 

PRE =  Lista(L) è corretta, eventualmente vuota, P[0...dimP-1] è definito
n è definito e n = vn */
cop match(nodo *L, int*P, int dimP, int n){
	if(!dimP || !L)
		return cop(L,n);
	if(*P == L->info1)
		return match(L->next,P+1,dimP-1,n+1);
	else return cop(L,n);
}

nodo* f0(nodo*L, int*P, int dimP){
	if(!L || !dimP)
		return 0;
	cop x = salta(L,*P,0);
	if(!x.N)
		return 0;
	cop y = match(x.N, P, dimP,0);
	nodo* z = f0(y.N, P+y.num,dimP-y.num);
	return new nodo(x.num,y.num,z);
}

void stampa(nodo*L, ofstream & OUT){
	if(L){
		OUT<<"salta="<<L->info1<<" matcha="<<L->info2<<' ';
		stampa(L->next,OUT);
	}
	else
		OUT<<endl;
}

main(){
	ifstream IN("input");
	ofstream OUT("output");
	if(IN && OUT) { 
		int dim,dimP, P[30];
		IN>>dim;
		nodo* L=costruisci(0,dim,IN);//data
   
   
		IN>>dimP;
		for(int i=0; i<dimP; i++)
			IN>>P[i];
		nodo*K=f0(L,P,dimP); //da fare 
		stampa(K,OUT); //data
		OUT<<"fine"<<endl;
   
		IN.close(); OUT.close(); 
	}
	else
		cout<<"errore con i files";
}