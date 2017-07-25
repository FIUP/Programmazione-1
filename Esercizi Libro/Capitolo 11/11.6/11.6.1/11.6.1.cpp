/*
Scrivere una funzione ricorsiva nodo* ins_ord(nodo* Q, char x) che inserisca un nuovo nodo con campo info uguale ad x nella lista ordinata Q in modo da produrre una
nuova lista ordinata che andra' restituita col return. La lista e' ordinata in modo crescente.
*/

#include<iostream>
using namespace std;

struct nodo {char info; nodo* next; nodo(char a='\0', nodo* b=0) {info=a; next=b;}};

/*
Notazione:
Sia Q una lista di caratteri corretta e ordinata in modo crescente. Sia inoltre dato un carattere x. Indichiamo con Q(x) la lista Q alla quale e' stato aggiunto il
nodo contenente x. Q(x) e' ancora ordinata. Diciamolo ora in maniera piu formale.
Sia Q una lista corretta e ordinata in modo crescente. Sia x un carattere. Poiche' ogni nodo della lista Q e' confrontabile con il carattere x, si ha che Q=T@S, con
T e S due liste tali che ogni nodo di T ha campo info minore di x, e ogni nodo di S ha campo info maggiore o uguale a x.
Quindi indichiamo con Q(x) la lista T@x@S. Chiaramente Q(x) e' ordinata.
*/

nodo* ins_ord(nodo* Q, char x)
{
  // PRE = (Q e' una lista corretta, quindi eventualmente vuota, ed e' ordinata in modo non decrescente)&&(x e' un carattere valido)
  if (!Q) {
    Q=new nodo(x);
    return Q;
  }
  if (x<=Q->info) {
    nodo* t=Q;
    Q=new nodo(x,t);
    return Q;
  }
  Q->next=ins_ord(Q->next, x);
  return Q;
  // POST = (la funzione restituisce Q(x))
}

/*
CASO BASE
Supponiamo di essere nel primo dei casi base, ovvero nel caso in cui Q e' una lista vuota. E' assolutamente ovvio che se Q e' vuota, allora Q(x) e' una lista formata
dal solo nodo x. Infatti la funzione crea semplicemente un nuovo nodo x, e ritorna tale lista. POST quindi e' soddisfatta.
Supponiamo ora di essere nel secondo dei casi base, ovvero nel caso in cui x e' minore o uguale del primo nodo della lista Q. Il primo nodo di Q chiaramente esiste,
perche' in caso contrario ci saremmo fermati all'esecuzione del primo fra i casi base disponibili. Qui la funzione crea un nuovo nodo x e lo mette in prima posizione,
postponendo tutti gli altri. Poi ritorna la lista cosi' formata. Questa cosa rispetta la POST? Ovvero tale lista restituita e' davvero Q(x)?
Certamente. La lista T (formata dai nodi minori di x) e' vuota (essendo x in prima posizione), ed e' giusto che sia cosi' perche' la lista Q e' ordinata, e se
nemmeno il primo nodo e' minore stretto di x allora significa che non ce ne sara' nessuno. Al contrario, la lista S (contenente i nodi maggiori o uguali a x)
contiene tutti i nodi di Q, ed e' giusto che sia cosi' perche' Q e' ordinata, e se il primo nodo di Q e' maggiore o uguale a x, allora significa che ogni nodo di Q e'
maggiore o uguale a x. Quindi, in conclusione, la lista x@S che viene restituita e' esattamente Q(x), come richiesto dall POST.
PASSO INDUTTIVO
Supponiamo ora di non essere in nessuno dei due casi base. Quindi Q ha almeno un nodo (possiamo scrivere Q=r@R) e x e' maggiore stretta del primo nodo di Q.
Enunciamo ora PRE_RIC e POST_RIC, che utilzzeremo in seguito.
PRE_RIC = (Q' e' una lista corretta, eventualmente vuota, ed e' ordinata in modo non decrescente)&&(x' e' un carattere valido)
POST_RIC = (la funzione restituisce Q'(x))
Alla funzione ricorsiva vengono passati la lista R (ricordiamo che Q=r@R perche' ha almeno il primo nodo) e il carattere x. Essi corrispondono dunque a Q' e x' di
PRE_RIC. Cerchiamo ora di verificare se PRE_RIC vale davvero, perche' in questo caso possiamo pensare vera POST_RIC. R' e' corretta e ordinata in modo crescente?
Certamente e' corretta, perche' era parte di Q, che a sua volta lo era. R potrebbe essere anche vuota, in quanto di Q sapevamo solo che aveva sicuramente il primo
nodo. E' ordinata per lo stesso motivo: era parte di Q, che a sua volta era una lista ordinata. Quindi PRE_RIC e' verificata.
Sara' a questo punto vera POST_RIC: viene restituita la lista R(x). La funzione a questo punto trasforma R in R(x). Di conseguenza Q non sara' piu' r@R ma r@R(x).
Nota: R(x)=T'@x@S'. => Q=r@T'@x@S'. Ma T' e' la lista che contiene nodi minori di x. Ma anche r e' minore di x! Quindi effettivamente Q rappresenta Q(x), e POST e'
verificata. La funzione ricorsiva e' esatta.
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
  Q=ins_ord(Q,x);
  stampa(Q);
  cout << endl;
}
