#include <iostream>
#include <fstream>
using namespace std;

/*PRE
  il programma legge da un file di input:
  -dim, la dimensione di un array
  -i suoi elementi
*/

main(){
  int A[100],dim,i=0;
  int lung=0,posI=0,posF=0;
  bool minore=false;

  ifstream IN("input2");
  IN>>dim;            // viene letto il numero di elementi dell'array

  while(i<dim){       // il ciclo inizializza l'array
    IN>>A[i];         // con gli elementi del file input2
    i++;             
  }//fine while 
  
  i=0;                //l'indice viene riportato a 0 in quanto ora ha valore i=dim

  while(i<dim){           //si scorrono tutti i valori
    if(A[i]<=A[i+1]){     //si verifica se il valore e' minore del prossimo
      if(!minore){        //se minore e' FALSA vuol dire che c'e' gia
	lung=0;           //stata una sott.seq. quindi si annulla il contatore
      }                   //della lunghezza della seq 
      minore=true;        //minore diventa VERO perche' siamo in una sott.seq
      lung++;             //si incrementa la dim della sott.seq
    }//fine if
    else{                 //il valore e' maggiore del successivo
      if(minore){         //se minore e' VERO stiamo uscendo da una sott.seq.
	minore=false;     //allora minore viene modidicato in FALSO
	if(lung>(posF-posI)){ //si verifica se la sott.seq dalla quale si e' usciti e' maggiore dell'ultima trovata. La prima ha ha lunghezza 0
	  posI=i-lung; //si aggiorna la posizione iniziale a quella della nuova sott.seq maggiore della precedente
	  posF=i;      //si aggiorna la posizione finale a quella della nuova sott.seq maggiore della precedente
	}
      }//fine if
    }//fine else
    i++;               //si incrementa l'indice che si sposta sull'array A
  }//fine while

  ofstream OUT("output2");
  OUT<<posI<<" "<<posF; //si scrive l'uscita inserendo la posizione iniziale e finale della maggiore sott.seq

}//fine main
/*
  POST
  Il file di uscita e' strutturato dai due valori di indice
  inferiore e superiore della maggiore sottosequenza crescente
*/
