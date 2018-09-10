#include<iostream>
using namespace std;
struct nodo{int info; nodo* left,*right; nodo(int a=0, nodo* b=0, nodo*c=0){info=a; left=b;right=c;}};

void sc(int*C)
{
  if(*C!=-1)
   {cout<<*C<<' '; sc(C+1);}
  else
    cout<<"fine cammino"<<endl;
}

main()
{
  int n, k,y;
  cin>>n;
  nodo* R=buildtree(0,n);//da esercizio del 17/5
  cout<<"start"<<endl;
  stampa_l(R);
   
  cin>>k>>y;
  int C[30];
  bool b=cerca_cam(R,k,y,C); //da fare
  cout<<endl;
   if(b)
     {cout<<"trovato  cammino= "; sc(C);} //sc data 
   else
    cout<<"nessun cammino con "<<k<<" valori="<<y<<endl;
   cout<<"end";
}
