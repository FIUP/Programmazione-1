#include<iostream>
#include<fstream>
using namespace std;
struct nodo{int info; nodo* left,*right; nodo(int a=0, nodo* b=0, nodo*c=0){info=a; left=b;right=c;}};
struct innesto{ bool l, r; nodo* N; innesto* next; innesto(bool a=false, bool b=false, nodo* c=0, innesto* d=0){l=a;r=b;N=c;next=d;}};

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
int conta_n(nodo*r)
{
   if(!r) return 0;
     else
    return conta_n(r->left)+conta_n(r->right)+1;
}

nodo* insert(nodo*r, int y)
{
  if(!r) return new nodo(y);
   
  if(conta_n(r->left)<=conta_n(r->right))
    r->left=insert(r->left,y);
   else   
    r->right=insert(r->right,y); 
  return r;
}

nodo* rep_ins(nodo*r, int dim, ifstream & INP)
{
  if(dim)
   {
    int z;
    INP>>z;
    nodo*x=insert(r,z);
    return rep_ins(x,dim-1,INP);
   }
  return r;
}

void stampa(innesto* a, ofstream & OUT)
{
  if(a)
   {OUT<<"left="<<a->l<<" right="<<a->r<<" nodo="<<a->N->info<<endl; stampa(a->next,OUT);}
  else
    OUT<<endl;

}


main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT) 
  { 
   int dim;
   IN>>dim;
   nodo* R=rep_ins(0,dim,IN);//data
   stampa_l(R,OUT);//data
   OUT<<endl;
   innesto* x=f0(R);//da fare
   stampa(x,OUT); //data
   int a=f1(x,IN); //da fare
   OUT<<"n. innesti="<<a<<endl;
   stampa_l(R,OUT); //data
   OUT<<endl;
   stampa(x,OUT); //data
   
   IN.close(); OUT.close(); 
  }
  else
   cout<<"errore con i files";
 }

