#include<iostream>
using namespace std;
struct nodo{int  info; nodo* next; nodo(int a=0, nodo*b=0){info=a; next=b;}};
struct coda{nodo* primo, *ultimo; coda(nodo*a=0,nodo*b=0){primo=a; ultimo=b;}};
coda push_end(coda a, nodo*b)
{
	if(!a.primo)
		{
			a.primo=a.ultimo=b;
			b->next=0;
			return a;
		}
	a.ultimo->next=b;
	a.ultimo=b;
	b->next=0;
	return a;
}


void stampa_lista(nodo*L)
{
	if(L)
	{
		cout<<L->info<<' ';
		stampa_lista(L->next);
	}
	else
		cout<<endl;

}
void build_array(int *P, int x)
{
	if(x)
		{
			cin>> *P;
			build_array(P+1,x-1);    
		}
}

nodo* build_list(int n)
{
	if(n)
		{
			int x;
			cin >> x;
			return new nodo(x,build_list(n-1));
		}
	return 0;
}

nodo* clone(nodo*L)
{
	if(!L) return 0;
	return new nodo(L->info,clone(L->next));
}

main()
{
	int  n,m;
	cout<<"start"<<endl;
	cin>> n;
	nodo*L=build_list(n);
	nodo*L1=clone(L);
	stampa_lista(L);
	
	cin>>m;
	int*A=new int[m];
	build_array(A,m);
	nodo*y=distr_iter(L,A,m);
	stampa_lista(y);
	stampa_lista(L);
	y=distr_ric(L1,A,m,0);
	stampa_lista(y);
	stampa_lista(L1);
	
	cout<<"end"<<endl;
}
