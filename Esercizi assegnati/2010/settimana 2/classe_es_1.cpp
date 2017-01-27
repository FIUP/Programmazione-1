#include<iostream>
#include<fstream>
using namespace std;

// Es 1, realizzato in classe.

// Leggenda:
// (V = per ogni, € = appartiene, § = esiste)

// Nota: se uso invarianti semplici, dimostro una post condizione semplice,
// se uso invarianti piu' precisi, post condizione piu' precisa e viceversa.
// l'invariante e' la post condizione parametrizzata

// Nota2: spesso si puo' cercare di fare prima la POST per poi ricavarsi gli
// invarianti.

main(){
    // PRE = { input ha inizialmente almeno n1.. n30 valori int }
    ifstream IN("input.txt");
    ofstream OUT("output.txt");
    int C[6][5];
    bool B[6][5];
    // Versione semplice: {0 <= i <= 6, C[0..i-1] sono riempite}
    // R1 = {Vk€[0,i-1], Vj€[0,4], C[k][j] e' definito} {0 <= i <= 6}
    // devo aggiungere = 6, per fare la prova di uscita.
    // Prova di uscita: R1 and !i<6
    // --> R1 and i >= 6
    // quindi, dato che R1 e' 0 <= i <=6, allora per uscire i deve
    // diventare 6 (i <= 6 e i >= 6 --> i == 6)
    for (int i = 0; i < 6; i++){
        // {0 <= j <= 5, abbiamo riempito C[i][0..j-1]}
        // |||| se usiamo la versione precisa, l'invariante qui e': C[i][z] = n[(5*i+j)+1 Vz € [0,j-1]}
        // in questo ciclo dobbiamo riempire la riga i-esima
        for (int j = 0; j < 5; j++){ // {0 <= i < 6 && 0<= j <5}
        // Versione semplice: {C e' stato riempito di valori int}
        // Versione precisa:
        // {Vk€[0,5] e Vz€[0,4], C[k][z] = n[(5*i+j)+1}
        // note: k e z sono variabili matematiche.
        // cambio l'invariante in modo che si riferisca all'invariante dei cicli sopra:
        // {Vk€[0,i-1] e Vz€[0,j-1], C[k][z] = n[(5*i+j)+1}
            IN >> C[i][j];
            // C[i][0...4] e' riempita
        }
        // POST ciclo interno = Vz€[0,j-1], C[i][z] e' definita
    }
    // POST 0 = {Vi€[0,5] e Vj€[0,4], C[i][j] e' definito}

    // seconda matrice:
    bool   miss = false, hit = false;
    // mi serve:    1:  for "r" per le righe
    //              2:      for "c" per le colonne
    //              3:          for "i" che scorre la riga
    //              4:              for "j" che scorre la colonna

    for (int r = 0; r < 6; r++){
        // R1 = {Va€[0,r-1] e Vb€[0,4], B[a][b] <=> C[a] e' contenuta in C[..][b]}, {0 <= r <= 6}
        for (int c = 0; c < 5; c++){
            // R2 = {Vb€[0,c-1], B[r][b] <=> C[r] e' contenuto in C[..][b]}, {0 <= c <= 5}
            for (int i = 0; i < 5 and not miss; i++){
                // R3 = {0 <= i <= 5, not miss <=> Vz€[r][z] e' nella colonna c di C}
                // o anche: R3 = {not miss <=> Va€[0,i-1], §b[0,5] t.c. C[r][z] == C[b][c], {0 <= i <= 5}
                hit = false;
                // con o senza l'hit e' uguale, senza si itera tutta la colonna,
                // con hit si esce prima appena si trova hit.
                for (int j = 0; j < 6 and not hit; j++){
                    // R4 = {0 <= j <= 6, hit <=> §k€[0,j-1], C[r][i] == C[k][c]}
                    if (C[r][i] == C[j][c]){
                        hit = true;
                    }
                }
                if (not hit){
                    miss = true;
                }
                // POST 4 = {hit <=> §a€[0,5] t. c. C[r][i] == C[a][c]}
            }
            // Arrivati qui, dobbiamo sapere che valore mettere in B[c][i]. Questo lo capisco definendo
            // miss come true o false a seconda della necessita'
            // POST 3 = {not miss <=> Vz € [0,4], C[r][z] e' nella colonna c dell'array C}
            //   che si puo' anche scrivere come: §b[0,5] t.c. C[r][z] == C[b][c]}
            B[r][c] = not miss;
            hit = false; miss = false;
        }// POST 2 = Vb€[0,4], B[i][b] <=> C[i] e' contenuto in C[..][b] || leggasi: ho riempito una riga
    }// POST 1 = {Va€[0,5] e Vb€[0,4], B[a][b] <=> C[a] e' contenuta in C[..][b]
     //                                 se C[a] e' contenuta, B[a][b] si riempie, altrimenti no (tradotto in: <=>).
     //                                 cioe', ho riempito B.

    // causa d'uscita:
    // R3 && !(i<5 and !miss) => POST
    // che e' uguale a : R3 && (i == 5 || miss) => POST

    // casi possibili:
    // 1) miss = true || c'e' un elemento della riga non nella colonna
                    // perche' se miss e' false, R3 e' false, cioe'
                    // "Vz€[r][z] e' nella colonna c di C" e' false!
    // 2) !miss and i == 5 || hit e' true, la riga e' contenuta nella colonna e finisco l'iterazione
    system("pause");

} // POST = { Vi€[0,5] e Vj€[0,4] B <=> C[i] e' contenuta nella colonna j di C}

