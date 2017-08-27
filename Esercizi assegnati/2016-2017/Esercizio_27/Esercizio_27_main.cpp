#include<iostream>
using namespace std;

int colonna(int X[],int n, int step); //da fare 


//PRE=(cin contiene n_ele, 0<n_ele<=400, seguito da n_ele interi qualsiasi)
main()
{
  int A[10][5][8], *p=A[0][0];
  int n_ele;
  cin>>n_ele;
  for(int i=0; i<n_ele; i=i+1)
    cin>>p[i];
  
  cout<<"start"<<endl;
  //da fare
  cout<<"V-fetta massima= "<<bestfetta<<" con somma= "<<bestvalue<<endl;
  cout<<"end"<<endl;
}
//POST=(stampa l'indice della V-fetta a somma massima seguito dalla sua somma e in caso di parità, stampa l'indice massimo)