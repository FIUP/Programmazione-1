#include<iostream>
#include<fstream>
using namespace std;
struct nodo2{int info1,info2; nodo2* next; nodo2(int a=0, int b=0, nodo2* c=0){info1=a;info2=b; next=c;}};
void crea(nodo2*&L, int dim, ifstream & INP, int n)
{
  int x;
  if(n<dim)
    {
      INP>>x;
      L=new nodo2(x,n,0);
      crea(L->next, dim,INP,n+1);
    }
  else
   L=0;
}
void crea1(nodo2*&L, int dim, ifstream & INP, int n)
{
  int x,y;
  if(n<dim)
    {
      INP>>x>>y;
    
      L=new nodo2(x,y,0);
      crea1(L->next, dim,INP,n+1);
    }
  else
   L=0;
}

void stampa(nodo2* x, ofstream & OUT)
{
  if(x)
    {
      OUT<<'('<< x->info1<<','<<x->info2<<')';
      if(x->next)
	OUT<<"->";
      
      stampa(x->next, OUT);
    }
   else
     OUT<<endl;
   
}
// ****** RICORSIVA
int  passi(nodo2* &T, int* &P)
{
  if (T)
    {
      if (T->info1!=P[0])
	{
	  T=T->next;
	  return 1+passi(T,P);
	}
    }
  return 0;

}
int L(nodo2 *&T,int *&P, int dimP)
{
  if (T && dimP>0)
    {
      if (T->info1==P[0])
	{
	  T=T->next;
	  P=P+1;
	  dimP=dimP-1;
	  return 1+L(T,P,dimP);
	}
    }
   
  return 0;
}

nodo2 *M1(nodo2 *T,int*P, int dimP) // PRE (T lista corretta, dimP>=0)
{
  
  if (dimP>0 && T)
    {
      int pas=0, lung=0;
      pas=passi(T,P);
      if (T)
	{
	  lung=L(T,P,dimP);
	  nodo2 *x =new nodo2(pas,lung,M1(T,P,dimP-1));
	}
    }
  else
    return 0;
  
}// POST (M1 restituisce con return la lista del march di P in T)
// Dimostrazione induttiva - 
// Caso Base dimP=0 M1 restituisce nessun match
// Passo Induttivo 
// caso 1 se dimP>0 ricerco inizio match. Se non trovato !T restituisco "nessun match"
// caso 2 se dimP>0 riverco inizio match. Se trova calcolo la lunghezza del match L(T,P,dimP) e aggiungo il nodo con i valori pas e lung)
// ************* iterativa *************
nodo2* &finelista(nodo2*&f)
{
   nodo2*tmp;
   for (tmp=f; tmp->next !=NULL;tmp=tmp->next);
   return tmp->next;  
}
nodo2* stacca(nodo2*&L, int k)
{
  nodo2*z=0;
  while (k>0 && L)
    {
     
       if(!z)
      	z=new nodo2(L->info1,L->info2);
       else
	 finelista(z)=new nodo2(L->info1,L->info2);
	
      delete L;
      L=L->next;
      k--;
    }
  return z;
}
nodo2 *TB(nodo2*&T,nodo2*X)
{
  nodo2*z=0,*q=0;
  while (X && T) // R1 X e T con nodi non ancora percorsi.Quando X=NULL il ciclo termina e non ho altri nodi di T da tenere/staccare
    {            // Quando T=NULL il ciclo termina e non ho altri nodi su cui eseguire operazioni indicate in X
      int k = X->info1, s=X->info2;
      
      if (!z)
      	z=stacca(T,k);
      else
	  finelista(z)=stacca(T,k);
     
      while (s>0 && T)
      	{
      	  if (!q)
      	    q=new nodo2(T->info1,T->info2);
      	  else
	    finelista(q)= new nodo2(T->info1,T->info2);
      	  
      	  T=T->next;
      	  s--;
      	}
      
      X=X->next;
    
      
    }
  T=q;
  return z;
  
}
main()
{
  try
    {
      ifstream INP("input");
      ofstream OUT("output");
      if(!INP) throw(0);
      if(!OUT) throw(1);
      int P[100],dimP,dim,dimX;
      INP>>dim>>dimP>>dimX;
      // cout<<dim<<' '<<dimP<<' '<<dimX<<endl;
      nodo2*L=0;
      crea(L,dim,INP,0);
      
      for(int i=0;i<dimP ; i++)
	{INP>>P[i];}
      nodo2*z=M1(L,P,dimP);//da fare
      if(!z)
      	OUT<<"nessun match"<<endl;
      else
      	stampa(z,OUT);
      OUT<<endl;
      cout<<endl;
      nodo2* X=0;
      crea1(X,dimX,INP,0);
     
       nodo2* z1=TB(L,X);
        stampa(z1,OUT);

      	stampa(L,OUT);
      	cout<<endl;
    }
  catch(int x)
    {
      switch(x)
	{
	case 0: cout<<"problemi con input"<<endl; break;
	case 1: cout<<"problemi con output"<<endl; break;
	}
    }
}
