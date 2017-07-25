/*
Scrivere una funzione ricorsiva void del_ord(nodo* & Q, char x) che elimini tutti i nodi con campo informativo uguale ad x dalla lista ordinata Q e che restituisca
la nuova lista attraverso il parametro passato per riferimento.
*/

#include<iostream>
using namespace std;

struct nodo {char info; nodo* next; nodo(char a='\0', nodo* b=0) {info=a; next=b;}};

/*
Notazione:
Sia Q una lista corretta, eventualmente vuota, ed ordinata in modo crescente (non decrescente). Sia inoltre x un carattere confrontabile con i nodi di Q.
Siccome Q e' ordinata, possiamo dire che Q=T@X@S. T, X e S sono liste corrette (eventualmente vuote) e ordinate in modo crescente. X e' una lista i cui nodi hanno
tutti campo informativo uguale ad x. T e' una lista i cui nodi hanno tutti campo informativo minore stretto di x. S e' una lista i cui nodi hanno tutti campo
informativo maggiore stretto di x.
Indichiamo con Q\x la lista T@S.
*/

void del_ord(nodo* & Q, char x)
{
  // PRE = (Q e' una lista corretta, eventualmente vuota, ordinata in modo crescente, e vQ=Q)&&(x e' un carattere confrontabile con i nodi della lista Q)
  if (!Q) return;
  if (Q->info>x) return;
  if (Q->info==x) {
    nodo* t=Q->next;
    delete Q;
    Q=t;
    del_ord(Q, x);
    return;
  }
  del_ord(Q->next, x);
  // POST = (Q=vQ\x)
}

/*
CASO BASE
Supponiamo di essere nel primo caso base (vQ e' una lista vuota). E' ovvio che se vQ e' vuota lo sara' anche vQ\x. Quindi vQ=vQ\x=0. POST e' dunque verificata.
Supponiamo ora di essere nel secondo caso base, ovvero supponiamo che vQ abbia almeno un nodo (vQ=r@R, con r nodo e R lista) e che questo nodo r sia maggiore di x.
Siccome r, che e' il primo nodo di vQ (che e' ordinata in modo crescente) e' maggiore di x, allora anche tutti i nodi di R saranno maggiori di x. Quindi tutta vQ e'
maggiore di x. Quindi Q\x=S (perche' la lista X e la lista T sono vuote). Ma anche Q=vQ=S. Quindi e' vero che Q=vQ\x. POST verificata anche qui.
PASSO INDUTTIVO
Supponiamo di non essere in nessuno dei casi base: vQ e' una lista non vuota (vQ=r@R) ordinata in modo crescente, e r<=x. Dividiamo ora la dimostrazione del passo
induttivo in due casi: 1) x=r 2)x>r.
Scriviamo inoltre PRE_RIC e POST_RIC per poi poterle usare in seguito.
PRE_RIC = (Q' e' una lista corretta, eventualmente vuota, ordinata in modo crescente, e vQ'=Q')&&(x' e' un carattere)
POST_RIC = (Q'=vQ'\x)
Cerchiamo ora di dimostrare che vale PRE_RIC, in modo tale da poter cosi' usare POST_RIC.
1) In questo primo caso viene prima di tutto eliminato il nodo r. Poi alla funzione ricorsiva viene passata la lista R (che corrisponde a Q' nella PRE_RIC): R e'
sicuramente corretta (perche' era parte di Q, che lo era), potrebbe essere vuota (di Q sapevamo solo che aveva almeno il primo nodo), e' ovviamente ordinata (sempre
perche' faceva parte di Q, che era ordinata). x chiaramente era un carattere prima e lo e' anche adesso. Quindi PRE_RIC e' verificata. Per POST_RIC sappiamo che R
diventa R\x. Quindi, di conseguenza, Q diventa R\x (ricordiamo che r e' stato cancellato). E' corretta rispetto alla POST questa cosa?
Ricordiamo che vQ=r@R. Togliere tutte le x a vQ o a r@R e' dunque la stessa cosa. Ma togliere le x a r@R e' come scrivere R\x (perche' r=x). Quindi Q=R\x=vQ\x. POST
verificata!
2) Supponiamo ora che r<x. Chiaramente si ha sempre vQ=r@R, perche' valgono le ipotesi di prima. R e' corretta ed eventualmente vuota (oltre che ordinata), quindi la
si puo' scrivere come R=T'@X'@S'. Se le x ci sono in vQ allora esse saranno sicuramente in R (quindi in X'), perche' r!=x. Quindi togliere le x a vQ o a R sara' la
stessa cosa. Quindi vQ\x=r@R\x. E infatti la funzione restituisce proprio questa lista. Quindi POST e' verificata anche in quest'ultimo caso.
La funzione ricorsiva e' dunque corretta.
*/

void stampa(nodo* P)
{
  if (!P) return;
  cout << P->info << ' ';
  stampa(P->next);
}

main()
{
  nodo* Q=new nodo('a', new nodo('c', new nodo('e', new nodo('e', new nodo('e', new nodo('z'))))));
  char x='e';
  del_ord(Q,x);
  stampa(Q);
  cout << endl;
}
