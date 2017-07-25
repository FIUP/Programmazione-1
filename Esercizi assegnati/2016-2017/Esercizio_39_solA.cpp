// soluzione di B.Cosentino
#include<iostream>
using namespace std;
// PRE = (C è costituita da n>=0 sottosequenze di interi, ciascuna terminante con -1 e la fine delle sottosequenze è segnata da -2, X ha almeno 2*n elementi) & (lim=0)
void IC(int C[], int X[], int &lim){
	
	int start=0;  // variabile per l'inizio della sottosequenza
	int i=0;  // indice per Y
    
    // PRE_while = (C è costituita da n>=0 sottosequenze di interi, ciascuna terminante con -1 e la fine delle sottosequenze è segnata da -2, X ha almeno 2*n elementi) & (lim=0) & (lung=0) & (start=0) & (i=0)
	while (C[i]!=-2){  // finche' non finisco la sequenza
	
	// R = (0<=i<=x, dove C[x]==-2) & (start == indice d'inizio della sottosequenza lim) & (lim == numero di sottosequenze presenti in C[0...i-1]) &
	//      & (X contiene, per ogni k in [0, lim-1], in X[2*k] l'indice in cui inizia in C la sottosequenza di indice k e in X[2*k+1] la lunghezza della sottosequenza di indice k)
		
		if (C[i]==-1){  // se trovo la fine di una sottosequenza
			
			X[2*lim]=start;   // scrivo nella corrispondente posizione di X il punto di inizio
			
			X[2*lim+1]=i-start;  // scrivo nella corrispondente posizione di X la lunghezza della sottosequenza
			
			start=i+1;  // imposto il punto di inizio della prossima sequenza
			lim+=1;  // incremento il contatore delle sottosequenze
		}
		
		i=i+1;  // incremento l'indice di C
	}
	// POST_while = (il valore di lim è il numero di sottosequenze presenti in C e l’array X contiene, per ogni i in [0, lim-1], in X[2*i] l'indice in cui inizia in C la sottosequenza di indice i e in X[2*i+1] la lunghezzadella sottosequenza di indice i)
}
// POST = (alla fine di IC, il valore di lim è il numero di sottosequenze presenti in C e l’array X contiene, per ogni i in [0, lim-1], in X[2*i] l'indice in cui inizia in C la sottosequenza di indice i e in X[2*i+1] la lunghezzadella sottosequenza di indice i)

/**************************************************************
DIMOSTRAZIONE
PRE_while -> R : (C è costituita da n>=0 sottosequenze di interi, ciascuna terminante con -1 e la fine delle sottosequenze è segnata da -2, X ha almeno 2*n elementi) & (lim=0) & (start=0) & (i=0)
                -> (i=0) & (start == 0 == indice d'inizio della sottosequenza 0) & (lim == 0 == numero di sottosequenze presenti in C[0...-1]) &
                & (X contiene, per ogni k in [0, -1], in X[2*k] l'indice in cui inizia in C la sottosequenza di indice k e in X[2*k+1] la lunghezza della sottosequenza di indice k) -> 
                -> R valida
                
R & B <C> R : (0<=i<=x, dove C[x]==-2) & (start == indice d'inizio della sottosequenza lim) & (lim == numero di sottosequenze presenti in C[0...i-1]) &  
            & (X contiene, per ogni k in [0, lim-1], in X[2*k] l'indice in cui inizia in C la sottosequenza di indice k e in X[2*k+1] la lunghezza della sottosequenza di indice k) &
            & (C[i]!=-2) ->
            -> (0<=i<x, dove C[x]==-2) & (start == indice d'inizio della sottosequenza lim) & (lim == numero di sottosequenze presenti in C[0...i-1]) &  
            & (X contiene, per ogni k in [0, lim-1], in X[2*k] l'indice in cui inizia in C la sottosequenza di indice k e in X[2*k+1] la lunghezza della sottosequenza di indice k)
            
            <C>
            2 CASI:
            1) se non trovo la fine di una sottosequenza, continuo a cercarla e incremento i di 1 -> 
                -> (0<=i<=x, dove C[x]==-2) & (start == indice d'inizio della sottosequenza lim) & (lim == numero di sottosequenze presenti in C[0...i-1]) &  
                & (X contiene, per ogni k in [0, lim-1], in X[2*k] l'indice in cui inizia in C la sottosequenza di indice k e in X[2*k+1] la lunghezza della sottosequenza di indice k) ->
                -> R valida
            
            2) se trovo la fine di una sottosequenza, 
            
                X[2*lim]=start;  scrivo l'indice di inizio della precedente sequenza in X 
                
                X[2*lim-1]=i-start;  scrivo la lunghezza della precedente sottosequenza in X
                
                start=i+1;  imposto il punto di inizio della prossima sequenza -> start==indice della sottosequenza lim+1
                lim+=1;  incremento il contatore delle sottosequenze -> start==indice della sottosequenza lim
                
                infine incremento i di 1;
                
                -> (0<=i<=x, dove C[x]==-2) & (start == indice d'inizio della sottosequenza lim) & (lim == numero di sottosequenze presenti in C[0...i-1]) &  
                & (X contiene, per ogni k in [0, lim-1], in X[2*k] l'indice in cui inizia in C la sottosequenza di indice k e in X[2*k+1] la lunghezza della sottosequenza di indice k) ->
                -> R valida

R & !B -> POST_while : (0<=i<=x, dove C[x]==-2) & (start == indice d'inizio della sottosequenza lim) & (lim == numero di sottosequenze presenti in C[0...i-1]) &
                    & (X contiene, per ogni k in [0, lim-1], in X[2*k] l'indice in cui inizia in C la sottosequenza di indice k e in X[2*k+1] la lunghezza della sottosequenza di indice k) &
                    & (C[i]==-2) -> 
                    -> (i=x, dove C[x]==-2) & (start == indice d'inizio della sottosequenza lim) & (lim == numero di sottosequenze presenti in C) &
                    & (X contiene, per ogni k in [0, lim-1], in X[2*k] l'indice in cui inizia in C la sottosequenza di indice k e in X[2*k+1] la lunghezza della sottosequenza di indice k) -> 
                    -> POST_while valida.

**************************************************************/
main(){
	int C[200], X[200];
	int x=0, lim=0;
	
	for(int i=0; x!=-2; i++)
		{cin>>x; C[i]=x;}
	cout<<"start"<<endl;
	
	IC(C,X,lim);//da fare
	
	for(int i=0; i<lim; i++)
		cout<<X[i*2]<<' '<<X[i*2+1]<<endl;

	cout<<"end"<<endl;
}
