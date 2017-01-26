#include<iostream>
#include<fstream>
using namespace std;

struct coord{int s,r,c; coord(int a=0, int b=0, int d=0){s=a;r=b;c=d;}};
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};
struct FIFO{nodo* inizio,*fine; FIFO(nodo*a=0,nodo*b=0){inizio=a; fine=b;}};

coord calc_coord(int lim1,int lim2,int lim3,int HF,int i)//da fare
{
  coord c(i%lim1,HF,i/lim1);
  return c;    
}
void legge(int* A, int lim1, int lim2, int lim3)
{
 for(int i=0; i<lim1*lim2*lim3; i++)
     cin>>A[i];
}

nodo* buildL(int* A, int lim1, int lim2, int lim3, int HF)
{
  int i=0;
  nodo* L=0;
  nodo* list_iter;
  while(i<lim1*lim3)
    {
      if (!L)
  	{
  	  L=new nodo;
  	  list_iter=L;
  	}
      else
  	{
  	  list_iter->next=new nodo;
  	  list_iter=list_iter->next;
  	}
      
      coord t=calc_coord(lim1,lim2,lim3,HF,i);
      list_iter->info=A[t.s*lim2*lim3+lim3*t.r+t.c];
      i++;
    }
  return L; 
}

void allunga(int* &S, int &dimS)
{
  int* T=new int[dimS+3];
  for (int i=0;i<dimS;i++)
    T[i]=S[i];
  delete[] S;
  S=T;
  dimS+=3;
}


int leggiS(int*& S, int & dimS)
{
  int x,i=0;
  cin>>x;
  while(x!=1000)
  {
    if(i==dimS)
      allunga(S,dimS); //da fare
    S[i]=x;
    i++;
    cin>>x;
  }
  return i;
}



void stampaL(nodo*L)
{
 if(!L)
  cout<<endl;
 else
  {
   cout<<L->info<<' ';
   stampaL(L->next);
  }
}

void move_right(nodo* &L1, nodo* &L2, int i)
{
  if (!i)
    return;
   if (!L2->next)
     return;
  nodo* iterator=L2;
  L2=L2->next;
  iterator->next=L1;
  L1=iterator;
  move_right(L1,L2,i-1);
}
void move_left(nodo* &L1, nodo* &L2, int i)
{
  if (!i)
    return;
  if (!L1)
    return;
  nodo* iterator=L1;
  L1=L1->next;
  iterator->next=L2;
  L2=iterator;
  move_left(L1,L2,i-1);
}

void travaso (nodo* &L1,nodo* &L2)
{
  while (L1)
    {
      nodo* iterator=L1->next;
      L1->next=L2;
      L2=L1;
      L1=iterator;
    }
  return;
}

void F(nodo* &L1,nodo* &L2, int* S, int dimS)
{
  if (!dimS || S[0]==1000)
    return;
  
  if (S[0]>0)
    {
      move_right(L1,L2,S[0]);
      cout<<L2->info<<" ";
    }

  else
    {
      move_left(L1,L2,-S[0]);
      cout<<L2->info<<" ";
    }
  F(L1,L2,S+1,dimS-1);
  travaso(L1,L2);
}


main()
{
   int A[400], lim1,lim2,lim3;
   cin>>lim1>>lim2>>lim3;
   legge(A,lim1, lim2, lim3);//data
   
   int dimS=3;
   int*S=new int[dimS];
   int neS=leggiS(S,dimS); // e' data ma invoca allunga da fare
   cout<<neS<<' '<<dimS<<endl; //attenzione output !!
   int HF;
   cin>>HF;
   nodo* L=buildL(A,lim1,lim2,lim3,HF);

   nodo*X=0;

   F(X,L,S,neS);
   cout<<endl;
   stampaL(L); 
   cout<<"end"<<endl;
}
