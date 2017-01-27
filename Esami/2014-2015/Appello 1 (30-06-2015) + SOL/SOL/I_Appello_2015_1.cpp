
//soluzione by: Enzo M.

#include<iostream>
#include<fstream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};
struct FIFO{nodo* primo, *fine; FIFO(nodo*a=0, nodo*b=0){primo=a; fine=b;}}; 

FIFO metti_fondo(FIFO a, nodo*b) // da fare
{
if(!a.fine)
	{
	a.primo=b;
	a.fine=a.primo;
	return a;
	}
else
	{
	(a.fine)->next=b;
	a.fine=(a.fine)->next;
	return a;
	}
}

nodo* togli(nodo* C,int y)/*PRE=(lista (C) è corretta e y è definito)*/
{
FIFO L;
bool stop=false;
while(!stop)
	{
	if(C)
		{
		if(C->info==y)
			{
			nodo* aux=C;
			C=C->next;
			delete aux;
			}
		else
			{
			L=metti_fondo(L,C);
			C=C->next;
			}
		}
	else
		stop=true;
	}
if(L.fine)
	(L.fine)->next=0;
return L.primo;
}/*POST=(restituisce la lista che resta eliminando da C i nodi con campo info=y che vengono deallocati. Nessun nodo nuovo rispetto a C è allocato)*/

nodo* no_rip(nodo* C)/*PRE=(lista (C) è corretta)*/
{
if(!C)
	return 0;
nodo* X=C;
X->next=no_rip(C->next);
nodo* V=togli(X->next,X->info);
if(V)
	{
	nodo* crea=X;
	crea->next=V;
	return crea;
	}
else
	{
	if(X->next)
		X->next=0;
	return X;
	}
}/*POST=(restituisce quello che resta di C mantenendo solo il primo nodo con un dato campo info ed eliminando i nodi successivi
con lo stesso campo info. I nodi tolti da C sono deallocati. Nessun nuovo nodo rispetto a C è allocato)*/

void elim(nodo*& T,nodo* C)
{
while(T && C)
	{
	T=togli(T,C->info);
	C=C->next;
	}
} 

void stampa_L(nodo* x,ofstream& OUT)
{
  if(x)
  {OUT<<x->info<<' '; stampa_L(x->next,OUT);}
  else
   OUT<<endl;
}

nodo* costruisci(int dim, ifstream & IN)
{
  if(dim)
  {
    int x;
    IN>>x;
    return new nodo(x,costruisci(dim-1,IN));
 
  }
 else
  return 0;
}

main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT) 
  { 
   int dimT, dimC;
   
   IN>>dimC;
   nodo*C=costruisci(dimC,IN);//data
   
   stampa_L(C,OUT); //data
   nodo*Y=no_rip(C);//da fare, essa usa togli (che usa FIFO)
   stampa_L(Y,OUT);
	

   IN>>dimT;
   nodo* T=costruisci(dimT,IN);
   stampa_L(T,OUT);
   
   elim(T,Y); //da fare, esercizio finale
   
   stampa_L(T,OUT);
   
   IN.close(); OUT.close(); 
  }
  else
   cout<<"errore con i files";
 }
