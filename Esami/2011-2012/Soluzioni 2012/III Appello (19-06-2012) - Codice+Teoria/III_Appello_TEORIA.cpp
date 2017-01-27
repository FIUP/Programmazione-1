//TEORIA
/* ESERCIZIO 1
PREMESSA: un cammino è detto STABILE se un nodo x con 2 figli del cammino ha valore false 
(il che significa che il suo figlio che appartiene al cammino 
ha anche lui valore false), allora x nell'albero deve avere valore false. 
Il che significa che tutti i cammini stabili che partono da x e 
arrivano ad una foglia danno valore false per x. Insomma possiamo 
contare sui cammini stabili, essi danno un valore di verità ai loro 
nodi che è uguale a quello che essi hanno nell'albero. 

PRE= a punta ad un albero eventualmente vuoto
POST= la radice dell'albero è true sse esiste un cammino STABILE dalla radice ad
una foglia con un numero pari di nodi con un solo figlio
*/

//ESERCIZIO 2
#include <iostream>
using namespace std;

int *f(int*&p)
{
	int b=3,*x=&b;
	x=p+1; //o equivalentemente x=b+3
	p++; 
	return x-2; //o equivalentemente b+3-2=b+1==&b[1]
}

main()
{
	int b[]={1,2,3,4},*q=b+2;
	*f(q)=*q; //altresì: *(&b[1])=b[3] =>b[1]=4
	cout<<b[0]<<b[1]<<b[2]<<b[3]<<endl; // CORRETTO, STAMPA: 1434	
}