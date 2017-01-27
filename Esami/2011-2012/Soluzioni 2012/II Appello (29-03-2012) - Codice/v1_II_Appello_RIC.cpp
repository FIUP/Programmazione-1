#include<iostream>
using namespace std;
struct nodo{int info;nodo*next;nodo(int a=0,nodo*b=0){int info=a;next=b;}};
void del(nodo* L)
{
while(L)
	{
	nodo*x=L->next;
	delete L;
	L=x;
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
void FR(nodo*L,int*A,int lim)
{
if(lim==0)
		return 0;
if(lim==1)
	{
	nodo*A=taglia(L,A[0]);
	del(A->next);
	A->next=0);
	}
else
	{
	nodo* k=taglia(L,A[0]);
	nodo* l=taglia(k->next,A[1]);
	nodo*a=k->next;
	k->next=l->next;
	l->next=0;
	del(a)
	F(k->next,A+2,lim-2);
	}
}
main()
{
nodo* L=new nodo(6,new nodo(4,new nodo(4,new nodo(7,new nodo(8,new nodo(10,new nodo(12,0)))))));
int A[3]={2,1,3};
FR(L,A,3);
}

}