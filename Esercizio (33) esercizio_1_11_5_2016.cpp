#include<iostream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};

nodo* F(int n_el){
    if(n_el){
        int num;
        cin>>num;
        nodo* temp = new nodo(num, F(n_el-1));
    }else
        return 0;
}

nodo* C(nodo*& Q, int k){
    if(Q == NULL)           //lista vuota niente da rimuovere, ritorno NULL
        return NULL;
    if(k == 1){             //manca un nodo da togliere, devo rimuoverlo da Q e ritornarlo
        nodo* a = Q;
        Q = Q->next;
        a->next = NULL;
        return a;
    }else{                  //k>1
        nodo* b = C(Q->next, k-1);
        if(b != NULL){      //ci sono abbastanza nodi nella lista Q
            nodo* a = Q;    //salvo ele Q in a
            Q = Q->next;    //rimuovo ele Q dalla lista Q
            a->next = b;    //collego a con b
            return a;
        }else{              //non ci sono abbastanza nodi nella lista Q
            return NULL;
        }
    }
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

    nodo* x = F(n_el);
    stampa(x);

    int k;
    cin>>k;
    nodo* y = C(x,k);

    cout<<"lista tagliata= ";
    stampa(y);
    cout<<"lista rimasta= ";
    stampa(x);
    cout<<"end"<<endl;
}
