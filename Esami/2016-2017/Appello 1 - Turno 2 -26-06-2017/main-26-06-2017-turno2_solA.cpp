// Soluzione di B. Cosentino
#include<iostream>
using namespace std;

struct nodo{int n; char info; nodo*left,*right; nodo(char b=0, nodo*c=0, nodo*d=0, int e=0){n=e; info=b; left=c; right=d;}};

nodo* cerca1_infix(nodo*r, int& k, int *C);
void completa(nodo*r);
nodo* cerca2_infix(nodo*r, int k, int *C);

void stampa_l(nodo *r)//stampa albero in forma lineare usando campo info
{
  if(r)
    {
      cout<<r->info<<'(';
      stampa_l(r->left);
      cout<<',';
      stampa_l(r->right);
      cout<<')';
    }
  else
    cout<< '_';
}
void stampa_ln(nodo *r)//stampa albero in forma lineare usando campo n
{
  if(r)
    {
      cout<<r->n<<'(';
      stampa_ln(r->left);
      cout<<',';
      stampa_ln(r->right);
      cout<<')';
    }
  else
    cout<< '_';
}

nodo* parse(char*& A) //costruisce albero dalla rappresentazione lineare
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
void stampaC(int*C) //stampa array che rappresenta cammino che termina con -1
{
  while(*C!=-1)
    {cout<<*C<<' '; C++;}
  cout<<endl;
}

//PRE=(albero(r) corretto, k>=1, C è un array di interi con un numero di elementi maggiore della profondità di albero(r), vk = k)
nodo* cerca1_infix(nodo*r, int& k, int *C){
    if (!r)
        return 0;
        
    // albero(r) non vuoto
    //PRE_ric1=(albero(r->left) corretto, k>=1, C+1 è un array di interi con un numero di elementi maggiore della profondità di albero(r->left))
    nodo* trov = cerca1_infix(r->left, k, C+1);
    // POST_ric1 = (restituisce nodo cercato e C+1 e' il cammino che conduce a tale nodo) || (restituisce 0 e k = vk - m, con m = numero nodi albero(r->left))
    if (trov){
        *C = 0;
        return trov;
    }
    
    if (k==1){
        *C = -1;
        return r;
    } else
        k--;
        
    //PRE_ric2=(albero(r->right) corretto, k>=1, C+1 è un array di interi con un numero di elementi maggiore della profondità di albero(r->right))    
    trov = cerca1_infix(r->right, k, C+1);
    // POST_ric2 = (restituisce nodo cercato e C+1 e' il cammino che conduce a tale nodo) || (restituisce 0 e k = vk - m, con m = numero nodi albero(r->left))
    if (trov){
        *C = 1;
        return trov;
    }
    
    // non ho trovato da nessuna parte il nodo
    return 0;
    
}

// POST=(se albero(r) ha almeno k nodi, allora la funzione restituisce col return il nodo k rispetto all’ordine infisso
//      dei suoi nodi, e inoltre in C restituisce il cammino che da r porta a questo nodo) && (se invece albero(r) ha m nodi, 
//      con m < k, allora il valore finale di k sarà vk - m e la funzione restituisce 0 col return)
/*******************************************************************************
DIMOSTRAZIONE
Casi base:
    - Se albero(r) e' vuoto restituisco un puntatore nullo, k = vk - m =k.
    - Dopo aver controllato nel ramo a sinistra, se k == 1 allora nodo(r) e' il nodo 
      cercato e pongo a -1 il primo elemento di C. Infine, restituisco r.
Casi induttivi:
    - So che vale la PRE e che albero(r) e' non vuoto --> albero(r->left) corretto.
      Inoltre, k non e' stato modificato.
      Inoltre,  C è un array di interi con un numero di elementi maggiore della
      profondità di albero(r) --> C+1 è un array di interi con un numero di 
      elementi maggiore della profondità di albero(r->left) -> PRE_ric1
      Data PRE_ric1 vale la POST_ric1.
      Se trov e' il nodo cercato allora imposto *C = 0 perche' sono andato a sinistra
      e restituisco trov. ->POST
      
    - Altrimenti trov = 0 e k = vk - m con m = numero di nodi di albero(r->left).
      Se non mi trovo nel secondo caso base, allora k>1 e dopo k--; k>=1.
      Inoltre, albero(r) e' non vuoto --> albero(r->right) corretto.
      Inoltre,  C è un array di interi con un numero di elementi maggiore della
      profondità di albero(r) --> C+1 è un array di interi con un numero di 
      elementi maggiore della profondità di albero(r->left) -> PRE_ric2.
      Data la PRE_ric2 vale la POST_ric2.
      Se trov e' il nodo cercato allora imposto *C = 1 perche' sono andato a destra
      e restituisco trov ->POST
    
    - Altrimenti se trov = 0 allora k = vk - m con m = numero di nodi di albero(r).
      Infatti, prima a k vengono sottratti il numero di nodi di albero(r->left), 
      poi 1 (ovvero il nodo corrente) e, infine, il numero di nodi di albero(r->right)
      -> POST
*******************************************************************************/



