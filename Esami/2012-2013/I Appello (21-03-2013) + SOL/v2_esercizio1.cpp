#include<iostream>
#include<fstream>
using namespace std;


// PRE_F=(X ha dimensioni [][5][10], lim1>0, dim>0, i primi dim elementi di X sono definiti, k1 e k2 sono definiti e k2 >=0)

int F(int(*X)[5][10], int lim1, int dim, int k1, int k2);

//POST_F=(F restituisce il minimo indice tra le fette che soddisfano (*) , se nessuna fetta soddisfa (*) allora F restituisce -1)


main()
{
  ifstream INP("input1");
  ofstream OUT("output1");
  int dim, k1,k2, X[10][5][10], *Y=**X;
  INP>>dim>> k1>>k2;
  for(int i=0; i<dim; i++)
    {INP>>Y[i];cout<<Y[i]<<' ';}
    
  int z=F(X,10, dim,k1,k2);//da fare
  OUT<<z;
  INP.close();
  OUT.close();
}

//k1= valore da trovare
//k2= numero di volte

//PRE:(dim > 0 , X array di dim elementi definiti, k1 intero valido)
int G(int *X, int dim, int k1){

	int conta=0;
	
	for(int i=0; i<dim; i++){
		if(X[i]==k1) {
			conta++;
		}
	}
	
	return conta;
}
//POST:(G ritorna il numero di occorrenze di k nell'array X)




int F(int(*X)[5][10], int lim1, int dim, int k1, int k2){
	
	int ns = dim/(5*10);	//strati definiti
	int eus = dim%(5*10);	//elementi ultimo strato
	int nrp = eus/10;	//righe definite (ultimo strato)
	int neur=eus%10;	//elementi ultima riga
	
	int indice=-1;
	int nf=5; //numero fette complete (5 è il numero massimo e verrà cambiato nel corso del codice

	if(dim/10<nf){ //calcolo numero fette piene
		nf=dim/10;
		if(nf%10) nf++;
	}
	
	bool trovato=false; //boleano per l'uscita anticipata dal ciclo
	
	for( int f=0; f<nf && !trovato; f++){
		
		int conta=0;
		
		for (int s=0; s<ns; s++) {
			
			conta += G(X[s][f], 10, k1);
			
		}
		
		if(f<nrp) conta += G(X[ns][f], 10, k1);				// calcolo dell'ultima riga (nell'ultimo strato)
		else if (f==nrp) conta += G(X[ns][ƒ],neur,k1);		// caso in cui non sia completa
															//caso in cui f>nrp non si deve calcolare l'ultima riga perchè non ha elementi definiti
		
		if(conta==k2){
			trovato=true;
			indice=f;
		}
	}
		
return indice;
}




//R:(0<=f<=nf)&&(nessuna fetta in 0...f-2 ha k2 occ. di k1)&&(trovata sse la fetta f-1 ha k2 occorrenze di k1)