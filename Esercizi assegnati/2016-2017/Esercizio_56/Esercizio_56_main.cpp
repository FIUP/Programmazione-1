#include<iostream>

#include<fstream>
using namespace std;


struct nodo{int info; nodo* left,*right; nodo(int a=0, nodo* b=0, nodo*c=0){info=a; left=b;right=c;}};


main()
{
  int n, k,y;
  cin>>n;
  nodo* R=buildtree(0,n);//da esercizio 2
  cout<<"start"<<endl;
  stampa_l(R);
   
  cin>>k>>y;
   int C[30];
   bool b=cerca_cam(R,k,y,C); //da fare
   OUT<<endl;
   if(b)
     {cout<<"trovato  cammino= "; sc(C);} //sc da fare 
   else
    cout<<"nessun cammino con "<<k<<" valori="<<y<<endl;
   cout<<"end";
}
