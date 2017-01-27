//Esercizio iterativo
#include<iostream>
using namespace std;
struct nodo{int info;nodo* next;nodo(int a=0,nodo* p=0){info=a;next=p;}};
void elim(nodo* L,int k,int y)
{
int c=0;						//c contiene il numero di nodi esaminati
int conta=0;					//numero di nodi con campo info==y
if(L->info==y)
		conta++;
while(L->next)					//R
	{
	c++;
	if(L->next->info==y)
		if(conta>k)
			{
			nodo* b=L->next;
			L->next=b->next;
			delete b;
			conta++;
			}
		else
		{conta++;
		L=L->next;
		}
	else
		L=L->next;
	}
}
/*
R=(a=L'@R,Vl=Vl(c)@R e Vl(c) ha conta nodi con info==y e se conta>k,allora L' è ottenuta da Vl(c)
eliminando gli ultimi conta-k nodi con info==y e altrimenti L'=Vl(c))
L'=lista competa da quel punto
R=parte della lista che non ho ancora esaminato
*/
main()
{
nodo* Ls=new nodo(6,new nodo(7,new nodo(8,new nodo(6,new nodo(6,new nodo(7,0))))));
int n,info;
cin>>n>>info;
elim(Ls,n,info);
}