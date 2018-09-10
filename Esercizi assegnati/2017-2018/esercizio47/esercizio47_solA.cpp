//Soluzione di S.Righetto
#include<iostream>
using namespace std;
struct nodoA{int info; nodoA* left,*right; nodoA(int a=0, nodoA*b=0,nodoA*c=0){info=a; left=b; right=c;}};
struct nodo{nodoA* info; nodo* next; nodo(nodoA* a=0, nodo*b=0){info=a; next=b;}};

nodo * match(nodoA* r, int* P, int dimP){
    if(!r) return 0;
    if(dimP==1 && r->info==*P){
        return new nodo(r,0);
    }
    
    nodo * left, *right;
    
    if(*P==r->info){
        left= match(r->left, P+1, dimP-1);
        if(left) 
            return new nodo (r,left); 
        right= match(r->right, P+1, dimP-1);
        if (right) 
            return new nodo(r,right); 
    }
    
    
    if(*P!=r->info){
        left= match(r->left, P, dimP);
        if (left) return left;
        right= match(r->right, P, dimP);
        if (right) return right;
    
    }
    return 0;
}

void stampa_l(nodoA *r)
{
  if(r)
    {
      cout<<r->info<<'(';
      stampa_l(r->left);
      cout<<',';
      stampa_l(r->right);
      cout<<')';
    }
  else
    cout<< '_';
}
int conta_n(nodoA*r)
{
   if(!r) return 0;
     else
    return conta_n(r->left)+conta_n(r->right)+1;
}

nodoA* insert(nodoA*r, int y)
{
  if(!r) return new nodoA(y);
   
  if(conta_n(r->left)<=conta_n(r->right))
    r->left=insert(r->left,y);
   else   
    r->right=insert(r->right,y); 
  return r;
}

nodoA* buildtree(nodoA*r, int dim)
{
  if(dim)
   {
    int z;
    cin>>z;
    nodoA*x=insert(r,z);
    return buildtree(x,dim-1);
   }
  return r;
}


void riempi(int*P,int m)
{
  if(m)
    {
      cin>>*P;
      riempi(P+1,m-1);
    }
}
void stampaL(nodo*a)
{
  if(a)
    {
      cout<<a->info->info<<' ';
      stampaL(a->next);      
    }
  else
    cout<<endl;
}
main()
{
  int  n,m;
  cout<<"start"<<endl;
  cin>> n;
  nodoA*R=buildtree(0,n);
  stampa_l(R);
  cout<<endl;
  int P[50];
  cin>> m;
  riempi(P,m);
  nodo*a=match(R,P,m);
  if(a)
      stampaL(a);
    else
      cout<<"no match found"<<endl;
  cout<<"end"<<endl;
}



