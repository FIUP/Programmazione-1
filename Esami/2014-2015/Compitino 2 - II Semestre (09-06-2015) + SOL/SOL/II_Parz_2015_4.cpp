
//soluzione by: Fabrizio C.

// nota: la funzione ausiliaria che non è ricorsiva.

innesto* conc(innesto* a, innesto* b){
	if(!a) return b;
	a->next=conc(a->next,b);
	return a;
}

innesto* f0(nodo* R){
	if(!R)
		return 0;
	innesto* a=f0(R->left);
	innesto* b=f0(R->right);

	if(!R->left && !R->right)
		b=new innesto(true,true,R,b);
		
	if(!R->left && R->right)
		b=new innesto(true,false,R,b);
		
	if(R->left && !R->right)
		b=new innesto(false,true,R,b);
			
	return conc(a,b);
}

//PRE=(inn e' lista di tipo innesto corretta,x intero)
void inserisci(innesto* inn,int x){
	if(inn->l==1 && inn->r==0){//inserisco a sx
		(inn->N)->left=new nodo(x);
		inn->l=0;
		return;
	}
	if(inn->l==0 && inn->r==1){//inserisco a dx
		(inn->N)->right=new nodo(x);
		inn->r=0;
		return;
	}
	//sono a l=1,r=1 prediligo left,metto l=0,r rimane a 1
	(inn->N)->left=new nodo(x);
	inn->l=0;
	return;
}
//POST=(aggiunge un nuovo nodo al nodo puntato dal campo N di inn. in ordine infisso)

/*PRE=(lista(Inn) è corretta, in particolare ciascun nodo punta ad un corrispondente punto d'innesto di un
qualche albero, INP contiene m interi seguiti dalla sentinella -2, 0<=m, sia vInn il valore iniziale di lista(Inn))*/
int f1(innesto* &inn, ifstream &INP){
	int z;INP>>z;
	
	if(z==-2) return 0;
	if(!inn) return 0;

	inserisci(inn,z);
	
	if(inn->l==0 && inn->r==0){ //se ho esaurito il nodo attuale di innesto lo dealloco
		innesto* t=inn;
		inn=inn->next;
		delete t;
	}
		
	return 1+f1(inn,INP);
	
}
/*POST=(se vInn contiene n campi l/r a true, allora vengono letti x=min(m,n) valori da INP e aggiunti x nuovi
nodi usando i punti di innesto di vInn in ordine; f1 restituisce il valore di x e, in caso resti una parte di vInn
non usata (succede quando n>m), questa lista rimasta deve essere il valore finale del parametro Inn. La
parte di vInn che è usata viene deallocata)
*/
