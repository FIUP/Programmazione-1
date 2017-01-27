#include <iostream>
using namespace std;
//PRE: T è definito con dim elementi, P è definito con dim_P elementi, colon= numero elementi della riga
bool match(char *T, char*P, int dim_P, int colon, int j){
	bool trovato=true;

	for(int k=1; k<dim_P && trovato; k++){//R: 1<=k<=dim_P, !trovato sse esiste una a in[1..k-1] t.c. P[a]!=T[a+j]
		if(P[k]!=T[k+j])					// && per ogni b in[1..k-2] P[b]=T[b]
			trovato=false;
	}
	return trovato;
}
//POST: trovato=> per ogni a in[1..dim_P] esiste P[a]=T[a+j] || !trovato=> esiste una a in[1..dim_P] t.c. P[a]!=T[a+j]

//PRE: T è definito con dim elementi, P è definito con dim_P elementi
int F(char *T, int dim, int colon, char*P, int dim_P){
	int rig=dim/colon, ele_ult_rig=dim%colon, indice=-1;
	bool trovato=false;
	for(int i=0; i<rig && !trovato; i++){
		for(int j=0; j<(colon-dim_P+1) && !trovato; j++){//R: 0<=j<=(colon-dim_P+1), trovato sse per a in[0..j-1] esiste P[0]=T[a]
			if(P[0]==T[j])								//    && per b in[1...dim_P] esiste P[b]=T[b] && indice = i
				trovato=match(T+i*colon, P, dim_P, colon, j);
			if(trovato)
				indice=i;
		}
	}
	//POST: indice=-1 && !trovato sse per c in[0..rig-1] esiste un T[c] (righe di T) t.c. per a in[0..colon-dim_P+1]
		// esiste P[0]=T[a] && per b in[1...dim_P] esiste P[b]=T[b] && indice = i
	if(!trovato){
		for(int i=0; i<(ele_ult_rig-dim_P+1) && !trovato; i++){ // R: 0<=i<=(ele_ult_rig-dim_P+1), trovato sse per a in[0..i-1]
		if(P[k]!=T[k+j])										// 	  esiste P[0]=T[a] && per b in[1...dim_P] 
			if(P[0]==*(T+rig*colon+i))							//    esiste P[b]=T[b] && indice=rig
				trovato=match(T+rig*colon, P, dim_P, colon, i);
			if(trovato)
				indice=rig;
		}
	}
		
	return indice;
}
//POST: indice=-1 sse non è stato trovato alcun match || indice=a, con a in[0..rig], a= riga in cui è 
// stato trovato il match

//PRE: T è definito con dim elementi, P è definito con dim_P elementi
main(){
char T[11]={'a','b','c','d', 'a','b','a','b', 'a','c','e'}, P[3]={'a','c','e'};
int colon=4, dim=11, dim_P=3;
int indice_riga=F(T, dim, colon, P, dim_P);
}
//POST: indice_riga=-1 sse non è stato trovato alcun match || indice_riga=a, con a in [0..(dim/colon)], a= riga in cui è 
// stato trovato il match

/*
PROVA di correttezza for funzione match
inizio: k=1 trovato=true => P[0]=T[0-j] && per ogni b =-2 P[b]=T[b] è insieme vuoto quindi valido
ciclo: R && (k<=dim_P && trovato) < if(P[k]==T[k+j]) => trovato rimane true && k++ >
fine: R && !(k<=dim_P && trovato) => POST
	  k=dim_P && trovato || k<dim_P && !trovato

PROVA di correttezza for interno funzione F
inizio: j=0 trovato=false poichè a=-1 P[0]=T[a] insieme vuoto
ciclo: R && (j<colon-dim_P+1 && !trovato) < if(P[0]!=T[j]) trovato rimane false && j++ >
fine: R && !(j<colon-dim_P+1 && !trovato) => POST
	  j=colon-dim_P+1 && !trovato || j<colon-dim_P+1 && trovato
*/
