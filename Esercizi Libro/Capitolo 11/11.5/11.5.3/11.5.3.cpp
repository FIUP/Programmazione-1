/*
Scrivere una funzione ricorsiva nodo* del_end(nodo* Q) che elimini l'ultimo nodo dalla lista Q e restituisca col return la lista che resta. Si supponga che Q
inizialmente non sia vuota.
*/

#include<iostream>
using namespace std;

struct nodo {char info; nodo* next; nodo(char a='\0', nodo* b=0) {info=a; next=b;}};

/*
Notazione:
Sia Q una lista non vuota. Allora possiamo scrivere Q come Q=R@a, dove a e' l'ultimo nodo della lista Q e R e' la lista formata dai rimanenti nodi (R puo' essere
eventualmente anche vuota.
*/

nodo* del_end(nodo* Q)
{
  // PRE = (Q e' una lista corretta, ma non vuota)
  if (!Q->next) {
    delete Q;
    return 0;
  }
  Q->next=del_end(Q->next);
  return Q;
  // POST = (la funzione restituisce R)&&(il nodo a e' deallocato)
}

/*
CASO BASE
Sappiamo che vale PRE. Supponiamo ora di essere nel caso base, ovvero nel caso in cui Q e' una lista con un solo nodo (quindi R e' una lista vuota). In questo caso la
funzione elimina l'unico nodo di cui e' composta Q e ritorna 0. E' corretta questa cosa rispetto alla POST? Si. Infatti R e' una lista vuota ed e' dunque giusto che
venga restituito 0. Inoltre l'unico nodo di cui e' composta Q (il nodo a) e' stato cancellato. Quindi POST e' verificata.
PASSO INDUTTIVO
Supponiamo innanzitutto di non essere nel caso base (ovvero Q ha piu' di un nodo, e di conseguenza R non e' vuota). Scriviamo ora PRE_RIC e POST_RIC (ci serviranno).
PRE_RIC = (Q' e' una lista corretta, ma non vuota)
POST_RIC = (la funzione restituisce R')&&(il nodo a' e' dealloacato)
Al momento dell'invocazione ricorsiva PRE_RIC e' verificata? Se si, allora possiamo assumere che POST_RIC valga. Cerchiamo quindi di dimostrare questa cosa.
Premessa: R, per ipotesi, e' non vuota, quindi possiamo scrivere R=r@S, con r primo nodo di R e S lista formata dai restanti nodi di R (S puo' essere vuota).
Ma poiche' Q=R@a si ha che Q=r@S@a. Alla fuzione ricorsiva viene passata la lista S@a (Q privata del primo nodo). Quindi S@a corrisponde a Q' di PRE_RIC. Ora ci
dobbiamo chiedere se S@a e' una lista corretta ma non vuota (come vuole PRE_RIC): sicuramente e' corretta (era parte di Q, la quale era corretta) ed e' anche non
vuota, perche' e' vero che S potrebbe essere vuota, ma sicuramente c'e' il nodo a. Quindi PRE_RIC e' verificata. Possiamo assumere che valga POST_RIC.
Essa afferma che a viene cancellato e viene restituita la lista S. Quindi ora si ha che Q=r@S. Ma r@S=R! Quindi restituire Q (cosa che la funzione fa) e' come
restituire R, che e' esattamente quello che la POST richiedeva. Inoltre a e' stato correttamente cancellato. La funzione ricorsiva e' quindi corretta rispetto alla
PRE e alla POST.
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
  Q=del_end(Q);
  stampa(Q);
  cout << endl;
}
