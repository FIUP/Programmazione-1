/*
Scrivere una funzione char pop(nodo* & Q) che elimina il primo nodo di Q, restituisca la nuova lista attraverso il parametro passato per riferimento e restituisca
anche il campo info del nodo eliminato. Si suppone che inizialmente la lista Q non sia vuota.
*/

#include<iostream>
using namespace std;

struct nodo {char info; nodo* next; nodo(char a='\0', nodo* b=0) {info=a; next=b;}};

/*
Notazione:
Sia Q una lista non vuota. Allora possiamo scriverla come Q=a@Q', dove a e' il primo nodo di Q e Q' rappresenta il resto della lista. Q' puo' essere vuota.
*/

char pop(nodo* & Q)
{
  // PRE = (Q e' una lista corretta, non vuota, e vQ=Q)
  char a=Q->info;
  nodo* t=Q;
  Q=Q->next;
  delete t;
  return a;
  // POST = (Q=vQ')&&(la funzione restituisce il contenuto del campo info del nodo a)
}

/*
CORRETTEZZA
Supponiamo che valga PRE (ovvero supponiamo che Q sia una lista corretta ma non vuota, e poniamo vQ=Q). Siccome vQ e' non vuota, possiamo scrivere (utilizzando la
notazione introdotta in precedenza) vQ=a@vQ'. La funzione prima di tutto memorizza il contenuto del campo info di a. Dopodiche' cancella il nodo a e pone Q=vQ'.
Alla fine restituisce il contenuto del nodo a che era stato memorizzato in precedenza.
Abbiamo dimostrato POST, quindi la funzione e' corretta rispetto a PRE e POST.
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
  char a=pop(Q);
  cout << a << endl;
  stampa(Q);
  cout << endl;
}
