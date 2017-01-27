#include <iostream>
#include <fstream>

using namespace std;


struct TRIPLE{
  int colonna, //indice della colonna del match
    inizio, //indice della colonna dal quale comincia il match
    lung; //lunghezza match
  TRIPLE(int a=0, int b=0, int c=0){colonna=a; inizio=b; lung=c;}
};


//PRE_cercaMatch=(T ha R*C elementi definiti, 0<=r<R, 0<=c<C e 0<=i<=R)
TRIPLE cercaMatch(int *T, int c, int r, int R, int C, int i){
  int j=0;
  int lung=0; //lunghezza del match
  while(j<C && *(T+(i+lung)*C+c)==*(T+r*C+j)){
    lung++;
    j++;
  }
  return TRIPLE(c,i,lung);
}//POST_cercaMatch=(la funzione restituisce il valore di tipo TRIPLE che rappresenta il massimo match della riga r nella colonna [i..C-1])


//PRE_It1=(T ha R*C elementi definiti, 0<=r<R e 0<=c<C)
TRIPLE It1(int*T, int r, int c, int R, int C){
  TRIPLE match;
  bool completo=false; //gestisce l'interruzione della ricerca nel caso avessimo trovato un match completo
  for(int i=0; i<R && !completo && R-i>match.lung ; i++){
    //R1=(0<=i<=R)&&(se !completo allora match è il match di lunghezza massima (non completo) della riga r sulla colonna [0..i-1]; altrimenti match è il primo match completo della riga r di T sulla colonna c di T)
    TRIPLE match_aux=cercaMatch(T,c,r,R,C,i);
    if(match_aux.lung>match.lung){
      match=match_aux;
      if(match.lung==R)
        completo=true;
    }
  }
  return match;
}//POST_It1=(la funzione restituisce il valore di tipo TRIPLE che rappresenta il massimo match della riga r nella colonna c)


//PRE_It0=(T ha R*C elementi definiti, R e C sono >0)
void It0(int*T, int R, int C, TRIPLE* Q){
  for(int r=0; r<R; r++){
    //R1=(0<=r<=R)&&(Q[0..r-1] contiene r TRIPLE con le informazioni per il massimo match delle rispettive righe 0,..,r-1 di T sulle colonne [0..C-1] di T)
    TRIPLE match; //match di lunghezza massima da scrivere in Q[r]
    bool completo=false;
    for(int c=0; c<C && !completo; c++){ 
      //R2=(0<=c<=C)&&(se completo=false allora match è il match più lungo (non completo) della riga r su T[0..c-1]; altrimenti match è il primo match completo di r su T[0..C-1])
      TRIPLE match_aux=It1(T,r,c,R,C);
      if(match_aux.lung>match.lung){
        match=match_aux;
        if(match.lung==R)
          completo=true;
      }
    }
    Q[r]=match;
  }
}//POST_It0=(alla fine Q contiene R valori TRIPLE che rappresentano i match massimi delle R righe di T nelle colonne di T).

/* PROVA DI CORRETTEZZA: PRE_It0 < for(C){B} > POST_It0

  Condizione di entrata: PRE_It0 → R
------------------------------------
Dato PRE_It0, se r=0 allora Q non contiene ancora TRIPLE in quanto non abbiamo ancora cercato match → vale R in quanto Q[0..-1] contiene 0 TRIPLE che rappresentano il massimo match delle righe 0,..,-1 di T sulle colonne [0..C-1] di T

  Condizione di invarianza: R && (C) → R
----------------------------------------
Dato PRE_It0, se 0<r<R allora Q[0..r-1] contiene r TRIPLE che rappresentano il massimo match delle rispettive righe 0,..,r-1 di T sulle colonne [0..C-1] di T e cerchiamo un TRIPLE che rappresenta il massimo match della riga r di T sulle colonne [0..C-1] di T e lo inseriamo in Q[r] → vale R

  Condizione di uscita: R && !(C) → POST_It0
--------------------------------------------
Dato PRE_It0, se r=R allora Q[0..R-1] contiene R TRIPLE che rappresentano il massimo match delle rispettive righe 0,..,R-1 di T sulle colonne [0..C-1] di T → vale POST_It0

*/


main(){
  ifstream INP("input1");
  ofstream OUT("output1");
  if(INP && OUT){
    int R,C;
    INP>>R>>C;
    int *T=new int[R*C];
    TRIPLE*Q=new TRIPLE[R];
    
    for(int i=0; i<R*C; i++){
      INP>>T[i];
      cout<<T[i]<<' ';
    }
    cout<<endl;
        
    It0(T,R,C,Q);//da fare 

    for(int i=0; i<R; i++)
    OUT<<Q[i].colonna<<' '<<Q[i].inizio<<' '<<Q[i].lung <<endl;
    OUT<<endl;
    INP.close();
    OUT.close();
  }else cout<<"errore apertura file"<<endl;
}