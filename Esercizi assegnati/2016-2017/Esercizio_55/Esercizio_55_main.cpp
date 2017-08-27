#include<iostream>

#include<fstream>
using namespace std;


struct nodo{int info; nodo* left,*right; nodo(int a=0, nodo* b=0, nodo*c=0){info=a; left=b;right=c;}};


main()
{
  int n;
  IN>>n;
  nodo* R=buildtree(0,n);//da fare
  cout<<"start"<<endl;
  stampa_l(R); //da fare, vista in classe
  
  cout<<endl<<"end";
  
      
}
