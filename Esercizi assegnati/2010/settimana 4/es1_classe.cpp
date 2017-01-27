#include<iostream>
using namespace std;

// Legenda:
// (V = per ogni, € = appartiene, § = esiste)

bool contenuto(char T[], int c, char P[], int dim_P){
    bool cicla = true;
    // R = {cicla <=> Vj € [0..i-1] e T[j+c] == P[j]}
    for (int i = 0; i < dim_P && cicla; i++){
        cicla = T[C+i] == P[i];
    }
    return cicla;
}
// POST = {cicla <=> Vi € [0..dim_P-1] e T[i+c] == P[i]}

//PRE = (dim_P > P[0..dim_P-1] e T[0..9][0..14] array di caratteri definiti)
int contaInStratoN(char T[][15], char P[], int dim_P){
    int ripetizioni = 0;
    // R1 = (ripetizioni = n° di match anche sovrapposti < nT[0..r-1]) && (0 <= r <= 10)
    for (int r = 0; r < 10; r++){
        for (int c = 0; c < 15 - dim_P+1;c++){
            if (contenuto(T[r],c,P,dim_P)){
                ripetizioni++;
            }
        }
    }
    return ripetizioni;
}
//POST = (contaInStratoN(T,P,dim_P) = match di P in T)

/*
PRE-F:
Array T di tipo char tutto definito in input: T[limite1][10][15] quindi limite1 e' la prima dimensione dell'array dato.
P[] array di tipo char, rappresenta il pattern dato, è definito.
dim_P e' la lunghezza del pattern dato.
*/
char * F(char (*T)[10][15], int limite1, char P[], int dim_P){
	int indice = 0, Mi_max = 0;
	// R1: indice = strato e Mi_max = Mi <=> Mi dello strato > VMi da 0 a strato-1 con strato che varia: {0 <= strato <= limite1}
	for (int strato = 0; strato < limite1; strato++){
        int Mi = 0;
        // R2: Mi = Mi_fino_riga_precedente + Mi_riga corrente per Vriga fino alla riga corrente, con riga che varia: {0 <= riga <= 10}
		for (int riga = 0; riga < 10; riga++){
            // R3: Mi++ <=> una stringa di elem corrisponde al pattern dato, con elem che varia: {0 <= elem <= 15-dim_P+1}
			for (int elem = 0; elem < 15-dim_P+1; elem++){
                bool ok = true;
                // R4: ok <=> T[strato][riga][spia+elem] == P[spia] e' vero Vspia che varia: {0 <= spia <= dim_P}
                // con strato, riga e elem fissati dai cicli piu' esterni.
                for (int spia = 0; (spia < dim_P && ok); spia++){
                    ok = T[strato][riga][spia+elem] == P[spia];
                }
                if (ok){Mi++;}
				}
			}
		}
		if (Mi > Mi_max){
			indice = strato;
			Mi_max = Mi;
		}
	}
	return &T[indice][0][0];
        // *T[indice]
        // T[indice][0]
        // *(*(T+indice))
}
/*
POST-F:
F ritorna il puntatore al primo elemento dello strato X tale che: Mi_X > Mi_Z per ogni strato Z € all'array T. Dove Mi=N0+N1+..N9 e dove N0, N1,.., N9
sono il numero di match anche sovrapposti di P sulla riga [0, 1, ..., 9].
Nota: il match non puo' continuare sulla riga successiva.
*/

main()
{
}
