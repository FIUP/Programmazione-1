#include<climits>
int somma(int (*S)[10]){
	int somma=0;
	for(int i=0; i<5;i++)
		for(int j=0;j<10;j++)
			somma += S[i][j];
	return somma;
} //somma = somma di S[5][10]

int somma_inc(int (*S)[10], int ne){
	int nrp=ne/10, somma=0, eur=ne%10;
	for(int i=0;i<nrp;i++){
		for(int j=0; j<10;j++)
			somma+=S[i][j];
	}
	for(int i=0;i<eur;i++)
		somma+=S[nrp][i];
	return somma;
}


//PRE = (n_ele >=0 e i primi n_ele elementi di A sono definiti)
int F(int (*A)[5][10], int limite1, int n_ele){
	int n_sp=n_ele/(5*10); //n_sp = numero di strati completi
	int n_eu=n_ele%(5*10); //n_eu = numero di elementi ultimo strato

	int sommaM = INT_MIN, indice =0;
	for(int i=0; i<n_sp; i++){
		int S = somma(*(A+i));
		if(S > sommaM){
			sommaM=S;
			indice =i;
		}
	} //POST1= (A[indice] ha sommaM che è massima tra gli strati A[=...n_sp-1] completi)
	if(n_eu > 0){ //consideriamo ora lo strato incompleto
		int S = somma_inc(*(A+n_sp),n_eu);
		if(S > sommaM)
			indice = n_sp;
	} //(A[indice] ha sommaM che è massima tra gli strati A[0...n_sp], contando solo gli elementi definiti)
	return indice;
} //POST = (A[indice] ha somma degli elementi definiti massima tra gli strati che contengono qualche elemento definito)

main(){
	//main vuoto non serve ai fini dell'esercizio
}