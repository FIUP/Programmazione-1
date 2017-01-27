#include<iostream>
#include<fstream>
using namespace std;

/*

--- LEGENDA: V = per ogni, € = appartiene, § = esiste. ---
*/

/*
PRE-F = {A: puntatore ad un array a limite1 strati, limite2 dimensioni per strato e limite3 elementi per dimensione, definito
         n_ele: valore int > 0
         limite1*5*10 = val massimo di elementi che puo' avere l'array dato.}
*/

int F(int A[][5][10], int limite1, int n_ele){
    // trovo il minore tra il max e n_ele dato e lo salvo nella stessa variabile n_ele
    if (n_ele > limite1*5*10){
        n_ele = limite1*5*10;
    }

    int indice = 0, somma_max = 0; // inizializzo somma_max per sicurezza a 0, anche se non e' necessario.
    // R1 = {finche' n_ele > 0: indice = strato-1 <=> somma_elem di (strato-1) >= somma_elem di Vt €[0, strato-1],
    for(int strato = 0; strato < limite1 and n_ele > 0; strato++){
        int somma = 0;
        // R2 = {finche' n_ele > 0: somma relativa = e1 + e2 + ... + ez per Vz € [0, (riga-1)*10]}
        for(int riga = 0; riga < 5 and n_ele > 0; riga++){
            // R3 = {finche' n_ele > 0: somma relativa = e1 + e2 + ... + ez per Vz € [0, elem-1]}
            for (int elem = 0; elem < 10 and n_ele > 0; elem++){
                n_ele--;
                somma += A[strato][riga][elem];
                }
        }
        cout << "\n\nSomma strato " << strato << ": " << somma;
        // se lo strato e' il primo, non serve confrontarlo con gli altri, lo salvo direttamente
        if (strato == 0){
            somma_max = somma;
            indice = strato;
        }else if (somma > somma_max){
            somma_max = somma;
            indice = strato;
        }
    }
    return indice;
}
/* POST-F (a parole) = { somma tutti gli elementi di ogni strato. Guarda quindi quale somma e' maggiore e ritorna lo strato corrispondente.
            In caso di somme uguali, ritorna uno strato qualsiasi.}

 POST-F (in formule) = {Dati 5 strati, somma_n = e1 + e2 + ... + ez per Vn € [0,4] e per Vz € [0,t]
dove t= 5*10-elementi non definiti. Risultato = w, dove w e' l'indice della somma > somma_n (per Vn € [0,limite1-1])}
*/

main(){

}













