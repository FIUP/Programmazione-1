//Leggere da file

#include <iostream>
#include <fstream>
using namespace std;

main(){
  ifstream PP("letturadafile.cpp");
  if(PP != 0){ //successo nell'apertura file
    while(!PP.eof()){
      int c;

      PP>>c;
      
      cout<<c;
    } //fine while
    PP.close(); //chiusura file
  } //fine if
  else{
    cout<<"ERRORE: apertura esercizio1.cpp"<<endl;
  } //fine else
} //fine main
