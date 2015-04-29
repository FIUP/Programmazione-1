/*Integrazione sei crediti*/
#include <iostream>
#include <fstream>

using namespace std;

int qdista(int strato, int rim, int hfetta, int lim2, int lim3){
	int distanza = strato*(lim2*lim3) + hfetta*lim3 + rim;
	return distanza;
}

bool match(int *x, int *P, int dimP, int distanza, int lim2, int lim3){
	bool ok=true;
	int dist = distanza;
	for(int i=0; i<dimP && ok; i++){
		if(x[dist]!=P[i])
			ok=false;
		else{
			if((dist+1)%lim3 ==0 )
				dist += (lim2-1)*lim3+1;
			else dist++;
		}
	}
	
	return ok;
}

int contaMatch(int *x, int fetta, int lung, int lim2, int lim3, int *P, int dimP){
	int n_match=0, jump=1, distanza = 0, strato=0, rim=0;
	for(int i=0; i<lung-dimP+1; i=i+jump){
		strato = i/lim3;
		rim= i%lim3;
		//OUT << "i " << i << endl;
		distanza = qdista(strato, rim, fetta, lim2, lim3);
		//OUT << "i: " << i << " distanza: " << distanza <<endl;
		if(match(x, P, dimP, distanza, lim2, lim3)){
			n_match++;
			//OUT << "match va";
			jump=dimP;
			//OUT << " jump :" <<jump << endl;
		}
		else{
			//OUT << "match non va ";
			jump=1;
			//OUT << " jump : " <<jump << endl;
		}
	}
	return n_match;	
}

int main(){
	ifstream IN("input");
	ofstream OUT("output");
	
	if(IN && OUT){
	int X[400], *x = X, P[50], lim1, lim2, lim3, n_el, dimP, match=0, hfmax=0;

	IN >> lim1 >> lim2 >> lim3 >> n_el;

	for(int i=0; i<400; i++)
		X[i] = -1;
	
	for(int i=0; i<n_el; i++)
		IN >> x[i];

	IN >> dimP;

	for(int i=0; i<dimP; i++)
		IN >> P[i];
	
	IN.close();
	
	if(n_el > lim1*lim2*lim3)
		n_el = lim1*lim2*lim3;
	
	int nsp = n_el/(lim2*lim3);			//strati pieni
	int nrimus= n_el%(lim2*lim3);		//rimanenti ultimo strato
	int nrpus = nrimus/lim3;			//righe piene ultimo strato
	int	nrp = n_el/lim3;				//nrp = righe piene, rim = rimanenti
	int rim= nrimus%lim3;				//rimanenti ultima riga
	
	if(n_el<=lim3)
			hfmax = 1;
	else{
		if(nrp<lim2)
			hfmax = nrp;
		else hfmax = lim2;
	} 
		
	int lung = nsp*lim3;
	
	for(int i=0; i < hfmax; i++){
		if(i<nrpus)
			lung=lung+lim3;
		else if(i ==nrpus)
			lung = lung+rim;
		match = contaMatch(x, i, lung,lim2, lim3,P,dimP);
		OUT << "H-fetta " << i << " = " << match << " match" << endl;
		match=0;
		lung = nsp*lim3;
	}

	}
	else
		cout << "errore coi file"<< endl;
}