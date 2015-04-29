/*Integrazione sei crediti*/
#include <iostream>
#include <fstream>

using namespace std;

bool match(int *x, int *P, int dimP, int lim3){
	bool ok=true;
	for(int i=0; i<dimP && ok; i++)
			if(x[i*lim3]!=P[i])
				ok=false;
	return ok;
}

int contaMatch(int *x, int lung, int lim3, int *P, int dimP){
	int n_match=0, jump=0;
	for(int i=0; i<lung-dimP+1; i=i+jump)
		if(match(x, P, dimP, lim3)){
			n_match++;
			x=x+dimP*lim3;
			jump=dimP;
		}
		else{
			x=x+lim3;
			jump=1;
		}
		return n_match;	
}

int main(){
	ifstream IN("input");
	ofstream OUT("output");
	
	if(IN && OUT){
	int X[400], *x = X, P[50], lim1, lim2, lim3, n_el, dimP, match=0, vfmax=0;

	IN >> lim1 >> lim2 >> lim3 >> n_el;

	for(int i=0; i<400; i++)
		X[i] = -1;
	
	for(int i=0; i<n_el; i++)
		IN >> x[i];

	IN >> dimP;

	for(int i=0; i<dimP; i++)
		IN >> P[i];

	if(n_el<lim3)
		vfmax = n_el;
	else vfmax=lim3;
	
	IN.close();
	
	int nsp = n_el/(lim2*lim3);
	int	nrp, rim;
	if(nsp >=lim1){
		nrp=lim1*lim2;
		rim =0;
	}
	else  {
		nrp=n_el/lim3;
		rim = n_el%lim3;
	}
	
	int lung = nrp;
	
	for(int i=0; i < vfmax; i++){
		if(i<rim)
			lung++;
		match = contaMatch(x+i,lung,lim3,P,dimP);
		OUT << "V-fetta " << i << " = " << match << " match" << endl;
		match=0;
		lung = nrp;
	}

	}
	else
		cout << "errore coi file"<< endl;
}