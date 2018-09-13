//Soluzione di S.Righetto

//code.h
#ifndef CODE_H_
#define CODE_H_
#include<iostream>

struct nodo {
	char info;
	nodo *next;
	nodo(char c = '\0', nodo* n = NULL);
};

struct coda {
	nodo *inizio;
	nodo *fine;
	coda();
};

void push(nodo*, coda &);
nodo* pop(coda &);
bool e_vuota(coda );
void push_list(nodo*,coda&);
#endif


//code.cpp

#include<iostream>
#include "code.h"

nodo::nodo(char c, nodo* n)
{
	info = c;
	next = n;
}

coda::coda()
{
	inizio = NULL;
	fine = NULL;
}

//PRE_push=(c è una lettera, Q è una coda, eventualmente vuota)

void push(nodo*n, coda &Q)
{
  n->next=0;
	if (Q.fine)
	{
		Q.fine->next = n;
		Q.fine = Q.fine->next;
	}
	else
	{
		Q.inizio = n;
		Q.fine = Q.inizio;
	}
}

//POST_push=(a Q è stato aggiunto un nodo terminale, di chiave c)

//NB: se inizo==fine, allora fine->next==NULL, e quando faccio inizio=inizio->next, inizio diventa NULL, quindi ottengo la lista vuota
//PRE_pop=(Q è una coda non vuota)

nodo* pop(coda &Q)
{
	nodo *x = Q.inizio;
	Q.inizio = x->next;

	if (Q.inizio == NULL)
		Q.fine = NULL;

	return x;
}

//POST_pop=(a Q è stato rimosso il nodo iniziale, e pop ritorna la chiave del nodo rimosso)

//PRE_e_vuota=(Q è una coda, eventualmente vuota)

bool e_vuota(coda Q)
{
	return Q.inizio == NULL;
}

//POST_e_vuota=(e_vuota ritorna true sse Q è vuota)


void push_list(nodo*L,coda & Q){ // da fare
    if(L){
        nodo * t= L->next;
        push(L,Q);
        push_list(t,Q);
    }
}
    

//main.cpp

#include<iostream>

#include "code.h"
using namespace std;


struct nodoA{char info; nodoA*left,*right; nodoA(char a='\0',nodoA*b=0,nodoA*c=0){info=a;left=b;right=c;}};

//iterativa
nodo*fuse(nodo*L1,nodo*L2){
    coda Q=coda();
    while(L1 || L2){
        if(L1 && L2){
            if(L1->info<L2->info){
                nodo*temp=L1->next;
                push(L1,Q);
                L1=temp;
            } else{
                nodo*temp=L2->next;
                push(L2,Q);
                L2=temp;
            }
        } else{
            if(L1){
                push_list(L1,Q);
                L1=0;
            } else{
                push_list(L2,Q);
                L2=0;
            }
        }
    }
    return Q.inizio;
}
//POST=(restituisce la lista ordinata costruita disponendo in ordine i nodi di L1 ed L2)

//ricorsiva
nodo*build_list(nodoA*r){
    if(!r) return 0;
    return fuse(new nodo(r->info),fuse(build_list(r->left),build_list(r->right)));
}

//-----------------parte vecchia-----------------------
void stampa_l(nodoA *r)
{
  if(r)
    {
      cout<<r->info<<'(';
      stampa_l(r->left);
      cout<<',';
      stampa_l(r->right);
      cout<<')';
    }
  else
    cout<< '_';
}
int conta_n(nodoA*r)
{
   if(!r) return 0;
     else
    return conta_n(r->left)+conta_n(r->right)+1;
}

nodoA* insert(nodoA*r, char y)
{
  if(!r) return new nodoA(y);
   
  if(conta_n(r->left)<=conta_n(r->right))
    r->left=insert(r->left,y);
   else   
    r->right=insert(r->right,y); 
  return r;
}

nodoA* buildtree(nodoA*r, int dim)
{
  if(dim)
   {
    char z;
    cin>>z;
    nodoA*x=insert(r,z);
    return buildtree(x,dim-1);
   }
  return r;
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
main()
{
  int  n;
  cout<<"start"<<endl;
  cin>> n;
  nodoA*R=buildtree(0,n);
  stampa_l(R);
  cout<<endl;
  nodo*x=build_list(R);
  stampa_lista(x);
  cout<<"end"<<endl;
}


