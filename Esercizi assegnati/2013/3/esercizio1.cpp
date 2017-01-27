#include <iostream>
#include <fstream>

using namespace std;

main(){
  char T[100],P[20];
  int dim,dimP,indice=0,indiceT=0,indiceP=0,indicematch=0;
  bool match=false;

  ifstream input("input1");
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
    if(T[indiceT]==P[indiceP]){
      while(indiceP<dimP){
	if(T[indiceT+indiceP]==P[indiceP])
	  match=true;
	else
	  match=false;
	indiceP++;
      }                        //fine while P
    }                          //fine if
    indiceT++;
  }                            //fine while T
  
  /*
  cout<<"\n\n";
  for(indice=0;indice<dim;indice++)
    cout<<T[indice]<<" ";
  for(indice=0;indice<dimP;indice++)
    cout<<P[indice]<<" ";
  cout<<"\n\n";
  cout<<match<<" "<<indiceT-1<<"\n";
  */
  
  if(match)
    indicematch=indiceT-1;
  
  ofstream output("output1");
  output<<match<<" "<<indicematch;
}                              //fine main
