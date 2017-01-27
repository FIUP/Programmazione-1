#include <iostream>
#include <fstream>

using namespace std;

main(){
  char T[100],P[20];
  int dim,dimP,indice=0,indiceT=0,indiceP=0,contamatch=0;
  bool match=false;

  ifstream input("input2");
  input>>dim>>dimP;  

  while(indice<dim){
    input>>T[indice];
    indice++;
  }
  
  indice=0;
  
  while(indice<dimP){
    input>>P[indice];
    indice++;
  }
  
  while(indiceT<dim && !match){
    indiceP=0;
    if(T[indiceT]==P[indiceP]){
      while(indiceP<dimP){
	if(T[indiceT+indiceP]==P[indiceP])
	  match=true;
	else
	  match=false;
	indiceP++;
      }                        //fine while P
    }                          //fine if
    if(match && indiceP==dimP){
      contamatch++;
      indiceT=indiceT+dimP;
      match=false;
    }
    else
      indiceT++;
  }                            //fine while T
      
  ofstream output("output2");
  output<<contamatch;
}                              //fine main
