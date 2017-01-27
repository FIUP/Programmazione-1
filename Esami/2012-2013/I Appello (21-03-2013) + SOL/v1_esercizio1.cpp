#include<iostream>
#include<fstream>
using namespace std;


//PRE=(riceve un array ad una dimensione, k1 definito, 0<=elem<10 intero)
int ContaMatch(int *X, const int &elem, int k1){
	
	int conta=0;
	for(int j=0; j<elem; j++){
		if(X[j]==k1)
			conta++;
	}
	return conta;

}//POST=(ritorna il numero di match di k1 nella riga)


//PRE_F=(X ha dimensioni [][5][10], lim1>0, dim>0, i primi dim elementi di X sono definiti, k1 e k2 sono definiti e k2 >=0)
int F(int(*X)[5][10], int lim1, int dim, int k1, int k2){

	int strati_pieni=dim/(5*10);
	int righe_ultimo_strato=(dim%(5*10))/10;
	int elem_ultima_riga=(dim%(5*10))%10;
	int fetta=-1;

	bool trovato=false;
	for(int i=0; i<5 && !trovato; i++){
	//R=(0<=i<=5)&&(se !trovato allora non ci sono k2 occorrenze di k1 in nessuna delle fette 0,..,i-1 di X[0..k][0..i-1][0..10]; trovato allora le fetta i-1 contiene k2 occorrenze di k1)
		int conta=0;
		// ---------- strati pieni ----------
		int k=0;
		for(; k<strati_pieni; k++)
			conta+=ContaMatch(X[k][i], 10, k1);
		// ---------- strato incompleto ----------
		if(righe_ultimo_strato!=0 && i<=righe_ultimo_strato){
			// ---------- righe piene ----------
			if(i<righe_ultimo_strato)
				conta+=ContaMatch(X[k][i], 10, k1);
			// ---------- riga incompleta ----------
			if(elem_ultima_riga!=0 && i==righe_ultimo_strato)
				conta+=ContaMatch(X[k][i], elem_ultima_riga, k1);
		}
		if(conta==k2){
			fetta=i;
			trovato=true;
		}
	}
	return fetta;

}//POST_F=(F restituisce il minimo indice tra le fette che soddisfano (*) , se nessuna fetta soddisfa (*) allora F restituisce -1)


main(){
	ifstream INP("input1");
	ofstream OUT("output1");
	int dim, k1, k2, X[10][5][10], *Y=**X;
	INP>>dim>>k1>>k2;
	
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
