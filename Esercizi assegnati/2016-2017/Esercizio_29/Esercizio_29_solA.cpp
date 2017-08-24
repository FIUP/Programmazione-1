// soluzione di B.Cosentino
#include<iostream>
using namespace std;

// PRE = (cin contiene n_ele >0 interi qualsiasi) 
/*
void leggiV(int* A, int n_strati, int n_righe, int n_colonne, int N){
	
	for (int i=0; i<N && i<n_strati*n_righe*n_colonne; i=i+1)
	// R = (0<=i<=min(N, n_strati*n_righe*n_colonne)) & (sono state riempite le colonne [0...(i/(n_strati*n_righe))-1] per ogni strato e la successiva fino allo strato (i/(n_righe*n_colonne))-1 in riga (i*n_colonne)%(n_strati*n_righe*n_colonne))  
		cin >> A[(i*n_colonne)%(n_strati*n_righe*n_colonne) + i/(n_strati*n_righe)];

}
*/
// POST = (A viene vista come Y[lim1][lim2][lim3] e riempito per V-fette con M valori, dove M=min(lim1*lim2*lim3, n_ele))


// PRE = (cin contiene N >0 interi qualsiasi) 
void leggiV(int* A, int n_strati, int n_righe, int n_colonne, int N){
    
    bool continua=true;
    
    // PRE1 = (continua == true) & (N>0, n_strati>0, n_righe>0, n_colonne>0) & (non ho riempito nessuna V-fetta)
    for (int c=0; c<n_colonne & continua; c=c+1){
    // R1 = (0<=c<=n_colonne) & (ho riempito le V-fette [0...c-1]) & (continua == true sse il numero di elementi letti (n_righe*c*n_strati) e' minore di N, altrimenti ne ho letti N)
        
        // PRE2 = (c fissato, ho riempito c-1 V-fette) & (continua == true sse il numero di elementi letti (n_righe*(c-1)*n_strati) e' minore di N) & (N>0) & (non ho riempito strati della V-fetta c)
        for (int s=0; s<n_strati & continua; s=s+1){
        // R2 = (0<=s<=n_strati) & (ho riempito la V-fetta negli strati [0...s-1]) & (continua == true sse il numero di elementi letti (n_righe*c*s) e' minore di N, altrimenti ne ho letti N)
            
            // PRE3 = (s e c fissati, ho riempito s-1 strati della V-fetta c) & (continua == true sse il numero di elementi letti (n_righe*c*(s-1)) e' minore di N) & (N>0) & (non ho inserito nello strato r della V-fetta c alcun elemento)
            for (int r=0; r<n_righe & continua; r=r+1){
                // R3 = (0<=r<=n_righe) & (ho riempito la V-fetta in colonna c nello strato s da 0 a r-1) & (continua == true sse il numero di elementi letti (r*c*s) e' minore di N, altrimenti ne ho letti N)
                cin >> A[s*n_righe*n_colonne+r*n_colonne+c];
                if (r*c*s>=N) continua = false;
            }
            // POST3 = (ho riempito la V-fetta in colonna c nello strato s per righe) & (continua == true sse il numero di elementi letti (n_righe*c*s) e' minore di N, altrimenti ne legge N)
        }
        // POST2 = (ho riempito la V-fetta in colonna c per strati) & (continua == true sse il numero di elementi letti (n_righe*c*n_strati) e' minore di N, altrimenti ne legge N)
    }
    // POST1 = (ho riempito l'array A per V-fette) & (il numero di elementi letti e' min(n_strati*n_righe*n_colonne, N))
}
// POST = (A viene vista come Y[lim1][lim2][lim3] e riempito per V-fette con M valori, dove M=min(n_strati*n_righe*n_colonne, N))

// PRE1 -> R1 : (continua == true) & (N>0, n_strati>0, n_righe>0, n_colonne>0) & (non ho riempito nessuna V-fetta) -> (ho riempito le V-fette [0...-1]) & (continua==true) -> 
//          -> (c=0) & (ho riempito le V-fette [0...c-1]) & (continua == true sse il numero di elementi letti (n_righe*0*n_strati) e' minore di N, altrimenti ne ho letti N) -> R1 valida

