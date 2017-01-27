#include <iostream>
using namespace std;
//PRE: T[n*n] array definito, P[n] array definito
int *F(int *T, int n, int *P){
	int z=0, match=n;
	int *R = new int [n];
	bool stop=false;
	for(int c=0; c<n && !stop; c++){//R1: 0<=c<=n, stop sse non esiste nessun P[0] nella colonna T[][c]
		bool trovato=false;
		for(int r=z; r<n && !trovato; r++){//R2: 0<=z<=r<=n, trovato sse esiste un T[a*n+c]=P[c] con a in [z...r-1] && z=a, match decrementato 
			if(T[r*n+c]==P[c]){				// di uno && R[c]=a
				R[c]=r; trovato=true;
				z=r; match--;
			}
		}//POST2: trovato sse trovato sse esiste un T[r*n+c]=P[c] && z=r, match decrementato di uno && R[c]=r
		if(!trovato)
			stop=true;
	}
	if(!match)
		return R;
	else
		return 0;
}
//POST: se è stato trovato un match restituisce l'array R, in cui R[a]=(num di riga in cui è stato trovato P[a]) con a in [0..n]

main(){
	int n=3, P[3]={7,8,4}, T[9]={7,9,2, 8,8,4, 10,8,10};
	int*R=F(T, n, P);
	if(R){
	for(int i=0; i<n; i++)
		cout << R[i] << " ";}
	cout << endl;
}
