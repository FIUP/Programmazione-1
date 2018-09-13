//Soluzione di S.Righetto

#include<iostream>

using namespace std;

struct coppia{int salta,prendi; coppia(int a=0,int b=0){salta=a;prendi=b;}};

//PRE_n=(T ha dimT elementi)
int not_match(char *T, char x, int dimT){ //salta finchè non trovo x nell'array T e restituisce il numero degli el da saltare
    if(dimT==0) return 0; //ho finito l'array T senza trovare match
    if(*T== x) return 0; //trovo subito un match quindi salta è nullo
    else return 1+not_match(T+1, x, dimT-1); //non trovo il match e cerco nel successivo
}
//POST_n=(restituisce il numero di elementi di T da saltare per arrivare a trovare x in T, partendo da T[0])

//PRE_m=( T ha dimT elementi definiti e P ne ha dimP)
int match(char *T, char *P, int dimT, int dimP){ //ogni match restituisce il numero di prendi
    if(dimT ==0) return 0; // ho terminato l'array T senza trovare match
    if(dimP==0) return 0; //ho terminato P senza trovare match
    if(*T!=*P) return 0; // non ho trovato il match, restituisco prendi nullo
    else return 1+match(T+1,P+1, dimT-1,dimP-1); //controllo i successivi
}
//POST_m=(deve restituire la lunghezza del massimo prefisso di P che matcha a partire da T[0] in posizioni contigue, cioè senza buchi)

//PRE_F=(T ha dimT elementi definiti e P ne ha dimP, X ha gli elementi che ci servono)
bool F(char*T, char *P, int dimT, int dimP, coppia *X){ //finisce quando arrivo alla fine di P quindi trovo almeno un match
    int salta=0, prendi=0;
    if(dimP==0){return true;} //arrivo alla fine di P
    if(dimT==0 && dimP != 0) return false; //arrivo alla fine di T ma non trovo nessun match
    else{
    salta=not_match(T, *P, dimT);
    //if(salta==-1) return false; //ho finito di scorrere T
        T=T+salta; //aggiungo al puntatore le celle già controllate che non hanno matchato
        dimT=dimT-salta; //tolgo a dimT le celle saltate
    
        
    prendi = match(T, P, dimT, dimP);
    //if (prendi == -1) return false; //ho finito di scorrere T
        T=T+prendi; //aggiungo al puntatore le celle già controllate
        P=P+prendi; //aggiungo al puntatore le celle già controllate
        dimT=dimT-prendi; //tolgo alla dimensione le celle già controllate
        dimP=dimP-prendi; //tolgo alla dimensione le celle già controllate
    }
    
    X->salta = salta; //assegno salta
    X->prendi = prendi; //assegno prendi
    
    return F(T,P,dimT,dimP,X+1);
}
//POST_F=(restituisce true sse esiste un match completo (con eventuali buchi) d P in T e, se il match c’è, X contiene le coppie che corrispondono al match)

void stampa(coppia *X){
    if(X->salta != -1 || X-> prendi != -1){
    cout << "(" << X->salta << "," << X->prendi << ") ";
    stampa(X+1);
    }
}

main()
{
  int dimT, dimP;
  char T[400],P[50];
  coppia X[50];
  for(int i=0; i<50; i++)
    X[i]=coppia(-1,-1);
  cin>> dimT>>dimP;
  
  for(int i=0; i<dimT; i++)
    cin>>T[i];
  for(int i=0; i<dimP; i++)
    cin>>P[i];
  cout<<"start"<<endl;
  if(F(T,P,dimT,dimP,X))
    stampa(X);
   else
    cout<<"nessun match completo"<<endl;
  cout<<"end"<<endl;
}
  

