/* Il programma deve calcolare il numero di elementi dell'array A che sono
   minori di 0 (A e' un array di interi a una dimensione con limite qualsiasi).
   Il limite dell'array e' noto.
*/

#include<iostream>
using namespace std;

main()
{
  int A[]={10, 0, -3, 5, -231, 15, 2, 0, -9, -1}; // A ha 10 elementi
  int num_negativi=0;

  // PRE
  for (int i=0; i<10; i++)     // R
    if (A[i]<0) num_negativi++;

  cout << "Ci sono " << num_negativi << " elementi dell'array minori di 0" << endl;
  // POST
}

/* Nota: Assumiamo che num_negativi e' uguale a zero per un array vuoto
         (significa che non ci sono elementi negativi in un array vuoto)

    PRE = (L'array A ha 10 elementi interi)
   POST = (cout=num_negativi, dove num_negativi e' il numero di elementi
          dell'array A[0..9] che sono minori di 0)
      R = (0<=i<=10)&&(num_negativi conta gli elementi negativi in A[0..i-1])

   CORRETTEZZA:
   1) R e' vera la prima volta?
      Si, perche' i=0 (0<=0<=10) e perche' num_negativi=0 (infatti l'array
      A[0..-1] e' vuoto).
   2) R e' invariante?
      R && B = (0<=i<10)&&(num_negativi conta gli elementi negativi in
      A[0..i-1])
      Eseguiamo ora una volta il corpo del ciclo.
      - Se A[i]<0 significa che ci saranno num_negativi elementi minori di 0
        in A[0..i-1], ai quali bisogna aggiungerne uno (appunto A[i]).
        Infatti num_negativi viene incrementato. Ora pero' num_negativi e' il
        numero di elementi negativi di A[0..i].
      - Se A[i]>=0 significa che il numero di elementi minori di 0 in A[0..i]
        e' identico al numero di elementi minori di 0 in A[0..i-1]. Infatti
        num_negativi non viene incrementato. Tuttavia ora num_negativi
        rappresenta il numero di elementi minori di 0 in A[0..i].
      Tutto viene riportato alla "normalita'" (cioe' si dimostra l'invarianza
      di R) grazie al finale incremento della i garantito dal ciclo for.
   3) R && !B => POST?
      R && !B = (i=10)&&(num_negativi conta gli elementi negativi in A[0..9])
      num_negativi viene stampato su cout.
      Questa e' esattamente POST. */
