#include <iostream>
#include <fstream>

using namespace std;

bool match(int *x, int *P, int dimP, int lim3){
	bool ok=true;
	int cont =0;
	for(int i=0; i<dimP && ok; i++)
		if(x[i*lim3] != -1){
			if(x[i*lim3]!=P[i])
				ok=false;
			else cont++;
		}
		else ok=false;
	
	if(cont == dimP)
		ok=true;
	else ok = false;
	
	return ok;
}

int contaMatch(int *x, int lim1, int lim2, int lim3, int *P, int dimP){
	int n_match=0, lim=lim1*lim2;
	for(int i=0; i<lim-dimP+1; i++)
		if(match(x, P, dimP, lim3)){
			n_match++;
			x=x+dimP*lim3;
		}
		else
			x=x+lim3;
		return n_match;	
}

int main(){
	ifstream IN("input");
	ofstream OUT("output");
	int quanti =0, garbage;
	if(IN && OUT){
	int X[400], *x = X, P[50], lim1, lim2, lim3, n_el, dimP, match=0, vfmax=0;

	IN >> lim1 >> lim2 >> lim3 >> n_el;

	for(int i=0; i<400; i++)
		X[i] = -1;
	
	for(int i=0; i<lim1; i++)
		for(int j=0; j<lim2; j++)
			for(int k=0; k<lim3 && i*lim2*lim3+j*lim3+k<n_el; k++)
				IN>>X[i*lim2*lim3+j*lim3+k];
	
	quanti = n_el - (lim1*lim2*lim3);
	if(quanti)
		for(int i =0; i < quanti; i++)
			IN >> garbage;

	//for(int i=0; i<n_el; i++)
		//IN >> x[i];

	IN >> dimP;

	for(int i=0; i<dimP; i++)
		IN >> P[i];

	if(n_el<lim3)
		vfmax = n_el;
	else vfmax=lim3;
	
	IN.close();
	
	for(int i=0; i < vfmax; i++){
		match = contaMatch(x+i,lim1,lim2,lim3,P,dimP);
		OUT << "V-fetta " << i << " = " << match << " match" << endl;
		match=0;
	}

	}
	else
		cout << "errore coi file"<< endl;
}