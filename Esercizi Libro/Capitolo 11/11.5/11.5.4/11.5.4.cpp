/*
Scrivere una funzione ricorsiva char del_end_rif(nodo* & Q) che elimini l'ultimo nodo della lista e restituisca la lista rimanente attraverso il parametro Q,
appositamente passato per riferimento, e il campo informativo del nodo eliminato col return. Si deve supporre che inizialmente la lista Q non sia vuota.
*/

#include<iostream>
using namespace std;

struct nodo {char info; nodo* next; nodo(char a='\0', nodo* b=0) {info=a; next=b;}};

/*
Notazione:
Sia Q una lista corretta ma non vuota. Allora possiamo scrivere Q come Q=R@a, dove a e' un generico nodo e R una lista formata dai rimanenti nodi di Q (R potrebbe
essere anche vuota).
*/

char del_end_rif(nodo* & Q)
{
  // PRE = (Q e' una lista corretta, non vuota, e Q=vQ=R@a)
  if (!Q->next) {
    char a=Q->info;
    delete Q;
    Q=0;
    return a;
  }
  return del_end_rif(Q->next);
  // POST = (Q=R e la funzione restituisce il contenuto del carattere a)
}

/*
CASO BASE
Sappiamo che vale PRE (vQ=R@a). Supponiamo a questo punto di essere nel caso base, ovvero nel caso in cui Q ha un solo nodo (quindi R e' una lista vuota). Quindi
vQ=a. A questo punto la funzione memorizza il contenuto di a e poi cancella a stesso. Se Q aveva solo il nodo a, ora che e' stato cancellato ovviamente Q e' vuota.
Infatti si ha che Q=0. Ma si ha anche che Q=R, perche' R per ipotesi e' vuota. Infine viene ritornato il valore dell'unico (e quindi anche ultimo) nodo di vQ.
POST e' quindi verificata.
PASSO INDUTTIVO
Sappiamo che vale PRE e supponiamo di non essere nel caso base (quindi Q ha piu' di un nodo, e di conseguenza R non e' vuota). Enunciamo ora PRE_RIC e POST_RIC.
PRE_RIC = (Q' e' una lista corretta, non vuota, e Q'=vQ'=R'@a')
POST_RIC = (Q'=R' e la funzione restituisce l contenuto del carattere a')
Cerchiamo ora di dimostrare in base a quello che conosciamo se vale PRE_RIC. Se effettivamente fosse cosi' allora possiamo supporre vera POST_RIC.
Premessa: vQ=R@a, con R non vuota. Siccome R e' non vuota allora la possiamo scrivere come R=r@R' (con R' lista corretta eventualmente anche vuota).
Alla funzione viene passata vQ alla quale e' stato tolto il primo nodo. Ma poiche' vQ=R@a=r@R'@a, allora viene passata la lista R'@a (che corrisponde dunque alla
lista Q' della PRE_RIC). R'@a verifica PRE_RIC? Certamente, infatti e' una lista corretta sicuramente non vuota (a causa della presenza del nodo a).
Possiamo dunque supporre vera POST_RIC, che afferma che R'@a viene "trasformata" in R'. Afferma inoltre che viene ritornato il valore del nodo a.
Prima della ricorsione si aveva che Q=r@R'@a. Dopo la ricorsione (lo dice POST_RIC) si ha che Q=r@R'. Ma r@R'=R! Quindi avremo che Q=R, esattamente quello che era
richiesto da POST. Infine POST_RIC affermava che veniva restituito il valore del nodo a. Questo valore non viene alterato e viene ritornato normalmente. Quindi anche
in questo caso POST e' verificata.
*/

void stampa(nodo* P)
{
  if (!P) return;
  cout << P->info << ' ';
  stampa(P->next);
}

main()
{
  nodo* Q=new nodo('a', new nodo('b', new nodo('c', new nodo('d', new nodo('e', new nodo('f'))))));
  char a=del_end_rif(Q);
  stampa(Q);
  cout << endl;
  cout << a << endl;
}