// R1 & B <C> R1 : (0<=c<=n_colonne) & (ho riempito le V-fette [0...c-1]) & (continua == true sse il numero di elementi letti (n_righe*c*n_strati) e' minore di N, altrimenti ne ho letti N) & (c<n_colonne) & (continua==true) -> 
//              -> (0<=c<n_colonne) & (ho riempito le V-fette [0...c-1]) & (continua == true sse il numero di elementi letti (n_righe*c*n_strati) e' minore di N, altrimenti ne ho letti N)
//              <C>
//              Alla fine del ciclo for_2 vale POST2, ovvero 
//              (ho riempito la V-fetta in colonna c per strati) & (continua == true sse il numero di elementi letti (n_righe*c*n_strati) e' minore di N, altrimenti ne legge N)
//              Viene incrementato c -> R1 valida


// R1 & !B -> POST1 : (0<=c<=n_colonne) & (ho riempito le V-fette [0...c-1]) & (continua == true sse il numero di elementi letti (n_righe*c*n_strati) e' minore di N, altrimenti ne ho letti N) & ((c>=n_colonne) || (continua==false)) ->
//                  -> 2 casi:
//                  1) (0<=c<=n_colonne) & (ho riempito le V-fette [0...c-1]) & (continua == true sse il numero di elementi letti (n_righe*c*n_strati) e' minore di N, altrimenti ne ho letti N) & (c>=n_colonne) ->
//                  -> (c=n_colonne) & (ho riempito tutte le V-fette) & (continua == true sse il numero di elementi letti (n_righe*n_colonne*n_strati) e' minore di N, altrimenti ne ho letti N) -> 
//                  -> (ho riempito tutte le V-fette) & (ho letto un numero di elementi pari a (n_righe*n_colonne*n_strati) < N) -> POST3 verificata
//                  2) (0<=c<=n_colonne) & (ho riempito le V-fette [0...c-1]) & (continua == true sse il numero di elementi letti (n_righe*c*n_strati) e' minore di N, altrimenti ne ho letti N) & (continua==false) ->
//                  -> (ho riempito le V-fette [0...c-1]) & (il numero di elementi letti (n_righe*c*n_strati) e' maggiore o uguale di N) -> 
//                  -> (ho riempito le V-fette [0...c-1]) & (ho letto un numero di elementi pari a N <=(n_righe*n_colonne*n_strati)) -> POST3 verificata


// PRE2 -> R2 : (c fissato, ho riempito c-1 V-fette) & (continua == true sse il numero di elementi letti (n_righe*(c-1)*n_strati) e' minore di N) & (N>0) & (non ho riempito strati della V-fetta c) ->
//          -> (s=0) & (ho riempito la V-fetta negli strati [0...-1]) & (continua == true sse il numero di elementi letti (n_righe*c*s) e' minore di N, altrimenti ne ho letti N) & (N>0) ->
//          -> (s=0) & (ho riempito la V-fetta negli strati [0...s-1]) & (continua == true sse il numero di elementi letti (n_righe*c*0) e' minore di N, altrimenti ne ho letti N) -> R2 valida

// R2 & B <C> R2 : (0<=s<=n_strati) & (ho riempito la V-fetta negli strati [0...s-1]) & (continua == true sse il numero di elementi letti (n_righe*c*s) e' minore di N, altrimenti ne ho letti N) & (s<n_strati) & (continua==true) ->
//              -> (0<=s<n_strati) & (ho riempito la V-fetta negli strati [0...s-1]) & (continua == true sse il numero di elementi letti (n_righe*c*s) e' minore di N, altrimenti ne ho letti N)
//              <C>
//              Alla fine del ciclo for_3 vale POST3, ovvero
//              (ho riempito la V-fetta in colonna c nello strato s per righe) & (continua == true sse il numero di elementi letti (n_righe*c*s) e' minore di N, altrimenti ne legge N)
//              Viene incrementato s -> R2 valida

// R2 & !B -> POST2 : (0<=s<=n_strati) & (ho riempito la V-fetta negli strati [0...s-1]) & (continua == true sse il numero di elementi letti (n_righe*c*s) e' minore di N, altrimenti ne ho letti N) & ((s>=n_strati) || (continua==false)) ->
//                  -> 2 casi:
//                  1) (0<=s<=n_strati) & (ho riempito la V-fetta negli strati [0...s-1]) & (continua == true sse il numero di elementi letti (n_righe*c*s) e' minore di N, altrimenti ne ho letti N) & (s>=n_strati) ->
//                  -> (s=n_strati) & (ho riempito la V-fetta in tutti gli strati) & (continua == true sse il numero di elementi letti (n_righe*c*n_strati) e' minore di N, altrimenti ne ho letti N) -> POST3 verificata
//                  2) (0<=s<=n_strati) & (ho riempito la V-fetta negli strati [0...s-1]) & (continua == true sse il numero di elementi letti (n_righe*c*s) e' minore di N, altrimenti ne ho letti N) & (continua==false) ->
//                  -> (ho riempito la V-fetta negli strati [0...s-1]) & (il numero di elementi letti (n_righe*c*s) e' maggiore o uguale a N) ->
//                  -> (ho riempito la V-fetta negli strati [0...s-1]) & (ho letto N elementi) -> POST2 verificata



