#include <iostream>
#include <fstream>

using namespace std;


//PRE_allungaArray=(X è un array dinamico di dim_array>=20 interi)
void allungaArray(int *&X, int &dim_array){

	int *new_X=new int[dim_array+20];
	for(int i=0; i<dim_array; i++)
		new_X[i]=X[i];
	delete []X;
	X=new_X;
	dim_array+=20;

}//POST_allungaArray=(alloca un nuovo array di dim_array+20 posizioni e si occupa di cancellare il vecchio array)

//PRE_aggiungiSequenza=(X è un array di dim_array>=20 elementi, dove, per ogni i in [0, lim-2], X[2*i] è l'indice dove inizia la sequenza (i+1)-esima e X[2*i+1] è la lunghezza della sequenza (i+1)-esima; lim è il numero di sottosequenze; inizio è l'indice dove inizia la sequenza lim-esima; lunghezza è la lunghezza della sequenza lim-esima)
void aggiungiSequenza(int *&X, int &dim_array, int lim, int inizio, int lunghezza){

	if(dim_array<lim*2)
		allungaArray(X, dim_array);
	X[(lim-1)*2]=inizio;
	X[(lim-1)*2+1]=lunghezza;

}//POST_aggiungiSequenza=()


// PRE_IC = (C è costituita da n>=0 sottosequenze di interi, ciascuna terminante con -1 e la fine delle sottosequenze è segnata da -2)
int * IC(int *C, int &lim){

	int indice=0;				//indice di C
	int *X=new int[20];			//array [inidice|lunghezza] da ritornare col return
	int lunghezza=0;			//lunghezza sequenza i-esima
	int dim_array=20;			//lunghezza iniziale dell'array X
	while( C[indice]!=-2 ){
		//R=(X è un array di dim_array elementi con lim*2 elementi definiti e lim<n)
		if( C[indice]==-1 ){
			lim++;
			aggiungiSequenza(X, dim_array, lim, indice-lunghezza, lunghezza);
			lunghezza=0;
		}else	lunghezza++;
		indice++;
	}
	return X;

}// POST_IC = (alla fine di IC, il valore di lim è il numero di sottosequenze presenti in C, IC restituisce col return un array X allocato dinamicamente in IC tale che per ogni i in [0, lim-1] contiene in X[2*i] l'indice in cui inizia in C la sottosequenza di indice i e in X[2*i+1] contiene la lunghezza della sottosequenza di indice i)


//PRE_confrontaSequenze(C lista di sottosequenze, X l'array prodotto da IC con input C, 0<=seq_lunga<lim indice della sequenza più lunga, 0<=seq_corta<lim indice della sequenza più corta, 0<=lung_match<=X[2*seq_corta+1] lunghezza del match delle sottosequenze della sequenza seq_corta nella sequenza seq_lunga)
bool confrontaSequenze(int *C, int *X, int seq_lunga, int seq_corta, int lung_match){

	if(lung_match==X[2*seq_corta+1])
		return true;
	if(C[X[2*seq_lunga]+lung_match]!=C[X[2*seq_corta]+lung_match])
		return false;
	return confrontaSequenze(C, X, seq_lunga, seq_corta, lung_match+1);

}//POST_confrontaSequenze(true se la sottosequenza della sequenza seq_corta è contenuta nella sequenza seq_lunga; false altrimenti)


//PRE_matchSequenza=(C lista di sottosequenze, X l'array prodotto da IC con input C, 0<=j<lim indice della sequenza, j+1<=j_succ<lim indice delle sequenze successive, lim>0 è il numero di coppie in X (cioè il numero delle sequenze), Z di lim elemento con valori >=0)
void matchSequenza(int *C, int *X, int j, int j_succ, int lim, int *Z){

	if(j_succ<lim){
		if(X[j*2+1]==X[j_succ*2+1]){
			if(confrontaSequenze(C, X, j, j_succ, 0)){ //cerca se sono uguali
				Z[j]++;
				Z[j_succ]++;
			}
		}else{
			if(X[j*2+1]>X[j_succ*2+1]){
				if(confrontaSequenze(C, X, j, j_succ, 0)) //cerca se j include j_succ
					Z[j]++;
			}else{ 
				if(confrontaSequenze(C, X, j_succ, j, 0)) //cerca se j_succ include j
					Z[j_succ]++;
			}
		}
		matchSequenza(C, X, j, j_succ+1, lim, Z);
	}

}//POST_matchSequenza=(per ogni 0<=i<lim, Z[i] è il numero di volte che le sottosequenze della sequenza i-esima sono contenute nelle altre sequenze)


//PRE_M=(C lista di sottosequenze, X l'array prodotto da IC con input C, lim= n. di coppie in X, lim>=0, j in [0,lim-1], Z di lim elementi con valori >=0, con vZ indichiamo il valore iniziale di Z)
void M(int *C, int *X, int lim, int j, int *Z){

	if(j<lim-1){
		matchSequenza(C, X, j, j+1, lim, Z);
		M(C, X, lim, j+1, Z);	
	}


}//POST_M=(per ogni n in [j..lim-1], Z[n]=vZ[n]+q dove q è il numero di sottosequenze in [j..lim-1] (distinte dalla n) che sono contenute nella sottosequenza n)


main(){
	try{
		ifstream INP("input");
		ofstream OUT("output");
		if(!INP) throw(0);
		if(!OUT) throw(1);
		int C[200];
		int x=0, lim=0;
		for(int i=0; x!=-2; i++){
			INP>>x; 
			C[i]=x;
		}
		int* X=IC(C,lim);
		
		for(int i=0; i<lim; i++)
			OUT<<X[i*2]<<' '<<X[i*2+1]<<endl;

		int *Z=new int[lim];
		for(int i=0; i<lim; i++)
			Z[i]=0;

		M(C,X,lim,0,Z);
		
		for(int i=0; i<lim; i++)
			OUT<<Z[i]<<' ';
		OUT<<endl;
	}catch(int x){
		switch(x){
			case 0: cout<<"problemi con input"<<endl; break;
			case 1: cout<<"problemi con output"<<endl; break;
		}
	}
}