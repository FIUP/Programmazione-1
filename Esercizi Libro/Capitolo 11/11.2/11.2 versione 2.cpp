#include<iostream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo * b=0){info=a; next=b;};};

void stampa(nodo *G)
{
	if(G)
		{
			cout<<G->info<<" ";
			stampa(G->next);
		}
	else
	cout<<endl;
	 return;
}

int conta_nodo(nodo *G)
{
	if(G)
	{
		return 1+conta_nodo(G->next);
	}
	else
		return 0;
}

nodo* build(int k,int i)
{
	if(k==0)
		return 0;
	else
		{
		return new nodo(i,build(k-1,i+1));
		}
}

main()
{
	int k;
	int i=1;
	cin >> k;
	nodo *G=build(k,i);
	stampa(G);
	int y=conta_nodo(G);
	cout<<"il numero di nodi e'=  "<<y<<endl;
}