// PRE3 -> R3 : (s e c fissati, ho riempito s-1 strati della V-fetta c) & (continua == true sse il numero di elementi letti (n_righe*c*(s-1)) e' minore di N) & (N>0) & (non ho inserito nello strato r della V-fetta c alcun elemento) ->
//          -> (continua == true sse il numero di elementi letti (r*c*s) e' minore di N, altrimenti ne ho letti N) & (N>0) & (ho riempito la V-fetta in colonna c nello strato s da 0 a -1) ->
//          -> (continua == true sse il numero di elementi letti (0*c*s) e' minore di N, altrimenti ne ho letti N) & (N>0) & (ho riempito la V-fetta in colonna c nello strato s da 0 a r-1) & (r=0) ->  
//          -> R3 valida

// R3 & B <C> R3 : (0<=r<=n_righe) & (ho riempito la V-fetta in colonna c nello strato s da 0 a r-1) & (continua == true sse il numero di elementi letti (r*c*s) e' minore di N, altrimenti ne ho letti N) & (r<n_righe) & (continua==true) ->
//              -> (0<=r<n_righe) & (ho riempito la V-fetta in colonna c nello strato s da 0 a r-1) & (continua == true sse il numero di elementi letti (r*c*s) e' minore di N, altrimenti ne ho letti N)
//              <C>
//              Viene letto da cin l'elemento A[s][r][c], quindi vale (ho riempito la V-fetta in colonna c nello strato s da 0 a r)
//              continua viene impostato a false sse r*c*s >= N, quindi vale (continua == true sse il numero di elementi letti (r*c*s) e' minore di N, altrimenti ne ho letti N)
//              Viene incrementato r -> R3 valida


// R3 & !B -> POST3 : (0<=r<=n_righe) & (ho riempito la V-fetta in colonna c nello strato s da 0 a r-1) & (continua == true sse il numero di elementi letti (r*c*s) e' minore di N, altrimenti ne ho letti N) & ((r>=n_righe) || (continua==false))
//                  -> 2 casi:
//                  1) (0<=r<=n_righe) & (ho riempito la V-fetta in colonna c nello strato s da 0 a r-1) & (continua == true sse il numero di elementi letti (r*c*s) e' minore di N, altrimenti ne ho letti N) & (r>=n_righe) ->
//                  -> (r=n_righe) & (ho riempito la V-fetta in colonna c nello strato s per righe) & (continua == true sse il numero di elementi letti (n_righe*c*s) e' minore di N, altrimenti ne ho letti N) -> POST3 verificata
//                  2) (0<=r<=n_righe) & (ho riempito la V-fetta in colonna c nello strato s da 0 a r-1) & (continua == true sse il numero di elementi letti (r*c*s) e' minore di N, altrimenti ne ho letti N) & (continua==false) ->
//                  -> (ho riempito la V-fetta in colonna c nello strato s da 0 a r-1) & (il numero di elementi letti (r*c*s) e' maggiore o uguale a N) ->
//                  -> (ho riempito la V-fetta in colonna c nello strato s da 0 a r-1) & (ho letto N elementi) -> POST3 verificata



void stampaS(int *A,int n_strati, int n_righe, int n_colonne){
	
	for (int i=0; i < n_strati*n_righe*n_colonne; i=i+1){
		
		if (i%(n_righe*n_colonne)==0) 
			cout << endl << "strato:" << i/(n_righe*n_colonne);
		
		if (i%n_colonne==0)
			cout << endl ;
		
		cout << *(A+i) << " ";
	}
	cout << endl;
}

main()
{
	int X[400];
	
	for(int i=0; i<400; i=i+1)
		X[i]=-1;
	
	int lim1,lim2,lim3,n_ele;
	cin >> lim1 >>lim2>>lim3 >>n_ele;
	
	leggiV(X,lim1,lim2,lim3,n_ele);
	
	cout<<"start"<<endl;
	
	stampaS(X,lim1,lim2,lim3);
	
	cout<<"end"<<endl;

}
