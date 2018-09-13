//Soluzione di S.Righetto

#include <iostream>

using namespace std;

// PRE = i <= j sono indici all'interno dell'array ,A è un array di int.
void inverti(int *A, int i, int j){
	if(j-i < 1) return; //caso base

	int temp= A[i]; //passo induttivo
	A[i]=A[j];
	A[j]=temp;
	
	// PRE_ric = i+1 <= j-1 sono indici all'interno dell'array ,A è un array di int.
	inverti(A, i+1, j-1);
	//POST_ric = A viene modificato invertendo l’ordine degli elementi nel sottoarray A[i+1 .. j-1]
}
// POST = A viene modificato invertendo l’ordine degli elementi nel sottoarray A[i,...,j]

/******* DIMOSTRAZIONE
CASO BASE: (j -i < 1) -> (j-i <= 0) -> (j <= i) ho due sotto casi, il primo in cui i = j ossia il sottoarray è A[i .. i] ovvero contiene un solo elemento che ha lo stesso ordine del sottoarray invertito -> POST valida, il secondo sottocaso in cui i = j+1 ossia il sottoarray è A[i .. i-1] ovvero non contiene nessun elemento -> POST valida.

PASSO INDUTTIVO: so che il mio array ha due o più elementi, quindi effettuo lo scambio tra il primo e l'ultimo elemento ossia A[i] e A[j]. Poi effettuo lo scambio anche nel resto del sottoarray ossia A[i+1] e A[j-1]. Da questo, PRE_ric è valida e quindi per ipotesi induttiva anche POST_ric -> se A[i+1 .. j-1] è un sottoarray invertito allora anche A[i..j] sarà un sottoarray invertito.

*******/

void stampa(int*A, int n){
	if(n>0){
		cout << *A << ' ';
		stampa(A+1, n-1);
	}
}


int main() 
{
    int lung, primo, ultimo;
    int A[100];
    cin >> lung >> primo >> ultimo;
    for(int i = 0; i < lung; i++) { 
        cin >> A[i];
    }
    cout << "start" << endl;
	inverti(A,primo,ultimo);
	stampa(A,lung);
	
    cout << endl << "end" << endl;
}
