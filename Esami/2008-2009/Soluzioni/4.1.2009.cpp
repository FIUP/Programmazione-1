#include <iostream>
using namespace std;

void F(int*A, int dim, int colon){
	
	for(int i=0; i<dim; i++){
		for(int j=0; j<colon ; j++)
			cout << A[i*(colon-1)+j]<<" ";
		cout << endl;
	}

}

main()
{ int A[10], dim=10, colon=3, rig_p=dim/colon, ult=dim%colon;
	for(int i=0;i<10;i++)
		cin>> A[i];
	F(A, rig_p, colon);
	F(A, 1, ult);
}
