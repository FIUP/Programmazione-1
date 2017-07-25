#include<iostream>
#include<fstream>

using namespace std;

struct nodo{int info; nodo* left, * right; nodo(int a=0, nodo* b=0, nodo* c=0){info=a;left =b;  right=c;}};

void stampa_l(nodo *r, ofstream & OUT)
{
  if(r)
    {
      OUT<<r->info<<'(';
      stampa_l(r->left,OUT);
      OUT<<',';
      stampa_l(r->right,OUT);
      OUT<<')';
    }
  else
    OUT<< '_';
}

nodo* costruz()
{
 nodo*x2=new nodo(2);
 nodo* x3=new nodo(3);
 nodo* x4=new nodo(4);
 nodo*x1=new nodo(1,x2,x3);
 x2->left=x4;
 return x1;
}

int conta_nodi(nodo* n)
{
    if(n)
        return 1+conta_nodi(n->left)+conta_nodi(n->right);
    else
        return 0;
}

nodo* inserisci_val(nodo* n, int x)
{
    if(!n)
    {
        return new nodo(x, 0, 0);
    }
    else
    {
        if(conta_nodi(n->left)<=conta_nodi(n->right))
        {
            n->left=inserisci_val(n->left, x);
            return n;
        }
        else
        {
            n->right=inserisci_val(n->right, x);
            return n;
        }
    }
}

main()
{
    ifstream INP("input.cpp");
    ofstream OUT("output.cpp");
    int n;
    INP>>n;
    nodo* X=costruz();
    nodo* A=inserisci_val(X, n);
    stampa_l(A, OUT);
}
