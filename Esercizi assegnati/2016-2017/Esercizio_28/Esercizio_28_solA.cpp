// soluzione di B.Cosentino
#include<iostream>
using namespace std;
// PRE = (nella sezione [0...N-1] di A c'è almeno un elemento) & (0<N<=n_righe*n_colonne dove N e' il numero degli elementi dello strato)
void stampaS(int *A,int strato, int n_righe, int n_colonne, int N){
	cout << endl << "strato" << strato;
	for (int i=0; i < N; i=i+1){
	// R = (0<=i<=N) & (stampa gli i elementi di A[0...i-1] in ((i/n_colonne)%n_righe)+1 di lunghezza (i%n_colonne)+1)
		if (i%n_colonne==0)
			cout << endl << "r" << (i/n_colonne)%n_righe << ":";
		
		cout << *(A+i) << " ";
	}
	cout << endl;
}
// POST = (stampa tutti gli N elementi di A[0...N-1] in al piu' n_righe righe di lunghezza n_colonne al massimo)

// PRE -> R : (nella sezione [0...N-1] di A c'è almeno un elemento) & (N>0 dove N e' il numero degli elementi dello strato) & (i=0) -> 
//          -> (i=0) & (stampa gli i elementi di A[0...-1] in 0 di lunghezza 0) -> R valida

// R & condperm -> R : (0<=i<=N) & (stampa gli i elementi di A[0...i-1] in (i/n_colonne)%n_righe di lunghezza i%n_colonne) & (i < N) ->
//                      -> (0<=i<N) & (stampa gli i elementi di A[0...i-1] in (i/n_colonne)%n_righe di lunghezza i%n_colonne)
//                      <C>
//                      Se i%n_colonne == 0 stampo "r (numero di riga):" dato che e' l'inizio di una nuova riga dello strato.
//                      Dopo stampo A[i] e incremento i -> R valida

// R & !condperm -> POST : (0<=i<=N) & (stampa gli i elementi di A[0...i-1] in ((i/n_colonne)%n_righe)+1 di lunghezza (i%n_colonne)+1) & (i >= N) ->
//                      -> (i=N) & (stampa gli N elementi di A[0...N-1] in ((N/n_colonne)%n_righe)+1 di lunghezza (N%n_colonne)+1).
//                      ((N/n_colonne)%n_righe < n_righe) & (N%n_colonne < n_colonne) -> ((N/n_colonne)%n_righe)+1 <= n_righe) & ((N%n_colonne)+1 <= n_colonne) ->
//                      -> (stampa gli N elementi di A[0...N-1] in al piu' n_righe di lunghezza n_colonne al massimo) -> POST vera.

main()
{
    int n_ele, lim1,lim2, lim3, X[400];
    cin>>n_ele;
    
    for(int i=0; i<n_ele; i=i+1)
        cin>>X[i];
    
    cin>>lim1>>lim2>>lim3;
    
    cout<<"start"<<endl;
    
    int strati_pieni=n_ele/(lim2*lim3);
	int ele_ustrato=n_ele%(lim2*lim3);
    
    for (int s=0; s<strati_pieni; s=s+1)
    	stampaS(X + s*lim2*lim3, s, lim2, lim3, lim2*lim3);
    	
    if (ele_ustrato>0)
    	stampaS(X + strati_pieni*lim2*lim3, strati_pieni, lim2, lim3, ele_ustrato); 
 
     
    cout<<"end"<<endl;
}
