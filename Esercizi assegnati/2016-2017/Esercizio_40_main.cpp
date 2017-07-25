#include<iostream>
using namespace std;

main()
{
  
  char T[400], P[50];
  char c;
  int i=0;
  cin >> c;
  while (c != '.')
    {P[i]=c; i++; cin>>c;}
  int dimP=i;
  i=0;
  cin >> c;
  while (c != '.')
    {T[i]=c; i++; cin>>c;}
  cout<<"start"<<endl;
  int dimT=i;
  int X[100];
 
  int num=0;
  bool m=match(T,dimT,P,dimP,X,num); // da fare
 
   if(!m)
    cout<<"nessun match"<<endl;
   else
     {
       for(int i=0; i<num; i=i+1)
	 cout<<X[2*i]<<' '<<X[2*i+1]<<endl;
       stampa(P,dimP,X,num);  // da fare
     }
   cout<<"end"<<endl;
}
