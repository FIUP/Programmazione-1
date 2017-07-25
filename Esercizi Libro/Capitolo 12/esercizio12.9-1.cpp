#include<iostream>
#include<fstream>

using namespace std;

struct nodo{int info1, info2; nodo* left, * right; nodo(int a1=0, int a2=0, nodo* b=0, nodo* c=0){info1=a1; info2=a2; left =b; right=c;}};

void stampa(nodo *r, ofstream & OUT)
{
  if(r)
    {
      OUT<<r->info1<<' '<<r->info2<<endl;
      stampa(r->left,OUT);
      stampa(r->right,OUT);
    }
}

nodo* costruz()
{
 nodo*x2=new nodo(0);
 nodo* x3=new nodo(0);
 nodo* x4=new nodo(0);
 nodo*x1=new nodo(0,0,x2,x3);
 x2->left=x4;
 return x1;
}

void dist_min_max_foglia(nodo* n)
{
    if(!n)
    {
        return;
    }
    dist_min_max_foglia(n->left);
    dist_min_max_foglia(n->right);
    if(!n->left && !n->right)
    {
        n->info1=0;
        n->info2=0;
    }
    if(n->left && !n->right)
    {
        n->info1=n->left->info1+1;
        n->info2=n->left->info2+1;
    }
    if(n->right && !n->left)
    {
        n->info1=n->right->info1+1;
        n->info2=n->right->info2+1;
    }
    if(n->left && n->right)
    {
        if(n->left->info1<=n->right->info1)
            n->info1=n->left->info1+1;
        else
            n->info1=n->right->info1+1;

        if(n->left->info2>n->right->info2)
            n->info2=n->left->info2+1;
        else
            n->info2=n->right->info2+1;
    }
}

main()
{
    ifstream INP("input.cpp");
    ofstream OUT("output.cpp");
    nodo* X=costruz();
    dist_min_max_foglia(X);
    stampa(X, OUT);
}
