// soluzione di B.Cosentino
#include <iostream>

using namespace std;

void stampaR(int A[], int dimA){

    if (dimA>=1){
        cout << A[0] <<" ";
        stampaR(A+1,dimA-1);
    }
}


// PRE = A e' un array di lunghezza lung >=2 & posmin=0
int* minimo(int A[], int lung){

    if (lung==2){

        if (A[0]<A[1])
            return A;
        else{
            return A+1;

        }
    }
    // PRE_ric: A[1...lung-1] e' un array di lunghezza lung-1 >=2 & posmin=0
    int* min=minimo(A+1,lung-1);
    // POST_ric = restituisce il puntatore al minimo di A[1...lung-1]
    if (A[0]<=*min){
        return A;
    } else {
        return min;
    }
    

}
// POST = restituisce il puntatore al minimo di A

/************************************************************
DIMOSTRAZIONE

Casi base:
    So che (lung >= 2).
    
    Se lung==2, allora o A[0]<A[1] o A[0]>=A[1].
        Nel primo caso, A[0] e' il minimo di A -> restituisco A -> 
        -> POST valida.
        Nel secondo caso, A[1] e' il minimo di A -> restituisco A+1 ->
        -> POST valida

Caso induttivo:
    Se (lung > 2) allora (lung>=3) -> (lung-1 >= 2)
    So che A=A[0...lung-1] e' un array di lunghezza lung, allora A[1...lung-1] e' un array di lunghezza lung-1 e (lung-1>=2)
    Quindi, A[1...lung-1] e' un array di lunghezza lung-1 >=2 -> PRE_ric valida
    
    Quindi,
    int* min=minimo(A+1,lung-1); 
    Quindi, per la POST_ric, min e' il puntatore al minimo di A[1...lung-1].
    Se A[0] <= *min, allora restituisco A.
    Se A[0]>min, allora restituisco il puntatore al minimo. -> POST valida
    
    
************************************************************/


// PRE = A è un array di int di lunghezza lung >= 1
void ordina(int *A, int lung){

    if (lung>1){
        int* min=minimo(A,lung);
        
        // m <= A[i] per ogni i in [0,lung-1]
        int temp = *min;
        *min = A[0];
        A[0]=temp;
        // PRE_ric = A[1...lung-1] è un array di int di lunghezza lung-1 >= 1
        ordina(A+1,lung-1);
        // POST = A[1...lung-1] è ordinato in modo crescente
    }

}
// POST = A è ordinato in modo crescente


/**********************************************************

DIMOSTRAZIONE

Caso base:
    So da PRE che (lung >= 1). Se (lung == 1), allora l'array A e' gia' ordinato.
    
Caso induttivo:
    So da PRE che (lung >= 1). Inoltre (lung > 1) -> (lung >= 2). Quindi, trovo la posizione del minimo ed effettuo lo scambio.
    int* min=minimo(A,lung);
    int temp = *min; *min=A[0]; A[0]=temp;
    
    Quindi, l'array A[1...lung-1] e' lungo lung-1.
    So che (lung >= 2) -> (lung-1 >= 2-1) -> (lung-1 >= 1) -> PRE_ric valida.
    Infine, ordino l'array A[1...lung-1] e vale la POST_ric
    
    Percio' in A[0] si trova il minimo dell'array A e l'array A[1...lung-1] e' ordinato -> POST valida
    
**********************************************************/

int main()
{
    int lung;
    int A[100];
    cin >> lung;
    for(int i = 0; i < lung; i++) {
        cin >> A[i];
    }
    cout << "start" << endl;

    ordina(A,lung);

    stampaR(A,lung);

    cout << "end" << endl;
}
