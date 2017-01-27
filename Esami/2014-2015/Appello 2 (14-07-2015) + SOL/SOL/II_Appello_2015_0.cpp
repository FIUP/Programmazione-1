
//soluzione by: Gilbero Filè (Prof)

#include<iostream>
#include<fstream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};
struct nodoT{int info; nodoT* left,* right; nodoT(int a=0, nodoT* b=0, nodoT* c=0){info=a; left=b;right=c;}};
nodo* costruisci_L(int prof);
//parte ricorsiva F0:  fa tutto al ritorno, mette a 0 gli 1 e mette a 1 il primo 0, contemporaneamente mettendo b=true per comunicare alle  invocazioni che restano sulla via del ritorno 
// che il lavoro è fatto
void F0(nodo*L, bool & b)
{
  if(!L)
    b=false;
  else
  {
  F0(L->next,b);
  if(!b)// se b=true non fa niente !
  {
   if(L->info==0)
     {L->info=1; b=true;} //lavoro fatto !
   else
     L->info=0;
  }
 }
  
}
//parte iterativa F1: è un ciclo sui diversi cammini che contiene un ciclo che scandisce ciascun cammino percorrendolo sull'albero
// se il nondo su cui si sta andando non c'è ancora nell'albero, allora lo si crea. Se l'albero è vuoto viene subito creata la radice

nodoT* F1(nodoT*R, int prof, ifstream & INP)
{
  nodo*lista=costruisci_L(prof);
  nodoT* a=R;
  if(!R)//radice non c'e'
    {int x; INP>>x; R=new nodoT(x); a=R;}
     
  bool b=true;
  
  while(b)
  {
    nodoT* a=R;
    nodo* cam=lista;
    while(cam)
    {
        if(cam->info)
          if(!a->right)
           {int x; INP>>x; a->right=new nodoT(x); a=a->right;cam=cam->next;}
          else
           {a=a->right; cam=cam->next;}
        else // a sinistra
         if(!a->left)
           {int x; INP>>x; a->left=new nodoT(x); a=a->left; cam=cam->next;}
          else
           {a=a->left; cam=cam->next;}
       }
    
   
   F0(lista,b); // va in fondo al ciclo perche' b va testato prima di considerare il cammino prodotto da F0
  }
 return R;
}
// funzioni date
nodo* costruisci_L(int prof)
{
  nodo* r=0;
  while(prof)
   {
    r=new nodo(0,r);
    prof--;
   }
  return r;

}
nodoT*buildt()
{
  nodoT* f1=new nodoT(10);
  nodoT* f2=new nodoT(20);
  nodoT*I=new nodoT(15,f1,f2);
  nodoT*R=new nodoT(2,I, new nodoT(23));
  return R;
}
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
   nodo*L=costruisci_L(alt);
   bool b=true;
   while(b)
    {
      stampa_L(L,OUT); 
      F0(L,b);
      
   }
    nodoT*R=F1(0,alt,IN);
    stampa_l(R,OUT);
    OUT<<endl;
    nodoT*K=buildt();
    stampa_l(K,OUT);
    OUT<<endl;
    K=F1(K,alt,IN);
    stampa_l(K,OUT);
     IN.close(); OUT.close(); 

  }
  else
   cout<<"errore con i files";
 }

