/* La funzione riceve una matrice char[limite_1][5]. La funzione deve determinare
   se tra le colonne dalla 1 alla 4 di questa matrice ce n'e' almeno una che
   contiene tutti gli elementi che sono nella colonna 0. Nel caso la risposta sia
   si, la funzione deve restituire al chiamante l'indice (in [1..4]) di una
   qualsiasi delle colonne che contenga la colonna 0. Altrimenti, la funzione
   restituisce 0. */

int trova_colonna (char A[][5], int limite_1)
{
  // PRE
  bool trovato=false;
  for (int i=1; i<4 && !trovato; i++) {     // R1
    bool colonna=true;
    for (int j=0; j<limite_1 && colonna; j++) {     // R2
      bool elemento=false;
      for (int k=0; k<limite_1 && !elemento; k++)     // R3
	if (A[j][0]==A[k][i]) elemento=true;
      //POST3
      if (!elemento) colonna=false;
    }
    // POST2
    if (colonna) trovato=true;
  }
  // POST1
  if (trovato) return i-1;
  else return 0;
  // POST
}

/*  PRE = (A e' una matrice di caratteri di dimensione limite_1 * 5)&&*(limite_1>0)
   POST = (La funzione restituisce l'indice I di una colonna tale che per ogni a
          in 0..limite_1 vale che A[a][0]=A[b][I], con b in 0..limite_1)&&(se I non
          esiste, la funzione restituisce 0)
     R3 = (0<=k<=limite_1)&&(A[0..k-2][i]!=A[j][0])&&(elemento<=>A[k-1][i]==A[j][0])
  POST3 = (elemento dice se il carattere A[j][0] e' presente oppure no sulla colonna i)
     R2 = (0<=j<=limite_1)&&(A[0..j-2][0]=A[a][i] per qualche a in [0..limite_1-1])&&
          &&(colonna<=>A[j-1][0]=A[a][i] per qualche a in [0..limite_1-1])
  POST2 = (colonna dice se la colonna i contiene la colonna 0)

  CORRETTEZZA 3:
  1) R3 e' valida la prima volta?
     k=0 => 0<=k<=limite_1 (limite_1>0 per PRE)
     Essendo k=0, A[0..k-2][i] sono elementi che non esistono, e quindi ovviamente sono
     diversi dall'elemento 0 della riga j)
     elemento e' false per inizializzazione. Infatti si ha che A[k-1][i]!=A[j][0] (la
     riga k-1 non esiste)
  2) R3 e' invariante?
     R3 && B(=condizione di permanenza) = (0<=k<limite_1)&&(A[0..k-1][i]!=A[j][0])
     Eseguiamo ora una volta il corpo del ciclo.
     Se A[j][0]=A[k][i] allora questa e' sicuramente la prima volta che troviamo un
     elemento della colonna i-esima che soddisfa questa condizione (ce lo dicono le
     ipotesi). Siccome lo abbiamo trovato impostiamo elemento=true. Se cosi' non
     fosse non viene fatto nulla. Quindi ora abbiamo che A[0..k-1][i]!=A[j][0] e
     se elemento=true allora si ha anche che A[k][i]=[j][0]. L'incremento della k
     a fine ciclo rimette le cose a posto.
  3) R3 && !B => POST3?
     R3 && !B = (elemento || k=limite)&&(A[0..k-2][i]!=A[j][0])&&(elemento<=>
     <=>A[k-1][i]==A[j][0])
     elemento a questo punto puo' essere true o false. Se e' true allora si ha che
     A[k-1][i]==A[j][0] (sia che k sia uguale a limite_1 sia che non lo sia).
     Se e' false allora si ha per forza che k=limite_1. Quindi ne ricaviamo che
     A[0..limite_1-1][i]!=A[j][0].
     Quindi la presenza o meno di A[j][0] nella colonna i dipende esclusivamente da
     elemento. Questa e' esattamente POST3.

  CORRETTEZZA 2:
  1) R2 e' valida la prima volta?
     j=0 => 0<=j<=limite_1 (limite_1>0 per PRE)
     Essendo j=0, A[0..j-2][0] sono elementi che non esistono, e quindi e' ovvio che
     sono anche elementi della colonna i.
     colonna e' true, e infatti si ha che A[j-1][0] (che e' un elemento non esistente)
     e' contenuto nella colonna i
  2) R2 e' invariante?
     R2 && B = (0<=j<limite_1)&&(A[0..j-2][0]=A[a][i] per qualche a in [0..limite_1-1])
     &&(A[j-1][0]=A[a][i] per qualche a in [0..limite_1])
     Eseguiamo una volta il corpo del ciclo.
     Ricordiamo che qui vale POST3, quindi elemento dice se il carattere A[j][0] e'
     presente oppure no sulla colonna i.
     Chiaramente se elemento=false (A[j][0] non presente nella colonna i) e' giusto
     porre colonna=false, perche' abbiamo trovato un elemento della colonna 0 che non
     e' contenuto nella colonna i.
     A questo punto dell'esecuzione viene incrementato j.
     Quindi si ha che (0<=j<=limite_1)&&(A[0..j-1][0]=A[a][i] per qualche a in
     [0..limite_1-1])&&(colonna<=>A[j][0]=A[a][i] per qualche a in [0..limite_1-1])
     Questa e' nuovamente R2
  3) R2 && !B => POST2?
     R2 && !B = (j=limite_1 || !colonna)&&(A[0..j-2][0]=A[a][i] per qualche a in
     [0..limite_1-1])&&(colonna<=>A[j-1][0]=A[a][i] per qualche a in [0..limite_1-1]).
     A questo punto colonna puo' essere true o false. Se e' false abbiamo che
     A[j-1][0]!=A[a][i] per ogni a in [0..limite_1]. Essendo che abbiamo trovato un
     elemento della colonna 0 che non e' contenuto nella colonna i, colonna giustamente
     e' false (in perfetto accordo con POST2).
     Se invece colonna e' true si ha per forza che j=limite_1. Quindi ne ricaviamo che
     A[0..Limite_1-1][0]=A[a][i] per qualche a in [0..limite_1-1]. Quindi colonna=true
     implica che tutti gli elementi della colonna 0 sono contenuti anche nella colonna.
     Anche questo e' in perfetto accordo con POST2.

  CORRETTEZZA 1:
  Si procede in maniera del tutto analoga a quanto fatto in precedenza (i casi sono
  molto simili). Basta dare per scontate POST3 e POST2. */
