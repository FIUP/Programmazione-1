// soluzione di B.Cosentino
#include<iostream>

using namespace std;

struct nodo{char info; nodo* left,*right; nodo(int a=0, nodo*b=0,nodo*c=0){info=a; left=b; right=c;}};
nodo* parse(char*& A)
{
  if(*A>='a' && *A<='z')
    {
      char p=*A;
      if(*(A+1) !='(') throw (1);
      A=A+2;
      nodo*l=parse(A);
      if(*A != ',') throw (2);
      A=A+1;
      nodo*r=parse(A);
      if(*A !=')') throw(3);
      
      A=A+1;
      return new nodo(p,l,r);
    }
  else
    if(*A=='_') {A=A+1;return 0;}
    else
      throw (4);
}

// PRE = (albero(r) corretto, k>0 e salto>0).
int stampaConSalti(nodo* r, int k, int salto){
    if (!r) return salto;
    
    // r non e' vuoto
    
    // PRE_ric1 = (albero(r->left) corretto, k>0 e salto>0)
    salto = stampaConSalti(r->left,k,salto); 
    // POST_ric1 = (la funzione stampa un nodo ogni salto-1 nodi di albero(r->left) in ordine infisso) && 
    //        && (restituisce l’intero che indica quanti nodi dovrebbe percorrere per fare la prossima stampa)
    
    if (salto == 1){
        cout << r->info << ' ';
        salto = k;
    } else {
        salto--;
    }
    // PRE_ric2 = (albero(r->right) corretto, k>0 e salto>0)
    return stampaConSalti(r->right,k,salto);
    // POST_ric2 = (la funzione stampa un nodo ogni salto-1 nodi di albero(r->right) in ordine infisso) && 
    //        && (restituisce l’intero che indica quanti nodi dovrebbe percorrere per fare la prossima stampa)
}
// POST = (la funzione stampa un nodo ogni salto-1 nodi di albero(r) in ordine infisso) && 
//        && (restituisce l’intero che indica quanti nodi dovrebbe percorrere per fare la prossima stampa)

/*******************************************************************************
Dimostrazione

Caso base:
    Se albero(r) e' vuoto non e' possibile stampare nulla e la funzione restituisce
    salto che e' ancora il numero di salti rimasti da fare -> POST
    
Caso induttivo:
    So che albero(r) e' non vuoto. Quindi, esistono albero(r->left) e albero(r->right)
    corretti. Inoltre, k e salto sono invariati, per cui k>0 e salto>0 ->
    -> vale PRE_ric1. PRE_ric1 <stampaConSalti> POST_ric1 comporta che 
    salto = numero di salti mancanti dopo la stampa infissa del ramo sinistro.
    
    2 casi:
        - Se salto == 1, allora va effettuata la stampa di r->info e reimpostato
          salto a k.
        - Se salto != 1, allora salto > 1 e viene decrementato perche' e' stato percorsa 
          la radice. Quindi salto >= 1.
    
    In ogni caso, salto >= 1 -> salto > 0. k e' invariato (k > 0).
    
    Ricapitolando, esiste albero(r->right) corretto, k > 0 e salto > 0 -> 
    -> vale PRE_ric2. PRE_ric2 <stampaConSalti> POST_ric2 -> POST
    
*******************************************************************************/

main()
try{
  char A[100],y,*q=A;
  int k;
  cin>>k;
  while(y!='$')
    {
      cin>>y;
      *q=y;
      q++;
    }
  q=A;
 
  nodo* R=parse(q);
  cout<<"start"<<endl;
  
  int a= stampaConSalti(R,k,k);//da fare
  
  cout<<endl<<"restituisce "<<a<<endl;
  
  cout<<"end"<<endl;
 }
 catch(int x)
   {
     switch(x)
       {
       case 1: cout<<"manca ("<<endl;   break;
       case 2: cout<<"manca ," <<endl; break;
       case 3: cout<<"manca )"<<endl;   break;
       case 4: cout<<"non albero"<<endl;   break;
       }

   }
