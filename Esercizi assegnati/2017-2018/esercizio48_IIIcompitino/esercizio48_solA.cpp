
#include<iostream>
using namespace std;
struct nodoA{int info; nodoA* left,*right; nodoA(int a=0, nodoA*b=0,nodoA*c=0){info=a; left=b; right=c;}};
struct nodo{nodoA* info; nodo* next; nodo(nodoA* a=0, nodo*b=0){info=a; next=b;}};


nodo*conc(nodo*a,nodo*b){
    if(!a) return b;
    a->next=conc(a->next,b);
}

nodo *f(nodoA*r, int k, int&n){
    if(!r) return 0;
    nodo *s=f(r->left,k,n);
    if(n==1){
        n=k;
        s=conc(s,new nodo(r,0));}
    else n--;
    nodo*d=f(r->right,k,n);
    return conc(s,d);    
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
  int  n,m,k;
  cout<<"start"<<endl;
  cin>> n;
  nodoA*R=buildtree(0,n);
  stampa_l(R);
  cout<<endl;
  
  cin>> k;
  m=k;
  nodo*a=f(R,k,m); // da fare 
  cout<<"lista:"<<endl;
  stampaL(a);
  cout<<"n="<<m<<endl;
  cout<<"end"<<endl;
}


