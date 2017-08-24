// soluzione di B.Cosentino
#include<iostream>

using namespace std;

struct nodo{
	int info;
	nodo* next;
	nodo(int a=0, nodo* b=0){
		info=a;
		next=b;
	}
};

// PRE = L e' un array dim x dim, 0<=i<=dim-1 e (i,j) e' la posizione di inizio del cammino
nodo* trova_lab(int L[], int dim, int i, int j){
    
    if (*(L+i*dim+j)==0 || j<0 || j>=dim)
        return 0;
    
    // L[i][j]==1 & 0<=i<=dim-1 & 0<=j<dim
    
    if (i==dim-1){
    	
    	return new nodo(j,0);
    }
    
    // L[i][j]==1 & 0<=i<dim-1 & 0<=j<dim
    
    
    // PRE_ric1 = L e' un array dim x dim, 0<=i+1<=dim-1 e (i+1,j-1) e' la posizione di inizio del cammino
    nodo* n = trova_lab(L,dim,i+1,j-1);
    // POST_ric1 = restituisce il cammino piu' a sinistra a partire da (i+1,j-1) se esiste altrimenti restituisce una lista vuota
    if (n)
        return new nodo(j,n);
    
    // PRE_ric2 = L e' un array dim x dim, 0<=i+1<=dim-1 e (i+1,j) e' la posizione di inizio del cammino
    n = trova_lab(L,dim,i+1,j);
    // POST_ric2 = restituisce il cammino piu' a sinistra a partire da (i+1,j) se esiste altrimenti restituisce una lista vuota
    if (n)
        return new nodo(j,n);
    
    // PRE_ric3 = L e' un array dim x dim, 0<=i+1<=dim-1 e (i+1,j+1) e' la posizione di inizio del cammino
    n = trova_lab(L,dim,i+1,j+1);
    // POST_ric3 = restituisce il cammino piu' a sinistra a partire da (i+1,j+1) se esiste altrimenti restituisce una lista vuota
    if(n)
        return new nodo(j,n);
        
    return 0;
} 
// POST = restituisce il cammino piu' a sinistra a partire da (i,j) se esiste altrimenti restituisce una lista vuota

/***************************************************
DIMOSTRAZIONE

Casi base:
    Caso 1
    (i,j) e' la posizione di inizio del cammino. Se L[i][j] e' una posizione non valida, 
    ovvero L[i][j]=0 oppure mi trovo fuori dai lati del labirinto (cioe' j<0 e j>=dim) ->
    -> non esiste un cammino a partire da (i,j) -> restituisco lista vuota -> POST
    
    Caso 2
    (i,j) e' la posizione di inizio del cammino ed e' valida (L[i][j]=1 & 0<=j<=dim-1).
    Se i=dim-1 allora i e' l'indice dell'ultima riga di L -> esiste un unico cammino da 
    (i,j) a dim-1 ed è (i,j) -> restituisco la lista formata dal nodo (j,0) -> POST
    
Casi induttivo:
    (i,j) e' la posizione iniziale del cammino. So che L[i][j]==1 & 0<=i<dim-1 & 0<=j<dim.
    
    Caso 1
    Quindi, cerco un cammino a partire dalla riga successiva (ovvero i+1) e quello piu' a
    sinistra (ovvero j-1). 0<=i<dim-1 & 0<=j<dim -> 0<=i+1<=dim-1 & -1<=j-1<dim-1 -> 
    -> PRE_ric1 -> POST_ric1 -> restituisce il cammino piu' a sinistra a partire da (i+1,j-1)
    se esiste altrimenti restituisce una lista vuota. n = cammino piu' a sinistra a partire da (i+1,j-1)
    Se tale cammino esiste (n!=0) allora viene restituito (i,j) @ n (if (n) return new nodo(j,n)) -> POST
    Se non esiste allora procedo col caso 2.
    
    Caso 2:
    So che a partire da (i+1,j-1) non ci sono cammini.
    Cerco un cammino a partire dalla riga successiva (ovvero i+1) e quello piu' a
    sinistra (ovvero j). 0<=i<dim-1 -> 0<=i+1<=dim-1 -> PRE_ric2 -> POST_ric2 ->
    -> restituisce il cammino piu' a sinistra a partire da (i+1,j) se esiste altrimenti 
    restituisce una lista vuota -> n = cammino piu' a sinistra a partire da (i+1,j).
    Se tale cammino esiste (n!=0) allora viene restituito (i,j) @ n (if (n) return new nodo(j,n)) -> POST
    Se non esiste allora procedo col caso 3.

    Caso 3
    So che a partire da (i+1,j-1) e da (i+1,j) non ci sono cammini
    Cerco un cammino a partire dalla riga successiva (ovvero i+1) e quello piu' a
    sinistra (ovvero j+1). 0<=i<dim-1 & 0<=j<dim -> 0<=i+1<=dim-1 & 1<=j+1<dim+1 -> PRE_ric3 -> POST_ric3 ->
    -> restituisce il cammino piu' a sinistra a partire da (i+1,j+1) se esiste altrimenti 
    restituisce una lista vuota -> n = cammino piu' a sinistra a partire da (i+1,j+1).
    Se tale cammino esiste (n!=0) allora viene restituito (i,j) @ n (if (n) return new nodo(j,n)) -> POST
    
    Caso 4
    Se non esiste allora non ci sono possibilita' di trovare una cammino e si restituisce una lista vuota. -> 
    -> POST
    
***************************************************/


// PRE = (L ha nxn posizioni, 0<=e<=n)
nodo* trova(int L[], int dim, int e){
    
    if (e>=dim){ // se ho superato il limite della riga
    	return 0;
    }
    nodo* n=trova_lab(L, dim, 0, e);
    if (L[e]==1 && n){// se trovo un cammino
    	return n;
    }
    // L[e]==0 && !trova_lab(L, dim, 0, e) && e<=dim-1
    
    //	se non lo trovo ne cerco uno a partire dalla posizione successiva
    return trova(L, dim, e+1);
    
}

// POST = (restituisce una lista non vuota sse esiste un cammino dalla riga 0 alla riga n-1 di L con inizio da un elemento e..n-1 della riga 0) &
//      & (se restituisce una lista non vuota, allora questa lista descrive il cammino più a sinistra che esiste)

void stampa(nodo* x, int n, int c){
	
	if (x){
		
		cout << "(" << c << "," << x->info << ")";
		stampa(x->next, n, c+1);
	
	}
}


main()
{
  int n;
  cin>>n;
  int* L= new int [n*n], *P=new int[n];
  for(int i=0; i<n*n; i++)
          cin>>L[i];
  nodo* x=trova(L,n,0);//da fare
  cout<<"start"<<endl;
  if(x)
    { cout<<"il cammino e':"; stampa(x,n,0); cout << endl;}//da fare
    
  else
    cout<<"il cammino non esiste"<<endl;
  cout<<"end"<<endl;
      
}
