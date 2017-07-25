/* Il programma deve eseguire la seguente sequenza di operazioni: legge dal file
   "input" una sequenza di caratteri numerici tra '0' e '9' che termina con il
   carattere 'a' e converte questa sequenza nel corrispondente valore intero.
   Se non vi e' alcuna cifra numerica da leggere (ovvero c'e' solo il carattere
   'a', allora si scriva 0. */

#include<iostream>
#include<fstream>
using namespace std;

main()
{
  ifstream input("input");
  char c;
  int num=0;

  // PRE
  input >> c;
  while (c!='a') {     // R
    num = num*10 + (c-'0');
    input >> c;
  }
  // POST
  input.close();
  cout << num << endl;
}

/* Chiamiamo c1..ck i caratteri che sono stati letti.
   Se c1..ck sono caratteri numerici, allora indichiamo con int[c1..ck] il
   numero intero formato con le cifre c1..ck.

    PRE = (Il file di input "input" contiene dei caratteri numerici '0'..'9', e
          alla fine di questa sequenza vi e' il carattere 'a')
   POST = (Viene stampato su cout num, ovvero il numero intero formato dai
          caratteri contenuti nel file di input)
      R = (num>=0)&&(c puo' essere un carattere numerico ('0'..'9') o 'a')&&
          &&(sono stati letti k caratteri fino ad ora (c1..ck))&&((k>1)=>i
          caratteri c1..c(k-1) sono numerici)&&((k=1)=>num=0)&&((k>1)=>
          =>num=int[c1..c(k-1)])

   CORRETTEZZA:
   1) R e' verificata la prima volta?
      num=0 per inizializzazione, quindi 0=0, nessun problema.
      c effettivamente puo' essere un carattere numerico oppure 'a'. Questa cosa
      infatti ci e' garantita dalla PRE.
      Essendo stato letto un solo carattere prima del ciclo si ha che k=1. E'
      quindi corretto dire che sono stati letti c1..ck caratteri (o che e' stato
      letto solo c1).
      Essendo k=1 si dovrebbe avere che num=0. E infatti cosi' e', per
      inizializzazione.
      Quindi abbiamo dimostrato che R e' valida la prima volta.
   2) R && (c!='a') <C> R?
      R && (c!='a') = (num>=0)&&(c e' un carattere numerico ('0'..'9')&&(sono
      stati letti k caratteri fino ad ora (c1..ck))&&(i k caratteri sono tutti
      numerici)&&((k=1)=>num=0)&&((k>1)=>num=int[c1..c(k-1)])
      Ora dobbiamo eseguire una volta il corpo del ciclo.
      Con la prima istruzione stiamo ponendo num=int[c1..c(k-1) ck]. Tanto
      sappiamo che il k-esimo carattere letto e' diverso da 'a' (per ipotesi),
      quindi questa cosa la possiamo fare.
      La seconda istruzione del ciclo, invece, legge un nuovo carattere dal file
      di input (il (k+1)-esimo carattere).
      Ma cosi' facendo siamo tornati esattamente a R. Infatti num e' ancora
      maggiore di zero (aggiungere cifre a un numero non gli fa certo cambiare
      di segno), il carattere appena letto con la seconda istruzione pue' essere
      un carattere numerico oppure una 'a' (ce lo assicura la PRE), sono stati
      letti k+1 caratteri (c1..c(k+1)), c1..ck sono sicuramente numerici (lo
      abbiamo assunto come ipotesi all'inizio di questo punto), infine si ha
      che num=int[c1..ck], ovvero num e' formato da tutti i caratteri numerici
      letti prima dell'ultimo.
      Quindi il punto 2 e' verificato.
   3) R && !(c!='a') => POST?
      R && !(c!='a') = R && (c='a') = (num>=0)&&(c='a')&&(sono stati letti k
      caratteri fino ad ora, di cui c1..c(k-1) sono numerici, e ck e' 'a')&&
      &&((k=1)=>num=0)&&((k>1)=>num=int[c1..c(k-1)])
      Noi, con POST, vogliamo che venga stampato num, e che esso sia un numero
      le cui cifre sono esattamente tutti i caratteri numerici che sono stati
      letti da input, prima di 'a'. Effettivamente POST e' verificata. Infatti
      sappiamo per ipotesi che c1..c(k-1) sono caratteri numerici, e che ck e'
      'a'. Sappiamo anche che num e' esattamente int[c1..c(k-1)], esattamente
      quello che volevamo fosse!
      Finita la correttezza. */
