/*
Scrivere una funzione void ins_ord_rif(nodo* & Q, char x) che inserisca un nuovo nodo con campo info uguale a x nella lista ordinata Q in modo da produrre una nuova
lista ordinata che andra' restituita attraverso il parametro passato per riferimento.
*/

#include<iostream>
using namespace std;

struct nodo {char info; nodo* next; nodo(char a='\0', nodo* b=0) {info=a; next=b;}};

/*
Notazione:
Sia Q una lista corretta (eventualmente vuota) ordinata in maniera crescente (non strettamente crescente). Sia inoltre x un carattere confrontabile con i nodi della
lista Q. Allora Q(x)=T@x@S, dove T e' una lista corretta (eventualmente vuota) formata dai nodi che hanno campo info strettamente minore di x, e S e' una lista
corretta (eventualmente vuota) formata dai nodi che hanno campo info maggiore o uguale a x.
*/

void ins_ord_rif(nodo* & Q, char x)
{
  // PRE = (Q e' una lista corretta, eventualmente vuota, ed e' ordinata in modo crescente, vQ=Q)&&(x e' un carattere valido)
  if (!Q) {
    Q=new nodo(x);
    return;
  }
  if (x<=Q->info) {
    nodo* t=Q;
    Q=new nodo(x,t);
    return;
  }
  ins_ord_rif(Q->next, x);
  // POST = (Q=vQ(x))
}

/*
CASO BASE
Supponiamo di essere nel primo caso base, ovvero nel caso in cui vQ e' una lista vuota. E' ovvio che vQ(x) sara' una lista contenente il solo nodo x. E infatti la
funzione crea un nodo x e lo assegna a vQ. Quindi alla fine si ha che Q e' una lista con il solo nodo x. E' corretta questa cosa rispetto alla POST? Si, in quanto
questa come detto prima e' esattamente vQ(x).
Supponiamo ora di essere nel secondo dei casi base, ovvero nel caso in cui x e' minore o uguale al campo info del primo nodo della lista vQ. In questo caso la
funzione crea un nuovo nodo x e lo fa diventare il primo nodo di Q. Tutti gli altri li postpone. Quindi ora si ha che Q=x@vQ, con vQ lista i cui nodi sono tutti
maggiori o uguali a x. Ma questa e' esattamente vQ(x), perche' S=vQ e T e' vuota! Quindi POST e' verificata.
PASSO INDUTTIVO
Supponiamo ora di non essere in nessuno dei due casi base: vQ sicuramente non e' vuota (vQ=r@R, con r generico nodo, e R lista) e r<x. Enunciamo PRE_RIC e POST_RIC,
che utilizzeremo fra poco:
PRE_RIC = (Q' e' una lista corretta, eventualmente vuota, ed e' ordinata in modo crescente, vQ'=Q')&&(x' e' un carattere valido)
POST_RIC = (Q'=vQ'(x'))
Cerchiamo ora di verificare se e' valida PRE_RIC al momento dell'invocazione ricorsiva, in modo tale da usare poi POST_RIC. 
ALla funzione viene passata la lista R (che corrisponde a Q' di PRE_RIC) e x (corrisponde a x'). R rispetta PRE_RIC? Certamente, infatti R e' una lista corretta in
quanto era parte di vQ (che era corretta), potrebbe essere vuota (di Q sapevamo solo che esisteva almeno il primo carattere), ed e' ordinata (sempre perche' era
parte di vQ, che era ordinata). Quindi PRE_RIC e' verificata, e possiamo usare POST_RIC. Quest'ultima afferma che R diventa R(x): R=T'@x@S' (vale la notazione
introdotta in precedenza). Quindi ora Q non sara' piu' r@R ma sara' r@R(x)=r@T'@x@S'. T' e' una lista con nodi tutti minori di x. Ma anche r, per ipotesi iniziale, e'
minore di x! Quindi Q e' diventata esattamente Q(x), quello che voleva POST. Quindi la funzione ricorsiva e' corretta.
*/

void stampa(nodo* P)
{
  if (!P) return;
  cout << P->info << ' ';
  stampa(P->next);
}

main()
{
  nodo* Q=new nodo('a', new nodo('c', new nodo('e', new nodo('h', new nodo('p', new nodo('z'))))));
  char x='b';
  ins_ord_rif(Q,x);
  stampa(Q);
  cout << endl;
}
