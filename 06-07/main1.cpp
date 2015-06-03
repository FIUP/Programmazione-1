#include<iostream>
#include<fstream>
using namespace std;
struct nodo{int info1,info2; nodo* next; nodo(int a=0, int c=0, nodo* b=0){info1=a;info2=c; next=b;}};


nodo* copia(nodo* X)
{
  if(X)
    return new nodo(X->info1, X->info2, copia(X->next));
  return 0;

}

void crea(nodo*&L, int dim, ifstream & INP, int n)
{
  int x;
  if(n<dim)
    {
      INP>>x;
      L=new nodo(x,n,0);
      crea(L->next, dim,INP,n+1);
    }
  else
   L=0;
}
void crea1(nodo*&L, int dim, ifstream & INP, int n)
{
  int x,y;
  if(n<dim)
    {
      INP>>x>>y;
      cout<<"x="<<x<<" y="<<y<<endl;
      L=new nodo(x,y,0);
      crea1(L->next, dim,INP,n+1);
    }
  else
   L=0;
}
void stampa(nodo* x, ofstream & OUT)
{
  if(x)
    {
      OUT<<'('<< x->info1<<','<<x->info2<<')';
      if(x->next)
      OUT<<"->";
      //cout<< x->info1<<' '<<x->info2<<' ';
      stampa(x->next, OUT);
    }
   else
   {OUT<<endl;
    //cout<<endl;
   }
}


main()
{
  try{
  ifstream INP("input");
  ofstream OUT("output");
  if(!INP) throw(0);
  if(!OUT) throw(1);
  int P[100],dimP,dim,dimX;
  INP>>dim>>dimP>>dimX;
  
  nodo*L=0;
  crea(L,dim,INP,0);//data
  
  for(int i=0;i<dimP ; i++)
   {INP>>P[i];}
  nodo*z=M1(L,P,dimP);    //da fare
  if(!z)
  OUT<<"nessun match"<<endl;
  else
  stampa(z,OUT);//data
  OUT<<endl;

  nodo* X=0;
  crea1(X,dimX,INP,0);//data
     
  nodo*L1=copia(L);//data
  
  TB(L1,X);        //da fare
  stampa(L1,OUT);
  cout<<endl;
  nodo* z1=TC(L,X); //da fare 
  stampa(L,OUT);
  cout<<endl;
  stampa(z1,OUT);
  cout<<endl;

 }
 catch(int x)
{
   switch(x)
  {
   case 0: cout<<"problemi con input"<<endl; break;
   case 1: cout<<"problemi con output"<<endl; break;
  }
}
}
