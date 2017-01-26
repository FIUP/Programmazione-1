#include<iostream>
using namespace std;
//-------------------strutture dati------osservare costruttore di FIFOX-----------------------
struct nodo {
int info;
nodo *next; 
nodo(int a=0, nodo*b=0){info=a; next=b;}
};

struct FIFOX {
nodo *primo, *ultimo;
int val_p, val_u, n_ele;
FIFOX(nodo*a=0,nodo*b=0, int c=0, int d=0, int e=0) 
 {
  
      primo=a;
      ultimo=b;
      val_p=c;
      val_u=d;
      n_ele=e;
  }
};

struct nodo_x{
FIFOX* fix;
nodo_x *next;};
//-------------------------------------funzioni date----------------------------
//trova ultimo nodo di lista non vuota
nodo* ult(nodo*n){if(!n->next) return n; return ult(n->next);}
//calcola lungheza di lista
int length(nodo*n){if(!n) return 0; return 1 + length(n->next);}

nodo* build(int n)//costruisce lista di n nodi
{
  if(n>0)
   {
     int x;
     cin >> x;
     return new nodo(x, build(n-1));
   }
 return 0;

}

nodo_x* fai()//costruisce la lista nodo_x su cui far girare partiziona
{
  
       nodo_x*m1=new nodo_x;
       int n;
       cin >> n;
       nodo*x1=build(n);
       m1->fix=new FIFOX(x1,ult(x1), x1->info, ult(x1)->info, n);
       return m1;
}
  

void stampaL(nodo* L)
{
  if(L)
   {cout<<L->info<<' '; stampaL(L->next);}
  else
    cout<<endl;
}
 void stampaT(nodo_x* x,int n)
 {
   if(x)
    {
      cout<<"nodo_x n."<<n<<" primo="<<x->fix->val_p<<" ultimo="<<x->fix->val_u<<':'<<"lista=";
      stampaL(x->fix->primo);
      stampaT(x->next,n+1);
    }
 }
nodo* cloneL(nodo*a)//fa copia di lista di tipo nodo
{
  if(a)
    return new nodo(a->info, cloneL(a->next));
  return 0;
}
nodo_x* clone(nodo_x* a)//fa copia di lista di tipo nodo_x
{
  FIFOX *b= a->fix;
  nodo*c=cloneL(b->primo);
  nodo_x* d=new nodo_x;
  d->fix=new FIFOX(c,ult(c),b->val_p, b->val_u,b->n_ele);
  return d;
}

//-----------------------------------------------Funzioni iterative---------------------------------------------------

//PRE=(nodo a contine nodi>k)
FIFOX* estraiFIFOX_it(nodo* a, int k, FIFOX* CODA){
    int conta=0;
    int lunghezzaL=length(a);
    while(a){
        conta++;
        if(conta==k){
            //taglio dopo k elementi percorsi
            nodo* temp = a->next;
            
            CODA->ultimo=a;
            CODA->val_u=a->info;
            CODA->n_ele=conta;
            CODA->ultimo->next=NULL;
            
            return new FIFOX(temp,ult(temp),temp->info,ult(temp)->info,lunghezzaL-k);
        }
        a=a->next;
    }
}//POST=(ritorna FIFOX collegato ad una lista di nodi che parte da va+k+1 nodi)

/*PRE=(N gestisce una lista c orretta di nodi di tipo nodo, chiamiamola L, N->next=0)*/
void partiziona_it(nodo_x* N, int k){
    if(!N || length(N->fix->primo)<=k) return;//se non esiste N || e' gia piu piccolo di k esco
    nodo_x* lavora = N;     //mi salvo un N temporaneo per poterlo scorrere senza perdere il primo puntatore ad N
    while(length(lavora->fix->primo)>k){ //R=(lunghezza lista attualmente puntata da lavora->fix e' maggiore di k)
        //estraggo da lavora una FIFOX che parte dal (k+1)esimo elemento
        FIFOX* temp = estraiFIFOX_it(lavora->fix->primo, k, lavora->fix);
        //lo inserisco in un nodo_x temporaneo
        nodo_x* m1 = new nodo_x();
        m1->fix=temp;
        //collego il tutto al mio lavora attuale
        lavora->next=m1;
        //scorro lavora attuale in avanti
        lavora=lavora->next;
    }
    
}/*POST=(N è il nodo iniziale di una lista di nodo_x tale che i nodi di questa lista gestiscano le sottoliste di L di lunghezza k (a parte l'ultima che può essere più corta) come descritto nell'esempio)*/

/*
1-pre while k intero che va da 0..k e lavora e' nodo_x attuale che punta ad una coda fifox che gestisce una lista corretta e non vuota (dalla quale mi ricavo la lunghezza)
2-vale R
3-esce quando k non e' piu maggiore della lista puntata da lavora attuale

*/

//-------------------------------------------Funzioni ricorsive---------------------------------------------

//PRE=(nodo a contine nodi>k)
FIFOX* estraiFIFOX_ric(nodo* a, int k, FIFOX* CODA, int conta){
    int lunghezzaL=length(a);
    
    if(conta==k){//taglio dopo k elementi percorsi
        nodo* temp = a->next;
        CODA->ultimo=a;
        CODA->val_u=a->info;
        CODA->n_ele=conta;
        CODA->ultimo->next=NULL;
        return new FIFOX(temp,ult(temp),temp->info,ult(temp)->info,lunghezzaL-k);
    }
    
    FIFOX* temp = estraiFIFOX_ric(a->next, k, CODA, conta+1);
}//POST=(ritorna FIFOX collegato ad una lista di nodi che parte da va+k+1 nodi)

/*PRE=(N gestisce una lista c orretta di nodi di tipo nodo, chiamiamola L, N->next=0)*/
void partiziona_ric(nodo_x* N, int k){
    nodo_x* lavora = N; //salvo N da parte
    
    if(!N || length(N->fix->primo)<=k) return;//se non esiste N || e' gia piu piccolo di k esco
    
    FIFOX* temp = estraiFIFOX_ric(lavora->fix->primo, k, lavora->fix, 1);
    nodo_x* m1 = new nodo_x();
    m1->fix=temp;
    lavora->next=m1;
    partiziona_ric(lavora->next,k);
    
}/*POST=(N è il nodo iniziale di una lista di nodo_x tale che i nodi di questa lista gestiscano le sottoliste di L di lunghezza k (a parte l'ultima che può essere più corta) come descritto nell'esempio)*/


main()
{
 cout<<"start"<<endl;
 nodo_x* T1=fai(), *T2=clone(T1);
 int k;
 cin >> k;
 stampaT(T1,0);
 partiziona_it(T1,k);
 stampaT(T1,0);
 partiziona_ric(T2,k);
 stampaT(T2,0);
 cout<<"end"<<endl;
}
