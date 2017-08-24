// soluzione di B.Cosentino
#include<iostream>
using namespace std;
// PRE=(n>0) & (A[0..(n-1)*step] è definito)
int colonna(int X[],int n, int step){
    int somma=0;
    for (int i=0; i<n; i=i+1)
    // R = (0<=i<=n) & (somma=A[0]+A[step]+A[2*step]+...+A[(i-1)*step])
        somma=somma+X[i*step];
    return somma;
}
// POST=(restituisce il valore di A[0]+A[step]+A[2*step]+A[3*step]+...+A[(n-1)*step])

// PRE -> R : (n>0) & (A[0..(n-1)*step] è definito) & (i=0) -> (somma gli elementi di A da 0 a -1*step ovvero nessuno) -> R valida

// R & condperm -> R : (0<=i<=n) & (somma=A[0]+A[step]+A[2*step]+...+A[(i-1)*step]) & (i<n) -> (0<=i<n) & (somma=A[0]+A[step]+A[2*step]+...+A[(i-1)*step])
//                  <C>
//                  Aggiungo a somma A[i*step] e incremento i -> R valida

// R & !condperm -> POST : (0<=i<=n) & (somma=A[0]+A[step]+A[2*step]+...+A[(i-1)*step]) & (i>=n) -> (i=n) & (somma=A[0]+A[step]+A[2*step]+...+A[(i-1)*step]) ->
//                      -> (somma=A[0]+A[step]+A[2*step]+...+A[(n-1)*step]) -> POST vera




//PRE=(cin contiene n_ele, 0<n_ele<=400, seguito da n_ele interi qualsiasi)
main(){
    
    int A[10][5][8], *p=A[0][0];
    int n_ele;
    cin>>n_ele;
    
    for(int i=0; i<n_ele; i=i+1)
        cin>>p[i];
    
    cout<<"start"<<endl;
    
    int bestfetta = -1, bestvalue;
    int strati_pieni = n_ele/40;
    int righe_piene = (n_ele%40)/8;
    int u_riga = (n_ele%40)%8;

    for (int v=0; v<8 && v<n_ele; v=v+1){
      
        int sommaT=0;
      
        for (int j=0; j<strati_pieni; j=j+1)
            sommaT=sommaT+colonna(&A[j][0][v], 5, 8);
          
        if (v<u_riga){
            sommaT=sommaT+colonna(&A[strati_pieni][0][v], righe_piene+1, 8);
        } else {
            sommaT=sommaT+colonna(&A[strati_pieni][0][v], righe_piene, 8);
        }
        
        if (bestfetta==-1 || sommaT >= bestvalue){
            bestvalue=sommaT;
            bestfetta=v;
        }
    }
    
    
    cout<<"V-fetta massima= "<<bestfetta<<" con somma= "<<bestvalue<<endl;
    cout<<"end"<<endl;
}
//POST=(stampa l'indice della V-fetta a somma massima seguito dalla sua somma e in caso di parità, stampa l'indice massimo)
