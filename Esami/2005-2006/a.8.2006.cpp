#include <iostream>
using namespace std;

int * TAB(int *A, int dimA){
int *B1 = new int[5];
for(int i=0;i<dimA-1;i++)
 {int conta=0;
	for(int j=i+1;j<dimA;j++)
		if(A[i]>A[j])
			conta++;
 
 B1[i]=conta;
}
return B1;
}

main()
{
int A[5]={3, -1, 0, 8, 5}, dimA=5;
int*B=TAB(A,dimA);
for(int i=0;i<dimA;i++)
	cout<<B[i]<<" ";
cout << endl;
}
