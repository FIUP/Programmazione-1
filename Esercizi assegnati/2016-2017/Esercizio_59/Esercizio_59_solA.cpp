// Soluzione di B. Cosentino
#include<iostream>
using namespace std;
struct nodo{int info; nodo* next; nodo(int a=0, nodo* b=0){info=a; next=b;}}; // nodo di lista 
struct FIFO{nodo* primo, *ultimo;FIFO(nodo*a=0, nodo*b=0){primo=a; ultimo=b;}};
struct nodot{int info; nodot* left, *right; nodot(int a=0, nodot* b=0, nodot* c=0){info=a; left=b; right=c;}};//nodo di albero

FIFO push_end(FIFO a, nodo*b)
{
  if(!a.primo)
  {a.primo=a.ultimo=b;}
  else
   {a.ultimo->next=b; a.ultimo=b;}
  return a;
}


int conta_n(nodot*r)
{
   if(!r) return 0;
     else
    return conta_n(r->left)+conta_n(r->right)+1;
}

nodot* insert(nodot*r, nodot* y)
{
  if(!r) return y;
   
  if(conta_n(r->left)<=conta_n(r->right))
    r->left=insert(r->left,y);
   else   
    r->right=insert(r->right,y); 
  return r;
}
void stampa_lista(nodo*C)
{
  if(C)
    {cout<<C->info<<' '; stampa_lista(C->next);}
  else
    cout<<endl;
}

nodot* build_tree(nodot*R,int n_el)
{
 if(!n_el) return R;
 int x;
 cin>>x;
 nodot* Q= insert(R,new nodot(x));
 return build_tree(Q,n_el-1);
}
void stampa(nodot *r)
{
  if(r)
    {
      cout<<r->info<<'(';
      stampa(r->left);
      cout<<',';
      stampa(r->right);
      cout<<')';
    }
  else
    cout<< '_';
}


FIFO concF(FIFO a, FIFO b){
	if(b.primo){
		a = push_end(a,b.primo); // L(a.primo) @ b.primo @ ... @ b.ultimo = L(a.primo) @ L(b.primo) 
		a.ultimo = b.ultimo;  // faccio puntare a.ultimo all'ultimo elemento della lista ottenuta, ovvero b.ultimo
	}
	return a;
}

//PRE=(Tree(R) corretto, 1<= n<=k, k definito, sia vn=n)
FIFO pickric_infix(nodot* R, int &n, int k){
	if (!R)
		return FIFO(NULL,NULL);
	
	// R e' non vuoto
	
	// PRE_ric1 = (Tree(R->left) corretto, 1<=n<=k, k definito, sia vn=n)
	FIFO Sx = pickric_infix(R->left, n, k);
	// POST_ric1 = (restituisce un valore FIFO f tale che f.primo sia una lista L tale che i 
	// nodi abbiano i campi info di valore uguale ai campi info dei nodi dell'albero 
	// Tree(R->left) che si trovano nella posizione vn, vn+k, vn+2*k, eccetera rispetto 
	// all'ordine infisso, inoltre n-1 è il numero di nodi presenti nell'albero che 
	// seguono, rispetto all'ordine infisso, il nodo dell'albero in corrispondenza del 
	// quale si è creato l'ultimo nodo di L)
	
	
	if (n==k){
		Sx = push_end(Sx,new nodo(R->info,NULL));
		n=1;
	} else {
		n+=1;
	}
	
	// PRE_ric2 = (Tree(R->right) corretto, 1<=n<=k, k definito, sia vn=n)
	FIFO Dx = pickric_infix(R->right, n, k);
	// POST_ric2 = (restituisce un valore FIFO f tale che f.primo sia una lista L tale che i 
	// nodi abbiano i campi info di valore uguale ai campi info dei nodi dell'albero 
	// Tree(R->right) che si trovano nella posizione vn, vn+k, vn+2*k, eccetera rispetto 
	// all'ordine infisso, inoltre n-1 è il numero di nodi presenti nell'albero che 
	// seguono, rispetto all'ordine infisso, il nodo dell'albero in corrispondenza del 
	// quale si è creato l'ultimo nodo di L)
	
	return concF(Sx,Dx);
} 
// POST = (restituisce un valore FIFO f tale che f.primo sia una lista L tale che i 
// nodi abbiano i campi info di valore uguale ai campi info dei nodi dell'albero 
// Tree(R) che si trovano nella posizione vn, vn+k, vn+2*k, eccetera rispetto 
// all'ordine infisso, inoltre n-1 è il numero di nodi presenti nell'albero che 
// seguono, rispetto all'ordine infisso, il nodo dell'albero in corrispondenza del 
// quale si è creato l'ultimo nodo di L)

