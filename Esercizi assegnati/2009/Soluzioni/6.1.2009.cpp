#include <iostream>
using namespace std;
//PRE: A[0 ... dim-1] definito, 0<=i<=dim, 0<=k<=vk
void F1(int *A, int i, int dim, int x, int k){
	if(k!=0)
	{
		if(i==dim)
			cout << endl;
		else {
			if(A[i]==x)
				{k--;cout << i << " ";
					
				}
			F1(A, i+1, dim, x, k);
		}
	}
}
//POST: a in[i .. dim-1] cout contiene gli indici di al massimo k elementi t.c. A[a]=x
main(){
	int A[15]={0,1,2,1,3,1,2,1,1,1,1,0,1,2,4}, x=1, k=3;
F1(A, 0,15,x,k);
}
/*
CASO BASE: se k!=0 && i=dim => cout è vuoto perchè l'array è finito || se k=0 && i<dim => F1 termina poichè abbiamo 0 indici da stampare
PASSO INDUTTIVO: PRE_ric: 0<=i<dim && 0<k<=vk 
				 se A[i]=x cout contiene i e al massimo altri k-1 indici, 
				 se A[i]!=x cout contiene al massimo altri k indici 
	
			
*/
