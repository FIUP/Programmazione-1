#include <iostream>
using namespace std;

int G(int*A, int dim){
	bool esci=false; int buoni=0, cont=0;
	for(int i=0; i<dim && !esci; i++){
		cin >> A[i];
		if(A[i]==-1) 
		cont++;
		else cont=0;
		if(cont==2) 
		esci =true;
		buoni++; 

	}
 if(esci) buoni=buoni-2;
	for(int i=0;i<buoni;i++)
		cout<< A[i]<<" "; 
}

main()
{
int A[10]={}, dim=10;

G(A, dim);

}
