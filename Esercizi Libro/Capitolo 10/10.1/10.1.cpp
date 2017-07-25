/* Scrivere una funzione ricorsiva void reverse() che legge da cin una sequenza di caratteri che termina con ';' e la stampa a video (';' compreso)
   in ordine inverso */


// Nota: indicheremo con w una generica sequenza di caratteri, e con !w la sequenza di caratteri inversa
// PRE = (cin contiene w;)&&(cout e' vuoto)
// POST = (cout contiene ;!w)

void reverse()
{
  char c;
  cin >> c;
  if (c!=';') reverse();
  cout << c;
}

/* CORRETTEZZA
   L'unico caso base e' il seguente: w e' una sequenza vuota di caratteri. Supponiamo dunque di essere in tale caso. Cosa succede? Viene letto da cin un carattere, ma
   questo carattere non puo' che essere ';', in quanto abbiamo assunto (PRE) che cin contiene w; e w e' vuota!
   Quindi, poiche' il carattere letto e' ';', allora viene semplicemente scritto su cout ';'. E' quello che si voleva? Certamente. Infatti l'obiettivo e' quello di
   stampare su cout ;!w. Inoltre si ricordi che cout (per la PRE) e' vuoto. Quindi ';' e' proprio il primo carattere stampato su cout, esattamente cio' che si voleva.

   Passiamo ora al passo induttivo. Supponiamo cioe' di essere al di fuori del caso base. Significa dunque che w non e' vuota. Quindi possiamo dire che w=xw', con x
   sicuramente diverso da ';' (per la PRE). Cosa accade in questo caso? Essendo x diverso da ';', viene invocata la funzione reverse(). Se riusciamo ora a dimostrare
   che vale la PRE_RIC di reverse allora possiamo dire che vale POST_RIC di reverse. PRE_RIC afferma che cin contiene w';. Questa cosa e' verificata in quanto e'
   appena stato letto il carattere x (quindi cin ha un carattere in meno). Inoltre cout e' vuoto (ce lo dice PRE, e non e' ancora stato stampato nulla su cout).
   Quindi possiamo affermare che vale POST_RIC: cout conterra' ora !w'. Viene infine eseguito il cout di x. E' corretta questa cosa? Ragioniamo. All'inizio si aveva
   su cin xw'. Il risultato che noi vogliamo e' !w'x. Ma questo e' esattamente quello che otteniamo: infatti per POST_RIC sappiamo che su cout c'e' !w', e alla fine
   viene stampato anche il carattere x.
