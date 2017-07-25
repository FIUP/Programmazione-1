/*
Scrivere una funzione iterativa che esegua l'operazione di eliminazione da una lista ordinata di tutti i nodi con un dato campo informativo. La funzione deve
restituire al chiamante la nuova lista col return.
*/

#include<iostream>
using namespace std;

struct nodo {char info; nodo* next; nodo(char a='\0', nodo* b=0){info=a; next=b;}};

/*
Notazione:
Sia Q una lista corretta, eventualmente vuota, ordinata in modo crescente. Sia x un carattere. Possiamo allora scrivere Q=T@X@S. T, X e S sono liste corrette ed
eventualmente vuote, oltre che ordinate. X e' una lista i cui nodi hanno tutti campo informativo uguale ad x. T e' una lista i cui nodi hanno tutti campo informativo
minore di x. S e' una lista i cui nodi hanno tutti campo informativo maggiore ad x.
Possiamo dunque scrivere che Q\x=S@T.
*/

nodo* del_iter(nodo* Q, char x)
{
  nodo* P=Q;
  // PRE = (Q e' una lista corretta, eventualmente vuota, ordinata in modo crescente, vQ=Q)&&(x e' un carattere confrontabile con tutti i nodi di Q)
  while (Q && Q->info<=x) {
    if (Q->info==x) {
      nodo* t=Q->next;
      delete Q;
      Q=t;
    }
    else {
      P->next=Q;
      Q=Q->next;
    }
  }
  return P;
  // POST = (Q=vQ\x)
}

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
