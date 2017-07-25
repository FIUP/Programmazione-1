// soluzione di B.Cosentino
#include<iostream>
using namespace std;

int main() {
	int A[8][6];
	bool B[8][6];
	int* p=*A;

	for (int i=0; i<8; i++){
	    for (int j=0; j<6; j=j+1){
	        cin >> A[i][j];
	    }
	}

	for (int i=0; i<8; i=i+1){ // R1 = (0<=i<=8) & (le righe [0...i-1] di B sono state riempite correttamente)
		for (int j=0; j<6; j=j+1){ // R2 = (0<=j<=6) & (la riga i di B e' stata riempita correttamente fino alla posizione j-1)
			bool OK=true;
			
			bool X[8]={0,0,0,0,0,0,0,0};
			for (int k=0; k<6 && OK; k=k+1){    
			// R3 = (0<=k<=6) & (OK==true sse gli elementi [0...k-1] della riga i di A sono uguali a degli elementi distinti della colonna j)
				OK=false;
				for (int l=0; l<8 && !OK; l=l+1){ 
				// R4 = (0<=l<=8) & (OK==true sse esiste un elemento in [0...l-1] della colonna j di A uguale a A[i][k] e A[i][k] e' associato a un solo elemento in [0...l-1] della colonna j)
					if (A[i][k]==A[l][j] && !X[l]){
						OK=true;
						X[l]=true;
					}
				}
				// POST4 = OK==true sse esiste un elemento della colonna j di A uguale a A[i][k] e A[i][k] e' associato a un solo elemento della colonna j
			}
			// POST3 = OK==true sse tutti gli elementi della riga i sono uguali a degli elementi distinti della colonna j
			B[i][j]=OK;
		}
	}

    for(int i=0; i<8; i++) {
        for (int j=0; j<6; j++)
         cout<<B[i][j]<<' ';
        cout<<endl;
    }
    cout << "end" << endl;
}

// PRE -> R3 : (OK==true) & (k=0) & (gli elementi [0...-1] della riga i di A sono uguali a elementi distinti della colonna j) -> R3 valida

// R3 & condperm -> R3 : (0<=k<=6) & (OK==true sse gli elementi [0...k-1] della riga i di A sono uguali a degli elementi distinti della colonna j) & (k<6) & (OK==true) ->
//                      -> (0<=k<6) & (gli elementi [0...k-1] della riga i di A sono uguali a degli elementi distinti della colonna j) & (OK==true)
//                      <C>
//                      OK = false.
//                      Alla fine del ciclo for_4 vale POST 4.
//                      Quindi, OK==true sse esiste un elemento della colonna j di A uguale a A[i][k] e A[i][k] e' associato a un solo elemento della colonna j.
//                      Quindi, vale (OK==true sse gli elementi [0...k] della riga i di A sono uguali a degli elementi distinti della colonna j).
//                      Infine, k viene incrementato -> (OK==true sse gli elementi [0...k-1] della riga i di A sono uguali a degli elementi distinti della colonna j) = R3

// R3 & !condperm -> POST3 : (0<=k<=6) & (OK==true sse gli elementi [0...k-1] della riga i di A sono uguali a degli elementi distinti della colonna j) & ((k>=6) || (OK==false)) ->
//                          -> 2 casi:
//                          1) (k=6) & (OK==true sse gli elementi [0...k-1] della riga i di A sono uguali a degli elementi distinti della colonna j) -> 
//                              -> (OK==true sse gli tutti elementi della riga i di A sono uguali a degli elementi distinti della colonna j) -> POST3 valida
//                          2) (OK==false) & (OK==true sse gli elementi [0...k-1] della riga i di A sono uguali a degli elementi distinti della colonna j) ->
//                              -> (esiste un elemento in [0...k-1] della riga i di A diverso da tutti gli elementi della colonna j) & (OK==false) -> 
//                              -> (esiste un elemento della riga i di A diverso da tutti gli elementi della colonna j) & (OK==false) -> 
//                              -> (OK==true sse tutti gli elementi della riga i sono uguali a degli elementi distinti della colonna j) -> POST3 valida

// PRE -> R4 : (OK==false) & (l=0) & (esiste un elemento in [0...-1] della colonna j di A uguale a A[i][k] e A[i][k] e' associato a un solo elemento in [0...-1] della colonna j) -> R4 valida

// R4 & condperm -> R4 : (0<=l<=8) & (OK==true sse esiste un elemento in [0...l-1] della colonna j di A uguale a A[i][k] e A[i][k] e' associato a un solo elemento in [0...l-1] della colonna j) &
//                      & (l<8) & (OK==false) ->
//                      -> (l<8) & (OK==false) & 
//                          & (nessun elemento in [0...l-1] della colonna j di A e' uguale a A[i][k] oppure A[i][k] non e' associato a un solo elemento in [0...l-1] della colonna j).
//                      <C> 
//                      OK e X[l] vengono impostati a true sse A[i][k]=A[l][j] e A[l][j] non e' associato a nessun altro elemento (!X[l]) -> 
//                      -> (0<=l<=8) & (OK==true sse esiste un elemento in [0...l] della colonna j di A uguale a A[i][k] e A[i][k] e' associato a un solo elemento in [0...l-1] della colonna j) ->
//                      Infine, viene incrementato l -> 
//                      -> (0<=l<=8) & (OK==true sse esiste un elemento in [0...l-1] della colonna j di A uguale a A[i][k] e A[i][k] e' associato a un solo elemento in [0...l-1] della colonna j) = R4

// R4 & !condperm -> POST4 : (0<=l<=8) & (OK==true sse esiste un elemento in [0...l-1] della colonna j di A uguale a A[i][k] e A[i][k] e' associato a un solo elemento in [0...l] della colonna j) &
//                          & ((l>=8) || (OK==true)) ->
//                          -> 2 casi:
//                          1) (l=8) & (OK==true sse esiste un elemento in [0...l-1] della colonna j di A uguale a A[i][k] e A[i][k] e' associato a un solo elemento in [0...l-1] della colonna j) ->
//                              -> (OK==true sse esiste un elemento in [0...7] della colonna j di A uguale a A[i][k] e A[i][k] e' associato a un solo elemento in [0...7] della colonna j) ->
//                              -> (OK==true sse esiste un elemento della colonna j di A uguale a A[i][k] e A[i][k] e' associato a un solo elemento della colonna j) -> POST4 valida
//                          2) (OK==true) & (OK==true sse esiste un elemento in [0...l-1] della colonna j di A uguale a A[i][k] e A[i][k] e' associato a un solo elemento in [0...l-1] della colonna j) -> 
//                              -> (OK==true) & (esiste un elemento in [0...l-1] della colonna j di A uguale a A[i][k] e A[i][k] e' associato a un solo elemento in [0...l-1] della colonna j) ->
//                              -> (OK==true) & (esiste un elemento della colonna j di A uguale a A[i][k] e A[i][k] e' associato a un solo elemento della colonna j) -> 
//                              -> (OK==true sse esiste un elemento della colonna j di A uguale a A[i][k] e A[i][k] e' associato a un solo elemento della colonna j) -> POST4
