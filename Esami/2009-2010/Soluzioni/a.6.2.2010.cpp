#include<iostream>
using namespace std;

bool maa(int q,int * A,int dim,int m, int j){
	bool trovato=false;
	if(j==dim)
		return trovato;
	if((q+A[1])==m){
		trovato=true;
		return trovato;
	}
		return maa(q, A+1, dim, m, j+1);
}

bool F_RIC(int m, int* A, int dim, bool *R){
	int q=A[0];
	if(q==m)
		R[0]=true;
	else {
		bool trovato=false; i=1;
		while(!trovato){
			trovato=maa(q, A+i,dim,m,0);
			q=q+A[i];
			i++;
		}
	}
}

main()
{	int dim=ciccia;
	for(int i=0; i<dim; i++)
		R[i]=0;

}
