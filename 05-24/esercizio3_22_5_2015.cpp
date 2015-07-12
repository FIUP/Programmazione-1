/*Integrazione sei crediti*/
#include<iostream>
#include<fstream>
using namespace std;

struct nodo{int info; nodo* left,*right; nodo(int a=0, nodo* b=0, nodo*c=0){info=a; left=b;right=c;}};

void stampa_l(nodo *r){										//stampa l'albero in forma lineare su output standard
	if(r){													//se ci sono nodi
		cout<<r->info<<'(';									//stampiamo il campo info e una parentesi aperta 
		stampa_l(r->left);									//stampiamo il sotto albero sinistro
		cout<<',';											//una virgola
		stampa_l(r->right);									//e stampiamo il sottoalbero destro
		cout<<')';											//chiudiamo la parentesi
    }
	else													//se l'albero non ha nodi
		cout<< '_';											//stampiamo un underscore _
}

void stampa_lf(nodo *r, ofstream& out){						//come la funzione precedente, ma stampa su file
	if(r){
		out<<r->info<<'(';
		stampa_lf(r->left,out);
		out<<',';
		stampa_lf(r->right,out);
		out<<')';
    }
	else
		out<< '_';
}

int conta_n(nodo*r){										//conta i nodi dell''albero
	if(!r) 													//se l'albero è vuoto
		return 0;											//ha zero nodi
	else													//altrimenti 
		return conta_n(r->left)+conta_n(r->right)+1;		//ha un nodo più i nodi del suo sottoalbero sinistro, più quelli del sottoalbero destro
}

nodo* insert(nodo*r, int y){								//Costruisce l'albero, inserendo i nodi in modo bilanciato
	if(!r) 													//se l'albero è vuoto
		return new nodo(y);									//crea la radice, unico nodo
															//altrimenti
	if(conta_n(r->left)<=conta_n(r->right))					//se i nodi del sottoalbero sinistro sono meno (o pari) al destro 
		r->left=insert(r->left,y);							//inseriamo il nuovo nodo nel sottoalbero sinistro
	else   													//altrimenti
		r->right=insert(r->right,y); 						//lo inseriamo nel sottoalbero destro
	return r;												//e ritorniamo l'albero creato
}

nodo* rep_ins(nodo*r, int dim, ifstream & INP){				//Ripete l'inserimento, inserendo dim nodi letti dal file di input
	if(dim){												//se ci sono nodi da inserire
		int z;												//creiamo un intero
		INP>>z;												//leggiamo il valore dal file di input
		nodo*x=insert(r,z);									//in un puntatore a nodo invochiamo insert che inserisce in modo bilanciato il nuovo valore
		return rep_ins(x,dim-1,INP);						//e invochiamo ricorsivamente rep_ins
	}														//altrimenti se non ci sono più valori da leggere
	return r;												//ritorniamo l'albero
}

void sc(int*C, ofstream & OUT){								//Stampa cammino
	if(*C!=-1){												//se il passo del cammino è diverso da -1
		OUT<<*C<<' '; 										//stampiamo il suo valore
		sc(C+1,OUT);}										//e invochiamo ricorsivamente sc sul prossimo elemento di C
	else													//altrimenti
		OUT<<"fine cammino"<<endl;							//abbiamo finito
}

bool leaf(nodo*x){											//stabilisce se un nodo è foglia
	if(!x->left && !x->right)								//se non ha sottoalberi sinistri o destri
		return true;										//è foglia 
	else return false;										//sennò no
}

/*PRE_cerca=(albero(r) è corretto e non vuoto, k>=0 e y valore qualsiasi, C ha almeno tanti elementi quant è
l'altezza di albero(r))*/
bool cerca_cam(nodo*r, int k, int y, int *C){				
	int cont = conta_n(r);									//cont conta i nodi dell'albero
		
	if(cont <k)												//se sono meno di k
		return false;										//il cammino cercato non c'è
	
	if(r->info ==y)											//se info è = a y
		k--;												//scaliamo uno da k

	if(k==0 && leaf(r)){									//se k vale zero e il nodo è una foglia
		*C=-1;												//chiudiamo il cammino 
		return true;										//e ritorniamo true, lo abbiamo trovato
	}														//altrimenti

	if(r->left && cerca_cam(r->left, k,y,C+1)){				//se c'è un sottoalbero sinistro e c'è un cammino nel sottoalbero sinistro
		*C =0;												//andiamo a sinistra
		return true;										//e ritorniamo true
	}														//altrimenti
	
	if(r->right && cerca_cam(r->right, k,y,C+1)){			//se c'è un sottoalbero destro e un cammino nel sottoalbero destro
		*C=1;												//andiamo a destra
		return true;										//e ritorniamo true
	}

}
/*POST_cerca=(restituisce true sse in r esiste un cammino da r ad una foglia con esattamente k nodi con
campo info=y e false altrimenti, in caso restituisca true, C contiene una sequenza (anche vuota) di 0/1 che
termina con -1 e che individua il cammino più a sinistra in albero(r) con esattamente k y).*/

main(){
	ifstream IN("input");
	ofstream OUT("output");
	if(IN && OUT) { 
		int dim,k,y;
		IN>>dim;
		nodo* R=rep_ins(0,dim,IN);//data
      
		IN>>k>>y;
		//stampa_lf(R,OUT);
		int C[30];
		bool b=cerca_cam(R,k,y,C);//da fare
		if(b){
			OUT<<"true con cammino="; 
			sc(C,OUT); OUT<<endl;
		} //sc data
		else
			OUT<<"nessun cammino con "<<k<<" valori="<<y<<endl;
			IN.close(); OUT.close(); 
	}
	else
		cout<<"errore con i files";
}