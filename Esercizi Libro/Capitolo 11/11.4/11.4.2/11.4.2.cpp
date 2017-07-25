/*
Scrivere una funzione ricorsiva void append(nodo* & P, nodo* Q) che riceve una lista P (per riferimento) e una lista Q (per valore). Tale funzione deve
restituire una nuova lista P+Q attraverso il parametro nodo* & P passato per riferimento. Nessun nuovo nodo deve essere creato e nessuno deve essere
distrutto. Semplicemente le due liste vanno concatenate per farne una sola.
*/

#include<iostream>
using namespace std;

struct nodo {char info; nodo * next; nodo(char a='\0', nodo * b=0) {info=a; next=b;}};

void append(nodo* & P, nodo* Q)
{
  // PRE = (P e Q sono due liste corrette, eventualmente vuote (con P=vP))
  if (!P) P=Q;
  else append(P->next, Q);
  // POST = (P=vP@Q)
}

/*
CASO BASE
Supponiamo di essere nel caso base, ovvero nel caso in cui P e' una lista vuota (caso contemplato dalla PRE, che afferma che P e' una lista corretta, nel
caso anche vuota). Cosa ne risulta se concateniamo a una lista vuota una generica lista Q? Ne ricaviamo esattamente Q. E infatti P viene posto uguale a Q.
Quindi, in sintesi abbiamo quanto segue: (P=vP=0, Q) => (vP@Q=0@Q=Q) => (P=Q). Quindi POST e' verificata: infatti essa richiede che P=vP@Q. Ma vP@Q=Q.
Quindi e' giusto che a P venga assegnato Q.
PASSO INDUTTIVO
Supponiamo ora di non essere nel caso base. Siccome vale PRE per ipotesi, abbiamo che P e' una lista corretta (sicuramente non vuota) e Q e' una lista
corretta (eventualmente vuota). Viene a questo punto fatta la chiamata ricorsiva append(P->next, Q). Scriviamo a questo punto PRE_RIC e POST_RIC, usando il
fatto che P=a@resto (con a generico nodo, e P' lista corretta eventualmente vuota).
PRE_RIC = (P' e Q' sono due liste corrette, eventualmente vuote (con P'=vP'))
POST_RIC = (P'=vP'@Q')
E' verificata PRE_RIC a questo punto dell'esecuzione? Ricordiamo che P=a@resto. Passare P->next alla funzione e' come passare resto. Quindi resto=P'. E'
vero che P' e' una lista corretta eventualmente vuota? Certamente. Infatti P' e' una parte di P (la quale ha almeno un nodo).
Alla funzione viene infine passato Q. Quindi Q=Q'. Essendo Q lista corretta eventualmente vuota (PRE), lo e' anche Q', essendo uguale.
Quindi, in conclusione PRE_RIC e' verificata.
Possiamo dunque supporre vera POST_RIC, che afferma che P'=vP'@Q. Ma siccome P' e' stata passata per riferimento, "attaccare" Q a P' e' come "attaccare" Q a
P=vP (infatti si ricordi che vP=a@P'). Quindi alla fine abbiamo che P=a@P'@Q=vP@Q. Questa e' esattamente POST.
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
  append(P,Q);
  stampa(P);
}
