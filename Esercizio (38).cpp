#include<iostream>
using namespace std;

struct nodo{int info; nodo* left,*right; nodo(int a=0, nodo* b=0, nodo*c=0){info=a; left=b;right=c;}};

void stampa_l(nodo *r){
    if(r){
        cout<<r->info<<'(';
        stampa_l(r->left);
        cout<<',';
        stampa_l(r->right);
        cout<<')';
    }else
        cout<< '_';
}

void sc(int*C){
    if(*C!=-1){
        cout<<*C<<' '; sc(C+1);}
    else
        cout<<"fine cammino"<<endl;
}

bool cerca_cam(nodo* R, int k, int y, int* C){
    if(!R->left && !R->right)
        if(k==0 && R->info!=y || k==1 && R->info==y){
            *C=-1;
            return true;
        }else
            return false;
        
    if(R->info==y)
        k--;
    
    if(k<0)
        return false;
    
    *C=0;
    bool b=false;
    if(R->left)
        b=cerca_cam(R->left,k,y,C+1);
    
    if(b)
        return b;
    else{
        *C=1;
        if(R->right)
            b=cerca_cam(R->right,k,y,C+1);
        return b;
    }
}

int conta_n(nodo*r){
    if(!r) 
        return 0;
    return conta_n(r->left)+conta_n(r->right)+1;
}

nodo* insert(nodo* r, int y){
    if(!r) 
        return new nodo(y);
    if(conta_n(r->left)<=conta_n(r->right))
        r->left=insert(r->left,y);
    else   
        r->right=insert(r->right,y); 
    return r;
}

nodo* rep_ins(nodo* r, int dim){
    if(dim){
        int z;
        cin>>z;
        nodo* x=insert(r,z);
        return rep_ins(x,dim-1);
    }
   return r;
}

main(){
    int dim, k,y;
    cin>>dim;
    nodo* R=rep_ins(0,dim);//data
      
    cin>>k>>y;
    int C[30];
    bool b=cerca_cam(R,k,y,C);//da fare
    if(b){
       cout<<"true con cammino= "; 
       sc(C); 
       cout<<endl;
    }else
        cout<<"nessun cammino con "<<k<<" valori="<<y<<endl;
        
    cout<<"end"<<endl;
}
