#include<iostream>
#include<fstream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};
struct nodoT{int info; nodoT* left,* right; nodoT(int a=0, nodoT* b=0, nodoT* c=0){info=a; left=b;right=c;}};


//PRE=(alt>=0)
nodo* costruisci_L(int alt)
{
  nodo* r=0;
  while(alt)
   {
    r=new nodo(0,r);
    alt--;
   }
  return r;

}
//POST=(restituisce una lista con alt nodi con info=0)

nodoT*buildt()
{
  nodoT* f1=new nodoT(10);
  nodoT* f2=new nodoT(20);
  nodoT*I=new nodoT(15,f1,f2);
  nodoT*R=new nodoT(2,I, new nodoT(23));
  return R;
}
//restituisce un albero per provare la vostra F1
//stampa gli alberi in forma lineare
void stampa_l(nodoT *r, ofstream & OUT)
{
  if(r)
    {
      OUT<<r->info<<'(';
      stampa_l(r->left,OUT);
      OUT<<',';
      stampa_l(r->right, OUT);
      OUT<<')';
    }
  else
    OUT<< '_';
}

//stampa lista 
void stampa_L(nodo* x,ofstream& OUT)
{
  if(x)
  {OUT<<x->info<<' '; stampa_L(x->next,OUT);}
  else
   OUT<<endl;
}
 
main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT) 
  { 
   int alt;
   
   IN>>alt;
   nodo*L=costruisci_L(alt);//data
   bool b=true;
   while(b)
    {
      stampa_L(L,OUT); 
      b=F0(L); //da fare
      
   }
    nodoT*R=F1(0,alt,IN); //da fare
    stampa_l(R,OUT);
    OUT<<endl;
    nodoT*K=buildt();//data
    stampa_l(K,OUT);//data
    OUT<<endl;
    K=F1(K,alt,IN);
    stampa_l(K,OUT);
     IN.close(); OUT.close(); 

  }
  else
   cout<<"errore con i files";
 }

