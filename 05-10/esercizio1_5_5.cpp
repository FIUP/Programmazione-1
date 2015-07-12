/*Integrazione sei crediti*/
#include<iostream>
#include<climits>
#include<fstream>
using namespace std;

struct M {int lung, inizioP, inizioT; M(int a=0, int b=0, int c=0){lung=a; inizioP=b; inizioT=c;}};
//lung lunghezza della porzione di P che viene matchata
//inizioP èposizione in P in cui inizia la porzione matchata
//inizioT indica la posizione in T in cui inizia il match

int lenght(int *T, int dim, int*P, int dimP, int index, int indiceT){	//restituisce la lunghezza della porzione di match trovata
	if (indiceT==dim || index==dimP)									//se non c'è più testo dove cercare o abbiamo finito il pattern
		return 0;														//ritorniamo 0

	if (T[indiceT]==P[index])											//se l'elemento considerato coincide con quello del pattern
		return 1+lenght(T,dim,P,dimP, index+1, indiceT+1);				//abbiamo matchato un elemento e ritorniamo 1+i prossimi elementi matchati
	else return 0;														//altrimenti ritorniamo 0
}

M currMatch(int *T, int dim, int*P, int dimP, int index, int indiceT){
	M mat=(0,-1,-1);													//riprendiamo la logica di match con un M base

	if (index==dimP)													//se index è uguale a dimP
		return mat;														//ritorniamo M

	M migl=currMatch(T,dim,P,dimP,index+1,indiceT);						//calcoliamo il migliore tramite un'invocazione ricorsiva

	int lung=lenght(T,dim,P,dimP,index, indiceT);						//calcoliamo la lunghezza del match corrente invocando lenght

	if (lung>=migl.lung && lung){										//se la lunghezza del corrente è maggiore di 0 e maggiore uguale a quella del migliore
		mat.lung=lung;													//impostiamo mat nella sua lunghezza
		mat.inizioP=index;												//inizioP
		mat.inizioT=indiceT; 											//e inizioT
		return mat;														//e lo ritorniamo
	}
return migl;															//di default ritorniamo il migliore
}

//PRE=(dimP>0, dim>0, T[0..dim-1] è definita, P[0..dimP-1] è definita, 0<=indiceT<=dim)
M match(int*T, int dim, int*P, int dimP, int indiceT){
	M mat(0,-1,-1);														//costruiamo un M base di lughezza 0 e posizioni convenzionalmente
																		//poste a -1 (valore non valido come indice dell'array)
	if (indiceT==dim) 													//indiceT coincide con la dimensione di T
		return mat;														//ritorniamo M

	M max=match(T,dim,P,dimP,indiceT+1); 								//calcoliamo il massimo invocando match

	M curr=currMatch(T,dim,P,dimP,0,indiceT);							//calcoliamo il valore corrente invocando currMatch

	if (curr.lung>max.lung)												//se la lunghezza di curr è maggiore di quella del massimo
		max=curr;														//curr diventa il nuovo massimo
	else																//altrimenti
		if (curr.lung==max.lung && curr.inizioP<max.inizioP)			//a parità di lunghezza se curr ha inizioP minimo rispetto a massimo
			max=curr;													//diventa il nuovo massimo
return max;																//ritorniamo il massimo trovato
}
/*POST=(restituisce un valore M che rappresenta il massimo match in T[indiceT..dim-1]di una porzione di P
(secondo l'ordine descritto prima: lunghezza massima, a parità di lunghezza, inizioP minimo e, a parità di
lunghezza e inizioP, inizioT massimo), qualora non ci siano match, la funzione deve restituire [lung=0,
inizioP=-1, inizioT=-1])*/

main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT) 
  { 
   int T[200], P[20], dim, dimP;
   IN>>dim;
   for(int i=0; i<dim;i++)
     IN>>T[i];
   IN>>dimP;
   for(int i=0; i<dimP;i++)
     IN>>P[i];
   M x=match(T,dim, P, dimP, 0);// funzione ricorsiva da fare
   OUT<<"[lung="<<x.lung<<" inizioP="<<x.inizioP<<" inizioT="<<x.inizioT<<']'<<endl; // e' l'occasione di ridefinire << per M
    
   IN.close(); OUT.close(); 
  }
  else
   cout<<"errore con i files";
 }
