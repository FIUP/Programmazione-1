//Soluzione di S.Righetto

#include<iostream>
using namespace std;

struct nodo{int info ; nodo* next; nodo(int a=0, nodo*b=0){info=a; next=b;}};
struct coda{nodo* primo,* ultimo;coda(nodo*a=0,nodo*b=0){primo=a; ultimo=b;}};

nodo*insric(nodo*ord, nodo *t){
    if(!ord) return t;
    if(ord->info < t->info){
        ord->next=insric(ord->next,t);
        return ord;
    }
    t->next=ord;
    return t;
}

//PRE=(lista(L) è ben formata, lista(ord) è ben formata, siano v_L e v_o i valori iniziali di lista(L) e lista(ord))

void ordric(nodo*&L, nodo*&ord){
    if(L){ //se esiste L
        nodo *t=L; //prendo il primo nodo della lista
        L=L->next; //lista comincia dal successivo
        t->next=0; //stacco il primo nodo
        ord=insric(ord,t); //inserisce in ord il nodo t in modo ordinato
        //PREric=(lista(L->next) è ben formata, lista(ord) è ben formata, siano v_L->next e v_o i valori iniziali di lista(L->next) e lista(ord))
        ordric(L,ord); //chiamata ricorsiva
        //POSTric=(L->next è vuota e lista(ord) è la lista ordinata composta dai nodi di v_L->next ediv_o)
    }    
}
//POST=(L è vuota elista(ord)èla listaordinatacomposta dai nodi div_L ediv_o)
/*
Caso base 1: !L ossia se L è zero allora L è vuota ed è ordinata.
Caso ricorsivo: 
    PRE_ric: dopo le istruzioni t è il nodo che sto esaminando, e lista(L) è il puntatore alla lista(L->next).
    Dopo l'invocazione e l'assegnazione di insord() lista(ord) è sia ordinata che ben formata e contiene tutti gli elementi
    di lista(vOrd) e anche nodo(t). 
    La PREric di ordric è:
        lista(vL->next) è ben formata.
        lista(ord) è ben formata.
    Essa è vera perchè se lista(vL) non è vuoto allora lista(vL->next) sarà ancora una lista ben formata. (è garantita dalla post di insord())
    Dato che PREric è valida la POSTric vale.
    POSTric: 
        lista(vL->next)=0 -> lista(L)=0
        lista(ord) è ordinata.
    lista(L)=lista(vL->next)=0 e nodo(p) è stato spostato in lista(ord) e nodo(p) =nodo(vL).

*/

coda push_beg(coda x, nodo*a);
/*
coda insord(coda c, nodo*n){
    if(c.primo==0){ //se la coda è vuota inserisco il primo nodo
        c= push_beg(c,n);
        return c;
    }
    nodo* temp=c.primo;
    if(c.primo->info>temp->info){ //se l'info della coda è maggiore dell'info del nodo temporaneo
        c= push_beg(c,temp); //aggiungo il temporaneo all'inizio della coda
        return c;
    }
    while(temp->next && temp->next->info < n->info){ //guardo se il nodo successivo esiste, e se il suo campo info è minore del nodo n
        temp=temp->next;    
    }
    n->next= temp->next;
    temp->next=n;
    
    if(!n->next) return c; //se ho finito la lista restituisco la coda ordinata
}

nodo * orditer(nodo*L){
    //nodo * ord=NULL; //puntatore a lista ordinata
    coda c=(NULL,NULL); //uso la coda al posto di nodo*ord
    nodo * tmp; //puntatore a nodo temporaneo
    while(L){//finchè ho elementi nella lista
        tmp=L;
        L=L->next; //vL-1nodo
        tmp->next=0; //stacco un nodo dalla lista 
        c=insord(c,tmp); 
        //L=L->next;
    }
    return c.primo; //ritorno l'inizio della coda, ossia il puntatore al primo nodo della lista ordinata
}*/

coda push_beg(coda x, nodo*a)
{
  if(!x.primo)
    {
      x.primo=x.ultimo=a;
      a->next=0;
      return x;
    }
  a->next=x.primo;
  x.primo=a;
  return x;
}
coda push_end(coda x, nodo*a)
{
  if(!x.primo)
    {
      x.primo=x.ultimo=a;
      a->next=0;
      return x;
    }
  x.ultimo->next=a;
  x.ultimo=a;
  a->next=0;
  return x;
}

/*del while di insord, fai il ciclo finche c'e un nodo successivo && quel nodo è piu piccolo 
di t, fai puntare t al resto di ord->next e ord->next diventa t(cioè il vecchio ord con t aggiunta)
*/

coda insord(coda Q, nodo*t){
    if(!Q.primo) 
        return Q= push_end(Q,t); //se non ho un nodo in coda lo inserisco
    if(t->info <= Q.primo->info) 
        return Q=push_beg(Q,t); //se il nodo t è più piccolo dell inizio della coda lo metto all inizio
    if(t->info > Q.ultimo->info) 
        return Q= push_end(Q,t); // se t è più grande dell'ultimo nodo della coda lo metto alla fine
    nodo*ord=Q.primo;
    while(t->info > ord->next->info ){ //finchè ho un nodo ed esso è più piccolo di t scorro in avanti ---- ord->next &&
        ord=ord->next; 
    } //il prossimo non esiste(improbabile) oppure t è più piccolo o uguale al prossimo nodo
    t->next=ord->next; // il puntatore di t punta al prossimo nodo di ord 
    ord->next=t;
    return Q;
}

//PRE=(lista(L) ben formata, v_L è il valore iniziale di lista(L))
nodo * orditer(nodo*L){  
    coda Q;
    while(L){ //R(L è una lista ben formata)&&(Q.primo è una lista che contiene gli elemnenti di vQ.primo + vL ed è ordinata)
        nodo*t=L;
        L=L->next;
        t->next=0;
        Q=insord(Q,t);
    }
    return Q.primo;
}
//POST=(restituisce la lista composta dai nodi di v_L ordinati rispetto al campo info)

nodo* buildlist(int m)
{
  if(m>0)
    {
      int x;
      cin >> x;
      return new nodo(x,buildlist(m-1));
    }
  return 0;
}
nodo* clone(nodo*L)
{
  if(L)
    return new nodo(L->info,clone(L->next));
  return 0;
}
void stampaL(nodo*L)
{
  if(L)
    {
      cout<< L->info<<' ';
      stampaL(L->next);
    }
  else
    cout<<endl;
}
main()
{
  int  n;
  cout<<"start"<<endl;
  cin>> n;
  nodo*L=buildlist(n);
  stampaL(L);
  nodo*L1=clone(L);
  //cout<<endl;
  nodo*L2=0;
  ordric(L,L2);
  stampaL(L2);
  nodo*y=orditer(L1);
  stampaL(y);
  cout<<"end"<<endl;
}



