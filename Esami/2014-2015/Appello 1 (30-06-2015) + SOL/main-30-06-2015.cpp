#include<iostream>
#include<fstream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};
struct FIFO{nodo* primo, *fine; FIFO(nodo*a=0, nodo*b=0){primo=a; fine=b;}}; 

FIFO metti_fondo(FIFO a, nodo*b); // da fare

void stampa_L(nodo* x,ofstream& OUT)
{
  if(x)
  {OUT<<x->info<<' '; stampa_L(x->next,OUT);}
  else
   OUT<<endl;
}

nodo* costruisci(int dim, ifstream & IN)
{
  if(dim)
  {
    int x;
    IN>>x;
    return new nodo(x,costruisci(dim-1,IN));
 
  }
 else
  return 0;
}

main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT) 
  { 
   int dimT, dimC;
   
   IN>>dimC;
   nodo*C=costruisci(dimC,IN);//data
   
   stampa_L(C,OUT); //data
   nodo*Y=no_rip(C);//da fare, essa usa togli (che usa FIFO)
   stampa_L(Y,OUT);

   IN>>dimT;
   nodo* T=costruisci(dimT,IN);
   stampa_L(T,OUT);
   
   elim(T,Y); //da fare, esercizio finale
   
   stampa_L(T,OUT);
   
   IN.close(); OUT.close(); 
  }
  else
   cout<<"errore con i files";
 }

