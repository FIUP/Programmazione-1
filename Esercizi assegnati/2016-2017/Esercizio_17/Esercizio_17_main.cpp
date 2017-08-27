#include<iostream>
using namespace std;
main()
{
   int C[5][5];
  bool B[5][5];
  for(int i=0; i<5; i=i+1)
    for(int j=0; j<5; j=j+1)
      cin>>C[i][j];
  //da fare
    
  for(int i=0; i<5; i=i+1)
  { 
    cout<<"riga="<<i<<':';
    for(int j=0; j<5; j=j+1)
      cout<<B[i][j]<<' ';  
    cout<<endl;
   } 
 cout<<"end"<<endl;   
    
} 