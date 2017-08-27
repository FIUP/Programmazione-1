#include<iostream>
using namespace std;
struct nodo{int info; nodo* next;};


main()
{
  int n;
  cin>>n;
  int* L= new int [n*n];
  for(int i=0; i<n*n; i++)
          cin>>L[i];
  nodo* x=trova(L,n,0);//da fare
  cout<<"start"<<endl;
  if(x)
    { cout<<"il cammino e':"; stampa(x,n,0);}//da fare
    
  else
    cout<<"il cammino non esiste"<<endl;
  cout<<"end"<<endl;
      
}
