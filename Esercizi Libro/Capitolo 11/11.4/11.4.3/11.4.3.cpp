/*
Scrivere una funzione ricorsiva nodo* alt_mix(nodo* P, nodo* Q) che riceva per valore due liste (possibilmente vuote) P e Q e restituisca col return una
lista composta da un nodo di P, seguita da un nodo di Q, poi di nuovo un nodo di P e cosi' via. Se una delle due liste finisce prima dell'altra
*/

#include<iostream>
using namespace std;

struct nodo {char info; nodo * next; nodo(char a='\0', nodo * b=0) {info=a; next=b;}};

/*
Notazione: mix(P,Q)
- se P e' vuota mix(P,Q)=Q
- se Q e' vuota mix(P,Q)=P
- altrimenti mix(P,Q)=p@q@mix(P',Q') (con P=p@P' e Q=q@Q')
*/

nodo* alt_mix(nodo* P, nodo* Q)
{
  // PRE = (P e Q sono due liste corrette, eventualmente vuote (vP=P e vQ=Q))
  if (!P) return Q;
  if (!Q) return P;
  nodo* t=P->next;
  nodo* s=Q->next;
  P->next=Q;
  Q->next=alt_mix(t,s);
  return P;
  // POST = (alt_mix restituisce mix(P,Q))
}
/*
CASO BASE
Supponiamo di essere nel primo dei casi base. Supponiamo cioe' che P sia una lista vuota. Viene restituito Q. E' giusto? O meglio, rispetta POST questa
cosa? Si. Infatti POST afferma che deve essere restituito mix(P,Q). Ma mix(P,Q)=Q nel caso in cui P sia vuota. Quindi POST e' verificata.
Supponiamo ora di essere nel secondo caso base. Supponiamo cioe' che Q sia una lista vuota. In questo caso la funzione restituisce P. E' corretta questa
cosa rispetto a POST? Si. Infatti POST afferma che deve essere restituito mix(P,Q). Ma mix(P,Q)=P nel caso in cui Q sia vuota. Quindi POST e' verificata.
PASSO INDUTTIVO
Supponiamo ora di non essere in nessuno dei casi base (e ovviamente sappiamo che vale PRE). Quindi, di conseguenza, siamo sicuri che P e Q hanno almeno un
nodo. Cosa viene fatto in questo caso? Viene concatenato il primo nodo di P (p) con il primo nodo di Q (q). Poi viene concatenato a q il risultato della
chiamata ricorsiva. Per la chiamata ricorsiva abbiamo la seguente PRE_RIC:
PRE_RIC = (P' e Q' sono due liste corrette, eventualmente vuote (vP'=P' e vQ=Q'))
Essa e' verificata al momento della chiamata ricorsiva? Ricordiamo che P=p@restoP e che Q=q@restoQ. Alla funzione vengono passati proprio restoP e restoQ.
Sono due liste corrette? Sicuramente. Infatti esse sono parte di P e Q che, per ipotesi, erano liste corrette (non vuote). Quindi PRE_RIC e' verificata.
Possiamo dunque supporre che valga POST_RIC. Essa afferma che viene restituito mix(P',Q') che, in questo caso, equivale a mix(restoP,restoQ). Questo
risultato viene concatenato a q (che era stato a sua volta concatenato a p). Quindi abbiamo p@q@mix(restoP,restoQ)=mix(P,Q). Questa e' esattamente POST,
quindi la funzione ricorsiva e' corretta.
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
  P=alt_mix(P,Q);
  stampa(P);
}
