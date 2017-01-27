#include <iostream>
using namespace std;

struct nodo{
	char info;
	nodo *next;
	nodo(char a='0',nodo *b=0)
	{info=a;next=b;}
};

void stampa(nodo *x)
{
	if(x){
		cout<< x->info;
		stampa(x->next);
	}
}


nodo *F(nodo *&L,char *P,int dimP){
	if(!L) return 0;
	if(!dimP) return 0;
	
	if(L->info==P[0]){
		nodo *x=L;
		L=L->next;
		x->next=F(L,P+1,dimP-1);
		return x;
	}
	else{
		return F(L->next,P,dimP);
	}
}

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
