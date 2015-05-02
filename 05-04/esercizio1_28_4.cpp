/*Integrazione sei crediti*/
#include <iostream>
#include <fstream>

using namespace std;

bool fin(int *x, int i, int *P, int dimP){
	if(dimP){
		if(x[i] != P[0])
			return false;
		else 
			return fin(x, i+1, P+1, dimP-1);
	}
	return true;
}

void match(int *x, int*P, int dim, int dimP, int i, int count_match, ofstream & OUT){
	if(i<dim-dimP+1){
		if(fin(x,i,P,dimP)){
			count_match++;
			OUT <<"match n." << count_match << " a partire dalla posizione " << i<<endl;
		}
		match(x,P,dim,dimP,i+1,count_match,OUT);
	}
	else{ 
		OUT <<"fine"<< endl;
		return;
	}
}

int main(){
	ifstream IN("input");
	ofstream OUT("output");
	
	if(IN && OUT){
	int X[400], P[20], n_el, dimP, count_match=0;

	IN >> n_el;

	for(int i=0; i<400; i++)
		X[i] = 0;
	
	for(int i=0; i<20; i++)
		P[i] = 0;
	
	for(int i=0; i<n_el; i++)
		IN >> X[i];

	IN >> dimP;
	for(int i=0; i<dimP; i++)
		IN >> P[i];
	
	IN.close();
	
	match(X, P, n_el, dimP, 0, count_match, OUT);
	OUT.close();
	}
	else
		cout << "errore coi file"<< endl;
}