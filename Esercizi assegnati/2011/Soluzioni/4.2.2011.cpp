#include <iostream>
using namespace std;

bool match(char *T, char *P, int dim_P, int h){
	bool trovato=true;
	for(int k=1; k<dim_P; k++)
		if(P[k]!=T[k+h])
			trovato=false;
	return trovato;
}

bool G(char (*T)[15][15], int limite1, char P[], int dim_P){
	bool trovato=false;
	for(int i=0; i<15 && !trovato; i++)
		for(int j=0; j<limite1 && !trovato; j++)
			for(int h=0; h<15 && !trovato; h++)
				if(P[0]==T[j][i][h])
					trovato=match(**(T+j*limite1+i), P, dim_P, h);

	return trovato;
}

main(){

}
