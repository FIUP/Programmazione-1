#include <iostream>
#include <fstream>

using namespace std;

int qdista(int strato, int rim, int hfetta, int lim2, int lim3){
	int distanza = strato*(lim2*lim3) + hfetta*lim3 + rim;
	return distanza;
}

bool match(int *x, int *P, int dimP, int distanza, int lim2, int lim3, int n_el){
	bool ok=true;
	int cont =0, dist = distanza;
	for(int i=0; i<dimP && ok; i++)
		if(distanza > n_el)
			return false;
		else {
		if(x[dist]!=P[i])
			ok=false;
		else{
			cont++;
			if((dist+1)%lim3 ==0 )
				dist += (lim2-1)*lim3;
			else dist++;
		}
		if(cont == dimP)
			ok = true;
		}
	return ok;
}

int contaMatch(int *x, int fetta, int lung, int lim1, int lim2, int lim3, int *P, int dimP, int n_el, ofstream& OUT){
	int n_match=0, jump=0, distanza = 0, strato=0, rim=0, f;
	for(int i=0; i<lung-dimP+1; i=i+jump)
		f = i;
		strato = f/lim3;
		rim= f%lim3;
		//if(rim ==0){
			//x=x+(strato*lim2*lim3+fetta*lim3)
		//}
		//else x = x+1;
		distanza = qdista(strato, rim, fetta, lim2, lim3);
		if(match(x, P, dimP, distanza, lim2, lim3, n_el)){
			n_match++;
			//x=x+dimP*lim3;
			jump=dimP;
		}
		else{
			//x=x+lim3;
			jump=1;
		}
		return n_match;	
}

int main(){
	ifstream IN("input.txt");
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
		else hfmax = lim3;
	} 
		
	int lung = nsp*lim3;
	
	for(int i=0; i < hfmax; i++){
		if(i<nrpus)
			lung=lung+lim3;
		else if(i ==nrpus+1 || (i==0 && nrpus ==0))
			lung = lung+rim;
		//match = contaMatch(x+(i*lim3),lung, i, lim1, lim2, lim3,P,dimP, OUT);
		match = contaMatch(x, i, lung,lim1, lim2, lim3,P,dimP, n_el, OUT);
		OUT << "H-fetta " << i << " = " << match << " match" << endl;
		match=0;
		lung = nsp*lim3;
	}

	}
	else
		cout << "errore coi file"<< endl;
}