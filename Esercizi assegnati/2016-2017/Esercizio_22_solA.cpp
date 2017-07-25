// soluzione di B.Cosentino
#include<iostream>
using namespace std;

main()
{
    int A[6][8]; bool B[6][8];
    for(int i=0; i<6; i=i+1)
     for(int j=0; j<8; j=j+1)
        cin>> A[i][j];
    
    
    for (int i=0; i<6; i=i+1){ // R1 = (0<=i<=6) && (le righe [0...i-1] di B sono state riempite correttamente)
    	for (int j=0; j<8; j=j+1){ // R2 = (0<=j<=8) && (la riga i e' stata riempita fino alla posizione j-1 correttamente)
    		bool OK=true;
    		
    		for (int k=0; k<8 && OK; k=k+1){  // R3 = (0<=k<=8) && (OK==true sse gli elementi [0...k-1] della riga i sono contenuti nella colonna j)
    			OK= false;
    			for (int l=0; l<6 && !OK; l=l+1){  // R4 = (0<=l<=6) && (OK==true sse esiste un elemento in [0...l-1] della colonna j uguale a A[i][k])
    				if (A[i][k]==A[l][j])
    					OK=true;
    			}	
    			// POST4 = (OK==true sse esiste nella colonna j un elemento uguale a A[i][k])
    		}	
    		// POST3 = (OK==true sse tutti gli elementi della riga i sono contenuti nella colonna j)
    		B[i][j]=OK;		
    	}
    	// POST2 = la riga i e' stata riempita correttamente
    }
    // POST1 = la matrice B e' stata riempita correttamente
    for(int i=0; i<6; i=i+1)
     {
      for(int j=0; j<8; j=j+1)
        cout << B[i][j]<<' ';
      cout<<endl;
     }
}

// PRE3 -> R3 : (OK==true) & (k=0) -> (gli elementi [0,-1] della riga i (ovvero l'insieme vuoto) sono contenuti nella colonna j) -> R3 valida

// R3 & condperm -> R3 : (0<=k<=8) & (OK==true sse gli elementi [0...k-1] della riga i sono contenuti nella colonna j) & (OK==true) & (k<8) ->
//                      -> (k<8) & (gli elementi [0...k-1] della riga i sono contenuti nella colonna j)
//                      <C>
//                      OK == false. Alla fine del ciclo for_4 vale POST4 -> OK == true sse esiste nella colonna j un elemento uguale a A[i][k].
//                      Quindi, varra' che OK==true sse gli elementi [0...k] della riga i sono contenuti nella colonna j.
//                      Infine, viene effettuato l'incremento -> (0<=k<=8) && (OK==true sse gli elementi [0...k-1] della riga i sono contenuti nella colonna j) = R3


// R3 & !condperm -> POST3 : (0<=k<=8) & (OK==true sse gli elementi [0...k-1] della riga i sono contenuti nella colonna j) & ((OK==false) || (k>=8)) ->
//                           -> 2 casi:  1) (k=8) & (OK==true sse gli elementi [0...7] della riga i sono contenuti nella colonna j) -> POST3
//                                       2) (OK==false) & (OK==true sse gli elementi [0...k-1] della riga i sono contenuti nella colonna j) ->
//                                       -> (esiste un elemento tra i [0...k-1] della riga i non contenuto nella colonna j) ->
//                                       -> (OK==false sse esiste un elemento tra i [0...k-1] della riga i non contenuto nella colonna j) ->
//                                       -> (OK==false sse esiste un elemento della riga i non contenuto nella colonna j) ->
//                                       -> (OK==true sse tutti gli elementi della riga i sono contenuti nella colonna j) -> POST3 valida

// PRE4 -> R4 : (OK==false) & (l=0) -> (non esiste un elemento in [0,-1] della colonna j uguale a A[i][k]) -> R4 valida

// R4 & condperm -> R4 : (0<=l<=6) & (OK==true sse esiste un elemento in [0...l-1] della colonna j uguale a A[i][k]) & (l<6) & (OK==false) ->
//                       -> (l<6) & (tutti gli elementi in [0...l-1] della colonna j sono diversi da A[i][k]).
//                      <C>
//                      OK all'inizio e' uguale a false. 
//                      OK viene impostato a true sse A[i][k] == A[l][j] -> OK==true sse esiste un elemento in [0...l] della colonna j uguale a A[i][k].
//                      Infine, l viene incrementato -> (0<=l<=6) && (OK==true sse esiste un elemento in [0...l-1] della colonna j uguale a A[i][k]) = R4


// R4 & !condperm -> POST4 : (0<=l<=6) & (OK==true sse esiste un elemento in [0...l-1] della colonna j uguale a A[i][k]) & ((l>=6) || (OK==true)) -> 
//                           -> 2 casi: 1) (l=6) & (OK==true esiste un elemento in [0...7] della colonna j uguale a A[i][k]) -> POST4 valida
//                                      2) (OK==true) & (OK==true esiste un elemento in [0...l-1] della colonna j uguale a A[i][k]) ->
//                                      -> (esiste un elemento in [0...l-1] della colonna j uguale a A[i][k]) -> POST4 valida
