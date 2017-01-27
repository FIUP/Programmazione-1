#include <iostream>
using namespace std;

struct nodo
{
       int info; nodo* next; nodo(int,nodo*);
};
nodo::nodo(int a, nodo*b) 
{
               info=a;
               next=b;
}

nodo* crea(int k, int l)
{
	if (!l)
		return 0;
	cin>>k;
	return new nodo(k,crea(k,l-1));
}

void stampa (nodo *i)
{
	if (!i)
		return;
	cout<<i->info<<" ";
	stampa(i->next);
}

int conta (nodo* inizio)
{
	if (!inizio)
		return 0;
	else
		return 1+conta(inizio->next);
}

int cerca (nodo* inizio, int x)
{
	if (!inizio)
		return 0;
	else
	{	if (inizio->info==x)
			return 1+cerca(inizio->next,x);
		else
			return 0+cerca(inizio->next,x);
	}
}

nodo* dealloca(nodo*& inizio, int k)
{
	if (!inizio||!k)
		return inizio;
	else
	{	
		nodo *n=inizio;
		inizio=inizio->next;
		delete(n);
		dealloca(inizio,k-1);
	}
}

nodo* inserisci_testa(nodo*& inizio)
{
	int k=0;
	cout<<endl<<"Inserire numero da mettere in testa alla lista: ";
	cin>>k;
	inizio=new nodo(k,inizio);
}

nodo* inserisci_coda(nodo*& i,int k)	// La lunghezza della lista NON puo' essere < 0 
{
	if (!i)
		i=new nodo(k,0);
	// if (!i->next)
	//	i->next=new nodo(k,0);
	// else
	// 	inserisci_coda(i->next,k);
	else
		inserisci_coda(i->next,k);
}

int main()
{
	int k=0,l=0,x=0;
	cin>>l;		// l=lunghezza
	while(l<0)
	{
		cout<<"ERRORE: Inserire un numero maggiore o uguale a zero."<<endl;
		cin>>l;
	}
	nodo* inizio=crea(k,l);
	stampa(inizio);
	cout<<endl<<"Sono presenti "<<conta(inizio)<<" nodi.";
	cout<<endl<<"Numero da cercare: ";
    cin>>x;
    cout<<""<<x<<" e' presente "<<cerca(inizio,x)<<" volte.";
	// cout<<endl<<"Nodi da eliminare: ";
	// cin>>k;
	// dealloca (inizio,k);
	inserisci_testa(inizio);
	cout<<"Nuova Stampa:"<<endl;
	stampa(inizio);
	k=0;
        cout<<endl<<"Inserire numero da mettere in coda alla lista: ";
        cin>>k;
	inserisci_coda(inizio,k);
	cout<<"Nuova Stampa:"<<endl;
        stampa(inizio);
	cout<<endl;
}


