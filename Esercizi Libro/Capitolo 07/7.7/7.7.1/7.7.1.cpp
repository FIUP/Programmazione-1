/* Scrivere una funzione che riceve una matrice di tipo char[][5] ed il numero
   di righe limite_1 e determina se c'e' un carattere che e' presente in tutte
   le righe della matrice. */

#include<iostream>
using namespace std;

bool trova_carattere (char A[][5], int limite_1)
{
  // PRE
  bool elemento=false;
  for (int i=0; i<5 && !elemento; i++) {     // R1
    bool riga=true;
    for (int j=1; j<limite_1 && riga; j++) {     //R2
      bool trovato=false;
      for (l=0; l<5 && !trovato; l++)     // R3
	if (A[j][l]==A[1][i]) trovato=true;
      // POST3
      if (!trovato) riga=false;
    }
    // POST2
    if (riga) elemento=true;
  }
  // POST1
  return elemento;
  // POST
}

/*  PRE = (A e' una matrice di caratteri di dimensioni limite_1 * 5)
   POST = (La funzione restituisce true se c'e' un carattere presente in tutte
          le righe, altrimenti restituisce false)
     R1 = (0<=i<=5)&&(nessuno degli elementi 0..i-2 della prima riga sono
          presenti anche in tutte le altre righe)&&(elemento<=>l'elemento i-1
          della prima riga e' presente anche in tutte le altre)
  POST1 = (elemento <=> e' stato trovato un carattere presente in tutte le righe)
     R2 = (0<=j<=limite_1)&&(nelle righe 1..j-2 l'elemento della prima riga di
          posto i e' stato trovato)&&(riga<=>nella riga j-1 e' stato trovato
          l'elemento di posto i della prima riga)
  POST2 = (riga <=> l'elemento della prima riga di posto i e' stato trovato nella
          riga j)
     R3 = (0<=l<=5)&&(trovato<=>A[j][l-1]=A[1][i])&&(gli elementi 0..l-2 della
          riga j non sono uguali ad A[1][i])
  POST3 = (trovato <=> e' stato trovato l'elemento A[1][i] nella riga j) */
