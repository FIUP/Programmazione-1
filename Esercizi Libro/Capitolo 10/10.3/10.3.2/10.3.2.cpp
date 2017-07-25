/* Si scriva una funziona ricorsiva int conta(char x) che riceve come valore del parametro formale x un carattere, legge da cin una sequenza di caratteri (che
   termina con ';') e restituisce quante volte il carattere x appare tra i caratteri letti. */

// Nota: w rappresenta una sequenza di caratteri, con num(x,w) si indica il numero di occorrenze di x nella sequenza w
// PRE = (cin contiene w;)
// POST = (conta restituisce un intero A t.c. A=num(x,w))

int conta(char x)
{
  char c;
  cin >> c;
  if (c==';') return 0; // caso in cui w e' vuota
  if (c==x) return 1+conta(x); // caso in cui si trova un'occorrennza di x
  else return conta(x);
}

/* CORRETTEZZA
   Partiamo dal primo caso base, ovvero quando w e' una sequenza vuota di caratteri. In questo caso viene restituito 0. POST e' verificata, infatti num(x,w)=0 se la
   sequenza e' vuota. Banale ma vero!

   Passiamo ora al passo induttivo. Sicuramente w non e' vuota. Quindi esiste per forza di cose un carattere k t.c. w=kw'. Ebbene questo k puo' essere uguale ad x
   oppure no.
   - k=x --> Verifichiamo se PRE_RIC (cin contiene w';) e' verificata. Effettivamente lo e'. Infatti, siccome e' stato letto il carattere k, cin conterra' un
     carattere in meno. In particolare, non conterra' piu' w ma w'. Quindi PRE_RIC e' verificata. Quindi possiamo supporre vera anche POST_RIC (conta restituisce un
     intero A t.c. A=num(x,w')). conta rappresenta ora il numero di occorrenze di x in w'. E' giusto restituire dunque 1+num(x,w')? Ovvero e' vero che
     1+num(x,w')=num(x,w)? Certamente, perche' num(x,w)=num(x,k)+num(x,w')=1+num(x,w') (si ricordi che w=kw' e k=x). Quindi POST e' verificata.
   - k!=x --> PRE_RIC e' verificata per lo stesso motivo scritto sopra. Possiamo anche in questo caso supporre vera POST_RIC. Anche in questo caso conta rappresenta
     num(x,w'), ovvero il numero di occorrenze di x in w'. E' dunque giusto restituire esattamente conta? Si, perche' num(x,w)=num(x,k)+num(x,w')=num(x,w'), perche'
     k e' diverso da x.
