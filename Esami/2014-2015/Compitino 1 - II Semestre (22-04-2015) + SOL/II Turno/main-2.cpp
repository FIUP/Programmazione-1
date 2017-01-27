#include<iostream>
#include<fstream>
using namespace std;
struct tripla{int prof, riga, colonna; tripla(int a=0, int b=0, int c=0){prof=a; riga=b; colonna=c;}}; //per modellare posizione in sotto-array

main()
{
  ifstream IN("input");

  ofstream OUT("output");
  if(IN && OUT) 
  { 
   
   int X[400],P[50], n_el, dimP, lim1,lim2,lim3;
   
   IN>>lim1>>lim2>>lim3;
   IN>>n_el;
   for(int i=0; i<n_el; i++)
     IN >> X[i];
   int r,c,h,l;
   IN>>r>>c>>h>>l; //definisce sotto-array
   
   IN>>dimP;
   for(int i=0; i<dimP; i++)
    IN>>P[i];

//pattern match sul sotto-array pieno con ordinamento per strati 

   //inizializzazione
   

 for(esame elementi del sotto-array in ordine per strati da cui può iniziare un match con P)
  {
    if(match(X,r,c,h,l,lim1,lim2,lim3,P,dimP,e))
     {.........OUT<<"trovato match a partire dall'elemento "<<e<<endl;}
    else
      {......OUT<<"a partire dall'elemento "<<e<<" non c'e' match"<<endl;}
  }
   OUT<<"n. totale match="<<......<<endl;
  
   IN.close(); OUT.close(); 
  }
  else
   cout<<"errore con i files";
 }
