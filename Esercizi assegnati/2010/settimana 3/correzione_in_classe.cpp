#include<iostream>
using namespace std;

// SOLUZIONE STUDENTE ES 1

// PRE: (esiste int A[limite1][5][10] con minore(limite1*5*10, n_ele) elementi definiti. Con n_ele > 0)
int F(int A[][5][10], int limite1, int n_ele){
    int min = minore(limite1*5*10, n_ele), stratoMax = 0, max = 0, somma;
    int i = 0, j = 0, elem = 0;
    for (j; j<5 && elem < min - 1; j++)
        for (k; k < 10 && elem < min - 1; k++){
            somma += A[i][j][k]
            elem = (j*10)+k;
        }
        max = somma;
        somma = 0;
        for (i = 1; i < limite1 && elem < min; i++){
            for (j = 0; j < 5 && elem < min; j++){
                for (k = 0; k<10 && elem < min; k++){
                    elem = (i*5*10)+(j*10)+k;
                    if (elem < min)
                        somma += A[i][j][k];
                }
            }
            if (somma > max){
                stratoMax = i;
                max = somma;
            }
            somma = 0;
        }
        return stratoMax;
}

}
// POST: (F: ritorna il valore di i (0<=i<limite1) t.c. somma degli elementi definiti di A[i] >= somma degli elementi definiti di A[x] (0<=x<limite1)

// SOLUZIONE PROFESSORE ES 1
#include<iostream>
using namespace std;

// PRE = {S e' un array[5][10] che contiene i primi n elem def con n > 0}
int somma(int (*S)[10], int n){
	int * inizio = &S[0][0];
	int somma = 0;
	for (int i = 0; i < n; i++){
		somma += inizio[i];
	}
	return somma;
}
// POST = {restituisce la somma dei primi n elementi dell'array S.


int F(int A[][5][10], int limite1, int n_ele){
	if (n_ele > limite1*5*10){
		n_ele = limite1*5*10;
	}
	int sp = n_ele/50, u = n_ele % 50,
	int max = INT_MIN, indice = 0, somma = 0;
	for (int s = 0; j < sp; s++){
		int s = somma(A[s], 50);
		if (s > max){
			max = 5;
			indice = s;
		}
	}
	int s = somma(A[sp, u)
		if (s > max)
			indice = sp;
	return indice;
}

// SOLUZIONE STUDENTE (PARZIALE) ES 2
#include<iostream>
using namespace std;

int G(int* A, int limite1, int limite2, int limite3, int n_ele){
	// indice e' l'indice della fetta tra [0,i-1]
	for (int i = 0; i < limite2; i++){
		int somma_parz = 0; bool fine_fetta = false;
		for (int j = 0; j < limite_1 and not fine_fetta; j++){
			for (int k = 0; k < limite3 and not fine_fetta, k++){
				int pas = j*limite2*limite3+limite3*i+k;
				if (pas < n_ele){
					somma_parz += *(p+pos);
				}else{
					fine_fetta = true;
				}
			}
		}
		if (somma < somma_parz){
			somma = somma_parz;

main(){

}
