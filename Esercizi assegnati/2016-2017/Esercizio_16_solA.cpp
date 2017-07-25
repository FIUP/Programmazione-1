// soluzione di B.Cosentino
ù#include<iostream>
using namespace std;
//PRE: cin contiene un intero N e N interi compresi tra 000000 e 999999
int main () {
	int N,contr=000000, dupl=0;
	cin >> N;
	int B[100], D[100];
	//PRE_for1: cin contiene N interi compresi tra 000000 e 999999
	for (int i=0; i<N; i=i+1) {     // R_for1: (0<=i<=n) && i numeri letti in B[0...i-1]
		cin >> B[i];
	}
	//POST_for1: B[0...N] contiene N interi
	
	//PRE_for2: B[0...N] contiene N interi
	for (int i=0; i<N; i=i+1) {         
    //R_for2: (0<=i<=N) && dupl<=i && D contiene i duplicati di B[0...i-1]
		//PRE_for3: i intero fissato && D e' vuoto
		bool trov=false;
		for (int j=0; j<i && !trov ; j=j+1) { 
        //R_for3: D[0...dupl-1] contiene contiene i duplicati di B[0...j-1] && dupl<=j && 0<=j<=i && (trov==true sse esiste un duplicato di B[i])
			if (B[i]==B[j]) {
				D[dupl]=B[i];
				dupl=dupl+1;
				trov=true;
			}
		}
		//POST_for3: D[0...dupl-1] contiene contiene i duplicati di B[0...i-1] && dupl<=i
	}
	//POST_for2: D contiene i tutti duplicati e dupl<=N]

    //PRE_for4:	D contiene dupl numeri 
	for (int i=0; i<dupl; i=i+1) { 
    //R_for4: D[posmin]<=D[i-1] && (0<=i<=dupl)
	    //Ordina gli elementi di D 
	    int posmin=i; 
	    //PRE_for5: posmin=i && D[posmin]<=D[i-1]
	    for (int j=i+1; j<dupl; j=j+1) { 
        //R_for5: D[j]<=D[i+1...dupl] && (i+1<=j<=dupl)
	       if (D[j]<D[posmin]) {
	           posmin=j;
	       }    
	    }
	    //POST_for5: trova l'indice del minimo di D[i+1...dupl-1]
	    int s=D[i];
	    D[i]=D[posmin];
	    D[posmin]=s;
	}
	//POST_for4: D e' ordinato
    cout << D[0] << endl;
    //PRE_for6:	D e' ordinato
	for (int i=1; i<dupl; i=i+1) { //R_for6: 0<=i<=dupl && stampa gli elementi D[i-2] e D[i-1] dove D[i-2]<=D[i-1]
		if (D[i]!=D[i-1]) {
			cout << D[i] << endl;
		}
	}
	//POST_for6: stampa gli elementi di D e quelli ripetuti una sola volta 
	
	if (dupl==0) {
	        cout << "Tutto regolare" << endl;
	} 
	cout << endl << "end" << endl;
}
