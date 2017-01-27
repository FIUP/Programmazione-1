#include<iostream>
#include<fstream>
using namespace std;


//PRE_ContaMatch=(riceve un array a una dimensione, k1 definito, 0<=elem<5))
int ContaMatch(int *X, int const &elem, int k1){
	int conta=0;
	for(int i=0; i<elem; i++){
		if(*(X+i*10)==k1)
			conta++;
	}
	return conta;

}//POST_ContaMatch=()


// PRE_F=(X ha dimensioni [][5][10], lim1>0, dim>0, i primi dim elementi di X sono definiti, k1 e k2 sono definiti e k2 >=0)
int F(int(*X)[5][10], int lim1, int dim, int k1, int k2){
  
	int strati_pieni=dim/(5*10);
	int righe_strato_incompleto=(dim%(5*10))/10;
	int elem_riga_incompleta=(dim%(5*10))%10;
	int fetta=-1;

	bool trovato=false;
	for(int j=0; j<10 && !trovato; j++){
	//R=(0<=j<=10)&&(!trovato allora le fette 0,..,j-1 non soddifano la condizione (*); trovato altrimenti)
		int conta=0;
		// ---------- strati pieni ----------
		int k=0;
		for(; k<strati_pieni; k++)
			conta+=ContaMatch(*(X[k])+j, 5, k1);
		// --------- strato incompleto ----------
		if(righe_strato_incompleto!=0){
			if(elem_riga_incompleta!=0 && j<elem_riga_incompleta)
				conta+=ContaMatch(*(X[k])+j, righe_strato_incompleto+1, k1);
			else conta+=ContaMatch(*(X[k])+j, righe_strato_incompleto, k1);
		}
		if(conta==k2){
			fetta=j;
			trovato=true;
		}
	}
	return fetta;

}// POST_F=(F restituisce il minimo indice tra le fette che soddisfano (*), se nessuna fetta soddisfa (*) allora F restituisce -1)


main(){
	ifstream INP("input1");
	ofstream OUT("output1");
	int dim, k1,k2, X[10][5][10], *Y=**X;
	INP>>dim>> k1>>k2;
	for(int i=0; i<dim; i++){
		INP>>Y[i];
		cout<<Y[i]<<' ';
	} 
	cout<<endl;
  
	int z=F(X,10,dim,k1,k2);

	OUT<<z;
	INP.close();
	OUT.close();
}
