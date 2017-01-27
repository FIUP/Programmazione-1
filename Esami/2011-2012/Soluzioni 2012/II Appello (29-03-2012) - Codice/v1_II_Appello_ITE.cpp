#include <iostream>
using namespace std;
struct nodo{
	int info;
	nodo* next;
	nodo(int a=0,nodo*b=0){
		info=a;
		next=b;
	}
};

void del(nodo* L)
{
while(L)
	{
	nodo*x=L;
	L=L->next;
	delete x;
	}
}
/*
PRE=(L è una lista non vuota)
POST=(restituite la lista vuota)
*/
nodo* taglia(nodo* L,int k)
{
while(k>1)
	{
	L=L->next;
	k--;
	}
return L;
}
/*
PRE=(L è una lista con almento k nodi, k>1)
POST=(restituisce il puntatore al k° nodo di L)
*/
void F(nodo*L,int* A,int dim)
{
nodo*x=L;
for(int i=0;i<dim-1;i+=2)
	{	
	nodo*k=taglia(x,A[i]);
	nodo*j=taglia(k->next,A[i+1]);
	nodo* d=k->next;
	k->next=j->next;
	j->next=0;	
	del(d);
	x=k->next;
	}
if(dim%2)
	{
	nodo* a=taglia(x,A[dim-1]);
	del(a->next);
	a->next=0;
	}
}
int main()
{
nodo* L=new nodo(6,new nodo(4,new nodo(4,new nodo(7,new nodo(8,new nodo(10,new nodo(12,0)))))));
int A[3]={2,1,3};
F(L,A,3);
}
