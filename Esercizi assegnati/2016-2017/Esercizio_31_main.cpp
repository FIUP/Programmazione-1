#include<iostream>
using namespace std;

main()
{
   int X[400];
   cin>>X[0];
   for(int i=1; i<400 && X[i-1]!=-2; i++)
   cin >>X[i];
    
    int a;
    cin>>a;
    cout<<"start"<<endl;
    int b=S(X,a); // da fare
    if(b==-2)
     cout<<"sottosequenza "<<a<<" non presente"<<endl;
    else
     cout<<"inizio sottosequenza "<<a<<" indice="<<b<<endl;
    cout<<"end"<<endl;
 }
