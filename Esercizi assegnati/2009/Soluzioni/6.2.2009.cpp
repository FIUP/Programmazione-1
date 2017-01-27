#include <iostream>
using namespace std;

void F1(int *A, int i, int dim, int x, int k){
	if(k!=0)
	{
		if(i==-1)
			cout << endl;
		else {
			if(A[i]==x)
				{k--;cout << i << " ";
					
				}
			F1(A, i-1, dim, x, k);
		}
	}
}

main(){
	int A[15]={0,1,2,1,3,1,2,1,1,1,1,0,1,2,4}, x=1, k=3;
	F1(A, 14,15,x,k);
}
