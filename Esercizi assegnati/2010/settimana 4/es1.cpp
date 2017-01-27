#include<iostream>
using namespace std;

// Legenda:
// (V = per ogni, € = appartiene, § = esiste)

/*
PRE-F:
Array T di tipo char in input: T[limite1][10][15] quindi limite1 e' la prima dimensione dell'array dato, valore int >= 0.
P[] array di tipo char, rappresenta il pattern dato.
dim_P e' la lunghezza del pattern dato, valore int >= 0
*/
char * F(char (*T)[10][15], int limite1, char P[], int dim_P){
	int indice = 0, Mi_max = 0;
	// R1 = (indice = strato e Mi_max = Mi <=> Mi dello strato > VMi fino a strato-1)
	for (int strato = 0; strato < limite1; strato++){
        int Mi = 0;
        // R2 = (Mi = Mi_fino_riga_precedente + Mi_riga corrente per Vr in [0..riga])
		for (int riga = 0; riga < 10; riga++){
            // R3 = (Mi++ <=> una stringa di elem corrisponde al pattern dato, con elem che varia: {0 <= elem <= 15}
			for (int elem = 0; elem < 15; elem++){
                bool ok = true;
                if ((14-elem)<dim_P){
                    ok = false;
                }
				if ((T[strato][riga][elem] == P[0])){
                    // R4: ok <=> T[strato][riga][spia+elem] == P[spia] e' vero Vspia che varia: {0 <= spia <= dim_P-1}
                    // con strato, riga e elem fissati dai cicli piu' esterni.
					for (int spia = 0; (spia < dim_P && ok); spia++){
					    if (T[strato][riga][spia+elem] != P[spia]){
								ok = false;
					    }
					}
					if (ok){Mi++;}
				}
			}
		}
		if (Mi > Mi_max){
			indice = strato;
			Mi_max = Mi;
		}
	}//POST = (indice = strato e Mi_max = Mi <=> Mi dello strato > VMi fino a limite1-1)
	return *T[indice];
}
/*
POST-F:
F ritorna il puntatore al primo elemento dello strato X tale che: Mi_X > Mi_Z per ogni strato Z € all'array T. Dove Mi=N0+N1+..N9 e dove N0, N1,.., N9
sono il numero di match di P sulla riga [0, 1, ..., 9].
Nota: il match non puo' continuare sulla riga successiva.
*/

main()
{
}
