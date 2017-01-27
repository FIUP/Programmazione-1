//correzione 5 appello 20/01/2015

//------RICORSIVA-------

int not_m(nodo2* &C, int x){ 
	if(C){
		if(C->info1!=x){
			C=C->next;
			return 1+not_m(C,x);
		}
		else
			return 0;
	}
	else
		return 0;	
}

int m(nodo2* &C, int* &P,int& dimP){
	if(C && dimP)
		if(C->info1==*P){
			C=C->next;
			P++;
			dimP--;
			return 1+m(C,P,dimP);
		}
		else
			return 0;
	else 
		return 0;
}

nodo2* B(nodo2* C,int *P, int dimP){
	if(C && dimP){ 
		int y=not_m(C,P[0]);
		if(!C)					//perche' C e' passato per riferimento in m e not_m, se arriviamo in fondo senza ave trovato nulla C=0
			return 0; 			//lista vuota. non e' stato trovato nessun elemento del pattern
		int x=m(C,P,dimP);
		
		return new nodo2(y,x,B(C,P,dimP));
	}
		
	else
		return 0;
}

//-------ITERATIVA-----------------

void attacca(nodo2* &I, nodo* &F, nodo* Z){ //attacca in fondo
	if(Z){ 
		if(!I){
			I=F=Z;
		}
		else{
			F->next=Z;
		}
		while(F->next)
			F=F->next;
	}	
}

nodo2* stacca(nodo2* &L, int k){
	nodo2* s=L, *a=0; //s la lista staccata, L la nuova lista, a punt al nodo precente
	while(L && k){
		a=L;
		L=L->next;
		k--;
	}
	
	if(!a) 
		return 0;
	else{
		a->next=0;
		return s; //s e' la nuova lista staccata
	}	
}

nodo*2 taglia(nodo*2 &L, nodo2* x){
	nodo2* SB=0, *FB=0, *SR=0, *FR=0, *Y=L; //sr (x-t)
	
	while(Y && x){
		int k1=x->info1, k2=x->info2;
		
		nodo2* z1=stacca(Y,k1); //Y si muove..e' per riferimento
		nodo2* z2=stacca(Y,k2); //Y il resto della lista
		
		attacca(SR,FR,z1);
		attacca(SB,FB,z2);
		x=x->next;
	}
	if(Y)
		attacca(SR,FR,Y);
	L=SB;
	return SR;
}
