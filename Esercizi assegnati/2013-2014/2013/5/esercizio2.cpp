#include <iostream>
#include <fstream>

using namespace std;

main(){
  char A[5][10];
  int dim,i=0,j=0,conta=0;

  ifstream IN("input2");
  
  IN>>dim;

  while(i<5 && conta<dim){
    while(j<10 && conta<dim){
      IN>>A[i][j];
      j++;
      conta++;
    }
    j=0;
    i++;
  }
  conta=0;
  i=0;
  j=0;
  int contaA,indicemax=0;
  bool trovato=false;
  
  while(i<5 && conta<dim){
    contaA=0;
    while(j<10 && conta<dim){
      if(A[i][j]=='a')
	contaA++;
      j++;
      conta++;
    }
    if(contaA%2==0){
      trovato=true;
      indicemax=i;
    }
    j=0;
    i++;
  }

  ofstream OUT("output2");
  if(trovato)
    OUT<<true<<" "<<indicemax;
  else
    OUT<<false;
}//fine main
