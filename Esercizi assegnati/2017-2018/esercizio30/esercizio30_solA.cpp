//Soluzione di S.Righetto (sbagliata)

#include<iostream>
using namespace std;

bool trova(bool* N, int m, int i, int j){
    bool a=false, b=false, c=false;
    if(i==m-1 && *(N+((i*m)+j)) ){ //se sono sull'ultima riga e l'ultimo è vero
    	return true;
    	}
    if(*(N+ ( (i*m) +j) ) ){ //controllo che ci siano ancora righe da controllare e che la cella corrente sia libera,bianca
        if(*(N + (i+1)*m + j-1) && (j-1>=0)) //controllo nella cella in basso a sinistra
            a = trova(N,m,i+1,j-1);
            else a=false;
            
        if( *(N +((i+1)*m) + j) ) //controllo della cella sottostante
        b= trova(N,m,i+1,j); 
            else b=false;   
        
        if( *(N + (i+1)*m + j+1) && (j+1<m)) //controllo nella cella in basso a destra
            c= trova(N,m,i+1,j+1);
            else c= false; 
    }
    return a || b || c;    
}

bool partenza(bool*N, int m, int j){ //j è la colonna di partenza
    if(trova(N,m,0,j)) return true;
    else {
        if(j<m) return partenza (N,m,j+1); //richiamo la funzione spostando la colonna di partenza
        else return false; //finisco le colonne da cui partire
    };
}

main()
{
  int m;
  bool N[400];
  cin>>m;
  cout<<"start"<<endl;
  for(int i=0; i<m*m;i++)
    cin>>N[i];
    
  if(partenza(N,m,0))
   cout<<"c'e' un cammino"<<endl;
  else
   cout<<"non c'e' un cammino"<<endl;
  cout<<"end"<<endl;
}
