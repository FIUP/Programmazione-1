#include<iostream>
#include<fstream>
using namespace std;
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};

void stampa(nodo* x, ofstream & OUT)
{
  if(x)
    {
      OUT<< x->info<<' ';
      stampa(x->next, OUT);
    }
}
//PRE_crea={dim>=0 e L e' una lista corretta anche vuota}
void crea(nodo*& L, int dim, ifstream & INP)
{
  if(dim==0)
    L=0;
  else{
    int elemento;
    INP>>elemento;
    L=new nodo(elemento,0);
    crea(L->next,dim-1,INP);
  }
}
//POST_crea={genera un lista corretta letta dal file input1 di dim elementi}

//PRE_match={L è una lista corretta, L=vL, P ha dimP elementi definiti con dimP>0}
nodo* match(nodo* & L, int*P, int dimP)
{
  if(!dimP)
    return 0;
  if(!L)
    return 0;
  if(L->info==P[0]){
    nodo* R=L;
    L=L->next;
    R->next=match(R->next,P+1,dimP-1);
    return R;
  }
  else
    return match(L->next,P,dimP);
}
//POST_match={se match restituisce col return un valore R diverso da 0, allora esiste un match completo di P in L e R è R(vL,P) e il valore di L è vL-P) && (se match restituisce 0 allora non c’è alcun match di P in L e il valore di L è vL}


main()
{
  ifstream INP("input1");
  ofstream OUT("output1");
  int dim, dimP, P[20];
  INP>>dim;
  
  nodo* inizio;
  crea(inizio,dim,INP);//da fare
  
  INP>>dimP;
  for(int i=0; i<dimP;i++)
    INP>>P[i];
  
  nodo* y=match(inizio,P,dimP);//da fare
  stampa(y, OUT);
  OUT<<endl;
  stampa(inizio,OUT);
}
