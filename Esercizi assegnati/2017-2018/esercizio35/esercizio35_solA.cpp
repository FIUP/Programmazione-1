//Soluzione di S.Righetto

#include<iostream>
using namespace std;

struct nodo{int info; nodo*next; nodo(int a=0, nodo*b=0){info=a; next=b;}};


nodo*inserisci(nodo*L,int x){
    if(!L) return new nodo (x,0);
    else {
        if(L -> info > x) {nodo*l= new nodo (x,L);//trovo che il nodo corrente è più grande di x, quindi creo un nodo da aggiungere alla lista
        return l;}
        else L->next= inserisci(L->next,x); //controllo i nodi successivi
    }
    return L;
}

nodo* F(nodo*L){
    int x;
    cin >> x;
    if(x!= -1){
        L= inserisci(L,x);
        L=F(L);
        return L;
    }
    else return L;
}

void stampa_lista(nodo*L)
{
    if(!L) return;
    cout<<L->info<<"->";
    stampa_lista(L->next);
}

main()
{
  cout<<"start"<<endl;
  nodo* L= F(0);
  if(!L) cout << "lista vuota" << endl;
  stampa_lista(L);
  cout<<"end"<<endl;
}

