#include<iostream>

/* modificare la funzione dell'esercizio 11.1 in modo che i k nodi che vengono costruiti, 
anziche avere campi info uguali a zero, contengono valori 1,...,k con 1 nel primo nodo e k nell'ultimo. su possono aggiungere parametri alla funzione*/

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
}
