#include <iostream>
using namespace std;
//PRE: T[limite] e P[dimP] definiti, limite definito
int conta(int *T, int *P, int dimP, int limite){
	bool esci=false; int conta=1;
	for(int k=1; k<dimP && k<limite && !esci; k++){
		if(P[k]==T[k]){
			conta++;
		}
		else
			esci=true;
	}
	return conta;
}
//POST: conta è il numero di P[a] = a T[a] con a in[1 ... x] con x=minore tra dimP e limite
//limite= termine della riga C-esima che si sta controllando

//PRE: T[R*C] e P[dimP] definiti, O[R] riempito di zeri
void F(int *T, int R, int C, int *P, int dimP, int *O){
	int q=0;
	for(int i=0; i<R && q<dimP; i++){
		bool esci=false;
		for(int j=0; j<C && q<dimP && !esci; j++)//R2
			if(P[q]==T[i*C+j]){
				O[i]=conta((T+i*C)+j, P+q, dimP-q, C-j); q=q+O[i];
				esci=true;
			}
	}
	/*for(int i=0; i<R; i++)
		cout << O[i] << " ";
	cout << endl;*/
}

main(){
int T[15]={0,0,0, 1,1,2, 2,3,0, 0,0,0, 0,4,5}, R=5, C=3, P[6]={}, dimP=6, O[5]={};
F(T, R, C, P, dimP, O); 
}
