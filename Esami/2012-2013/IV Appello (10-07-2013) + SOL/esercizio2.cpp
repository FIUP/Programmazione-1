#include <iostream>
#include <fstream>

using namespace std;


struct TRIPLE{
  int colonna, 
    inizio, 
    lung; 
  TRIPLE(int a=0, int b=0, int c=0){colonna=a; inizio=b; lung=c;}
};


//PRE_R3=(T ha R*C elementi definiti, 0<=riga<R, 0<=colonna<C, 0<=indice_col<=R, 0<=indice_riga<=C, R>0, C>0)
TRIPLE R3(int *T, int indice_riga, int riga, int indice_col, int colonna, int R, int C){
  
  if(indice_riga==C || indice_col+indice_riga==R)
    return TRIPLE(colonna,indice_col,indice_riga);
  
  if(*(T+(indice_col+indice_riga)*C+colonna)==*(T+riga*C+indice_riga))
    return R3(T,indice_riga+1,riga,indice_col,colonna,R,C);
  
  return TRIPLE(colonna,indice_col,indice_riga);

}//POST_R3=(restituisce la TRIPLE che rappresenta il massimo match della riga riga [0..indice_riga-1] di T nella colonna colonna [indice_col..indice_col+indice_riga-1] di T)


//PRE_R2=(T ha R*C elementi definiti, 0<=riga<R, 0<=colonna<C, 0<=indice_col<R, R>0, C>0)
TRIPLE R2(int *T, int riga, int indice_col, int colonna, int R, int C){
  if(indice_col==R)
    return TRIPLE(colonna,indice_col,0);
  TRIPLE prossimo=R2(T,riga,indice_col+1,colonna,R,C);
  TRIPLE match=R3(T,0,riga,indice_col,colonna,R,C);
  if(prossimo.lung>match.lung)
    return prossimo;
  return match;
}//POST_R2=(restituisce la TRIPLE che rappresenta il massimo match della riga riga di T nella colonna colonna [indice_col..R-1] di T)

/* PROVA DI CORRETTEZZA: PRE_R2 < R2() > POST_R2

  Caso base: indice_col==R
--------------------------
Dato PRE_R2, se indice_col==R allora il massimo match della riga riga nella colonna colonna [indice_col..indice_col-1] è lungo 0 e quindi ritorniamo la TRIPLE [colonna,indice_col,0] → vale POST_R2

  Caso ricorsivo: indice_col!=R
-------------------------------
Dato PRE_R2, se indice_col!=R allora non abbiamo ancora cercato il più lungo match a partire dall'indice indice_col della colonna colonna [indice_col..R-1] e quindi invochiamo la chiamata ricorsiva R2(T,riga,indice_col+1,colonna,R,C), con indice_col<=R: al ritorno confronterà il massimo match a partire da inice_col e quello a partire da indice_col+1 e ritornerà la TRIPLE che rappresente il massimo match della riga riga di T rispetto alla colonna [indice_col..R-1] → vale POST_R2

*/


//PRE_R1=(T ha R*C elementi definiti, 0<=riga<R, 0<=colonna<=C, R>0 e C>0)
TRIPLE R1(int*T, int riga, int colonna, int R, int C){
  if(colonna==C)
    return TRIPLE();
  TRIPLE X=R2(T,riga,0,colonna,R,C); //da fare 
  TRIPLE Y=R1(T,riga,colonna+1,R,C);
  if(X.lung>=Y.lung)
    return X;
  else return Y;
}//POST_R1=(restituisce la TRIPLE che rappresenta il massimo match della riga riga di T rispetto alle colonne [colonna..C-1] di T)


//PRE_R0=(T ha R*C elementi definiti, 0<=riga<=R)
void R0(int*T, int riga, int R, int C, TRIPLE*Q){
  if(riga<R){
    Q[riga]=R1(T,riga,0,R,C);
    R0(T,riga+1,R,C,Q);
  }
}//POST_R0=(per k in [0..R-1], Q[k] contiene (colonna, inizio e lunghezza) del massimo match della riga k rispetto a tutte le colonne di T)


main(){
  ifstream INP("input2");
  ofstream OUT("output2");
  if(INP && OUT){
    int R, C;
    INP>>R>>C;
    int *T=new int[R*C];
    TRIPLE*Q=new TRIPLE[R];
    for(int i=0; i<R*C; i++){
      INP>>T[i];
      cout<<T[i]<<' ';
    }
    cout<<endl;
        
    R0(T,0,R,C,Q);

    for(int i=0; i<R; i++)
      OUT<<Q[i].colonna<<' '<<Q[i].inizio<<' '<<Q[i].lung <<endl;
    OUT<<endl;
    INP.close();
    OUT.close();
  }else cout<<"errore apertura file"<<endl;
}