#include<iostream>
#include<fstream>

using namespace std;

struct nodo{int info; nodo* left, * right; nodo(int a=0, nodo* b=0, nodo* c=0){info=a;left =b;  right=c;}};


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
        return -2;
    }
    else
    {
        int h1=0, h2=0;
        h1=altezza(n->left)+2;
        h2=altezza(n->right)+2;
        if(h1>h2)
            return h1%2+2;
        else
            return h2%2+2;
    }
}

main()
{
    ifstream INP("input.cpp");
    ofstream OUT("output.cpp");
    nodo* X=costruz();
    int h=altezza(X);
    OUT<<h;
}
