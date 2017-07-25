// soluzione di B.Cosentino
#include <iostream>

using namespace std;

// PRE = A e' un array di int, i <= j+1 sono indici all’interno dell’array
void inverti(int *A, int i, int j){
    
    if (i<j){
        int S;
        S=A[i];
        A[i]=A[j];
        A[j]=S;
        
        
        // PRE_ric: A e' un array di int, i+1 <= j-1+1 sono indici all’interno dell’array
        inverti(A,i+1,j-1);
        // POST_ric = A viene modificato invertendo l’ordine degli elementi nel sottoarray A[i+1,...,j-1]
    }
   
}
// POST = A viene modificato invertendo l’ordine degli elementi nel sottoarray A[i,...,j]

/*****************************************************
DIMOSTRAZIONE

Caso base: dalla PRE sappiamo che A e' un array di int, (i <= j+1) sono indici all’interno dell’array.
            
            Il caso base implicito e' (i>=j).  (i <= j+1) & (i>=j) -> (j<=i<=j+1) -> (i=j || i=j+1).
            
            Se i=j, il sottoarray e' A[i...i], ovvero contiene un elemento solo che possiede lo stesso ordine dello stesso sottoarray invertito. ->
            -> POST valida
            Se i=j+1, ovvero i-1=j, il sottoarray e' A[i...i-1], ovvero l'array vuoto che non possiede nessun elemento -> POST valida
Caso induttivo:
            Effettuo lo scambio degli elementi A[i] e A[j]. E poi effettuo lo scambio del resto del sottoarray, ovvero A[i+1...j-1].
            So da PRE che (i <= j+1). Inoltre, (i < j) -> (i+1 <= j) -> (i+1 <= (j-1) + 1) -> PRE_ric
            Quindi, per l'ipotesi induttiva vale POST_ric -> Ho invertito tutto il sottoarray A[i+1...j-1] -> POST
            
*****************************************************/

void stampaR(int A[], int dimA){
   
    if (dimA>=1){
        cout << A[0] <<" ";    
        stampaR(A+1,dimA-1);
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
    
    //stampaR(A,lung);
    for (int i=0; i<lung; i++)
        cout << A[i] << " ";
    

    cout << "end" << endl;
}
