/* Questa funzione riceve una matrice di dimensione limite_1 * 10 di int e
   restituisce il puntatore al primo elemento della riga la somma dei cui
   elementi e' massima tra tutte le righe della matrice. */

// Attenzione che manca il main(). E' stata scritta solo la funzione.

int *riga_max (int M(*)[10], int limite_1)
{
  //PRE
  int somma_max=0;
  for (int j=0; j<10; j++)             // somma della riga 0 per avere un valore  // R1
    somma_max=somma_max+M[0][j];       // per somma_max
  // POST1

  int riga=0;

  for (int i=1; i<limite_1; i++) {     // scorre le righe  // R2
    int somma=0;
    for (int j=0; j<10; j++) {         // scorre gli elementi di una riga  // R3
      somma=somma+M[i][j];             // somma i vari elementi di una riga
    }
    // POST3
    if (somma>somma_max) {             // se la somma degli elementi della riga corrente
      somma_max=somma;                 // e' maggiore di somma_max, allora somma_max=somma
      riga=i;                          // trovata nuova riga massima, la si memorizza
    }
  }
  // POST2

  return &M[riga][0];
  // POST
}

/*   Nota: Se k e' una riga di M e j0..j9 gli elementi di questa riga, indichiamo con somma[k][j0..j9] la
           somma di questi elementi. In generale, se j e' un generico indice compreso tra 1 e 10, indichiamo
           con somma[k][0..j-1] la somma dei primi (j-1) elementi della riga k in questione.
           La somma di un array vuoto si suppone essere 0 (somma[]=0)

     PRE = (M e' una matrice di dimensioni limite_1 * 10 di interi)&&(limite_1>0)
    POST = (La funzione restituisce un puntatore al primo elemento della riga la somma dei cui elementi
           e' massima tra tutte le righe della matrice)
      R1 = (0<=j<=10)&&(somma_max=somma[0][0..j-1])
   POST1 = (somma_max rappresenta la somma di tutti i 10 elementi della riga 0 di M)
      R2 = (1<=i<=limite_1)&&(riga rappresenta la riga la somma dei cui elementi e' massima tra le righe 0..i-1
           della matrice M)&&(somma_max=somma[riga][0..9])
   POST2 = (riga rappresenta la riga la somma dei cui elementi e' massima tra tutte le righe della matrice)&&
           &&(somma_max rappresenta la somma di tutti i 10 elementi della riga riga di M)
      R3 = (0<=j<=10)&&(somma=somma[i][0..j-1])
   POST3 = (somma rappresenta la somma di tutti i 10 elementi della riga i di M)
 
   CORRETTEZZA 1:
   1) R1 e' verificata la prima volta?
      Essendo j=0, l'array [0..j-1] e' vuoto, e infatti somma_max=somma[0][0..-1]=0.
      Inoltre j=0 e vale 0<=0<=10.
   2) R1 e' invariante?
      R1 && (j<10) = (0<=j<10)&&(somma_max=somma[0][0..j-1])
      Eseguiamo una volta il corpo del ciclo, seguito dall'incremento di j.
      Ne ricaviamo che somma_max diventa somma[0..j]. Ma alla fine del for j viene incrementato e quindi R1
      risulta invariante, in quanto torna ad essere che somma_max=somma[0][0..j-1] (inoltre 0<=j<10 =>
      => 0<=j+1<=10)
   3) R1 && !(j<0) => POST1?
      R1 && !(j<0) = (j=10)&&(somma_max=somma[0][0..9])
      Questa e' esattamente POST1 (somma_max=somma[0][0..9]).

   CORRETTEZZA 3:
   Identica a CORRETTEZZA 1. Infatti POST1=POST3, R1=R3, e anche i corpi dei cicli sono uguali. Cambia solo
   il nome dato a una variabile (somma invece di somma_max) e la riga in questione (la riga i invece della
   riga 0).

   CORRETTEZZA 2:
   1) R2 e' verificata la prima volta?
      i=1 => 1<=1<=limite_1 (limite_1>0)
      riga=0 => fra le righe 0..i-1 (0..0) rientra solo la riga 0. La riga "massima", quindi, non puo' che
      essere la riga 0 (e infatti riga=0)
      somma_max=[0][0..9] perche' si ricordi che vale POST1
   2) R2 e' invariante?
      R2 && i<limite_1 = (0<=i<limite_1)&&(riga rappresenta la riga la somma dei cui elementi e' massima tra le
      righe 0..i-1 della matrice M)&&(somma_max=somma[riga][0..9])
      Eseguiamo ora una volta il corpo del ciclo, seguito dall'incremento della i alla fine.
      somma viene posto a zero. A questo punto, come dimostrato prima, vale POST3, ovvero somma rappresenta la
      somma di tutti i 10 elementi della riga i di M.
      A questo punto ci chiediamo se la somma degli elementi di i (somma) e' maggiore di somma_max (che
      rappresenta la somma della riga massima fra le righe 0..i-1). Se effettivamente lo e', allora si da il
      valore di i a riga (infatti sara' i ora la riga "massima") e si assegna a somma_max il valore di somma
      (in questo modo somma_max diventa (somma[i][0..9]=somma[riga][0..9]).
      Se invece somma<=somma_max, allora si ha sempre che somma_max=somma[riga].
      A questo punto l'unico problema per l'invarianza e' che riga rappresenta la riga "massima" da 0 a i.
      Ma tutto viene riportato "a posto" dall'incremento finale della i.
   3) R2 && !(i<limite_1) => POST2?
      R2 && !(i<limite_1) = (i=limite_1)&&(riga rappresenta la riga la somma dei cui elementi e' massima tra le
      righe 0..limite_1-1 della matrice M)&&(somma_max=somma[riga][0..9])
      Le righe 0..limite_1-1 sono tutte le righe di M. Quindi questa e' esattamente POST2.

   CORRETTEZZA PARZIALE:
   Vale PRE, e successivamente ai cicli vale POST2. Viene poi eseguita l'istruzione return &M[riga][0];
   A questo punto vale POST?
   POST2 ci dice che riga rappresenta la riga la somma dei cui elementi e' massima tra tutte le righe della
   matrice. L'istruzione return &M[riga][0] restituisce l'indirizzo del primo elemento della riga riga.
   Ma questa e' esattamente POST.

   CORRETTEZZA TOTALE:
   L'unico ciclo che potrebbe non avere fine e' quello in cui i cresce da 0 fino a limite_1-1. Tuttavia
   limite_1 e' un numero finito maggiore di 0 (ce lo dice PRE) ed inoltre esso non viene mai modificato
   (inoltre i viene incrementato sempre). Quindi prima o poi e' ovvio che i raggiungera' limite_1. */
