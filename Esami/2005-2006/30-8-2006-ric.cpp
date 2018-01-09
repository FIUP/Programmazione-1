#include<iostream>
using namespace std;

struct nodo{
    int info;
    nodo* next;
    nodo(int a=0, nodo* b=0){
        info=a;
        next=b;
    }
};



nodo* F(nodo*& L, int l1, int l2){
    if(!L)
        return 0;
    nodo* a;
    a = F(L->next, l1, l2);
    if(L->info>=l1 && L->info<=l2){
        nodo* b = L;
        L = L->next;
        b->next = a;
        return b;
    }
    return a;
}

nodo* costruisci(int dim){
    if(dim==0)
        return 0;
    else{
        int a;
        cin>>a;
        return new nodo(a,costruisci(dim-1));
    }    

}

void stampa(nodo* b){
    if(b){
        cout<<b->info<<" ";
        stampa(b->next);
    }
    else    
        cout<<endl; 
}


int main(){
    int dim; cin>>dim;
    nodo* a = costruisci(dim);
    stampa(a);
    int l1, l2;
    cin>>l1>>l2;
    nodo* b = F(a,l1,l2);
    stampa(a);
    stampa(b);
}
