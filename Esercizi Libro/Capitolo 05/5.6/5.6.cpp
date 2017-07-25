/* Il programma deve dichiarare un array C di 10 char e deve leggere dieci
   caratteri dall'input standard negli elementi di C. Dopo di che esamina C per
   vedere se tra i suoi elementi e' presente il carattere 'a'. Se il carattere
   'a' c'e', allora il programma assegna ad una variabile booleana apres il
   valore true e ad un'apposita variabile intera pos assegna la posizione in C
   in cui e' stato trovato. Si tenga conto della prima posizione in cui si
   trova 'a'. Altrimenti il programma assegna ad apres il valore false. */

#include<iostream>
using namespace std;

main()
{
  char C[10];

  for (int i=0; i<10; i++)
    cin >> C[i];

  // PRE
  bool apres=false;
  int pos=0;
  while ((pos<10)&&(!apres)) {     // R
    if (C[pos]=='a') apres=true;
    else pos++;
  }

  if (apres) cout << "La 'a' si trova in posizione " << pos << " nell'array." << endl;
  else cout << "Non ci sono 'a' nell'array";
  // POST
}

/*  PRE = (C contiene 10 caratteri)
   POST = (cout=posizione in cui si trova la prima 'a' nell'array)&&(se 'a' non
          e' presente messaggio di errore)
      R = (0<=pos<=10)&&(apres=>C[pos]='a')&&(non sono presenti 'a' in
          C[0..pos-1])

   CORRETTEZZA:
   1) R e' valida la prima volta?
      pos=0 => 0<=0<=10
      Non ci sono 'a' in C[0..-1] (l'array infatti e' vuoto).
      apres e' false, quindi nulla da controllare.
   2) R e' invariante?
      R && B = (0<=pos<10)&&(apres=false)&&(non ci sono 'a' in C[0..pos-1])
      Eseguiamo ora una volta i corpo del ciclo.
      - Se C[pos]='a' allora questo e' sicuramente la prima 'a' dell'array (ce
        lo assicurano le ipotesi). In questo caso viene settato apres=true (che
        significa che e' stata trovata una 'a').
        Siccome vale che 0<=pos<10 sicuramente vale anche che 0<=pos<=10.
        Ora si ha anche che apres=true. Secondo R si dovrebbe avere che
        C[pos]='a'. Infatti cosi' e', come detto all'inizio.
        In questo caso dunque R e' invariante.
      - Se C[pos]!='a' allora si ha che pos viene incrementato. Siccome si
        aveva che 0<=pos<10, vale di sicuro che 0<=pos+1<=10.
        apres si ricordi e' ancora false (lo e' per ipotesi, e il suo valore
        non e' cambiato). Secondo R dovrebbe a questo punto essere che non ci
        sono 'a' in C[0..pos]. Cosi' e': per ipotesi non ce ne sono in
        C[0..pos-1] e abbiamo appena visto che neanche C[pos]=a.
        Quindi anche in questo caso R e' invariante.
   3) R && !B => POST?
      R && !B = (o (pos=10) o (apres=true))&&(apres=>C[pos]='a')&&(non sono
      presenti 'a' in C[0..pos-1])
      Ci sono vari casi da discutere, vediamoli.
      A) (pos=10)
         A.1) apres=false
              Abbiamo che pos=10 e che non sono presenti 'a' in C[0..9].
              Infatti, siccome apres=false, viene stampato messaggio d'errore.
         A.2) apres=true
              Questo caso non puo' avvenire: infatti o viene incrementato pos
              o viene settato apres=true.
      B) (pos<10)
         Si deve per forza avere che apres=true, altrimenti non si sarebbe
         usciti dal ciclo.
         Si ha che C[pos]='a'. E' la prima 'a' dell'array? Si, ce lo
         assicurano le ipotesi. POST e' verificata, in quanto, essendo
         apres=true, viene stampato pos. */
