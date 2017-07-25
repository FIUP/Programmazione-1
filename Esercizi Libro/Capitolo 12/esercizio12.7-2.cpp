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

int altezza(nodo* n)
{
    if(!n)
    {
        return -1;
    }
    else
    {
        int h1=0, h2=0;
        h1=altezza(n->left)+1;
        h2=altezza(n->right)+1;
        if(h1>h2)
        {
            n->info=h1;
            return h1;
        }
        else
        {
            n->info=h2;
            return h2;
        }
    }
}

main()
{
    ifstream INP("input.cpp");
    ofstream OUT("output.cpp");
    nodo* X=costruz();
    int h=altezza(X);
    stampa_l(X, OUT);

}
