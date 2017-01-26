#include<iostream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};

nodo* F(int n_el){
    if(n_el){
        int num;
        cin>>num;
        nodo* temp=new nodo(num, F(n_el-1));
    }else
        return 0;
}
/* //Soluzione secondo filè
nodo* ins_end(nodo* Q,nodo* a){
    if(!Q) {a->next=0;return a;}Q->next=ins_end(Q->next,a); return Q;
}
nodo* G(nodo* Q){
    if(!Q) return 0;
    nodo* a=G(Q->next);
    nodo*b=ins_end(a,Q);
}*/

nodo* G(nodo* n) {
    if(n==NULL || n->next==NULL){
        return n;
    }
    nodo* tempN = n;
    n = G(n->next);
    (tempN->next)->next = tempN;
    tempN->next = NULL;
    return n;
}

void stampa(nodo* x){
    if(x){
        cout<<x->info<<' ';
        stampa(x->next);
    }else
        cout<<endl;
}

main(){

    int n_el;

    cin>>n_el;

    nodo* x=F(n_el);
    cout<<"x= ";
    stampa(x);

    nodo* y = G(x);
    cout<<"y= ";
    stampa(y);

    cout<<"end"<<endl;
}
