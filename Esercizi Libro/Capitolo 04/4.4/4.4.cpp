/* Si tratta di leggere dal file "input" una sequenza di caratteri da '0' a '9'
   terminata dal carattere 'a'. La sequenza va interpretata come un valore
   decimale. Quindi se si legge '3' '2' '8' 'a' va costruito il valore double
   0.328. Questo valore va stampato sul file "output". */

#include<fstream>
using namespace std;

main()
{
  ifstream input("input");
  char c;
  double num_dec=0;
  int cont=1;

  // PRE
  input >> c;
  while (c!='a') {     // R
    num_dec = num_dec*10 + (c-'0');
    cont = cont*10;
    input >> c;
  }
  // POST1

  input.close();
  ofstream output("output");

  output << num_dec/cont;

  output.close();
  // POST
}

/* Indichiamo con c1..ck dei caratteri numerici, e con dec[c1..ck] il numero
   decimale formato da tutte queste k cifre, con int[c1..ck] il nuero intero
   formato da tutte queste cifre. Per definizione si ha che dec[0]=int[0]=0.

    PRE = (Il file "input" contiene n caratteri numerici (c1..cn, n>=0) seguiti
          dal carattere 'a')
   POST = (Il file "output" contiene il numero decimale formato dalle n cifre
          presenti su "input" prima di 'a')
  POST1 = (num_dec=int[c1..c(n-1)])&&(cont=10^(n-1))&&(sono stati letti n
          caratteri)
      R = (Sono stati letti n caratteri c1..cn, con n>=0)&&((n>1)=>i caratteri
          c1..c(n-1) sono numerici)&&(num_dec=int[c1..c(n-1)])&&(cont>=1)&&
          &&(cont e' una potenza di 10 tale che, se sono stati letti n caratteri,
          cont=10^(n-1))&&(cn=c)

   CORRETTEZZA:
   1) R e' vera la prima volta?
      E' stato letto un solo carattere, quindi n=1. E' vero che num_dec=int[0]?
      int[0], per definizione, e' uguale a 0. Ed effettivamente num_dec e' 0.
      cont=1 (per inizializzazione) e 1>=1.
      E' stato letto un solo carattere, ed effetivamente cont=10^(1-1)=1.
      E' stato letto un solo carattere, ed esso lo chiamiamo c1, come indicato
      inizialmente. Esso e' stato assegnato a c, quindi effettivamente c=c1.
   2) R && (c!='a') <C> => R?
      Assumiamo come ipotesi R e che c e' diverso da 'a'. Eseguiamo ora una volta
      il corpo del ciclo. Da ipotesi si ha che sono stati letti n caratteri.
      Con la prima istruzione facciamo si che num_dec=int[c1..cn]. Con la seconda
      facciamo si che cont=10^(n-1)*10=10^n.
      Infine viene letto un carattere, per la precisione l'(n+1)-esimo carattere.
      Questo viene assegnato alla variabile c.
      Ma siamo tornati esattamente a R! Infatti sono stati letti n+1 caratteri,
      n+1>=0 (si aveva che n>=0) e di conseguenza n>=1. cn e' sicuramente numerico
      (per ipotesi c!='a'), ma anche c1..c(n-1) lo sono, sempre per ipotesi.
      num_dec=int[c1..cn] (operazione del ciclo), cont>=1 (lo era per ipotesi, e
      poi e' stato anche moltiplicato per 10). Si ha anche che cont=10^n, sempre
      a causa di un'operazione del ciclo. Infine e' stato letto il carattere c, che
      rappresenta proprio l'(n+1)-esimo carattere letto da input.
   3) R && !(c!='a') => POST1?
      R && !(c!='a') = R && (c='a')
      Abbiamo che sono stati letti n caratteri, e c1..c(n-1) sono numerici, mentre
      cn, che e' c stesso, e' uguale ad 'a'. Abbiamo inoltre che cont=10^(n-1).
      Poi num_dec=int[c1..c(n-1)].
      Ma questa e' esattamente POST1!

   POST1 <istruzioni varie> => POST?
   Da POST1 abbiamo ricavato che cont=10^(n-1) e che num_dec=int[c1..c(n-1)].
   Ora ci sono alcune istruzioni da eseguire. Una semplicemente chiude il dile
   di input, la seconda apre quello di output. Cosa viene scritto su quello di
   output? Viene diviso num_dec per cont. Cosa accade? Ricordiamo che num_dec ha
   n-1 cifre. Ricordiamo inoltre che cont e' la potenza (n-1)-esima di dieci.
   Cosa succede se dividiamo un numero di x cifre per 10^x? Otteniamo che la
   virgola e' spostata di x posizioni. Quindi la cifra più significativa del
   numero intero di partenza diventa la prima cifra dopo la virgola ecc.
   Questa e' esattamente POST. */
