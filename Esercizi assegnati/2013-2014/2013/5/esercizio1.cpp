#include <iostream>
#include <fstream>

using namespace std;
/*
  PRE
  il programma legge da un file di input la dimensione di un array 
  a 2 dimensioni e lo riempie disponendo i componenti in righe da 10
  per un massimo di 5 righe.
  Poi cerca la prima riga in cui e' presente un numero pari di 
  caratteri 'a'.
*/
main(){
  char A[5][10];
  int dim,i=0,j=0,conta=0;

  ifstream IN("input1");
  
  IN>>dim;

  while(i<5 && conta<dim){     //si sposta sulle righe fino all'ultimo elemento
    while(j<10 && conta<dim){  //si sposta sugli elementi della righa fino all'ultimo elemento
      IN>>A[i][j];             //l'arrai viene inizializzato dal file di input
      j++;
      conta++;                 //si contano gli elementi caricati
    }
    j=0;                       //si azzera l'indice perche' sulla nuova riga si riparte dal primo
    i++;
  }
  
  conta=0;                     //si azzerano tutti i contatori per poter ricominciare la lettura dell'array
  i=0;
  j=0;
  int contaA;                  //contatore per i caretteri 'a'
  bool trovato=false;          //variabile per la conferma di un numero pari di caratteri 'a'
  

  /*
    i<=0<=5 && 0<=j<=10 && 0<=conta<=dim &&
    trovato=false l'ultima riga non aveva 'a' pari --> si prosegue alla riga successiva &&
    trovato=true l'ultima riga aveva 'a' pari --> si esce dal ciclo
  */
  while(i<5 && conta<dim && !trovato){
    contaA=0;
    while(j<10 && conta<dim){
      if(A[i][j]=='a')
	contaA++;
      j++;
      conta++;
    }
    if(contaA%2==0){
      trovato=true;
    }
    j=0;
    i++;
  }

  ofstream OUT("output1");
  if(trovato)
    OUT<<true<<" "<<i-1;
  else
    OUT<<false;
}//fine main
/*
  POST
  il file di uscita e' composto:
   - in caso sia presente una riga con un numero pari di 'a' da il valore true
     e l'indice della riga
   - in caso non sia presente dal valore false
*/
