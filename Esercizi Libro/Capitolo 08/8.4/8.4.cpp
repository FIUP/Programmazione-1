bool MT(char*T, char *P, int dim_P){
	bool ok = true;
	for(int i=0; i<dim_P && ok; i++)
		if(T[i] != P[i])
			ok=false;
	return ok;
}

int matchG(char *T, int lim, char *P, int dim_P){
	int nmatch = 0, incr=1;
	
	for(int i=0; i<lim-dim_P+1; i = i+incr)
		if(MT(T+i, P, dim_P)){
			nmatch++;
			incr=dim_P;
		}
		else
			incr=1;
	return nmatch;						//nmatch = numero di match non sovrapposti di P in T[0...lim-1]
}

char *G(char(*T)[10][15], int limite1, char *P, int dim_P){
	int nmax=0;							//nmax = numero massimo di match non sovrapposti di P sugli strati 0...i-1
	char *Q=**T;						//Q = puntatore allo stato con nmax
	for(int i=0; i< limite1; i++){
		int n=0;						//n = numero di match di P nello strato i (con match anche su più righe)
		n+=matchG(T[i][0],150,P,dim_P);
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