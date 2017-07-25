/*
Scrivere una funzione nodo* del_ord(nodo* Q, char x) che elimini dalla lista ordinata Q tutti i nodi (ce ne potrebbero essere 0, 1, e anche piu' di 1) che contengono
campo informativo uguale a x. La nuova lista va restituita col return.
*/

#include<iostream>
using namespace std;

struct nodo {char info; nodo* next; nodo(char a='\0', nodo* b=0) {info=a; next=b;}};

/*
Notazione:
Sia Q una lista corretta, eventualmente vuota, ed ordinata in modo crescente. Sia inoltre x un carattere confrontable con tutti i nodi della lista Q.
Allora possiamo scrivere Q=T@X@S. T, X ed S sono tutte liste corrette, eventualmente vuote. X e' una lista i cui nodi sono tutti uguali ad x. T e' una lista i cui
nodi sono minori strettamnte di x. S e' una lista i cui nodi sono maggiori strettamente di x.
Quindi indichiamo con Q\x la lista Q\x=T@S.
*/

nodo* del_ord(nodo* Q, char x)
{
  // PRE = (Q e' una lista corretta, evenutalmente vuota, ed ordinata in modo crescente)&&(x e' un carattere confrontabile con tutti i nodi della lista Q)
  if (!Q) return 0;
  if (Q->info>x) return Q;
  if (Q->info==x) {
    nodo* t=Q->next;
    delete Q;
    Q=del_ord(t, x);
    return Q;
  }
  Q->next=del_ord(Q->next, x);
  return Q;
  // POST = (la funzione restituisce la lista Q\x)
}

/*
CASO BASE
Supponiamo di essere nel primo caso base (Q e' una lista vuota). E' ovvio che Q\x sara' vuota! Infatti viene restituito 0. POST verificata.
Supponiamo di essere nel secondo caso base (il primo nodo di Q e' maggiore di x). Intanto siamo sicuri che il primo nodo esista, altrimenti ci troveremmo nel primo
caso base. Siccome Q e' una lista ordinata, se il primo nodo di Q e' maggiore di x, allora lo saranno anche tutti gli altri nodi. Quindi non ci potranno essere nodi
uguali ad x in Q (in altre parole Q=S, perche' T e X sono vuote). Q=S, T=0 => Q\x=T@S=S=Q. Infatti la funzione restituisce Q. POST verificata.
PASSO INDUTTIVO
Supponiamo di non essere in nessuno dei casi base. Quindi Q ha almeno un elemento (possiamo dunque scrivere Q=r@R, con r generico nodo e R lista corretta, nel caso
anche vuota) e r<=x. Possono dunque esserci due casi: 1) r=x o 2) r<x.
1) Se r=x significa che S e' una lista vuota (perche' Q per ipotesi e' ordinata, e Q=S@X@T). Scriviamo PRE_RIC e POST_RIC, che useremo fra poco (anche nel caso (2)):
PRE_RIC = (q' e' una lista corretta, eventualmente vuota, ed ordinata in modo crescente)&&(x' e' un carattere)
POST_RIC = (la funzione restituisce la lista Q'\x')
La funzione a questo punto cancella il nodo r (=x) e fa un'invocazione ricorsiva passando la lista R (corrisponde a Q' di PRE_RIC) e x (corrisponde a x'). A questo
punto dell'esecuzione PRE_RIC e' verificata? Se si, possiamo usare POST_RIC. Perche' sia dimostrata dobbiamo mostrare che R e' una lista corretta e ordinata.
Sicuramente e' corretta (perche' faceva parte di Q, che era corretta) e potrebbe essere anche vuota (perche' di Q sapevamo solo che esisteva per forza il primo
carattere). Inoltre e' ordinata perche' Q lo era. Quindi vale PRE_RIC. Possiamo dunque usare POST_RIC: la chiamata ricorsiva restituisce R\x. Questa lista R\x viene
assegnata proprio a R. Quindi R diventa R\x. Quindi ora Q=R\x (perche' r era stato cancellato). Ricordiamo ora che all'inizio Q era r@R. Se togliamo tutte le x da Q
ne ricaveremo proprio R\x (perche' r=x). Quindi Q\x=R\x. Restituire dunque R\x verifica pienamente la POST.
2) Supponiamo ora che r<x. Anche in questo caso all'invocazione ricorsiva vengono passate R ed x. Quindi PRE_RIC e' verificata e possiamo usare POST_RIC. La funzione
restituisce R\x. Ma siccome siamo sicuri che r e' diverso da x, Q\x=r@R\x. Quindi restituire r@R\x (come fa appunto il programma) e' assolutamente corretto rispetto
alla POST.
Quindi la funzione ricorsiva si pu; dire che e' corretta rispetto alla PRE e alla POST.
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
  Q=del_ord(Q,x);
  stampa(Q);
  cout << endl;
}
