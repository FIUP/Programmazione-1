bool cerca(int *A, int top, int y, int & start, int & quanti){
	bool trovato = false;
	for(int i =0; i<top && A[i]<=y && !trovato; i++)
		if(A[i]==y){
			trovato = true;
			start = i;
		} 
	if(trovato){
		quanti=1;
		for(int i=start+1; i<top && A[i]==y;i++)
			quanti++;
		}
	return trovato;
}

void shift(int *A, int &top, int start, int quanti){
	for(int i=start; i<top-quanti;i++)
		A[i] = A[i+quanti];
	top -= quanti;
}

void F(int *A, int& top, int y){
	int start,quanti;
	if(cerca(A,top,y,start,quanti))
		shift(A,top,start,quanti);
}

main(){
	//main vuoto
}