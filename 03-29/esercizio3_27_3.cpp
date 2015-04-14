/*Integrazione sei crediti
TEORIA:
1) char & C(char &x, char &y) {y=x; return x;}
main(){ 
char A[] = {‘a’,’b’,’c’};
C(A[0],A[1]) = A[2];
cout << A[0] << A[1] << A[2] <<endl; }

La funzione C ritorna un char per riferimento e accetta due char per riferimento
come parametri formali. Ritorna x il che è corretto essendo x passato per riferimento
dunque "sopravvive" alla deallocazione delle variabili locali di f.
Quindi C è corretta, nel main vengono passati alla funzione i valori a e b,
A[1] diventa alias di A[0] quindi viene ritornato A[0] a questo punto l'array contiene
(a, a, c) in A[0] viene assegnato c e l'array diventa (c, a, c).
Quindi La funzione è corretta, il main pure e stampa "cac"
 
2) 
char * C(char *x, char &y) {x=&y; return x;}

main(){ 
char A[] = {‘a’,’b’,’c’};
*C(A,A[1]) = *(A+2);
cout << A[0] << A[1] << A[2] <<endl; }

La funzione ritorna un puntatore char, come parametri formali chiede un puntatore
ed una variabile passata per riferimento (invocazione nel main corretta). 
Assegna al puntatore x l'L-valore di y (A[1] in questo caso) che esiste sempre essendo
passato per riferimento e ritorna il puntatore. Quindi C è corretta, al suo ritorno
viene assegnato il valore di A[2] (c) in A[1] (il valore ritornato da C) quindi l'array
sarà (a, c, c) e verrà stampato acc.
*/

#include<iostream>
#include<fstream>
using namespace std;

//PRE=(X contiene una sequenza che soddisfa le condizioni esposte nel pdf, e 0<=i)
int S(int* X, int i){
	int conta=0, j;

	for(j=0; X[j] !=-2 && conta <i; j++){
		/*(X[0..j-1] sono diversi da -2) &&
		(conta = numero di -1 trovati in X[0..j-1])*/
		if(X[j] ==-1)
			conta++;
	}

	if (conta == i) {
		if(X[j] ==-2)
			return -2;
		else return j;
	}
	else return -2;
		
	//R && (X[j] ==-2 || conta=i) => POST
}// POST=(se X contiene la sottosequenza i, allora S restituisce l'indice di X in cui la
//sottosequenza i inizia, altrimenti S restituisce -2)

main()
{
  ifstream IN("input");
  ofstream OUT("output");
  if(IN && OUT) 
  { 
   int X[100];
   IN>>X[0];
   for(int i=1; i<100 && X[i-1]!=-2; i++)
   {IN>>X[i];}
    
    int a;
    IN>>a;
    int b=S(X,a); // funzione da fare
    if(b==-2)
     OUT<<"sottosequenza "<<a<<" non presente"<<endl;
    else
     OUT<<"inizio sottosequenza "<<a<<" indice="<<b<<endl;


   OUT<<"fine"<<endl;
   IN.close(); OUT.close(); 
  }
  else
   cout<<"errore con i files";
 }
