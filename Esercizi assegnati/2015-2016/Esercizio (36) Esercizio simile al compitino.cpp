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

nodo *sUk(nodo* &Q, int k, int z, int &ck, int &lasciak) {
	if(!Q){                //se Q è NULL
		if(ck>k) {         //se ck è maggiore o uguale a K
			//ck=k;           //ck diventa k
			lasciak=ck-k;
			return NULL;    //ritorna 0
		}else{              //se ck è minore di K
			ck=0;           //azzero ck
			return NULL;    //ritorno NULL
		}
	}
	if(Q->info==z){                         //se Q->info è uguale a z
		ck++;                               //ck++
		nodo* p=sUk(Q->next, k, z, ck, lasciak);     //creo nodo p e gli passo prossimo el di Q finchè non arrivo alla fine
		if(ck>0){
			if(ck<=lasciak){
			   //if(ck<=k){
			    nodo* a=Q;                      //salvo Q in a
			    Q=Q->next;                      //Q va al prossimo el
			    a->next=p;                      //prossimo el di a diventa p
			    ck--;                           //riduco di 1 ck
			    return a;                       //ritorno a
			}
			ck--;
		}
		return p;                           //ritorno p
	}else                                   //se Q-info non è uguale a z
		return sUk(Q->next, k, z, ck, lasciak);      //passo al prossimo el di Q
}

void stampa(nodo* x){
    if(x){
        cout<<x->info<<' '; stampa(x->next);
    }else
        cout<<endl;
}

main(){
    int n_el, k, z, ck=0, lasciak=0;
    cin>>n_el>>k>>z;

    nodo* x=F(n_el);
    cout<<"x= ";
    stampa(x);

    nodo*y=sUk(x,k,z,ck, lasciak);
    cout<<"y= ";
        stampa(y);
    cout<<"x= ";
        stampa(x);
    cout<<"end"<<endl;
}