/**********************************************************************************
DIMOSTRAZIONE
Caso Base:
	Se Tree(R) e' un albero vuoto, allora la lista di FIFO da restituire e' vuota, ovvero
	la funzione deve restituire FIFO(NULL,NULL)
Caso Induttivo:
	# Se Tree(R) e' non vuoto, allora Tree(R->left) e' corretto. Inoltre n e k sono
	  immutati dalla PRE -> 1<=n<=k && k definito. Quindi vale PRE_ric1.
	  Alla fine di pickric_infix(R->left, n, k) vale POST_ric1.
	  Quindi, Sx contiene una lista L tale che i nodi abbiano campo info uguale al 
	  campo info di Tree(R->left) in posizione vn, vn+k, vn+*2k e cosi' via (in 
	  ordine infisso). Inoltre, n-1 e' il numero di nodi presenti in Tree(R->left)
	  che seguono l'ultimo nodo dell'albero visitato.
	
	# Necessariamente n<=k perche' viene inserito in Sx un nodo ogni k, per cui i
	  restanti saranno al piu' k. Se n == k, allora bisogna inserire la radice in 
	  lista(Sx.primo) e si reimposta n a 1. 
	  Altrimenti, si segna che c'e' un nodo restante in piu', cioe' la radice.
	  In ogni caso, vale che n<=k.
	 
	# Tree(R) e' non vuoto. Quindi, Tree(R->right) e' corretto, inoltre vale 
	  1<=n<=k e k e' ancora definito. Quindi, vale PRE_ric2 con vn = n.
	  Segue che dopo pickric_infix(R->right, n, k), vale POST_ric2.
	  Quindi, Dx contiene la lista dei nodi con campo info dei nodi di 
	  Tree(R->right) nelle posizioni vn, vn+k, vn+2*k e cosi' via. Inoltre, n-1 e'
	  il numero di nodi restanti in Tree(R->right) e, quindi, anche di Tree(R).
	  
	# Alla fine viene restituita la concatenazione di Sx e Dx e n-1 indica i nodi 
	  restanti di Tree(R) -> POST
	  
**********************************************************************************/

nodo** amplia(nodo** A, int &dim){
	
	nodo** B = new nodo*[dim*2];
	
	for (int i=0; i<dim; i=i+1)
		B[i]=A[i];

	dim=dim*2;	
	
	delete [] A;
	
	return B;
}

FIFO ripetuto(nodo** A,nodo* Q,int dim){
	
	FIFO rep;
	for (int i=0; i<dim; i++){
		if (A[i] && Q->info==A[i]->info){
			rep=push_end(rep,A[i]);
			A[i]->next=0;
			A[i]=NULL;
		}
	}
	return rep;
}


FIFO tieni_primo(nodo*& Q){
	int dim = 10;
	nodo** A = new nodo*[dim];
	int N=0;
	while (Q){
			
		if (N==dim)// se supero la dimensione dell'array dinamico
			A = amplia(A,dim);
		
		A[N]=Q;
		N++;	
		Q=Q->next;
	}
	// A contiene i puntatori per tutti i nodi di vQ
	nodo* prec=A[0];
	Q=A[0]; // reimposto Q all'inizio
	FIFO tolti;
	
	for (int j=0; j<N; j++){
	// R
		if (A[j]){	
			FIFO rep = ripetuto(A+j+1,A[j],N-j); 	// rep contiene una struttura FIFO con al suo interno i nodi ripetuti
			if (rep.primo){     // se rep non e' vuoto allora concateno rep
				tolti=concF(tolti,rep);
			}
			tolti.ultimo->next=0; //separo la lista in tolti da Q
			// concateno il nodo* non NUll precedente all'attuale
			// si noti che tutti gli A[j] non NULL sono quelli NON RIPETUTI
			prec->next=A[j];
			A[j]->next=0;
			prec=A[j];	
		}
	}
	return tolti;
} 
// POST = (restituisce una FIFO che gestisce L(Q) che corrisponde a vL(Q) in cui
// per ogni valore info resta solo il primo nodo)


/********************************
INVARIANTE
R = (0<=j<=N) & (tolti gestisce L(Q) che corrisponde a vL(Q) in cui per ogni valore 
	info nelle posizioni 0...j-1 resta solo il primo nodo)
********************************/


 main()
{
  int test,n_el, k, n=1;
 cin>>test>>n_el>>k;
 
 nodot* R=build_tree(0,n_el);
 cout<<"albero:"<<endl;
 stampa(R);
 FIFO x=pickric_infix(R,n,k);
 cout<<endl<<"lista creata:"<<endl;
 stampa_lista(x.primo);
 if(test>0)
 {
  FIFO y=tieni_primo(x.primo);
  cout<<"lista dei nodi tolti"<<endl;
  stampa_lista(y.primo);
  cout<<"lista dei nodi che restano"<<endl;
  stampa_lista(x.primo);
 }

 cout<<endl<<"end"<<endl;
 
}
