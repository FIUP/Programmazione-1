// soluzione di B.Cosentino
#include<iostream>
using namespace std;
int main(){
	cout<<"start"<<endl;
	int A[6][6];
	for(int i=0; i<6; i=i+1)
		for(int j=0; j<6; j=j+1)
			cin >> A[i][j];
	
	int val1=0, val2=0; 
	bool OKp=true, OKs=true, OKP=true, OKS=true;    
	
	for (int i=0; i<6 && (OKP || OKS); i=i+1){
	// R1 = (0<=i<=6) && (OKP == true sse ogni elemento della diagonale principale nelle righe [0...i-1] si trova nella diagonale secondaria) && (OKS == true sse ogni elemento della diagonale secondaria nelle righe [0...i-1] si trova nella diagonale principale)
		OKp=false;
		OKs=false;
		for (int j=0; j<6 && (!OKp || !OKs); j=j+1){
		// R2 = (0<=j<=6) && (OKp == true sse A[i][i] e' contenuto nella diagonale secondaria) && (OKs == true sse A[i][5-i] e' contenuto nella diagonale principale)
			if (OKP){
				if (A[i][i]==A[j][5-j])
					OKp = true;
				val1 = A[i][i];
			}
			
			if (OKS){ 
				if (A[j][j]==A[i][5-i])
					OKs = true;
				val2 = A[i][5-i];
			}
		}
		OKP = OKP && OKp;
		OKS = OKS && OKs;
	}
	if (OKP && OKS){
		cout << "le due diagonali contengono gli stessi valori" << endl;	
	} else { // !OKp1 || !OKs1
		if (!OKP)
			cout << "diagonale principale contiene "<< val1 << " che non e' sulla diagonale secondaria" << endl;
		if (!OKS)
			cout << "diagonale secondaria contiene " << val2 << " che non e' sulla diagonale principale" << endl;
	}
	cout << "end" << endl;
}
