#include <iostream>
using namespace std;

void cerca(int *A, int dim, int & inizio, int & lung){
	int temp=1;
	for(int i=0; i<dim-1; i++){//R: 0<=i<=dim-1,n in[1..i] temp=n t.c. A[i-n]<=A[i-n+1]...<=A[i], lung è il valore maggiore di temp
		if(A[i]<=A[i+1])
			temp++;
		else{ 
		if(temp>lung){ lung=temp; inizio=i-lung+1;}
		temp=1;}
	}	
}//POST:  lung è la sottosequenza contigua di lunghezza massima che sia non decrescente in A


main()
{	int A[9]={10, 3,4,2,-5,1,10,10,4};
	int dim=9, inizio=0, lung=1;

	cerca(A, dim, inizio, lung);

	cout << "inizio= "<< inizio <<" "<< "lunghezza= " << lung << endl;

}
