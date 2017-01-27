bool match(int* T, int* P, int dimP){
	bool ok=true;
	for(int i=0; i<dimP && ok; i++){
		if(T[i]!=P[i])
			ok=false;
	}
	return ok;
}

bool check_R(int* T, int dimr, int*P, int dimP, int n_m){
	int inizio=0, conta=0;
	while(inizio<dimr-dimP+1){
		if(match(T+inizio,P,dimP)){
			conta++;
			inizio=inizo+dimP;
		}else inizio++;
		if(conta==n_m)
			return true;
		else return false;
	}
}

void trova_strato(int* T, int n, int lim1, int lim2, int lim3, int *P, int dimP, int n_m, int &indice_S){
	int nrp=n/lim3, neur=n%lim3, r=0;
	bool trovato=false;
	while(n<nrp && !trovato){
		trovato=check_R(T+r*lim3, lim3, P, dimP, n_m)
		if(!trovato)
			r++;
	}
	if(trovato)
		indice_S=r/lim2;
	else{
		if(neur>0)
			trovato=check_R(T+nrp*lim3, neur, P, dimP, n_m)
		if(trovato)
			indice_S=nrp/lim2;
	}
}
