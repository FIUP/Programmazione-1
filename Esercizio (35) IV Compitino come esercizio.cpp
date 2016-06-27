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

nodo *sUk(nodo* &Q, int k, int z, int &ck) {
	if(!Q){                 //se è vero (non zero)
		if(ck>=k) {
			ck=k;
			return 0;
		}else{
			ck=0;
			return 0;
		}
	}
	if(Q->info==z){
		ck++;
		nodo* p=sUk(Q->next, k, z, ck);
		if(ck>0){
			nodo* a=Q;
			Q=Q->next;
			a->next=p;
			ck--;
			return a;
		}
		return p;
	}else
		return sUk(Q->next, k, z, ck);
}

void stampa(nodo* x){
    if(x){
        cout<<x->info<<' '; stampa(x->next);
    }else
        cout<<endl;
}

main(){
    int n_el, k, z, ck=0;
    cin>>n_el>>k>>z;

    nodo* x=F(n_el);
    cout<<"x= ";
    stampa(x);

    nodo*y=sUk(x,k,z,ck);
    cout<<"y= ";
        stampa(y);
    cout<<"x= ";
        stampa(x);
    cout<<"end"<<endl;
}
