/* Il programma deve dichiarare un array C di 10 char e deve leggere i dieci
   caratterei dall'input standard negli elementi di C. Dopo di che esamina C per
   vedere quanti caratteri 'a' ci sono in esso. Il programma infine restituisce
   il numero di 'a' contenuti in C. */

#include<iostream>
using namespace std;

main()
{
  char C[10];

  for (int i=0; i<10; i++)
    cin >> C[i];

  // PRE
  int contatore=0;
  for (int i=0; i<10; i++)     // R
    if (C[i]=='a') contatore++;

  cout << "Nell'array sono presenti " << contatore << " 'a'" << endl;
  // POST
}

/*  Nota: si assume che il numero di 'a' di un array vuoto e' 0

    PRE = (C contiene 10 caratteri)
   POST = (cout=numero 'a' presenti in C)
      R = (0<=i<=10)&&(contatore indica quante 'a' sono presenti in C[0..i-1])

   CORRETTEZZA:
   1) R e' valida la prima volta?
      i=0 (per inizializzazione), e quindi vale che 0<=0<=10.
      contatore conta effettivamente il numero di 'a' in C[0..i-1]? Si, infatti
      contatore=0 (per inizialzzazione) e C[0..-1] e' un array vuoto.
   2) R e' invariante?
      R && B (B=condizione di permanenza) = (0<=i<10)&&(contatore indica quante
      'a' sono presenti in C[0..i-1]
      Eseguiamo ora una volta il corpo del ciclo.
      - Se C[i]='a' allora significa che il numero di 'a' in C[0..i] e'
        superiore di 1 rispetto a contatore (che indica le 'a' in C[0..i-1]).
        Infatti si incrementa contatore di 1. Tuttavia ora contatore indica le
        'a' in C[0..i]! Tutto pero' viene riportato a posto dal fatto che alla
        fine del ciclo i viene incrementato di 1.
      - Se C[i]!='a' allora non viene fatto nulla. Contatore sara' ora il
        numero di 'a' in C[0..i] (rimasto uguale al numero di 'a' in C[0..i-1]).
        Tutto viene riportato alla "normalita'" dall'incremento di i.
      Quindi R e' invariante.
   3) R && !B => POST?
      R && !B = (i=10)&&(contatore indica quante 'a' sono presenti in C[0..9])
      contatore indica proprio quante 'a' ci sono in tutto l'array. Esso viene
      poi stampato su cout. Questa e' esattamente POST. */
