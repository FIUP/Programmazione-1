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
				{k--; F1(A, i+1, dim, x, k); cout << i << " ";
					
				}
			else F1(A, i+1, dim, x, k);
		}
	}
}
//POST: a in[i .. dim-1] cout contiene gli indici di al massimo k elementi t.c. A[a]=x
main(){
	int A[15]={0,1,2,1,3,1,2,1,1,1,1,0,1,2,4}, x=1, k=3;
F1(A, 0,15,x,k);
}
