/* Il programma deve leggere dall'input standard dei caratteri e man mano che li
   legge li scrive sull'output standard. Il programma deve continuare a leggere
   e stampare caratteri per tutto il tempo in cui nessuna delle tre seguenti
   condizioni e' vera (cioe' la lettura termina quando una delle tre condizioni
   diventa vera):
   a) ha letto due caratteri 'a' (anche non di seguito)
   b) ha letto due caratteri 'b' (anche non di seguito)
   c) ha letto un carattere 'a', un 'b' ed un 'c' (anche non di seguito e non
      necessariamente nell'ordine specificato, quindi, per esempio, il caso si
      applica anche sw e' stato letto prima 'c', poi 'a' e poi 'b').
   Non appena una di queste condizioni e' vera, il programma deve terminare
   stampando la corrispondente stringa "caso a", "caso b" o "caso c" a seconda
   del caso che e' diventato vero. Il programma deve sempre stampare tutti i
   caratteri che legge dall'input standard. */

#include<iostream>
using namespace std;

main()
{
  char car;
  int a=0, b=0, c=0;

  // PRE
  while ((a!=2) && (b!=2) && ((a!=1) || (b!=1) || (c<1))) {     // R
    cin >> car;                                                 // su R e' fondamentale dire che al piu' si verifica solo una delle tre condizioni di uscita
    cout << car << endl;                                        // altrimenti risulta impossibile dimostrare POST1
    if (car=='a') a++; else
      if (car=='b') b++; else
        if (car=='c') c++;
  }
  // POST1

  if (a==2) cout << "caso a" << endl; else
    if (b==2) cout << "caso b" << endl; else
      cout << "caso c" << endl;
  // POST
}

/* Nota: Chiamiamo k1..kn gli n caratteri letti fino ad un certo punto

    PRE = (Vengono letti dei caratteri da cin)
   POST = (A seconda del verificarsi dei casi a, b, c, viene stampato su cout la
          corrispettiva stringa "caso a", "caso b" o "caso c")
  POST1 = (Deve essere verificato uno solo dei tre casi)
      R = (0<=a<=2)&&(0<=b<=2)&&(c>=0)&&(se sono stati letti n caratteri da cin,
          si ha che per i caratteri k1..k(n-1) non si verifica nessuno dei tre
          casi descritti in precedenza, ovvero non ci sono due 'a', non ci sono
          due 'b' e non ci sono contemporaneamente una 'a', una 'b' e una 'c')&&
          &&((n>=1)=>car=kn)&&(tutti i caratteri letti fino ad ora sono stati
          stampati su cout)&&(a,b,c sono le occorrenze di, rispettivamente, 'a',
          'b' e 'c' fra gli n caratteri letti)&&(al più si verifica una delle
          tre condizioni di uscita)

   CORRETTEZZA:
   1) R e' vera la prima volta?
      Si ha che a=0, b=0 e c=0 (per inizializzazione variabili). Quindi e'
      ovvio che a e b sono comprese tra 0 e 2, e che c e' maggiore o uguale a
      zero. Inoltre non sono ancora stati letti caratteri, quindi e' altrettanto
      ovvio che per i caratteri precedenti non si verifica nessuno dei tre casi
      (semplicemente perche' non ci sono caratteri precedenti).
      Infine non ci sono caratteri letti, e infatti non e' stato stampato nulla.
      Sono stati inseriti 0 caratteri, ed effettivamente a, b e c sono tutti
      uguali a zero (non ci sono occorrenze dei relativi caratteri)
      Nessuna dei tre casi e' vero. Quindi e' giusto dire che al piu' e' vero
      uno di essi.
      Quindi effettivamente R e' vera la prima volta.
   2) R && B (con B condizione di permanenza) <C> => R?
      R && B = (0<=a<2)&&(0<=b<2)&&(per i caratteri k1..kn non si verifica
      nessuno dei tre casi)&&(sono stati letti n caratteri)&&(car=kn)&&(fra gli
      n caratteri non ci sono contemporaneamente una 'a', una 'b' e una 'c')&&
      &&(sono stati letti n caratteri e sono stati stampati tutti su cout).
      Eseguiamo ora una volta il corpo del ciclo.
      Viene letto un ulteriore carattere (l'(n+1)-esimo) e viene assegnato a
      car (quindi car=k(n+1)). Questo (n+1)-esimo carattere viene poi stampato
      su cout. A questo punto si controlla (tramite tre condizionali annidati)
      se car e' uguale ad 'a', 'b' o 'c'. In ognuno di questi casi aumenta a,
      b o c di 1. Giunti a questo punto ci sono 4 casi da studiare: i casi in
      cui car sia uno dei caratteri sopra citati e il caso in cui non lo sia.
      Nei primi tre casi si verifica facilmente che R e' ancora verificata. In
      particolare, per ipotesi si aveva che 0<=a<2, e quindi un eventuale a++
      implica 0<=a+1<=2 (del tutto concorde con R). Stessa cosa vale nel caso
      sia incrementato b. La condizione su c e' che deve essere semplicemente
      maggore o uguale a zero, quindi non ci sono problemi. Nel caso nessuno dei
      tre venga aumentato e' ancora piu' semplice verificare che le condizioni
      sopra citate vengono rispettate (infatti, se e' vero che 0<=a<2, e' ovvio
      che vale anche 0<=a<=2, e stessa cosa per b e c).
      Ora si ricordi che sono stati letti n+1 caratteri. Ma siccome siamo
      entrati nel ciclo quando ne avevamo letti solo n, e' sicuramente vero che
      per i primi n caratteri non si era verificato nessuno dei tre casi.
      car, come visto prima, contiene l'ultimo carattere letto (k(n+1)). Infine,
      tutti i caratteri letti sono stati stampati. Infatti per ipotesi i primi n
      caratteri erano gia' stati stampati, e poi in questo ciclo abbiamo prima
      letto k(n+1) e subito dopo stampato.
      Si noti che grazie agli if annidati (può avvenire solo uno di essi)
      possiamo affermare con certezza che una volta che il ciclo ricomincia
      potra' verificarsi al piu' uno solo dei tre casi. Infatti inizialmente
      non ne valeva nemmeno uno, e poiche' i condizionali modificano solo una
      singola cosa, al massimo si avrà che uno di questi casi si verifica.
      Quindi, in conclusione, R e' verificata nuovamente!
   3) R && !B => POST1?
      Se si verifica R && !B significa che o a=2, o b=2 o contemporaneamente si
      ha che a=b=1 e c>0. Chiaramente questi tre casi non possono avvenire
      insieme, perche' viene letto un carattere alla volta, e quindi, per
      esempio, non puo' aumentare allo stesso tempo sia a che c. Questa cosa,
      comunque, ci viene confermata anche dall'invarianza, che afferma che può
      avvenire solo uno dei tre casi sopra citati.
      (a=2)=>caso a, (b=2)=>caso b, (a=b=1 && c>0)=>caso c
      Quindi POST1 e' verificata

   POST1 <istruzioni> => POST?
   Grazie a tre condizionali anidati viene stampato su cout "caso a", "caso b" o
   "caso c" a seconda di cosa si e'verificato su POST1.
   Quindi abbiamo ottenuto esattamente POST. */
