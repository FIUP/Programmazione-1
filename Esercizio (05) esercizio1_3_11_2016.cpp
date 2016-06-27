#include<iostream>
using namespace std;
//PRE=(cin contiene almeno 20 interi oppure  contiene due -1 consecutivi)
main()
{
  int A[20], n=1;
  bool stop=false;
  cin>>A[0];
  while(!stop && n<20)
  /* R=(0<=n<=20)&&(stop=> letto n+2 valori dove gli ultimi 2 sono -1 -1 e n e. al + 18 i primi n sono in A)
  &&(!stop=> letto n valori che sono in A e tra essi non c'e' -1 -1) */
  {
      cin>>A[n];
      if(A[n]==-1 &&A[n-1]==-1)
         {stop=true;n=n-1;}
      else
        {n=n+1;}
  }
    if(stop)
        cout << "trovata la sentinella, letti " << n << " valori in A";
    else
        cout << "niente sentinella, letti 20 valori in A";

}
//POST=(se ci sono 20 interi in cin senza sentinella allora stampa niente sentinella. letti 20 valori in A. s e

//se invece tra i primi 20 valori c'e' la sentinella allora stampa trovata sentinella, letti n valori in A)


/* R && !stop && n<20

terza parte R && !(!stop && n<20) == R && (stop || n>=20)
a) stop
b) !stop && n>=20 da R abbiamo che n=20 e da R saappiamo che abbiamo letto 20 interi in A
ed essi non contengono la sentinella
*/
