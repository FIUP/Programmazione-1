// soluzione di B.Cosentino
#include<iostream>
#include<fstream>
using namespace std;


struct nodo{int info; nodo* left,*right; nodo(int a=0, nodo* b=0, nodo*c=0){info=a; left=b;right=c;}};

// PRE = (albero(r) corretto)
int contanodi(nodo* r){
    
    if (!r)
        return 0;
        
    // r e' non vuoto
    
    return 1+contanodi(r->left)+contanodi(r->right);
    
}
// POST = restituisce il numero di nodi di albero(r)



// PRE = (albero(r) è corretto e bilanciato, valbero(r)=albero(r))
nodo* alberobil (nodo*r, int k){
    
    if (!r)
        return new nodo(k,0);
        
    // r non e' vuoto
    
    if (contanodi(r->left) <= contanodi(r->right))
        // PRE_ric1 = (albero(r->left) è corretto e bilanciato, valbero(r->left)=albero(r->left))
        r->left = alberobil(r->left, k);
        // POST_ric1 = (albero(r->left) è corretto e ancora bilanciato ed è ottenuto da valbero(r->left) aggiungendogli una nuova foglia con info=k)
    else
        // PRE_ric2 = (albero(r->right) è corretto e bilanciato, valbero(r->right)=albero(r->right))
        r->right = alberobil(r->right, k);
        // POST_ric2 = (albero(r->right) è corretto e ancora bilanciato ed è ottenuto da valbero(r->right) aggiungendogli una nuova foglia con info=k)
    return r;
}
// POST = (albero(r) è corretto e ancora bilanciato ed è ottenuto da valbero(r) aggiungendogli una nuova foglia con info=k)

/*******************************************************************************
Dimostrazione

Caso base:
    Se albero(r) e' vuoto, allora inserisco nodo(k) come radice. L'albero e' 
    bilanciato -> POST
    
Caso induttivo:
    So che albero(r) e' non vuoto e bilanciato -> esistono albero(r->left) e 
    albero(r->right) corretti e bilanciati -> valgono entrambe le PRE_ric.
    Conto i nodi di albero(r->left) e albero(r->right) con contanodi().
    2 casi:
        - Se contanodi(r->left) <= contanodi(r->right), allora aggiungo la foglia
          a albero(r->left) -> albero(r->left) e' corretto e bilanciato ed e' 
          ottenuto da valbero(r->left) aggiungendo una foglia con info=k ->
          -> albero(r) e' corretto e bilanciato ed e' ottenuto da valbero(r) 
          aggiungendogli una nuova foglia con info=k.
          
        - Se contanodi(r->left) > contanodi(r->right), allora aggiungo la foglia
          a albero(r->right) -> albero(r->right) e' corretto e bilanciato ed e' 
          ottenuto da valbero(r->left) aggiungendo una foglia con info=k ->
          -> albero(r) e' corretto e bilanciato ed e' ottenuto da valbero(r) 
          aggiungendogli una nuova foglia con info=k.
          
    Alla fine, restituisco albero(r) -> POST. 

*******************************************************************************/

// PRE = (albero(r) è corretto e bilanciato, n>=0, valbero(r)=albero(r))
nodo* buildtree(nodo* r, int n){
    
    if (!n)
        return r;
    
    int k;
    cin >> k;
    
    r = alberobil(r,k);
    
    return buildtree(r, n-1);
    
}
// POST = (restituisce valbero(r) con n nodi aggiuntivi inseriti in modo da conservare il bilanciamento)


void stampa_l(nodo* r){
    
    if (!r)
        cout << '_';
    else {
        cout << r->info << '(';
        stampa_l(r->left); 
        cout << ',';
        stampa_l(r->right);
        cout << ')';
    }
}


main()
{
  int n;    //numero nodi
  cin>>n;
  
  nodo* R=buildtree(0,n);//da fare
  
  cout<<"start"<<endl;
  stampa_l(R); //da fare, vista in classe
  
  cout<<endl<<"end";
  
      
}
