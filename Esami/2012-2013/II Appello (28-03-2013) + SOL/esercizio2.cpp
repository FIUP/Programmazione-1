#include<iostream>
#include<fstream>
using namespace std;


struct nodo{
	int info; 
	nodo* left,*right; 
	nodo(int a=0, nodo* b=0, nodo* c=0) {info=a; left=b; right=c;}
};


// PRE_M=(R è un albero corretto, P ha dimP>=0 elementi def., prof>=0 e C ha abbastanza elementi)
bool M(nodo*R, int*P, int dimP, int prof, int*C){
	
	if(!dimP){
		if(prof!=0){
			*(C-1)=-1;
			return 1;
		} else return 0;
	}
	if(!R){
		*C=2;
		return 0;
	}
	if(R->info==*P){
		P=P+1;
		dimP=dimP-1;
	}
	*C=0;
	if(M(R->left, P, dimP, prof+1, C+1)){
		if(!R->left && *(C+1)==-1)
			*C=-1;
		return 1;
	}
	*C=1;
	if(M(R->right, P, dimP, prof+1, C+1)){
		if(!R->right && *(C+1)==-1)
			*C=-1;
		return 1;
	}
	*C=2;
	return 0;

}//POST_M(se M restituisce false, allora C[0]=2 e R non contiene match di P)&&(se M restituisce true, allora C=[i1,..,im,-1] è il primo cammino (rispetto all’attraversamento in prefisso) che caratterizza un match di P in R)


/* PROVA DI CORRETTEZZA: PRE_M <M(){}> POST_M

	caso base: !dimP
------------------
Dato PRE_M, se dimP==0 allora abbiamo trovato un match ...

	caso base: !R && dimP!=0
--------------------------
Dato PRE_M, se R è un albero vuoto e non ho trovato un match completo, allora segnalo che in quel cammino non c'è match con *C=C[0]=2 e ritorno 0 → vale POST_M

	caso ricorsivo: M(R->left, P, dimP, prof+1, C+1)
--------------------------------------------------
Dato PRE_M, devo considerere il figlio sinistro, quindi *C=0, poi assumo per ipotesi induttiva la chiamata ricorsiva M(R->left, P, dimP, prof+1, C+1):
- se ritorna true allora c'è almeno un match completo di P[1..dimP-1] nel sottoalbero sinistro e C=[0,..,-1] → valgono PRE_M e POST_M
- se ritorna false allora non c'è match completo di P[1..dimP-1] nel sottoalbero sinistro e C=[0] diventa C[2] → valgono PRE_M e POST_M

	caso riscorsivo: M(R->right, P, dimP, prof+1, C+1) && !M(R->left, P, dimP, prof+1, C+1)
-----------------------------------------------------------------------------------------
Dato PRE_M, devo considerare il figlio destro, quindi *C=1, poi assumo per ipotesi induttiva la chiamata ricorsiva M(R->right, P, dimP, prof+1, C+1):
- se ritorna true allora c'è almeno un match completo (non ci sono match nel sottoalbero sinistro) di P[0..dimP-1] nel sottoalbero destro e C=[1,..,-1] → valgono PRE_M e POST_M
- se ritorna false allora non c'è match completo di P[1..dimP-1] nel sottoalbero R (nè a destra nè a sinistra) e C[1] diventa C[2]

*/


// stampa il cammino in C su OUT
void stampa(int* C, ofstream & OUT){
	if(*C==2)
		OUT<< 2<<endl;
	else{
		bool ok=true; 
		int i=0;
		while(ok){
			OUT<<C[i]<<' ';
			if(C[i]==-1)
				ok=false;
			else i++;
		}
		OUT<<endl;
	}
}


//conta nodi nell'albero r
int conta(nodo* r){
	if(!r)
		return 0;
	else return conta(r->left)+conta(r->right)+1;
}


//inserisce un nodo nell'albero r
void insert(nodo*& r,int x){
	if(!r){
		r=new nodo(x);
		return;
	}
	int a=conta(r->left);
	int b=conta(r->right);
	if(a<=b)
		insert(r->left,x);
	else insert(r->right,x);
}


//inserisce i nodi ricorsivamente nel sotto-albero con meno nodi
void crea(nodo*& L,int dim, ifstream & INP){
	while(dim){
		int x;
		INP>>x;
		insert(L,x);
		dim--;
	}
}


//stampa albero in forma lineare
void stampa_r(nodo*r){
	if(!r)
		cout<<"_";
	else{
		cout<<r->info<<'(';
		stampa_r(r->left);
		cout<<',';
		stampa_r(r->right);
		cout<<')';
	}
}


main(){
	ifstream INP("input2");
	ofstream OUT("output2");
	int dim,dimP, P[20], C[30];
	INP>>dim;
   
	nodo* root=0;
	crea(root,dim,INP); //fatta
	stampa_r(root); //fatta
	cout<<endl;
	INP>>dimP;
	for(int i=0; i<dimP;i++)
		INP>>P[i];

	M(root, P, dimP, 0, C); // da fare 
  
	stampa(C, OUT); //fatta
	cout<<endl;

	INP.close();
	OUT.close();
}
