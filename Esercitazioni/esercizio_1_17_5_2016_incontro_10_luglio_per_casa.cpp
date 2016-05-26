#include<iostream>
#include<fstream>
using namespace std;

struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};

void stampa(nodo* x)
{
 if(x)
 {cout<<x->info<<' '; stampa(x->next);}
 else
  cout<<endl;
}

nodo* F(int n_el)
{
    if(n_el==0)
        return 0;
    int valore;
    cin>>valore;
    return new nodo(valore, F(--n_el));
}

nodo* lUk(nodo*&Q, int k, int z, int & ck){
	if(Q){
		if(Q->info==z){
			ck++;
			nodo *T=lUk(Q->next, k, z, ck);
			if(ck!=-1 && (k-ck)>0){
				ck++;
				return T;
			}
			else{
				nodo *w=Q;
				Q=Q->next;
				w->next=T;
				return w;
			}
		}
		else
			return lUk(Q->next, k, z, ck);
	}
	else{
		if(ck>=k)
			ck=0;
		else
			ck=-1;
		return 0;
	}
}


/*POST=(se vL(Q) contiene x nodi con info=z e vck+x >=k, allora viene restituito col return la lista che consiste
degli ultimi k-ck nodi di vL(Q) che contengono info=z ed L(Q) è vL(Q) meno i nodi restituiti col return)
&&(se vL(Q) contiene x nodi con info=z e vck+x<k, allora L(Q)=vL(Q) e viene restituito 0 col return)*/

main()
{
 int n_el, k, z, ck=0;
 //n_el dimensione della lista L(Q)
 
 cin>>n_el>>k>>z;
 nodo* x=F(n_el);				//esercizio 0 11/5
 cout<<"x= ";
 stampa(x);
 nodo*y=lUk(x,k,z,ck);			//da fare 
 cout<<"y= ";
 stampa(y);
 cout<<"x= ";
 stampa(x);
 cout<<"end"<<endl;
}