// PRE=(albero(r) è corretto, valbero(r)=albero(r))
void completa(nodo*r){
    if (!r)
        return;
    
    // albero(r) non vuoto
    
    r->n = 1;

    if (r->left){
        // PRE_ric1=(albero(r->left) è corretto, valbero(r->left)=albero(r->left))
        completa(r->left);
        // POST_ric1 =(ogni nodo di albero(r->left) contiene nel campo n il numero di nodi del sottoalbero radicato in quel nodo, compreso il nodo stesso)
        r->n += r->left->n;
    }
    
    if (r->right){
        // PRE_ric2=(albero(r->right) è corretto, valbero(r->right)=albero(r->right))
        completa(r->right);
        // POST_ric2 =(ogni nodo di albero(r->right) contiene nel campo n il numero di nodi del sottoalbero radicato in quel nodo, compreso il nodo stesso)
        r->n += r->right->n;
    }
}
//POST=(albero(r) ha la stessa struttura di valbero(r), ma ogni nodo contiene nel campo n il numero di nodi del sottoalbero radicato in quel nodo, compreso il nodo stesso)
/*******************************************************************************
DIMOSTRAZIONE
Casi base:
    - Se albero(r) e' vuoto allora non faccio nulla -> POST
    
Casi induttivi:
    So che vale la PRE e che albero(r) e' non vuoto.
    Innanzitutto, pongo r->n = 1 per contare nodo(r).
    - Se esiste r->left imposto tutti i campi n dei nodi di albero(r->left) 
      correttamente e dopo sommo a r->n il campo n di nodo(r->left) che conta 
      tutti i nodi dei suoi figli.
    - Se esiste r->right imposto tutti i campi n dei nodi di albero(r->right) 
      correttamente e dopo sommo a r->n il campo n di nodo(r->right) che conta 
      tutti i nodi dei suoi figli.
    Alla fine, r->n contiene il numero di nodi dei figli e considera anche se stesso ->
    -> POST
*******************************************************************************/




// PRE = (albero(r) è corretto e ogni suo nodo x contiene nel suo campo n il n. di nodi del sottoalbero radicato in x, 
//      1<=k <= r ->n, C è un array di interi con un numero di elementi maggiore della profondità di albero(r))
nodo* cerca2_infix(nodo* r, int k, int*C){
    
    
    while (k>0){  // R = (0<=k<=r->n) && (C contiene il cammino da nodo(vr) a nodo(r)) && (se k = 0, allora nodo(r) e' il nodo cercato, altrimenti albero(r) contiene il nodo cercato)
          
        if (r->left && k<=r->left->n){
            r=r->left;
            *C = 0;
            C++;
        } else {
            if (r->left)
                k -= r->left->n;
            // k > 0
            if (k==1){
                *C = -1;
                k--;
            } else {
                // k > 1
                if (r->right){
                    r = r->right;
                    *C = 1;
                    C++;
                    k--;
                }
            }
        }
    }
    return r;
}
// POST = (restituisce il nodo k di albero(r) e in C il cammino da r fino a quel nodo)

main()
try{
  char A[100],y='a',*q=A;
  int m, M[10],C[50];
  
  while(y!='$')
    {
      cin>>y;
      *q=y;
      q++;
    }
  cin>>m;
  for(int i=0; i<m; i++)
    cin>>M[i];
  cout<<"start"<<endl;
  q=A;
  nodo* R=parse(q);
  stampa_l(R);
  cout<<endl;
 
  for(int i=0; i<m; i++)
    {
      int z=M[i];
      nodo*x=cerca1_infix(R,z,C); //domanda (1) ricorsiva
      if(x)
	{cout<<"info nodo N." << M[i]<<" ="<<x->info<<" il cammino e':" << endl; stampaC(C);}
      else
        cout<<"il nodo N."<<M[i]<<" non c'e'"<<endl;	
    }
  
  completa(R); //domanda (2) ricorsiva
					      
  stampa_ln(R);
					      
  cout<<endl;

  for(int i=0; i<m; i++)
    {
      if(M[i]<= R->n)
	{
	  nodo*x=cerca2_infix(R,M[i],C); // domanda (3) iterativa
	  cout<<"info nodo N."<<M[i]<<" =" <<x->info <<" il cammino e':"<<endl;
	  stampaC(C);
	}
      else
        cout<<"il nodo N."<<M[i]<<" non c'e'"<<endl;	
    }
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

