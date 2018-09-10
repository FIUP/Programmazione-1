//Soluzione di S.Righetto

#include<iostream>
using namespace std;

bool trova(bool* N, int m, int i, int j, int *P){
    bool a=false, b=false, c=false;
    if(i==m-1 && *(N+ ( (i*m) +j) ) ){
        P[i]=j;
        return true;
    }
    
    if(*(N+ ( (i*m) +j) ) ){ //controllo che la cella corrente sia libera,bianca
        P[i]=j;
    
        if(*(N + (i+1)*m + j-1) && (j-1>=0)){ //controllo nella cella in basso a sinistra
            a = trova(N,m,i+1,j-1,P);}
            else a=false;
            
        if(!a && *(N +((i+1)*m) + j) ) //controllo della cella sottostante
        b= trova(N,m,i+1,j,P); 
            else b=false;   
        
        if(!a && !b && *(N + (i+1)*m + j+1) && (j+1<m)){ //controllo nella cella in basso a destra
            c= trova(N,m,i+1,j+1,P);}
            else c= false; 
    }
    return a || b || c;    
}


bool partenza(bool*N, int m, int j, int *P){ //j è la colonna di partenza
    if(trova(N,m,0,j,P)){ 
        
        return true;}
    else {
        if(j<m) return partenza (N,m,j+1,P); //richiamo la funzione spostando la colonna di partenza
        else return false; //finisco le colonne da cui partire
    };
}

void stampa(int *P, int m, int i){
    if(i<m){
    cout << '(' << i << ','<<P[i]<< ") ";
    stampa(P,m,i+1);
    } else cout << endl;
}

   
main()
{
  int m,P[50];
  cin>>m;
  bool N[400];
  for(int i=0; i<m*m; i++)
          cin>>N[i];
  bool x=partenza(N,m,0,P);
  cout<<"start"<<endl;
  if(x)
    { cout<<"esiste un cammino e quello più a sinistra e’:"<<endl;
      stampa(P,m,0);
    }    
  else
    cout<<"il cammino non esiste"<<endl;
  cout<<"end"<<endl;
      
}


