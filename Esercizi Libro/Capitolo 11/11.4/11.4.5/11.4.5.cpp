/*
Scrivere una funzione ricorsiva che, data per riferimento una lista P ed un intero k, restituisca due liste: quella composta dai primi k nodi di P e poi quella
composta dai restanti nodi di P (dal (k+1)-esimo in poi). Se P contiene un numero di nodi non maggiore di k, allora la prima lista conterra' tutti i nodi di P e la
seconda sara' vuota. La seconda lista va ritornata con return, mentre la prima va restituita attraverso il parametro P che va passato per riferimento.
*/

#include<iostream>
using namespace std;

struct nodo {char info; nodo * next; nodo(char a='\0', nodo * b=0) {info=a; next=b;}};

/*
Notazione:
Data una lista corretta P, P(k) rappresenta una lista formata dai primi k nodi di P. Inoltre con k(P) si indica cio' che rimane della lista P.
Ora enunciamo questa cosa in maniera piu' formale.
Sia P una lista corretta. P=L@resto (L e' una lista di k nodi, resto e' la lista formata dai rimanenti nodi di P). Allora P(k)=L e k(P)=resto.
*/

nodo* due_liste(nodo* & P, int k)
{
  // PRE = (P e' una lista corretta, eventualmente vuota, e vP=P)&&(k>=0)
  if (!P) return 0;
  if (!k) {
    nodo* t=P;
    P=0;
    return t;
  }
  return due_liste(P->next, k-1);
  // POST = (P=vP(k))&&(la funzione due_liste ritorna la lista k(vP))
}

/*
CASO BASE
Supponiamo ora di essere nel primo dei casi base, ovvero supponiamo che P(=vP) sia una lista vuota (ovvero con 0 nodi). Sappiamo inoltre grazie alla PRE che k>=0.
La POST afferma che deve essere vero che P=vP(k), cioe' P deve essere la lista formata dai primi k nodi di vP. Ma vP e' vuota, dunque non ha senso parlare dei suoi
primi k nodi. vP(k) e' insomma una lista vuota. P=vP(k)=0? Certamente. Quindi il primo caso base e' corretto rispetto alla PRE e alla POST.
Cerchiamo ora di capire se e' giusto che venga ritornato 0. La POST afferma che dovrebbe essere restituita la lista k(vP). Ma come gia' detto vP e' vuota. Quindi
anche k(vP) sara' vuota. Secondo quanto detto dovrebbe essere che la funzione ritorna 0 (=k(vP)). E infatti cosi' e'. Verificata la POST anche in questo caso.
Supponiamo ora di essere nel secondo caso base, ovvero nel caso in cui k=0. Sappiamo che sicuramente P non e' vuota (altrimenti saremmo nel caso base precedente).
Secondo quanto afferma POST si dovrebbe avere che P=vP(0), perche' k=0. Ma vP(0) e' vuota, perche' e' vuota una lista formata da 0 nodi. Infatti il programma pone
P=0. Quindi la prima parte di POST e' verificata. Cerchiamo ora di capire se effettivamente la funzione ritorna la lista k(vP). Per come sono state definite
all'inizio, se vP(k)=0, allora k(vP)=vP. Si dovrebbe quindi avere che la funzione ritorni esattamente vP. E infatti cosi' e'. Quindi anche questo secondo caso base e'
verificato rispetto alla PRE e alla POST.
PASSO INDUTTIVO
Scriviamo ora PRE_RIC e POST_RIC, poiche' ci serviranno fra poco.
PRE_RIC = (P' e' una lista corretta, eventualmente vuota, e vP'=P')&&(k'>=0)
POST_RIC = (P'=vP'(k'))&&(la funzione deu_liste ritorna la lista k'(vP'))
Cerchiamo di dimostrare che a questo punto dell'esecuzione valga PRE_RIC. Sappiamo innanzitutto P e' non vuota. Quindi possiamo scrivere P come a@R (con a
generico nodo, e R lista corretta). Alla funzione viene passata la lista R (P' nella funzione). La lista R rispetta PRE_RIC? Ovvero e' una lista corretta?
Certamente, perche' essa era parte di P, che era corretta e non vuota. Alla funzione viene passato anche k-1 (k' nella funzione). Esso rispetta PRE_RIC? Certo,
perche' per la PRE sappiamo che k>=0, e sappiamo inoltre che k!=0 (caso base). Quindi k>=0 => k-1>0 => k'>=0.
Quindi la PRE_RIC e' verificata: possiamo ora assumere che valga POST_RIC.
Innanzitutto si ha che R=vR(k-1). Ma si ricordi che P=a@R. Quindi P=a@R => P=a@vR(k-1)=vP(k). Questa cosa rispetta esattamente la POST.
Cerchiamo infine di capire se effettivamente la funzione ritorna la lisa k(vP). POST_RIC afferma che l'invocazione ricorsiva restituisce k-1(vR).
All'inizio si era detto che P=a@R. Ma ora R e' diventato vR(k-1) (lo dice la prima parte della POST appena dimostrata). Quindi ora P=a@vR(k-1)=vP(k). Si avra' quindi
che k-1(vR)=k(vP). Quindi, siccome e' proprio questa la lista restituita dalla funzione alla fine, anche la seconda parte della POST e' verificata.
*/

void stampa(nodo* P)
{
  if (!P) return;
  cout << P->info << ' ';
  stampa(P->next);
}

main()
{
  nodo* P=new nodo('a', new nodo('b', new nodo('c', new nodo('d', new nodo('e', new nodo('f', 0))))));
  int k=2;
  nodo* Q=due_liste(P,k);
  stampa(P);
  cout << endl;
  stampa(Q);
  cout << endl;
}
