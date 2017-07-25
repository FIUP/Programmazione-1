/*
Scrivere una funzione ricorsiva che riceva una lista P per riferimento e una Q per valore (eventualmente vuote). Essa deve restituire attraverso il
parametro P una lista composta da un nodo di P, seguito da un nodo di Q, poi di nuovo un nodo di P e cosi' via. Se una delle due liste finisce prima
dell'altra, i nodi di quella rimasta verranno appesi alla fine della lista da costruire.
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

void alt_mix(nodo* & P, nodo* Q)
{
  // PRE = (P e Q sono due liste corrette, eventualmente vuote, con vP=P)
  if (!P) {
    P=Q;
    return;
  }
  if (!Q) return;
  nodo* t=P->next;
  nodo* s=Q->next;
  P->next=Q;
  Q->next=t;
  alt_mix(P->next->next,s);
  // POST = (P=mix(vP,Q))
}

/*
CASO BASE
Supponiamo di essere nel primo dei casi base, ovvero supponiamo che P (vP) sia una lista vuota. In tale caso viene concatenata a vP la lista Q. E' corretta
questa cosa rispetto alla POST? POST richiede che P sia uguale a mix(vP,Q). Ma mix(vP,Q), nel caso in cui vP sia vuota, P e' esattamente uguale a Q.
Quindi P=Q=mix(vP,Q). Corretto rispetto alla POST.
Supponiamo ora di essere nel secondo dei casi base. Supponiamo cioe' che Q sia una lista vuota. In questo caso non viene fatto nulla. E' corretta rispetto
alla POST questa cosa? La POST afferma che P=mix(vP,Q). Ma essendo vP vuota, mix(vP,Q)=vP. E' vero che P=vP? Si, ce lo dice la PRE. Quindi anche in questo
secondo caso la soluzione e' corretta rispetto alla POST.
PASSO INDUTTIVO
Supponiamo ora che valga PRE e supponiamo inoltre di non essere in nessuno dei casi base. In tal modo avremo che P e Q sono due liste corrette ma sicuramente
non sono vuote (e P=vP). Di conseguenza si avra' che vP=a@vP' e Q=b@Q' (con a e b due generici nodi). Il programma ora non fa altro che concatenare b ad a.
Poi concatena b al resto di P. Quindi ora si ha che P=a@b@vP'
A questo punto viene fatta la chiamata ricorsiva. Se vogliamo utilizzare i risultati di tale chiamata, ovvero se supponiamo vera POST_RIC, dobbiamo prima
dimostrare che vale PRE_RIC = (H e K sono due liste corrette, eventualmente vuote, con vH=H). Che liste vengono passate alla funzione? vP' e Q'. Entrambe
sono liste corrette (perche' sono parte di una lista corretta non vuota), e di conseguenza potrebbero essere anche vuote. Quindi PRE_RIC e' verificata.
Possiamo a questo punto supporre vera POST_RIC, che afferma che vP' sara' trasformata in mix(vP',Q').
Quindi ora abbiamo che: P=a@b@vP' => P=a@b@mix(vP',Q') => P=mix(vP,Q) (si ricordi che a era il primo nodo di vP, e b era il primo nodo di Q). Quindi POST
e' verificata e la dimostrazione e' conclusa.
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
  alt_mix(P,Q);
  stampa(P);
}
