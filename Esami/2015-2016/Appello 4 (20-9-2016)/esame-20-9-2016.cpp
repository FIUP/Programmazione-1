#include<iostream>
#include<fstream>
using namespace std;
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}}; // nodo di lista 
struct FIFOX{nodo* primo, *ultimo; int valp, valu,nele; FIFOX(nodo*a=0, int b=0, int c=0, int d=0){primo=a; ultimo=a;valp=b;valu=c;nele=d;}};

ostream & operator<<(ostream & OUT, FIFOX& a)
{
  OUT<< '['<<"nele="<<a.nele<<" valp="<<a.valp<<" valu="<<a.valu<<']'<<endl; 
  int x=0;
  nodo*z=a.primo;
  while(x<a.nele)
  {OUT<<z->info<<' ';z=z->next; x++;}
  OUT<<endl;
  return OUT;
}

main()
{
   int dim1,dim2, x;
   
   cin>>dim1>>dim2;
   FIFOX a;
   while(dim1)
   {
   
   cin>>x;
   a=push_iter(a,new nodo(x));
   dim1--;
  }
   cout<< a;

   while(dim2)
   {
     cin>>x;
     a=deleteX(a,x);
     dim2--;
   }
   cout<<a;

   cout<<"end"<<endl;  
}
