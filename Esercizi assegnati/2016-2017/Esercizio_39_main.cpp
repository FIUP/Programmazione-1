#include<iostream>
using namespace std;

main()
{
  int C[200], X[200];
  int x=0, lim=0;
  for(int i=0; x!=-2; i++)
   {cin>>x; C[i]=x;}
  cout<<"start"<<endl;
  IC(C,X,lim);//da fare
  for(int i=0; i<lim; i++)
  cout<<X[i*2]<<' '<<X[i*2+1]<<endl;
  
  cout<<"end"<<endl;
}
