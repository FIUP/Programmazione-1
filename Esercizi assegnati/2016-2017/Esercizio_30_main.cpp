#include<iostream>
using namespace std;


main()
{
   int X[400];
   for(int i=0; i<400; i=i+1)
     X[i]=-1;
   int lim1,lim2,lim3,n_ele;
   cin >> lim1 >>lim2>>lim3 >>n_ele;
   //
   leggiV(X,lim1,lim2,lim3,n_ele);
   cout<<"start"<<endl;
   stampaS(X,lim1,lim2,lim3,n_ele);
   cout<<"end"<<endl;   
}