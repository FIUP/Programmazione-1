#include <iostream>
#include <fstream>
using namespace std;

/*PRE
  il programma legge da un file di input:
  -dim, la dimensione di un array
  -i suoi elementi
  -x, il numero di volte che un valore dovrebbe essere presente
  -y, il valore da cercare
  e cerca se il valore y e' realmente presente x volte
*/

main(){
  int A[100],dim,i=0,x,y;
  int contaY=0;
  int posY[100];
  bool match=false;

  ifstream IN("input1");
  IN>>dim;            // viene letto il numero di elementi dell'array

  while(i<dim){       // il ciclo inizializza l'array
    IN>>A[i];         // con gli elementi del file input1
    i++;
  }//fine while

  IN>>x;              // viene letto il numero di volte che y deve presentarsi
  IN>>y;              // viene letto il valore da cercare
  i=0;
  while(i<dim){       // il ciclo scorre tutti gli elementi dell'array
    if(A[i]==y){      // si cerca l'uguaglianza tra un elemento dell'array e y
      posY[contaY]=i; // si memorizza nell'array posY la posizione degli y in A
      contaY++;       // si conta il numero di volte che y e' stato trovato
    }//fine if
    i++;
  }//fine while

  if(contaY==x)       // si verifica se y era presente tante volte  
    match=true;       // quanto letto da input1
  i=0;
  ofstream OUT("output1");
  OUT<<match;         // l'output varia in base al valore del match
  if(match){          // se VERO oltre a 1 bisogna scrivere in output1    
    while(i<contaY){  // le posizioni in cui y e' stato trovato
      OUT<<" "<<posY[i];
      i++;
    }//fine while
  }//fine if
  else                // se FALSO oltra a 0 bisogna scrivere in output1
    OUT<<" "<<contaY; // il numero di volte che y e' stato trovato
}//fine main
/*
  POST
  il file di output e' strutturato
  dal valore 1 se sono state trovate x istanze di y
  e dalla posizione delle y trovate
  oppure
  dal valore 0 se non sono soddisfatte le condizioni
  e dal numero di y trovate
*/
