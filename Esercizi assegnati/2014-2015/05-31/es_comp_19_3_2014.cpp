/*Integrazione sei crediti*/
#include<iostream>
#include<fstream>
using namespace std;
struct nodo{int info; nodo* left, * right; nodo(int a=0, nodo* b=0, nodo* c=0){info=a;left =b;  right=c;}};

void stampa_l(nodo *r, ofstream & OUT){
	if(r){
		OUT<<r->info<<'(';
		stampa_l(r->left,OUT);
		OUT<<',';
		stampa_l(r->right,OUT);
		OUT<<')';
    }
	else
		OUT<< '_';
}

//PRE = C[x...] contiene un cammino terminato da -1
int scorri(int* C, int x){											//x è un indice
	while(C[x]!=-1)													//finché C[x] non vale -1
		x++;														//il cammino continua
  return x+1;														//e ritorniamo l'indice della prima posizione del prossimo cammino
  
}
/*POST = restituisce la posizione in C immediatamente dopo il cammino che inizia in C[x]*/

int inizio_cam(int* C, int i){										//i è un'indice
	int x = 0;														//
	for(int count =0; (count <i && C[x] !=-2); count++)				//
		x= scorri(C,x);												//
	if(C[x] !=-2)													//
		return x;													//
	else 															//
		return -2;													//
}

void add_iter(int*C, nodo*& r,ifstream& INP, ofstream& OUT){
	nodo * avanti = r, *indietro = 0;
	bool lungo = false;
	int i = 0,x;
	INP >>x;
	while(C[i] !=-1 && !lungo){
		if(avanti){
			if(C[i] ==0){
				indietro = avanti;
				avanti = avanti->left;
			}
			else{
				indietro = avanti;
				avanti = avanti->right;
			}
		}
		else{
			OUT<<"cammino troppo lungo "<< x << endl;
			lungo = true;
		}
		i++;
	}
	if(!lungo){ //C[i] = -1
		if(avanti)
			OUT << "cammino troppo corto " << x << endl;
		else{
			//INP >>x;
			if(!indietro)
				r= new nodo(x,0,0);
			else{
				if(C[i-1] ==0)
					indietro->left = new nodo(x,0,0);
				else 
					indietro->right = new nodo(x,0,0);
			}
		}
	}
}

nodo* build_iter(int*C, nodo*r,ifstream & INP, ofstream & OUT){
	bool fine=false;
	for(int i=0; !fine; i++){
		int j=inizio_cam(C,i);
    
		if(j==-2)
			fine=true;
		else{
			add_iter(C+j, r, INP, OUT);
    
		}
	}
	return r;
}

void add_ric(int* C, nodo*& r, ifstream & INP, ofstream & OUT){
	if (C[0] ==-1)
		if(!r){
			r = new nodo();
			INP >> r->info;
		}
		else{
			int x;
			INP >>x;
			OUT << "cammino troppo corto "<< x << endl;
		}	
	else{
		if(r)
			if(C[0]==0)
				add_ric(C+1,r->left,INP,OUT);
			else 
				add_ric(C+1, r->right,INP,OUT);
			else{
				int x;
				INP >>x;
				OUT <<"cammino troppo lungo "<< x << endl;
			}
				
	}
}

nodo* build_ric(int*C, nodo* r, ifstream & INP, ofstream & OUT){	//costruisce un albero in base al cammino
	bool fine=false;												//
	for(int i=0; !fine ; i++){										//
		int j=inizio_cam(C,i);										//
		if(j==-2)													//
			fine=true;												//
		else														//
			add_ric(C+j, r, INP, OUT);								//
	}						
	return r;														//
}
	
nodo* costruz(){													//costruisce un albero di quattro nodi
	nodo*x2=new nodo(2);									
	nodo* x3=new nodo(3);									
	nodo* x4=new nodo(4);									
	nodo*x1=new nodo(1,x2,x3);								
	x2->right=x4;											
	return x1;												
}

main(){
	try{
	ifstream INP("input");
	ofstream OUT("output");
	if(!INP) throw(0);
	if(!OUT) throw(1);
	int C[200],x;
	INP>>C[0];
 
	for(int i=1; C[i-1]!=-2; i++)
		INP>>C[i];

	nodo *X=costruz();										//costruisce l'albero
	nodo *r=build_iter(C,X,INP,OUT);						//in modo iterativo
	stampa_l(r,OUT);										//e lo stampa
	OUT<<endl;

	r=build_iter(C,0,INP,OUT);
	stampa_l(r,OUT); 
	OUT<<endl;
	
	X=costruz();
	r = build_ric(C,X,INP, OUT);
	stampa_l(r,OUT);
	OUT<<endl;

	r=build_ric(C,0,INP,OUT);
	stampa_l(r,OUT);
	OUT<<endl;

	}
	catch(int x){
		switch(x){
		case 0: cout<<"problemi con input"<<endl; break;
		case 1: cout<<"problemi con output"<<endl; break;
		}
	}
}