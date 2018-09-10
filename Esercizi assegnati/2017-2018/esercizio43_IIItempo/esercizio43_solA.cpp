//Soluzione di S.Righetto

#include<iostream>
using namespace std;
struct nodo{int info; nodo* left,*right; nodo(int a=0, nodo* b=0, nodo*c=0){info=a; left=b;right=c;}};

// PRE = (albero(r) corretto)
int conta(nodo *r){
    if(!r) 
    	return 0;
    return 1+ conta(r->left) + conta(r->right);
}
// POST = restituisce il numero di nodi di albero(r)


// PRE = (albero(r) è corretto e bilanciato, valbero(r)=albero(r))
nodo* alberobil(nodo* r, int k){
    if(!r) 
    	return new nodo(k,0,0);
    if(!r->left) 
        r->left = new nodo(k,0,0);
    else 
    	if(!r->right) 
        	r->right = new nodo(k,0,0);
    	else 
    		if(conta(r->left)-conta(r->right) <1) alberobil(r->left,k);
    		else alberobil(r->right,k);
    return r;
}
// POST = (albero(r) è corretto e ancora bilanciato ed è ottenuto da valbero(r) aggiungendogli una nuova foglia con info=k)

// PRE = (albero(r) è corretto e bilanciato, n>=0, valbero(r)=albero(r))
nodo* buildtree(nodo * r,int n){
    int t;
    for(int i=0; i<n; i++){
        cin >> t;
        r = alberobil(r,t);
    }
    return r;
}
// POST = (restituisce valbero(r) con n nodi aggiuntivi inseriti in modo da conservare il bilanciamento)

void stampa(nodo * r){
    if(!r) return ;
    cout << r->info << '(';
    if(r->left) stampa(r->left);
    else cout << '_';
    cout << ',';
    if(r->right) stampa(r->right);
    else cout << '_';
    cout << ')';
}

main() {
  int n;
  cin>>n;
  nodo* R=buildtree(0,n);//da fare
  cout<<"start"<<endl;
  stampa(R); //da fare, vista in classe
  
  cout<<endl<<"end";
}

