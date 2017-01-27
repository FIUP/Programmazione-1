//Leggere 10 numeri interi e trovare il massimo e il minimo

#include <iostream>
using namespace std;

main(){
  int min=INT_MAX,max=INT_MIN,x,indice=0;

  cout<<"Inserire 10 valori"<<endl;
  while(indice<10){
    cin>>x;
    if(x>max)
      max=x;
//  else                            //solo se e' sempre vero che min <= max
    if(x<min)
      min=x;
  indice++;
  }                                 //fine while
}                                   //fine main
