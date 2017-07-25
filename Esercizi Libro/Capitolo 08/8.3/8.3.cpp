bool MT(char*T, char *P, int dim_P){
	bool ok = true;
	for(int i=0; i<dim_P && ok; i++)
		if(T[i] != P[i])
			ok=false;
	return ok;
}

int match(char *T, int lim, char *P, int dim_P){
	int nmatch=0;
	for(int i=0; i < lim-dim_P+1; i++)
		if(MT(T+i,P,dim_P))
			nmatch++;
	return nmatch;
} //POST = (nmatch = numero di match di P in T[0...lim-1])

char *F(char(*T)[10][15], int limite1, char *P, int dim_P){
	int nmax=0;								// massimo numero di match di P sugli strati 0...,i-1, 
	char * Q=**T;							//puntatore al primo elemento dello strato con nmax
	for(int i=0; i< limite1; i++){ 			//i = strati
		int n=0;							//n = numero di match nello strato i 
		for(int j=0; j<10;j++)				//j = righe
			n+=match(T[i][j],15,P,dim_P);
		if(n>nmax){
			nmax=n;
			Q=T[i][0];
		}
	}	
	return Q;
} //POST = (Q punta al primo elemento di uno strato con massimo numero di match)

main(){
	//main vuoto
}