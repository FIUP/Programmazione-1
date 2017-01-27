#include<iostream>
using namespace std;

/*
-- TEORIA --

(i)
- A ha tipo int (*)[3][6]
- *(A+3)-10 = A[3][-10] quindi, dato che ogni strato ha tre righe, corrisponde a A[0][-1] quindi dato che l'indirizzo di partenza e'
  1000, bisogna fare: 1000-6*4 = 976. Quindi il tipo di *A(A+3)-10 e' (*)[6] e il suo valore e' 976.
- *(*A+2)-10 = A[0][2][-10] quindi, dato che ogni riga ha 6 elementi, corrisponde a A[0][0][2], quindi dato che l'indirizzo di
  partenza e' 1000, bisogna fare: 1000+2*4 = 1008

(ii)
La funzione e l'invocazione sono corrette. La funzione e' corretta perche' accetta in input una variabile int **x e ritorna, dopo alcune
operazioni, *x che e' l'indirizzo di una variabile del main() e quindi non viene de-allocata quando la funzione termina, non causando quindi
nessun dangling pointer. L'invocazione poi e' corretta, perche' si dereferenzia il puntatore p che diventa quindi un int ** che va bene per la funzione
F in input e, ritornando un L-valore, de-referenziandolo e' possibile poi assegnarci il valore a*3 che e' quindi corretto.

--- PROGRAMMAZIONE ---
Funzione (a):
PRE=(A[0..top-1] contiene valori definiti e ordinati in modo non decrescente, con top >=0, y è un intero > 0, pos e' un intero
>= 0 con la posizione del primo y nell'array e yNum il numero di y trovati nell'array.)
&& (vA è il valore iniziale di A e similmente vtop è il valore iniziale di top)

PROTOTIPO: bool cerca(int *A, int top, int y, int &pos, int &yNum)

POST = (cerca deve restituire trovato <=> y e' in A[0..top-1] e deve avere dei side-effect su pos e yNum in modo che pos punti al primo y trovato e
        yNum sia il numero di y trovati nell'array)

POST = (!trovato => Vj € [0,top-1] A[j] != y) && (trovato => 0 <= pos <= pos+yNum-1 < top
&& A[pos...pos+yNum-1] = y && A[0...pos-1] < y && A[pos+yNum..top-1]>y)
*/
bool cerca(int *A, int top, int y, int &pos, int &yNum){
    bool trovato = false;
    // R = {0 <= indice <= top-1} && {trovato esiste <=> y e' in A[0..indice-1]} && (A[0..indice-2] <= y)
    for (int indice = 0; indice < top && A[indice]<=y; indice++){
        if (A[indice] == y){
            // se yNum = 0, prima volta che troviamo un y nell'array.
            if (yNum == 0){
                pos = indice;
                trovato = true;
            }
            yNum++;
        }
    }// POST = (trovato <=> esiste almeno un A[i] == y con i in [0..top-1])
    return trovato;
}

bool a(int * A, int top, int y, int & start, int & quanti){
    bool trovato = false;
    // R = (A[0..i-2] < y && trovato <=> A[i-1] = y) && (0 <= i <= top-1)
    for (int i = 0; i < top && !trovato && A[i] <= y; i++){
        if (A[i] == y){
            trovato = true; start = i;
        }
        if (trovato){
            quanti = 1;
            // R = (A[start..i-1] = y && quanti = i-start)
            for (int i = start+1, y < top && A[i] == y; i++){
                quanti++;
            }
            // POST 2 = (A[start..start+quanti-1] = y && A[start+quanti...top-1] > y)
        }
        // A[0..i-1] < y && trovato <=> A[i] = y && i < top
    }
    return trovato;
    /* POST 1 = (trovato => A[0...start-1] < y && A[start] = y)
                  (!trovato => A[0...top-1] != y)
     R && !(permanenza) => Post1
     R && (i = top || trovato || A[i] > y)
     - trovato => A[0..start-1] < y
                  A[start] = y OK
    - R && i = top && !trovato:
        => A[0..top-1] < y
    */
}
/*
Alla fine del ciclo, indice sara' uguale a top o A[indice] > y, in quanto la condizione di permanenza nel ciclo, data da R, e'
che 0 <= indice <= top e che A[indice] <= y e la condizione di uscita e' !(indice < top && A[indice]<=y).

Due casi:

- indice = top:
    trovato = true -> y e' stato trovato in A[0...top-1] un yNum di volte.
    trovato = false -> y non e' stato trovato.
- indice < top && A[indice] > y:
    trovato = true -> y e' stato trovato in A[0...top-1] un yNum di volte
        e A[indice] e' un numero piu' grande di y, quindi non ha senso di cercare oltre
    trovato = false -> y non e' stato trovato in A[0...top-1] ma A[indice] e' troppo
        grande per provare a cercare oltre.

*/


/* Funzione (b):
PRE=(A[0..top-1] contiene valori definiti e ordinati in modo non decrescente, con top >=0, y e' un intero > 0, pos e' un intero
>= 0 con la posizione del primo y nell'array e yNum il numero di y trovati nell'array.) && (vA e' il valore iniziale di A e similmente vtop è il valore iniziale di top)

PROTOTIPO: int eliminaY(int *A, int top, int y, int pos, int yNum)

POST = (eliminaY deve restituire top tale che top sia la nuova lunghezza dell'array, A[0..top-1] sia definito, ordinato e senza y al suo interno e senza
        "buchi" al suo interno.)

POST = (A[0...pos-1] = vA[0...pos-1] && A[pos..top-1] = vA[pos+yNum...vtop-1] && top = vtop-yNum)
*/

int eliminaY(int *A, int top, int y, int pos, int yNum){
    int diff = top - pos;
    // R = {0 <= i <= diff-1} && {i e' tale che l'elemento di indice pos+i
    //deve venire sostituito dall'elemento di indice pos+i+yNum dell'array A, se e solo se
    // l'indice non indica l'ultimo elemento dell'array}
    // SINTETICAMENTE: R = (Vind in [0..i-1], A[pos+ind] = A[pos+ind+yNum])
    for (int i = 0; i < diff; i++){
        if (pos+i != top){
            A[pos+i] = A[pos+i+yNum];
        }
    }// POST = (Vind in [0..diff-1], A[pos+ind] = A[pos+ind+yNum])
    // cancello gli ultimi elementi
    // R = {0 <= j <= yNum-1} && {j e' tale che l'elemento di indice top-1-j viene azzerato}
    // VARIANTE: R = (Vk in [0..j-1], A[top-1-k] = 0)
    for (int j = 0; j < yNum; j++){
        A[top-1-j] = 0;
    }
    // POST = (Vj in [0..yNum-1], A[top-1-j] = 0)
    top -= yNum;
    return top;
}

// PRE=(A[0..top-1] contiene valori definiti e ordinati in modo non decrescente, con top >=0, y e' un intero > 0)
// && (vA e' il valore iniziale di A e similmente vtop e' il valore iniziale di top)
void F(int *A, int & top, int y){
    int pos = 0, yNum =0;
    if (cerca(A, top, y, pos, yNum)){
        top = eliminaY(A, top, y, pos, yNum);
    }
}
// POST=(F deve restituire un valore top, tale che A[0..top-1] e' ordinato, non contiene alcun y
// e contiene tutti gli elementi di vA[0..vtop-1] che sono diversi da y)

main(){

}
