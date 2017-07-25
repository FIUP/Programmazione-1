/* Il programma deve leggere con >> dal file "input" un valore intero positivo
   (direttamente in una variabile dichiarata intera) e deve calcolare la
   rappresentazione binaria interna di questo valore stampandola sul file
   "output". Tuttavia la sequenza va stampata al rovescio (questo serve a
   mantenere semplice l'esercizio). Quindi, per esempio, se nel file "input" e'
   contenuto il numero 30, si deve stampare la sua rappresentazione binaria (che
   e' 11110) al contrario, ovvero 01111. */

#include<fstream>
using namespace std;

main()
{
  ifstream input("input");
  int num;

  input >> num;
  int x=num;
  input.close();

  ofstream output("output");
  // PRE
  if (num==0) output << num;
  else 
    while (x>0) {     // R
      output << x%2;
      x=x/2;
    }
    // POST

  output.close();
}

/* Nota: per trasformare un numero intero positivo in base dieci in un numero in
         base due bisogna continuamente dividere il numero stesso per due e
         prendere i resti della divisione (vanno presi al contrario).

    PRE = (Il file "input" contiene un intero positivo)
   POST = (Il file "output" contiene la rappresentazione binaria del numero
          intero contenuto in "input" scritta al contrario)
      R = (num>=0)&&(num=x+
