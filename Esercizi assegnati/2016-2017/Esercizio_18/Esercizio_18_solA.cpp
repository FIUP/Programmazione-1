// soluzione di B.Cosentino
#include <iostream>

using namespace std;

int main() {
    int M[6][6];
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            cin >> M[i][j];
        }
    }
    
    cout << "start" << endl;
    // PRE = M e' una matrice quadrata di interi positivi di dimensione 6 x 6    
    
    int cos_mag=0; //Costante magica
    bool ver=true;
    
    //Ciclo costante
    for (int j=0; j<6; j=j+1){ //R=(0<=j<=6)&&(ho sommato gli interi in [0..i-1])
        cos_mag=cos_mag+M[0][j];
    }
    
    //Ciclo righe e colonne
    for (int i=0; i<6; i=i+1){ //R=(0<=i<=6)&&(ho controllato le righe[0...i-1])&&(ho controllato le colonne[0..i-1])&&(ver=true <=> le righe[0...i-1] e le colonne[0...i-1] hanno somma interna pari a cos_mag)
        int s_riga=0;
        int s_colonna=0;
        for (int j=0; j<6; j=j+1) { //R=(0<=j<=6)&&(in riga i ho sommato gli interi in [0...j-1])&&(in colonna i ho sommato gli interi in [0..j-1])
            s_riga=s_riga+M[i][j];
            s_colonna=s_colonna+M[j][i];
        }
        if (s_riga!=cos_mag || s_colonna!=cos_mag) {
            ver=false;
        }
    }
    
    //Alternativamente si poteva descrivere un ciclo apposito per le colonne ed evitare di controllare la prima riga nel ciclo precedente,
    // elimininando chiaramente la parte che controlla le colonne.
 
    //Ciclo colonne
    /*
    for (int j=0; j<6; j=j+1) { //R=(0<=j<=6)&&(ho controllato le colonne[0...j-1])&&(ver=true <=> tutte le righe e le colonne[0...j-1] hanno somma interna pari a cos_mag)
        int s_colonna=0;
        for (int i=0; i<6; i=i+1) {  //R=(0<=j<=6)&&(in colonna j ho sommato gli interi in [0...i-1])
            s_colonna=s_colonna+M[i][j];
        }
        if (s_colonna!=cos_mag) {
            ver=false;
        }
    }
    */
    int s_diag1=0;
    int s_diag2=0;
    
    //Ciclo diagonali
    for (int i=0; i<6 && ver; i=i+1) { //R=(0<=i<=6)&&(ho sommato gli interi nei posti [0...i-1][0...i-1] e [0..i-1][0...5-(i-1)])&&(ver=true <=>tutte le righe e le colonne hanno somma interna pari a cos_mag)
        s_diag1=s_diag1+M[i][i];
        s_diag2=s_diag2+M[i][5-i];
    }
    
    if (s_diag1!=cos_mag || s_diag2!=cos_mag) {
        ver=false;
    }
    
    //Stampa
    if (ver) {
        cout << cos_mag << endl;
    } else {
        cout << "Non e' un quadrato magico" << endl;
    }

    // POST = se M e' un quadrato magico stampa il valore della costante magica di M, altrimenti stampa "Non e' un quadrato magico"
    cout << "end" << endl;
}
