/*
Scrivere una funzione ricorsiva nodo* append(nodo* P, nodo* Q) che riceve (per valore) due liste concatenate (possibilmente vuote) P e Q e restituisce col
return la lista P+Q. Nessun nuovo nodo deve essere creato e nessuno deve essere distrutto. Semplicemente le due liste vanno concatenate per farne una sola.
*/

#include<iostream>
using namespace std;

struct nodo {char info; nodo * next; nodo(char a='\0', nodo * b=0) {info=a; next=b;}};

nodo* append(nodo* P, nodo* Q)
{
  // PRE = (P e' una lista corretta, eventualmente vuota)&&(Q e' una lista corretta, eventualmente vuota)
  if (!P) return Q;
  P->next=append(P->next, Q);
  return P;
  // POST = (append restituisce la lista P@Q, dove @ e' simbolo di concatenazione)
}

/*
CASO BASE
Assumiamo valga PRE. Supponiamo inoltre di essere nel caso base, ovvero nel caso in cui P e' una lista vuota. Cerchiamo quindi di verificare se vale POST.
Per la PRE P puo' essere anche vuota. Se lo e' viene restituito Q. E' corretta questa cosa? Rispetta POST? Si. Infatti POST afferma che append deve
restituire P@Q. Ma siccome P e' una lista vuota, P@Q=Q. Quindi il caso base e' corretto rispetto alla POST.

PASSO INDUTTIVO
Introduciamo innanzitutto PRE_RIC e POST_RIC.
PRE_RIC = (P' e' una lista corretta, eventualmente vuota)&&(Q e' una lista corretta, eventualmente vuota).
POST_RIC = (append restituisce la lista P'@Q)
Supponiamo ora di non essere nel caso base. Quindi P e' una lista corretta non vuota. Cerchiamo di dimostrare che in questo caso vale PRE_RIC. Se ci
riusciamo possiamo supporre vera POST_RIC.
Piccola premessa: poiche' P e' non vuota, si ha che P=a@P', con a un generico nodo. Detto questo, cosa fa l'istruzione che contiene l'invocazione ricorsiva?
Semplicemente "appende" al primo nodo di P (che abbiamo chiamato a) il risultato di append(P->next, Q). Ma come si puo' facilmente notare, PRE_RIC e'
verificata. Infatti append viene invocata passando come parametro proprio P' (oltre che Q, invariato). Di conseguenza possiamo supporre vera POST_RIC.
Se supponiamo vera POST_RIC, POST e' verificata? Se si, abbiamo finito.
POST_RIC ci dice che append restituisce P'@Q. L'istruzione P->next=append(P->next, Q) non fa altro che concatenare il nodo a con il risultato di append.
Quindi il risultato finale e' a@P'@Q=P@Q. POST e' verificata, quindi la funzione append e' corretta rispetto a PRE e POST.
*/

void stampa(nodo* P)
{
  if (!P) return;
  cout << P->info << ' ';
  stampa(P->next);
}

main()
{
  nodo* P=new nodo('a', new nodo('b', new nodo('c', 0)));
  nodo* Q=new nodo('d', new nodo('e', new nodo('f', 0)));
  P=append(P,Q);
  stampa(P);
}
