/* Realizzare un programma che legge 10 interi dall'input standard, memorizza
   il minimo e il massimo tra i valori letti e alla fine li stampa sull'output
   standard. Il programma deve avere un ciclo while che esegue 10 volte e che
   dopo aver letto il prossimo intero lo confronta con il massimo ed il minimo
   tra i valori letti in precedenza e li modifica a seconda dei casi. */

#include<iostream>
#include<climits>
using namespace std;

main()
{
  int x, i=0, max=INT_MIN, min=INT_MAX;

  cout << "Inserisci 10 numeri interi" << endl;

  while (i<10)    // R
  {
    cin >> x;
    if (x>max) max=x;
    if (x<min) min=x;
    i++;
  }
  // POST

  cout << "Il valore massimo inserito e' " << max << endl;
  cout << "Il valore minimo inserito e' " << min << endl;
}

/*    R = (0<=i<=10)&&(i=0 => max=INT_MIN, min=INT_MAX)&&(i>0 => max e min
          contengono rispettivamente il valore piu' alto e il valore piu'
          basso fra gli i valori letti fino a quel momento)
   POST = (max contiene il massimo dei 10 valori letti)&&(min contiene il
          minimo dei 10 valori letti)

   CORRETTEZZA:
   1) R e' vera la prima volta?
      i=0 => 0<=0<=10 (verificata 0<=i<=10)
      i=0 ed effettivamente max=INT_MIN e min=INT_MAX (per inizializzazione)
   2) R && (i<10) <C> R?
      R && (i<10) = (0<=i<10)&&(i=0 => max=INT_MIN, min=INT_MAX)&&(i>0 => 
      => max e min contengono rispettivamente il valore piu' alto e il valore
      piu' basso fra gli i valori letti fino a quel momento)
      Eseguiamo ora una volta il corpo {cin >> x; if (x>max)...i++;}
      x contiene un valore (compreso tra INT_MIN e INT_MAX). Se (x>max) allora
      x diventa il nuovo valore massimo e quindi max=x. Se (x<min) allora x
      diventa il nuovo valore minimo. Se x non è maggiore di max e x non e'
      minore di min allora max e min rimangono inalterati (ma, come afferma
      R && (i<10), essi contengono comunque valore massimo e valore minimo
      trovati fino a quel momento).
      i viene incrementato di 1. Siccome siamo partiti dal presupposto che
      (0<=i<10), ora si può affermare che (0<=i<=10).
      Quindi R vale nuovamente.
   3) R && !(i<10) => POST?
      R && !(i<10) = (i=10)&&(i=0 => max=INT_MIN, min=INT_MAX)&&(i>0 => max e 
      min contengono rispettivamente il valore piu' alto e il valore piu' basso
      fra gli i valori letti fino a quel momento).
      Siccome i=10 si ha che R && !(i<10) => (i=10)&&(max e min contengono
      rispettivamente il valore più alto e il valore più basso fra i 10 valori
      letti fino a quel momento). Che e' esattamente la post. */
