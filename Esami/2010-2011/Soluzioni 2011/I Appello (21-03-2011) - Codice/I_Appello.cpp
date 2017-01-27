#include <iostream>
using namespace std;

struct nodo{
	int info;
	nodo *next;
	nodo(int a=0,nodo *b=0)
	{info=a;next=b;}
};

void stampa(nodo *x)
{
	if(x){
		cout<< x->info;
		stampa(x->next);
	}
}

//iterativa  
void F(nodo *&L,nodo *&E,int k){ // occhio, per k=3 questa soluzione non va.
	int cont=1;
	nodo *questo=L;
	nodo *prec=0;
	E=0;
	
	while(questo->next){
		if(cont+1==k){
			nodo *temp=questo->next;
			questo->next=questo->next->next;
			temp->next=0;
			if(!E){
				E=temp;
				prec=temp;
			}
			else{
				prec->next=temp;
				prec=temp;
			}
			cont=0;
		}
		
		cont++;		
		if (questo->next) questo=questo->next;
	}
}

//ricorsiva
void G(nodo *&L,nodo *&E,int k,int i){
	if(!L){E=0; return;}
	
	if(k==i){
		E=L;
		L=E->next;
		G(L,E->next,k+k,1);
	}
	else
		G(L->next,E,k,i+1);
}

int main(){
	nodo *d=new nodo(3,0);
	nodo *c=new nodo(2,d);
	nodo *b=new nodo(4,c);
	nodo *a=new nodo(1,b);
	nodo *L=new nodo(0,a);	
	nodo *E=new nodo(0,0);
	int k=2,i=1;
	
	cout<<"Lista originale"<<endl;
	stampa(L);
	cout<<endl;
	
	//F(L,E,k);
	G(L,E,k,i);
	
	cout<<"Lista estratta"<<endl;
	stampa(E);
	cout<<endl;
	cout<<"Lista rimanenti"<<endl;
	stampa(L);
	cout<<endl;
}
