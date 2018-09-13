//manca la soluzione

#include<iostream>
using namespace std;

struct nodo{int info; nodo* left,*right; nodo(int a=0, nodo* b=0, nodo*c=0){info=a; left=b;right=c;}};

main()
{
  int dim,k;
  cin>>dim;
  nodo* R=buildtree(0,dim);
  cout<<"start"<<endl;
  stampa_l(R);
  cin>>k;
  int b=stampa_a_salti(R,k,k);
  cout<<"valore restituito="<<b<<endl;
  cout<<"end"<<endl;
}


