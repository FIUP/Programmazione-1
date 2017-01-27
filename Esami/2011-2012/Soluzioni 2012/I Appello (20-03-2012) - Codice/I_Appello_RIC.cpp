//Esercizio ricorsivo
#include<iostream>
using namespace std;
struct nodo{int info;nodo* next;nodo(int a=0,nodo* p=0){info=a;next=p;}};
int G(nodo* &L,int y,int k)
{
if(!L)
	return 0;
int a=G(L->next,y,k);
if(L->info==y)
	{
	a++;
	if(a>k)
		{
		nodo* b=L;
		L=L->next;
		delete b;
		return a;
		}
	else
		return a;
	}
	else
			return a;
	}
main()
{
nodo* Ls=new nodo(6,new nodo(7,new nodo(8,
new nodo(6,new nodo(6,new nodo(7,0))))));
int n,inf;
cin>>n>>inf;
int num=G(Ls,inf,n);   //numero di nodi con campo campo info==inf
}
