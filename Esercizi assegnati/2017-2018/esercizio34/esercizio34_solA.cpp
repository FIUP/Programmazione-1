//Soluzione di S.Righetto

#include<iostream>
using namespace std;

struct nodo{int info; nodo*next; nodo(int a=0, nodo*b=0){info=a; next=b;}};

nodo*leggi(){ //legge valori da cin e costituisce una lista fino a -1 escluso
    int n;
    cin >> n;
    if(n==-1) return 0;
    return new nodo(n,leggi());
}


int ricerca(nodo*L, int x){
    if(!L) return -1;
    if(L->info==x) return 0; //controllo che il campo info sia uguale
    if(L->next==0) return -1; //controllo che il prossimo nodo sia definito
    
    if(ricerca(L->next,x)==-1) return -1;
    return 1+ ricerca(L->next,x); 
    
}


void fai_ricerche(nodo*L, int n){ //usa ricerca dentro di se
    if(n!=0){
        int x,m;
        cin >> x;
        m= ricerca(L,x);
        if(m == -1) cout << "il valore " << x << " non si trova nella lista" << endl;
        else cout << "il valore "<< x<< " e' in posizione " <<m << endl;
        
        fai_ricerche(L,n-1);
    }
}

main()
{
  nodo* L=leggi();
  int n;
  cin>>n;
  cout<<"start"<<endl;
  fai_ricerche(L,n);
  cout<<"end"<<endl;
}


