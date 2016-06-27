#include<iostream>
using namespace std;

struct nodo{int info; nodo* left; nodo* right; nodo(int a=0, nodo* b=0, nodo* c=0){info=a; left=b; right=c;}};

int conta_n(nodo*R){
    if(!R)  return 0;
    return conta_n(R->left)+conta_n(R->right)+1;
}

nodo* insert(nodo*R,nodo* n){
    if(!R) return n;

    if(conta_n(R->left)<=conta_n(R->right))
        R->left=insert(R->left,n);
    else
        R->right=insert(R->right,n);
    return R;
}

nodo* build_tree(nodo* R, int n_el){
    if(n_el){
        int z;
        cin>>z;

        nodo*x=insert(R, new nodo(z,0,0));
        return build_tree(x,n_el-1);
   }return R;
}

void stampa(nodo *r){
    if(r){
        cout<<r->info<<'(';
        stampa(r->left);
        cout<<',';
        stampa(r->right);
        cout<<')';
    }else
        cout<< '_';
}

main(){
    int n_el;
    cin>>n_el;

    nodo* R=build_tree(0, n_el);
    stampa(R);
    cout<<endl<<"end"<<endl;
}
