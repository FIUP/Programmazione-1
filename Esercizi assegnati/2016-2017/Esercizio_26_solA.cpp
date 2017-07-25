// soluzione di B.Cosentino
#include<iostream>
using namespace std;

// PRE = (X[0...lung-1] sono definiti) & (lung>0)
int riga(int X[], int lung){
    int somma=0;
    for (int i=0; i<lung; i=i+1)
    // R = (0<=i<=lung) & (somma contiene la somma degli elementi di X[0...i-1])    
        somma=somma+X[i];
    return somma;
}
// POST = (la funzione restituisce la somma degli elementi in X[0...lung-1])

// PRE -> R : (X[0...lung-1] sono definiti) & (lung>0) & (i=0) -> (0<=i<=lung) & (somma contiene la somma degli elementi di X[0...-1]) -> R valida

// R & condperm -> R :  (0<=i<=lung) & (somma contiene la somma degli elementi di X[0...i-1]) & (i<lung) -> 
//                      -> (0<=i<lung) & (somma contiene la somma degli elementi di X[0...i-1])
//                      <C>
//                      somma = somma + X[i] -> (somma contiene la somma degli elementi di X[0...i])
//                      Infine, i viene incrementato -> R valida

// R & !condperm -> POST : (0<=i<=lung) & (somma contiene la somma degli elementi di X[0...i-1]) & (i>=lung) -> 
//                          -> (i=lung) & (somma contiene la somma degli elementi di X[0...i-1]) -> 
//                          -> (somma contiene la somma degli elementi di X[0...lung-1]) -> POST vera


main(){
    int A[10][5][8], *p=A[0][0];
    int n_ele;
    cin>>n_ele;
  
    for(int i=0; i<n_ele; i=i+1)
        cin>>p[i];
        

    int bestfetta=-1, bestvalue;
    cout<<"start"<<endl;
    
    int strati_pieni=n_ele/40;
    int righe_piene=(n_ele%40)/8;
    int u_riga=(n_ele%40)%8;
    
    
    
    for (int i=0; i<5 && (i*8 < n_ele); i=i+1){
        
        int sommaT=0;
        
        for (int j=0; j<strati_pieni; j=j+1)
            sommaT=sommaT+riga(A[j][i],8);
            
        if (i < righe_piene){
            sommaT=sommaT+riga(A[strati_pieni][i], 8);
        } else {
            // aggiungo questo controllo perche' se i>righe_piene viene sommato uno strato non definito, infatti nel test C in base a determinati valori che non abbiamo definito 
            // e' possibile che capiti un risultato sballato
            if (i==righe_piene)    
                sommaT=sommaT+riga(A[strati_pieni][i], u_riga);
        }
        
        if (bestfetta==-1 || sommaT >= bestvalue){
            bestvalue = sommaT;
            bestfetta=i;
        }
    }
    
    
    cout<<"H-fetta massima= "<<bestfetta<<" con somma= "<<bestvalue<<endl;
    cout<<"end"<<endl;
}
