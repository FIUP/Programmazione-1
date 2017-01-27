#include<iostream>
using namespace std;
    
struct nodo
{
  int info;
  nodo *next;
  nodo(int a=0, nodo *b=0){info=a; next=b;}
};

void stampa(nodo *L){
	while(L){
		cout<<L->info<<" ";
		L=L->next;
	}
	cout<<endl;
}

nodo *taglia(nodo *L,int k){
	while(k>1){
		k--;
		L=L->next;
	}
	return L;
}

void del(nodo *L){
	if(L)
	{	
		del(L->next);
		delete L;
	}
	
}

//iterativa
void F(nodo *L,int *A,int lim){
	nodo * temp=0;
	for(int i=0;i<lim;i++){
		nodo *x=taglia(L,A[i]);		
		if(i%2!=0){
			temp->next=x->next;
			x->next=0;
			del(L);
			L=temp->next;
		}
		else{
			temp=x;
			L=temp->next;
		}
	}	
	
	if(lim%2!=0){
		temp->next=0;
		del(L);
	}
}

//ricorsiva
void FRpari(nodo *L,int *A,int lim){
	if(lim==2){
		nodo *x=taglia(L,A[0]);
		nodo *y=taglia(x->next,A[1]);
		nodo *temp=y->next;
		y->next=0;
		del(x->next);
		x->next=temp;
	}
	else{
		nodo *x=taglia(L,A[0]);
		nodo *y=taglia(x->next,A[1]);
		nodo *temp=y->next;
		y->next=0;		
		del(x->next);
		x->next=temp;
		FRpari(temp,A+2,lim-2);
	}
}

void FRdispari(nodo *L,int *A,int lim){
	if(lim==1){
		nodo *x=taglia(L,A[0]);
		nodo *y=x->next;
		x->next=0;
		del(y);
	}
	else{
		nodo *x=taglia(L,A[0]);
		nodo *y=taglia(x->next,A[1]);
		nodo *temp=y->next;
		y->next=0;
		del(x->next);
		x->next=temp;
		FRdispari(temp,A+2,lim-2);
	}	
}

void FR(nodo *L,int *A,int lim){
	if(lim%2==0) FRpari(L,A,lim);
	else FRdispari(L,A,lim);
}

int main(){
	nodo *g=new nodo(2,0);
	nodo *f=new nodo(1,g);
	nodo *e=new nodo(2,f);
	nodo *d=new nodo(0,e);
	nodo *c=new nodo(2,d);
	nodo *b=new nodo(3,c);
	nodo *a=new nodo(2,b);
	nodo *L=new nodo(3,a);	
	int lim=3;
	int A[]={2,1,3};
	
	//F(L,A,lim);	
	FR(L,A,lim);
	
	stampa(L);
}
