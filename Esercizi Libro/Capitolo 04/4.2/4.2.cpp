/* Il programma calcola il minimo esponente intero tale che 2 elevato a
   quell'esponente sia maggiore o uguale ad un intero positivo letto da cin. */

#include<iostream>
using namespace std;

main()
{
  int x, esponente=0, potenza=1;

  cout << "Digita un valore intero positivo: ";
  cin >> x;

  while (potenza<x) {     // R
    esponente++;
    potenza = potenza*2;
  }
  // POST

  cout << "Il minimo esponente intero tale che 2 elevato a questo esponente sia maggiore o uguale a " << x <<" e': " << esponente << endl; 
}

/*    R = (esponente>=0)&&(potenza>=1)&&(2^esponente=potenza)&&(non esiste un
          intero y (0<=y<=esponente-1) tale che 2^y>=x)&&((potenza>=x)=>esiste 
          y tale che 2^y>=x e y=esponente)
   POST = (esponente e' il minimo intero positivo (esponente >=0) tale che
          2^esponente>=x)

   CORRETTEZZA:
   1) R e' verficata la prima volta?
      esponente=0 (per inizializzazione), e quindi 0>=0.
      potenza=1 (per inizializzazione), e quindi 1>=1.
      2^esponente=2^0=1=potenza
      Sicuramente non esiste un intero y (con 0<=y<=esponente-1) tale che
      2^y>=x, perche' dovrebbe perlomeno valere che 0<=y<=0-1 (impossibile).
      Potenza>=x, con potenza=1 e x intero positivo, implica che x=1. Cosa
      succede se x=1 (cioe' se potenza>=x)? Succede che 2^esponente=2^0=1>=x=1.
      Quindi effettivamente esiste una y tale che 2^y>=x, con y=esponente.
   2) R && (potenza<x) <C> R?
      R && (potenza<x) = (esponente>=0)&&(1<=potenza<x)&&(2^esponente=
      =potenza)&&(non esiste un intero y (0<=y<=esponente-1) tale che 2^y>=x)
      Eseguiamo ora una volta il corpo {esponente++; potenza = potenza*2}.
      L'esponente viene aumentato di 1, e si calcola il doppio di potenza.
      Alla fine di <C> si ha esponente+1, e ovviamente vale esponente+1>0
      (prima dell'incremento era >=0). Quindi si ha, banalmente, che
      esponente>=0.
      Inoltre, poiché potenza e' raddoppiata, ora abbiamo potenza*2.
      Sicuramente vale che potenza*2>1 (prima di <C> avevamo che potenza>=1).
      Quindi, di conseguen<a, vale anche potenza>1/2, e dunque potenza>=1.
      Se prima di <C> valeva 2^esponente=potenza, ora abbiamo che
      2^(esponente+1)=(2^esponente)*(2)=potenza*2. Semplificando il 2 si
      ottiene che 2^esponente=potenza.
      Attenzione pero': raddoppiando potenza non siamo piu' sicuri che
      potenza*2<x. Supponiamo dunque che potenza*2>=x. Ricordando quanto detto
      poco fa si avra' che 2^(esponente+1)>=x. Quindi in questo caso avremmo
      trovato un intero y tale che 2^y>=x, e y=esponente+1. Siamo sicuri però
      che questo e' l'intero minimo tale che valga questa cosa? Si, vedi sotto.
      Si ha che non esiste un intero y (0<=y<=esponente+1-1) tale che 2^y>=x. 
      Di conseguenza non esiste nemmeno y (0<=y<=esponente-1) tale che 2^y>=x.
      Abbiamo ottenuto esattamente R, come volevasi dimostrare.
   3) R && !(potenza<x) => POST?
      R && !(potenza<x) = (potenza>=x)&&(esponente>=0)&&(2^esponente=potenza)&&
      &&(non esiste un intero y (0<=y<=esponente-1) tale che 2^y>=x)&&(esiste y
      tale che 2^y>=x e y=esponente)
      Questo sicurmanete implica la POST. Infatti esiste un y tale che 2^y>=x e
      y=esponente. E' il minimo esponente tale che valga questa cosa? Si, ce lo
      assicurano le ipotesi, che affermano che non esiste un tale numero
      nell'intervallo 0..esponente-1. */
