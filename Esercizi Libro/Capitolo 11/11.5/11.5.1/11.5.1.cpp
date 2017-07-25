/*
Scrivere una funzione nodo* pop(nodo* Q) che elimini il primo nodo della lista data Q e restituisca col return quello che resta della lista. Il nodo deallocato va
eliminato con delete. Si puo' assumere che inizialmente la lista Q non sia vuota
*/

#include<iostream>
using namespace std;

struct nodo {char info; nodo * next; nodo(char a='\0', nodo * b=0) {info=a; next=b;}};

/*
Notazione:
Sia Q una lista corretta non vuota. Allora scriviamo Q come a@Q', dove a e' un generico nodo e Q' una lista corretta (eventualmente vuota) formata dai restanti
nodi di Q.
*/

nodo* pop(nodo* Q)
{
  // PRE = (Q e' una lista corretta non vuota)
  nodo* t=Q->next;
  delete Q;
  return t;
  // POST = (la funzione restituisce Q')&&(a viene eliminato)
}

/*
CORRETTEZZA
Supponiamo valga PRE (ovvero supponiamo che Q sia una lisa corretta ma non vuota). Significa che Q ha almeno un nodo, e quindi Q puo' essere scritta come a@Q', con a
generico nodo e Q' il resto della lista (Q' puo' essere anche vuota). La funzione ricorda innanzitutto Q', poi elimina il nodo a, e infine restituisce la lista Q'.
Questo e' esattamente quanto richiesto da POST.
*/

void stampa(nodo* P)
{
  if (!P) return;
  cout << P->info << ' ';
  stampa(P->next);
}

main()
{
  nodo* Q=new nodo('a', new nodo('b', new nodo('c', new nodo('d', new nodo('e', new nodo('f', 0))))));
  Q=pop(Q);
  stampa(Q);
  cout << endl;
}
