#include<iostream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};

//PRE=(n_el>=0)
nodo* F(int n_el){
    if(n_el==0)
        return 0;
    else{
        int el;
        cin>>el;
        return new nodo(el,F(n_el-1));
    }
}
//POST=(Restituisce una lista corretta contenente n_el>=0 nodi con campo info dato da cin)

//PRE=(L(Q) è lista corretta, sia vL(Q)=L(Q), k>0)
nodo* C(nodo*& Q, int k){
    if(!Q)
        return NULL;
        
    if(k==1){
        nodo* a=new nodo(Q->info,0);
        Q=Q->next;
        return a;
    }else{
        nodo* L=C(Q->next,k-1);
        if(L){
            nodo* a=new nodo(Q->info,L);  //aggiungo il nodo all'inizio della lista L (a@L)
            Q=Q->next;
            return a;
        }else
            return NULL;
    }
}
//POST=(se vL(Q) contiene almeno k nodi, allora col return viene restituita una lista corretta che consiste dei
//primi k nodi di vL(Q) e L(Q) è il resto di vL(Q)) &&(se invece vL(Q) non contiene k nodi, allora la funzione
//restituisce 0 col return e L(Q)=vL(Q))

nodo* conc(nodo* a, nodo* b){
    if(!a)
        return b;
    else{
        a->next=conc(a->next,b);
        return a;
    }
}

//PRE=(L(Q1) e L(Q2) sono liste corrette, k>0, vL(Q1)=L(Q1) e vL(Q2)=L(Q2))
nodo* G(nodo*Q1, nodo*Q2, int k){
    if(!Q1)
        return Q2;
    else if(!Q2)
        return Q1;
    
    nodo* L1=C(Q1,k);
    nodo* L2=C(Q2,k);
    if(!L1)
        return conc(Q1,Q2);
    else if(!L2){
        nodo* L=conc(L1,Q2);
        return conc(L,Q1);
    }else{
        nodo* L=conc(L1,L2);
        return conc(L,G(Q1,Q2,k));
        }
}
//POST=(restituisce una lista corretta composta da pezzi di k nodi prelevati alternativamente da vL(Q1) e
//vL(Q2), se una lista ha meno di k nodi, viene usato quello che c'è)

void stampa(nodo* x)
{
 if(x){
   cout<<x->info<<' '; stampa(x->next);
 } 
 else
  cout<<endl;
}

main(){
 int n_el1,n_el2;
 cin>>n_el1>>n_el2;
 
 nodo* x1=F(n_el1);
 cout<<"x1= ";

 stampa(x1);
 nodo* x2=F(n_el2);
 cout<<"x2= ";
 stampa(x2);
 int k;
 cin>>k;
 nodo* y=G(x1,x2,k);
 cout<<"lista risultante= ";
 stampa(y);
 
 cout<<"end"<<endl;
}
