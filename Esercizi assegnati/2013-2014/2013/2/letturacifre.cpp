#include <iostream>
using namespace std;

main(){
  char carattere='0';
  int numero=0,cifra=0,indice=0;

  cout<<"\n\nInsericsci un carattere numerico compreso tra 0 e 9"<<endl;
  cout<<"Per uscire inserire a"<<endl;
  
  while(carattere!='a'){

    numero=numero*10+cifra;
    
    cin>>carattere;
    cifra=carattere-'0';
    
    indice++;
  }//fine while
  cout<<"\nIl numero scritto e': "<<numero<<endl<<endl;
}//fine main
