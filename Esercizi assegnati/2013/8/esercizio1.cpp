#include <iostream>
#include <fstream>
using namespace std;

//PRE_match=(T da dim elementi definiti, P ha dimP elementi definiti)
bool match(int* T, int dim, int*P, int dimP){
  if(dim<dimP){
    return false;
  }
  if(dimP==0){
    return true;
  }
  if(T[0]!=P[0]){
    return false;
  }
  else{
    return match(T+1,dim-1,P+1,dimP-1);
  }
}
//POST_match=(match restituisce true sse c’è un match (completo e contiguo) di P in T a partire da T[0]).

/*
  PROVA INDUTTIVA MATCH
  passo base: 
    dim<dimP --> T ha meno elementi di P, non puo' esserci il match --> return false --> e' verificata la POST_match
    dimP==0 --> abbiamo esaminato tutto P (si prosegue con P solo se gli elementi corrispondono) --> abbiamo trovato un match --> return TRUE --> e' verificata la POST_match
    T[0]!=P[0] --> gli elementi sono diversi non puo' verificarsi un match --> return FALSE --> e' verificata la POST_match

  passo induttivo:
    assumiamo match(T+1,dim-1,P+1,dimP-1) vera per la PRE e POST
    PRE_match_ric = (T+1 da dim-1 elementi e P+1 da dimP-1 elementi)
    POST_match_ric = (da true se c'e' un match tra T+1 e P+1 a partire da T+1[0])

    e' corretto in quanto nella ricorsione T+1 avra' dim-1 elementi e lo stesso vale per P in quanto non si considera piu' T[0] ma si parte da T[1] quindi si ha un elemento in meno.
    e' verificata la PRE_match_ric di conseguenza e' vera la POST_match_ric
*/

//PRE_F=(T ha dim elementi definiti, P ha dimP elementi definiti)
int F(int*T, int dim, int *P, int dimP){
    
  if(dim<dimP){
    return 0;
  }
  else{
    if(match(T,dim,P,dimP)){
      return F(T+1,dim-1,P,dimP)+1;
    }
    else{
      return F(T+1,dim-1,P,dimP);
    }
  }
}
//POST_F=(F restituisce il n. di match di P in T considerando anche match sovrapposti)

/*
  PROVA INDUTTIVA F 
  passo base: 
    dim<dimP --> T ha meno elementi di P, non puo' esserci il match --> return false --> e' verificata la POST_F

  passo induttivo:
    assumiamo F(T+1,dim-1,P+1,dimP-1) vera per la PRE e POST
    PRE_F_ric = (T+1 da dim-1 elementi e P+1 da dimP-1 elementi)
    POST_F_ric = (somma 1 al return se c'e' un match tra T+1 e P+1 a partire da T+1[0])
    e' corretto in quanto nella ricorsione T+1 avra' dim-1 elementi e lo stesso vale per P in quanto non si considera piu' T[0] ma si parte da T[1] quindi si ha un elemento in meno.
    e' verificata la PRE_F_ric di conseguenza e' vera la POST_F_ric
    se il match da valore true il return somma 1 altrimenti no, la somma fiene effettuata al ritorno non al richiamo ricorsivo della funzione
*/

//PRE_F2=(T ha dim elementi definiti, P ha dimP elementi definiti)
int F2(int*T, int dim, int *P, int dimP){
    
  if(dim<dimP){
    return 0;
  }
  else{
    if(match(T,dim,P,dimP)){
      return F2(T+dimP,dim-dimP,P,dimP)+1;
    }
    else{
      return F2(T+1,dim-1,P,dimP);
    }
  }
}
//POST_F2=(F2 restituisce il n. di match di P in T non considerando i match sovrapposti)

main(){

  int T[100],P[20],dim,dimP;

  ifstream IN("input1");
  ofstream OUT("output1");
  ofstream OUT2("output2");

  //RIEMPIAMO GLI ARRAY T E P
  IN>>dim;
  for(int i=0;i<dim;i++){
    IN>>T[i];
  }

  IN>>dimP;
  for(int i=0;i<dimP;i++){
    IN>>P[i];
  }

  OUT<<F(T,dim,P,dimP);
  OUT2<<F2(T,dim,P,dimP);

}//fine main


/*
  TEORIA
  il programma e' corretto e stampa i valori 1 3 3

  MAIN:
  nel main viene inizializzato un array di tre valori tale che
  X[0]=1
  X[1]=2
  X[2]=3
  un puntatore *q=X-1 punta al valore precedente ad X[0]
  e un puntatore z puntera' all'oggetto puntato dal return della funzione g(&q)
   
    FUNZIONE G:
    g accetta come ingressi un puntatore a puntatore, le viene passato L-valore
    del puntatore q, quindi x punta al valore precedente a X[0]
    viene inizializzato un puntatore *p=*x+2 che puntera' a due posizioni successive a x
    quindi p punta a X[1]
    x assume come R-valore l'L-valore di p e viene ritornato x

  l'oggetto puntato da z e' quindi X[1] che assume il valore di X[2]
  allora X[1]=X[2]=3
  l'output sara 133
*/
