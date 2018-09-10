//Soluzione di S.Righetto

#include<iostream>
using namespace std;
struct nodo{int info; nodo* left,*right; nodo(int a=0, nodo* b=0, nodo*c=0){info=a; left=b;right=c;}};

bool cerca_cam(nodo * r, int k, int y, int *C){
    if(r->info == y) 
    	k--;
    if(!r->left && !r->right){
        if(k==0) {
            *C=-1;
            return true;
        }
        return false;
    } 
    
    if(r->left && cerca_cam(r->left, k,y,C+1 )){
        *C=0;
        return true;
    }
     if(r->right && cerca_cam(r->right, k,y,C+1)){
        *C=1;
        return true;
    }
    //return false;
}

void sc(int*C)
{
  if(*C!=-1)
   {cout<<*C<<' '; sc(C+1);}
  else
    cout<<"fine cammino"<<endl;
}

int conta(nodo *r){
    if(!r) return 0;
    return 1+ conta(r->left) + conta(r->right);
}

nodo* alberobil(nodo* r, int k){
    if(!r) return new nodo(k,0,0);
    if(!r->left) 
        r->left= new nodo(k,0,0);
    else if(!r->right) 
        r->right= new nodo(k,0,0);
    else if(conta(r->left)-conta(r->right) <1) alberobil(r->left,k);
    else alberobil(r->right,k);
    return r;
}


nodo* buildtree(nodo * r,int n){
    int t;
    for(int i=0; i<n; i++){
        cin >> t;
        r= alberobil(r,t);
    }
    return r;
}

void stampa(nodo * r){
    if(!r) return ;
    cout << r->info << '(';
    if(r->left) stampa(r->left);
    else cout << '_';
    cout << ',';
    if(r->right) stampa(r->right);
    else cout << '_';
    cout << ')';
}

main()
{
  int n, k,y;
  cin>>n;
  nodo* R=buildtree(0,n);//da esercizio del 17/5
  cout<<"start"<<endl;
  stampa(R);
   
  cin>>k>>y;
  int C[30];
  bool b=cerca_cam(R,k,y,C); //da fare
  cout<<endl;
   if(b)
     {cout<<"trovato  cammino= "; sc(C);} //sc data 
   else
    cout<<"nessun cammino con "<<k<<" valori="<<y<<endl;
   cout<<"end";
}


