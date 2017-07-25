#include<iostream>
#include<fstream>

using namespace std;

struct nodo{int info; nodo* left, * right; nodo(int a1=0, nodo* b=0, nodo* c=0){info=a1; left =b; right=c;}};

void stampa(nodo *r, ofstream & OUT)
{
  if(r)
    {
      OUT<<r->info<<' '<<endl;
      stampa(r->left,OUT);
      stampa(r->right,OUT);
    }
}

nodo* costruz()
{
 nodo*x2=new nodo();
 nodo* x3=new nodo();
 nodo* x4=new nodo();
 nodo*x1=new nodo(0,x2,x3);
 x2->left=x4;
 return x1;
}

int num_nodi_un_figlio(nodo* n)
{
    if(!n)
    {
        return 0;
    }
    n->info=n->info+num_nodi_un_figlio(n->left);
    n->info=n->info+num_nodi_un_figlio(n->right);
    if(!n->left && !n->right)
        return 0;
    if(n->left && !n->right)
        return 1;
    if(n->right && !n->left)
        return 1;

}

main()
{
    ifstream INP("input.cpp");
    ofstream OUT("output.cpp");
    nodo* X=costruz();
    num_nodi_un_figlio(X);
    stampa(X, OUT);
}
