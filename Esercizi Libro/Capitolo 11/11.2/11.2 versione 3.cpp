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

/*int conta_nodo(nodo *G)
{
	if(G)
	{
		return 1+conta_nodo(G->next);
	}
	else
		return 0;
}*/

int campi_x(nodo *G, int x)
{
	if(G)
	{
		if(G->info==x)
		{
			return 1+campi_x(G->next,x);
		}
		else return campi_x(G->next,x);
	}
	return 0;
}

void build(nodo *&G, int m)
{
	if(m==0)
		return;
	else
		{
			int x;
			cin >> x;
			G=new nodo(x,0);
			build(G->next,m-1);
		}
}

main()
{
	nodo *G=0;
	build(G,10);
	stampa(G);
	//int y=conta_nodo(G);
	//cout<<"il numero di nodi e'=  "<<y<<endl;
	int x=2;
	int z=campi_x(G,x);
	cout<<"campi info x="<<z<<endl;
}
