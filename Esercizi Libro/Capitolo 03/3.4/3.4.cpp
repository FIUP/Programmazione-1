/* Scrivere un programma che apre come input un file di testo 3.4.cpp
   (contenente il codice di questo stesso programma) e legge il suo contenuto
   carattere per carattere ricopiando i caratteri letti sul file di output
   standard (il video, associato allo stream cout). */

#include<fstream>
#include<iostream>
using namespace std;

main()
{
  ifstream input("3.4.cpp");
  if (input!=0) {     // se l'apertura ha avuto successo
    while (!input.eof()) {     // R
      char c;
      c=input.get();
      cout << c;
    }
    // POST
    input.close();
  }
  else cout << "errore nell'apertura del file" << endl;
}

/*   R = (eof()=>il contenuto del file e' stato tutto ricopiato sul video)&&
         &&(!eof()=>esiste almeno un carattere contenuto nel file 3.4.cpp che
         non e' ancora stato ricopiato sul video)
  POST = (Tutto il contenuto del file e' stato copiato sul video. Quindi si e'
         arrivati alla fine del file)

  CORRETTEZZA:
  1) R e' verificata la prima volta?
     L'apertura del file ha avuto sicuramente successo.
     Il file può essere vuoto oppure no. Se e' vuoto, allora eof()==true, e R e'
     verificata. Infatti, R afferma che se eof()==true allora il contenuto del
     file e' stato tutto ricopiato sullo schermo. Ma non c'e' contenuto, e
     infatti non e' stato copiato nulla. Se invece il file e' non vuoto si ha
     per forza di cose che !eof(). E R e' ancora verificata, perche' se !eof()
     allora esiste almeno un carattere che on e' ancora stato copiato sullo
     schermo.
  2) R && (!eof()) <C> R?
     R && (!eof()) = (esiste almeno un carattere contenuto nel file 3.4.cpp che
     non e' ancora stato ricopiato sul video.
     Eseguiamo ora una volta il corpo {char c; c=input.get(); cout << c;}: viene
     letto un carattere c dal file di input, e viene scritto sul video. Questo
     potrebbe essere l'ultimo del file, oppure no. Entrambi i casi sono
     nuovamente contemplati da R
  3) R && !(!eof()) => POST?
     R && !(!eof()) = R && eof() = (il contenuto del file e' stato tutto
     ricopiato sul video)&&(eof()). Questa e' esattamente la POST. */
