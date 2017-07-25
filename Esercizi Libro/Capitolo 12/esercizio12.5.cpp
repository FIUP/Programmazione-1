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

void prefisso_stampa(nodo* n, ofstream & OUT)
{
    if(n)
    {
        OUT<<n->info<<' ';
        prefisso_stampa(n->left, OUT);
        prefisso_stampa(n->right, OUT);
    }
}

void postfisso_stampa(nodo* n, ofstream & OUT)
{
    if(n)
    {
        postfisso_stampa(n->left, OUT);
        postfisso_stampa(n->right, OUT);
        OUT<<n->info<<' ';
    }
}


main()
{
    ifstream INP("input.cpp");
    ofstream OUT("output.cpp");
    nodo* X=costruz();
    prefisso_stampa(X, OUT);
    OUT<<endl<<endl;
    postfisso_stampa(X, OUT);
}
