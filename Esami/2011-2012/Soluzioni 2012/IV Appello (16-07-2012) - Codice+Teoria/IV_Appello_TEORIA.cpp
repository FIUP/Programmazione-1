//TEORIA
/* ESERCIZIO 1
PRE: (data nel testo)
POST: F ritorna true sse il numero di nodi dell'albero è pari,
false se il numero dei nodi è dispari
*/

//ESERCIZIO 2
#include <iostream>
using namespace std;

int *F(int* p)
{
	int b=0,*x=&b;
	x=p+2; //o equivalentemente x=b+4
	x[0]--;
	cout<<*x;
	p++; 
	return x-3; //o equivalentemente b+4-3=b+1==&b[1]
}

main()
{
	int b[]={1,2,3,4,5},*q=b+2;
	*F(q)=*q; //altresì: *(&b[1])=b[2] =>b[1]=3
	//cout<<b[0]<<b[1]<<b[2]<<b[3]<<b[4]<<endl; // CORRETTO, STAMPA: 13345	
}
