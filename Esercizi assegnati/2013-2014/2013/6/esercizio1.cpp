#include <iostream>
#include <fstream>
using namespace std;

//PRE_R=(A[0..dim-1] definita,dim>0, lim1>0, lim2>0, r in [0..lim1-1])
void R(int*A,int dim,int lim1,int lim2,int r,ofstream & OUT){
  
  int conta,contael=0;
  bool rigavuota=true;

  conta=lim2*r;            //l'indice salta le prime r righe in modo da 'vedere' solo gli elementi successivi
  if(conta<dim){
    rigavuota=false;
    while(contael<lim2 && conta<dim){
      OUT<<A[(r*lim2)+contael]<<" ";
      contael++;
      conta++;
    }
    OUT<<"\n";
  }
  if(rigavuota){
    OUT<<-r<<"\n";
  }
}//fine R
//POST_R=(stampa su OUT gli elementi definiti della riga r di X)

//PRE_C=(A[0..dim-1] definita,dim>0, lim1>0, lim2>0, r in [0..lim2-1])
void C(int*A,int dim,int lim1,int lim2,int c,ofstream & OUT){


  int conta;
  bool colvuota=true;

  conta=c;
  if(c<=dim-1){
    colvuota=false;
    while(conta<dim){
      OUT<<A[conta]<<" ";
      conta=conta+lim2;
    }
    OUT<<"\n";
  }
  if(colvuota){
    OUT<<-c<<"\n";
  }


}//fine C
//POST_C=(stampa su OUT gli elementi definiti della colonna c)

main(){
  int A[400],dim,lim1,lim2,r1,r2,c1,c2;
  
  ifstream IN("input1");
  ofstream OUT("output1");
  IN>>dim;
  for(int i=0; i<dim; i++){
    IN>>A[i];
  }
  IN>>lim1;
  IN>>lim2;
  IN>>r1;
  IN>>r2;
  IN>>c1;
  IN>>c2;

  R(A,dim,lim1,lim2,r1,OUT);
  R(A,dim,lim1,lim2,r2,OUT);
  C(A,dim,lim1,lim2,c1,OUT);
  C(A,dim,lim1,lim2,c2,OUT);

}//fine main

/*
  TEORIA
  Domanda sull’aritmetica dei puntatori:
  
  Dato int A[5][10][20], specificare il tipo, la dimensione dell’oggetto puntato e il
  valore delle seguenti espressioni. Si indichi il valore di A semplicemente con A.
  
  il tipo e' int (*)[10][20]
  la dimensione e' 10*20*4=800    int --> 4 byte

  (*A)[2] = A+2*20*4 = A+160
  (A[-10])+1 = (A-10*(10*20*4))+1*20*4 = A-7920
  (**A)-20 = A-20*4 = A-80
  
*/
