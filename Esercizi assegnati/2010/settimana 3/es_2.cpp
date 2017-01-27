#include<iostream>
using namespace std;

/*
--- LEGENDA: V = per ogni, € = appartiene, § = esiste. ---
*/

/*
PRE-F = {A: puntatore ad un array a limite1 strati, limite2 righe per strato e limite3 elementi per riga, gia' caricato
                       con gli elementi su cui lavorare.
         limite1 = strati.
         limite2 = righe
         limite3 = elementi per riga
         n_ele: dettoci che e' > 0, numero degli elementi che sono definiti nella torta,
         0 < n_ele < limite1*limite2*limite3, limite1*limite2*limite3 = val massimo di elementi che puo' avere l'array dato.}
*/
int G(int* A, int limite1, int limite2, int limite3, int n_ele){
    // trovo il minore tra il max e n_ele dato e lo salvo nella stessa variabile n_ele
    if (limite1*limite2*limite3 < n_ele){
        n_ele = limite1*limite2*limite3;
    }

    int indice = 0, somma_max = 0; // inizializzo somma_max per sicurezza a 0, anche se non e' necessario.
    // R1 = {indice = r <=> somma_elem di r >= somma_elem di Vr€[0, riga-1],
    for(int riga = 0; riga < limite2; riga++){
        // R2 = somma relativa = e1 + e2 + ... + ez per Vz € [0, (strato-1)*limite3], se l'elemento "e" e' definito}
        int somma = 0;
        for(int strato = 0; strato < limite1; strato++){
            // R3 = {somma relativa = e1 + e2 + ... + ez per Vz € [0, elem-1], se l'elemento "e" e' definito}
            for (int elem = 0; elem < limite3; elem++){
                // se l'indice, che puo' assumere i valori da uno a limite1*limite2*limite3, e' minore di n_ele
                // vuol dire che tale elemento e' definito, altrimenti no.
                if ((strato*limite2*limite3+riga*limite3+elem) < n_ele){
                   somma += *(A+(strato*limite2*limite3+riga*limite3+elem));
                }
            }
        }
        cout << "\n\nSomma fetta " << riga << ": " << somma;
        // se lo strato e' il primo, non serve confrontarlo con gli altri, lo salvo direttamente,
        // altrimenti la somma data dev'essere > di quella salvata
        if (riga == 0 or somma > somma_max){
            somma_max = somma;
            indice = riga;
        }
    }
    return indice;
}
/* POST-F (a parole) = { somma tutti gli elementi di ogni fetta. Guarda quindi quale somma e' maggiore e ritorna la fetta corrispondente.
            In caso di somme uguali, ritorna una fetta qualsiasi.}

 POST-F (in formule) = {Dati limite2 fette, somma_n = e1 + e2 + ... + ez per Vn € [0,limite2-1] e per Vz € [0,top-F]
dove top-F = limite1*limite3-elementi non definiti. Risultato = w, dove w e' l'indice della somma > somma_n (per Vn € [0,limite2-1])}
*/

main(){

}













