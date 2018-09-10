//Soluzione di S.Righetto

#include<iostream>
using namespace std;


struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}};

// PRE=(L(T) è corretta, dimP>0, P ha dimP elementi definiti)
nodo* match(nodo *& T, int *P, int dimP){ 
    nodo *m = 0, *n = 0;
    if(!T) 
    	return 0;
    if(dimP == 1){
        if(T->info == *P){
            n = T;
            T = T->next;
            n->next = 0;
            return n;
        }
        return match(T->next, P, dimP);
    }
    if(T->info == *P)
        m=match(T->next, P+1, dimP-1);
    else
        m=match(T->next, P, dimP); 
    if(m){
        if(T->info == *P){
            n = T;
            T = T->next;
            n->next = m;
            return n;
        }
        return m;
    }
    return 0; 
}
//POST=(c’è un match -> la funzione restituisce la lista del match e T = lista restante) && (non esiste match -> restituisce 0 col return e T = vT)

nodo* crea(int dim)
{
 if(dim)
  {
	int x;
	cin>>x;
	return new nodo(x,crea(dim-1));
  }
 return 0;
}

void stampa(nodo*L)
{
  if(L)
  {
	cout<<L->info<<' ';
	stampa(L->next);
  }
  else cout<<endl;
}

void leggi(int dim, int*P)
{
  if(dim)
   {
	cin>>*P;
	leggi(dim-1,P+1);
   }

}

main()
{
  int dim, dimP, P[20];
  cin>>dim;
  nodo* L1=crea(dim);
  cin>>dimP;
  leggi(dimP, P);
  cout<<"start"<<endl;
  nodo* L2= match(L1,P, dimP);
  if(L2)
	stampa(L2);
  else
	cout<<"Lista del match vuota"<<endl;
   if(L1)
	 stampa(L1);
   else
	 cout<<"Lista restante vuota"<<endl;
   cout<<"end"<<endl;
}



    
    
