/*Integrazione sei crediti*/
#include<iostream>
#include<climits>
#include<fstream>
using namespace std;

struct M {int lung, inizioP, inizioT; M(int a=0, int b=0, int c=0){lung=a; inizioP=b; inizioT=c;}};

int lenght(int *T, int dim, int*P, int dimP, int index, int indiceT){
	if (indiceT==dim || index==dimP)
		return 0;

	if (T[indiceT]==P[index])
		return 1+lenght(T,dim,P,dimP, index+1, indiceT+1);
	else return 0;
}

M currMatch(int *T, int dim, int*P, int dimP, int index, int indiceT){
	M mat=(0,-1,-1);

	if (index==dimP)
		return mat;

	M migl=currMatch(T,dim,P,dimP,index+1,indiceT);

	int lung=lenght(T,dim,P,dimP,index, indiceT);

	if (lung>=migl.lung && lung){
		mat.lung=lung;
		mat.inizioP=index;
		mat.inizioT=indiceT; 
		return mat;
	}

return migl;
}

//PRE=(dimP>0, dim>0, T[0..dim-1] è definita, P[0..dimP-1] è definita, 0<=indiceT<=dim)
M match(int*T, int sim, int*P, int dimP, int indiceT){
	M mat(0,-1,-1);

	if (indiceT==sim) 
		return mat;

	M max=match(T,sim,P,dimP,indiceT+1); 

	M curr=currMatch(T,sim,P,dimP,0,indiceT);

	if (curr.lung>max.lung)
		max=curr;
	else
		if (curr.lung==max.lung && curr.inizioP<max.inizioP)
			max=curr;

return max;
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
