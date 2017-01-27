//PRE: x e' un intero definito
int traduci(int x){
	if(x>=0)
		return 1;
	else
		return -1;
}
//POST: x>=0 => 1 && x<0 => -1

//PRE: B[i+1] è bilancio max tra gli intervalli con inizio in i+1
void fixB(int*A,int*B, int i){
	if(B[i+1]>0)
		B[i]=traduci(A[i])+B[i+1];
	else
		B[i]=traduci(A[i]);
}
//POST: B[i] è bilancio max tra gli intervalli con inizio in i

//PRE: A definito, inizio >= 0, bilancio è il "bilancio" massimo a partire da inizio
int lunghezza(int *A, int inizio, int bilancio) {
	int bil = (A[inizio] >= 0) ? 1 : -1;
	int fine = inizio+1;
	while (bil != bilancio){
		if (A[fine] >= 0)
			bil++;
		else
			bil--;
		fine++;
	}
	return fine - inizio;
}
//POST: restituisce la lunghezza più corta a bilancio massimo in A

//PRE: A[0..lim-1] e B[0..lim-1] sono definiti e lim>0
interv F(int*A,int*B,int lim){ 
	B[lim-1]=traduci(A[lim-1]);
	int pos=lim-1;
	for(int i=lim-2; i>=0; i--){//R: per ogni a in [i+1..lim-1], B[a] contiene bilancio max interv
		fixB(A,B,i);	// con inizio in a && B[pos] è max in B[i+1..lim-1] && -1<=i<=lim2
		if(B[i]>B[pos])
			pos=i;
	}

	interv I;
	I.inizio = pos;
	I.lunghezza = lunghezza(A, pos, B[pos]);
	
	return I;
}
//POST: restituisce valore Y di tipo interv tale che A[Y.inizio ... Y.inizio+Y.lunghezza-1] è un 
//	intervallo di A che ha bilancio massimo

/*
CONDIZIONE INIZIALE: i=lim-2 => a=lim-1, B[a] contiene il bilancio massimo poichè era già stato 
		       precedentemente analizzato e pos=lim-1 poichè è l'unico elemento

INVARIANZA: prima dell'iterazione pos è l'indice in cui c'è il bilancio massimo tra i+2 .. lim-1 e 
	   		in ogni elemento di B tra i+2 e lim-1 è presente il bilancio massimo a partire dalla 
	    	propria posizione, dopo l'iterazione B[i-1] è il bilancio massimo a partire da 
	   		i-1 e se B[i-1]>B[pos] allora pos diventa i-1.

CONDIZIONE D'USCITA: i=-1 allora tutto l'array B è stato riempito correttamente e B[pos] è massimo 
		     		 tra i+1=0 e lim-1.
                      
Restituisce (5,3) 
*/
