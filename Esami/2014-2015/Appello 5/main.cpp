#include<iostream>
#include<fstream>
using namespace std;

struct nodo{int info; nodo* left, *right; nodo(int a=0, nodo*b=0, nodo*c=0){info=a; left=b;right=c;}};
struct ni{nodo* info; ni* next; ni(nodo* a=0, ni*b=0){info=a; next=b;}};


struct dni{ni* primo, *ultimo; dni(ni*a=0){primo=a; ultimo=a;}};

dni pend_ni(dni x, ni*a)
{
  if(!x.primo)
    {x.primo=x.ultimo=a; return x;}
  else
   {x.ultimo->next=a;x.ultimo=a; return x;}
}

dni pop_ni(dni x)
{
  if(x.primo)
 {
  ni*w=x.primo;
  x.primo=x.primo->next;
  delete w;
  if(!x.primo) 
   x.ultimo=0;
 }
 return x; 
 
}
void svuota(dni x)
{
 while(x.primo)
 {
   ni*w=x.primo;
   x.primo=x.primo->next;
   delete w;
  }
 
}

//funzioni di stampa
void stampa_alb(nodo*x, ofstream & out)
{
  if(x)
   {
     out<<x->info;
     out<<'(';
     stampa_alb(x->left,out);
     out<<',';
     stampa_alb(x->right,out);
     out<<')';
   }
  else
     out<<'_';
}

void stampa_dni(dni x, ofstream & OUT)
{
 while(x.primo)
  {
   OUT<<x.primo->info->info<<' ';
   x=pop_ni(x);
  }
}
//PRE=(primo valore su "input" e' n>0 ed e' seguito da n valori interi)
main()
{
 ifstream IN("input");
 ofstream OUT("ouput");
 int n,y;
 IN>>n>>y; 
 nodo*root=new nodo(y);
 dni X0;
 X0=pend_ni(X0,new ni(root));
 n=n-1;
 while(n)
 {
  X0=creastrato(n,X0,IN); //da fare 
 }
 svuota(X0);
 stampa_alb(root,OUT);
 OUT<<endl;
 X0=unfold(root); //da fare 
 stampa_dni(X0,OUT);
 OUT<<endl<<"fine output"<<endl;
}