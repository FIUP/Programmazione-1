/* Il programma determina la posizione del massimo in un array di interi ad una
   dimensione con limite qualsiasi */

#include<iostream>
using namespace std;

main()
{
  int A[]={10, 0, 5, -12, 45, -9, 23};     // A ha 7 elementi
  int pos_max=0;
  // PRE
  for (int i=1; i<7; i++)     // R
    if (A[pos_max]<A[i]) pos_max=i;
  // POST
  cout << "La posizione dell'intero massimo contenuto nell'array e': " << pos_max << endl;
}

/*  PRE = (A e' un array a una dimesione contenente 7 interi)
      R = (1<=i<=7)&&(A[0..i-1]<=A[pos_max], ovvero pos_max e' l'indice
          dell'array che contiene il numero maggiore fra gli 0..i-1 numeri letti
          fino ad ora)
   POST = (pos_max contiene l'indice dell'intero massimo presente nell'array)

   CORRETTEZZA:
   1) (1<=i(=1)<=7)&&(A[0]<=A[pos_max](=A[0]))
   2) R && (i<7) = (0<=i<7)&&(A[0..i-1]<=A[pos_max])
      Eseguiamo una volta {if (A[pos_max]...; i++;}. I casi saranno due: o
      A[pos_max]<A[i] oppure A[pos_max]>=A[i]. Trattiamoli entrambi. Nel primo
      caso pos_max viene posta uguale ad i, e poi i viene incrementato (i+1). Si
      ottiene che (1<=i+1<=7). Inoltre si ha che A[pos_max]>=A[0..i]. Infatti e'
      sicuramente maggiore di A[0..i-1] per ipotesi, ed e' uguale ad A[i].
      Se invece A[pos_max]>=A[i] allora viene solo incrementato i (i+1). Si ha
      dunque che (1<=i+1<=7). Inoltre sicuramente A[pos_max]>A[0..i] perche' per
      ipotesi A[pos_max]>=A[0..i-1] e vale anche A[pos_max]>=A[i].
      Quindi R vale ancora.
   3) R && !(i<7) = (i=7)&&(A[0..6]<=A[pos_max]). E' esattamente POST. */
