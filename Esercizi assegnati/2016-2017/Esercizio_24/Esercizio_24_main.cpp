#include<iostream>
using namespace std;

main()
{
  int A[3][4][5];
  for(int i=0; i<3; i=i+1)
    for(int j=0; j<4; j=j+1)
      for(int k=0; k<5; k=k+1)
       cin >> A[i][j][k];
  
  cout<<"start"<<endl;
  char c;
  int f;
  cin >> c >> f;
  if(c=='H')
    {
      //stampa H fetta f
    }
  else
    //stampa V fetta f
  cout<<"end"<<endl;
}