#include<iostream>
#include<fstream>
using namespace std;

struct coord{int s,r,c; coord(int a=0, int b=0, int d=0){s=a;r=b;c=d;}};
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};
struct FIFO{nodo* inizio,*fine; FIFO(nodo*a=0,nodo*b=0){inizio=a; fine=b;}};

coord calc_coord(int lim1,int lim2,int lim3,int HF,int i);//da fare

void legge(int* A, int lim1, int lim2, int lim3, ifstream & IN)
{
 for(int i=0; i<lim1*lim2*lim3; i++)
     IN>>A[i];
}


int leggiS(int*& S, int & dimS, ifstream &IN)
{
  int x,i=0;
  IN>>x;
  while(x!=1000)
  {
    if(i==dimS)
      allunga(S,dimS); //da fare
    S[i]=x;
    i++;
    IN>>x;
  }
  return i;
}



void stampaL(nodo*L,ofstream & OUT)
{
 if(!L)
  OUT<<endl;
 else
  {
   OUT<<L->info<<' ';
   stampaL(L->next,OUT);
  }
}


main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT) 
  { 
   int A[400], lim1,lim2,lim3;
   IN>>lim1>>lim2>>lim3;
   legge(A,lim1, lim2, lim3, IN);//data
   
   int dimS=3;
   int*S=new int[dimS];
   int neS=leggiS(S,dimS,IN); // e' data ma invoca allunga da fare
   OUT<<neS<<' '<<dimS<<endl; //attenzione output !!
   int HF;
   IN>>HF;
   nodo* L=buildL(A,lim1,lim2,lim3,HF);
   
   nodo*X=0;
   
   F(X,L,S,neS,OUT);
   OUT<<endl;
   stampaL(L,OUT); 
   OUT<<"fine"<<endl;
   IN.close(); OUT.close();

  }
  else
   cout<<"errore con i files";
 }
