#include<iostream>
using namespace std;

main()
{
  cout<<"start"<<endl;
  int A[3][4][5], *p=A[0][0],n_ele;
  IN>>n_ele;
  for(int i=0; i<n_ele; i=i+1)
    IN>>p[i];
  char c;
  int f;
  IN >> c >> f;
  
  if(c=='H')
    {
     //stampa H fetta
    }
  else
    {
     //stampa V fetta
    }

  OUT<<"endl"<<endl;
}