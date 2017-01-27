#include <iostream>
#include <fstream>
using namespace std;

/*PRE_F=(X ha 10 posizioni) && (vale caso (i) o caso (ii)), specificati di seguito:
caso (i)= (input1 contiene w -2..., con w = seq. di non più di 10 valori)
caso (ii)=(input1 contiene w1 w2 -2 .., con w2 = seq. di 10 int e w1= seq. non vuota di interi)
*/

void F(int X[], ifstream & INP, ofstream & OUT){
  int sentinella=-2; //nel caso si voglia modificare il valore sentinella
  int conta=0,elemento,inizioarray=0;
  bool trovasentinella=false,arrayciclo=false;

  while(!INP.eof() && !trovasentinella){  
    INP>>elemento;
    if(elemento!=sentinella){
      if(conta==10){
	conta=0;
	arrayciclo=true;
      }
      X[conta]=elemento;
      conta++;
    }//fine if
    else{
      trovasentinella=true;
    }
    if(arrayciclo){
      inizioarray=conta;
    }
  }//fine while
  if(arrayciclo){
    for(int i=0;i<10;i++){
      if(inizioarray+i<10){
	OUT<<X[inizioarray+i]<<" ";
      }
      else{
	OUT<<X[inizioarray+i-10]<<" ";
      }
    }
  }
  else{
    for(int i=0;i<conta;i++){
      OUT<<X[i]<<" ";
    }
  }
}

//POST_F=(nel caso (i) output1 contiene w) &&(nel caso (ii) output1 contiene w2)

//PRE_SEL=(X ha dim elementi definiti e k è definito)&&(X=vX) &&(vdim=dim) vX e vdim sta per vecchio a indicare i valori originali di X e dim

void SEL(int X[], int& dim,int k){
  int i=0;
  while(i<dim){
    if(X[i]==k){
      for(j=i+1;j<dim;j++){
	X[i]=X[j];
      }
      dim--;
    }
    i++:
  }
}

//POST_SEL=(X contiene esattamente tutti i valori di vX diversi da k e nello stesso ordine relativo che avevano in vX) &&(il numero di elementi che restano in X è dim<=vdim)


main(){
  int A[10];
  
  ifstream INP("input1");
  ofstream OUT("output1");
  F(A,INP,OUT);

}//fine main

/*
conta: scorre l'array
trovasentinella: verifica se la sentinella e' stata trovata
arrayciclo: verifica se sono stati letti piu' di dieci valori quando leggi il 10 valore conta viene posto uguale a 0

0<=conta<=10
  && trovasentinella=false
    && arrayciclo=false --> inizioarray=0 && letti meno di 10 valori
    && arrayciclo=true --> inizioarray=conta && letti piu' di 10 valori
  && trovasentinella=true
   1) && arrayciclo=false --> inizioarray=0 && il file di input era formato al massimo da 10 valori
   2) && arrayciclo=true --> inizioarray=conta && letti piu' di 10 valori --> almeno un valore dell'array e' stato sostituito

OUTPUT
in output vengono stampati gli ultimi x elementi letti con 0<x<=10
in base hai casi visti sopra
1) il ciclo di stampa parte dal primo elemento dell'array (X[0]) in quanto sono stati letti al massimo 10 valori e li scorre fino a conta (il numero degli elementi letti, in questo caso) con 0<=conta<=10
2) il ciclo stampa gli ultimi 10 elementi letti e usa come punto di partenza il primo elemento non modificato X[inizioarray] scorre fino a scrivere l'elemento di indice 9 e poi torna al primo, un contatore ferma il ciclo alla 10 scrittura
*/



/*
TEORIA
Il programma funziona e restituisce 1 2 5 come output

X e' un array con elementi X[0]=1,X[1]=2,X[2]=3
q punta a X=1 cioe' alla posizione dopo X[0] quindi X[1]
alla funzione viene dato in input L-valore del puntatore q

nella funzione
x e' un puntatore che punta a q
e p punta a *x+1 quindi alla posizione successiva a quella puntata da q
*p=**x+*p
l'oggetto puntato da p (X[2]) diventera' la somma tra l'oggetto puntato da q e quello puntato da p X[2]=X[1]+X[2]=5
viene restituito il valore di X[1]
*/
