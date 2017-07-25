#include<iostream>

using namespace std;



main()
{
  int n;
  cin>>n;
  int* L= new int [n*n], *P=new int[n];
  for(int i=0; i<n*n; i++)
          cin>>L[i];
  bool x=trova(L,n,0,P);//da fare
  cout<<"start"<<endl;
  if(x)
    { cout<<"il cammino e':"; stampa(P,n,0);}//da fare
    
  else
    cout<<"il cammino non esiste"<<endl;
  cout<<"end"<<endl;
      
}
