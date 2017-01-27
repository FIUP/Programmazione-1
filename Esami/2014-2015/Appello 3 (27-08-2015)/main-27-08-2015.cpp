#include<iostream>
#include<fstream>
using namespace std;

struct coord{int s,r,c; coord(int a=0, int b=0, int d=0){s=a;r=b;c=d;}};

main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT) 
  { 
   int A[400],P[30], dimP, lim1,lim2,lim3;
   
   IN>>dimP;
   for(int i=0; i<dimP;i++)
    IN>>P[i];
   IN>>lim1>>lim2>>lim3;
   int nel=legge(A, lim1, lim2, lim3, IN);//da fare
   
   OUT<<nel<<endl;
   F1(A,lim1,lim2,lim3,P,dimP,nel,0,0,OUT);//da fare
   
   IN.close(); OUT.close();

  }
  else
   cout<<"errore con i files";
 }
