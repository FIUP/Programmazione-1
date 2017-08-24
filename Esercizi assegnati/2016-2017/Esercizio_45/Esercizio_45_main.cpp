#include<iostream>
using namespace std;
main()
{
  int n;
  cin>>n;
  int L[n*n];
  for(int i=0; i<n*n; i++)
          cin>>L[i];
  bool x=trova(L, n);
  if(x)
    cout<<"il cammino esiste"<<endl;
  else
    cout<<"il cammino non esiste"<<endl;
}
