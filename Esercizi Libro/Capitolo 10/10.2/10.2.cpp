/* Realizzare una funzione ricorsiva int conta() che legge da cin una sequenza di caratteri fino a trovare ';' e conta quanti caratteri diversi da ';' sono letti. */

// Nota: w e' una sequenza di caratteri, lung(w) e' il numero di caratteri della sequenza w
// PRE = (cin contiene w;)
// POST = (conta restituisce un intero A t.c. A=lung(w))

int conta()
{
  char c;
  cin >> c;
  if (c=';') return 0; // caso base
  return 1+conta();
}

/* CORRETTEZZA
   Cominciamo con il discutere il caso base. Supponiamo dunque che w e' una sequenza vuota (dunque lung(w)=0). In questo caso il carattere c che viene letto sara'
   sicuramente uguale a ';' (ce lo dice la PRE --> cin contiene w;, ma w e' vuota). Quindi conta restituisce 0. E' esatto? Certamente. Infatti noi ci aspettiamo che
   venga restituito un intero che rappresenta il numero di caratteri contenuti in w. Ma essendo w vuota e' giusto che venga restituito 0.

   Passiamo ora al passo induttivo. Supponiamo che non si verifichi il caso base, ovvero supponiamo che w non e' vuota. Dunque si avra' che esiste sicuramente un
   carattere x t.c. w=xw'. Questo carattere x viene letto. Esso sara' sicuramente diverso da ';' (per ipotesi). Quindi viene restituito 1+conta(). Ma conta() cosa
   restituisce? Dobbiamo dimostrare che a questo punto vale PRE_RIC di conta. Se effettivamente vale, allora possiamo dire che vale anche POST_RIC.
   PRE_RIC afferma che cin contiene w';. E infatti cosi' e': Siccome e' stato letto un carattere non si avra' piu' w (come da PRE) ma w'. Quindi PRE_RIC e' verificata
   e si puo' assumere che vale POST_RIC: conta restituisce un intero A t.c. A=lung(w').
   Ritorniamo ora alla nostra funzione principale, la quale si era detto restituiva 1+conta (ovvero 1+lung(w')). Questo risultato e' dunque corretto. Infatti ci
   aspettiamo che questo risultato rappresenti lung(w). Ma w=xw', e quindi lung(w)=lung(x)+lung(w')=1+lung(w') --> Esattamente quello che viene restituito.
*/
