#include<iostream>
using namespace std;
//PRE: T[col] definito, col>=0, P definito
bool Vilnius(char *T, int col, char P){
	if(!col)
		return false;
	if(T[col-1]==P)
	return true;
  return Vilnius(T,col-1,P);
}
//POST: ritorna true sse P == T[b] con b in [0..col-1]

//PRE: T[dimP*col] definito, P[dimP]definito, dimP>=0
bool eddai(char *T,int col, char*P, int dimP)
{ if(!dimP)
	return true;
  if (Vilnius(T,col, *P))
	return eddai(T+col, col, P+1,dimP-1);
  return false;

}
//POST: ritorna true sse trova per ogni a in [0..dimP-1] t.c. esiste almeno un elemento della riga a di T=P[a]

//PRE: T[rig*col] definito, P[dimP] definito, 0<=conta<=rig-dimP+1
int PMR(char*T,int rig, int col, char*P, int dimP,int conta){
	if(conta+dimP-1>rig)
		return -1;
	 if(eddai(T+conta*col,col,P,dimP))
		return conta;
	 return PMR(T,rig,col,P,dimP,conta+1);	
}
//POST: ritorna l'indice della riga da cui parte il match

/* VILNIUS: caso base: col=0, quindi l'array è vuoto e non può esserci match e ritorna false
			caso base2: l'ultimo elemento dell'array è uguale a P, quindi ritorna true
			passo induttivo: T=T'+A, T[col-1]!=P e col>0
							 l'invocazione ricorsiva soddisfa la PRE_ric perchè col-1>=0 quindi per il passo induttivo l'invocazione
							  restituisce true o false se è stato trovato o meno un match in T', quindi soddisfa la post
	
	EDDAI: caso base: dimP=0 quindi a in[0..-1] ciò "soddisfa" la post è restituisce true
		   case base2: l'elemento P[0] non è presente nella riga 0, quindi restituisce false
		   passo induttivo: P[0] è presente nella riga 0, dimP>0, T[0..col-1+(dimP-1)*(col)]
						     l'invocazione ricorsiva soddisfa la PRE_ric poichè T+col= T[(dimP-1)*(col)] che è un array definito e dimP-1>=0
							 quindi per l'ipotesi induttiva soddisfa la POST_ric e il risultato viene restituito, ciò soddisfa la POST
	PMR: caso base1: conta+dimP-1>rig => non è possibile trovare un match completo in T => ritorna -1 
		 case base2: se è stato trovato un match nelle prime dimP-1 righe => restituisce conta che è il numero della riga inviata
		passo induttivo:  conta+dimP-1<rig, per la riga conta non è stato trovato un match => richiamo la funzione con conta incrementato di uno
							che soddisfa la PRE_ric poichè conta+1<=rig-dimP+1 quindi per il passo induttivo soddisfa la POST poichè tornerà (se è
							stato trovato un match) conta, sennò tornerà -1


*/

main()
{char T[8]={'a','a', 'b','a', 'a','a', 'c','a'}, P[2]={'a','x'};
	int  rig=4, col=2, dimP=2, indice;
	indice=PMR(T, rig, col, P, dimP,0);
	if(indice>-1)
	cout << indice << endl;
	else
	cout<<"non c'è"<<endl;
}
