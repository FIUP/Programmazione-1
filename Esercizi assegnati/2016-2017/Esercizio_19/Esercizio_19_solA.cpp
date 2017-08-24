// soluzione di B.Cosentino
#include <iostream>

using namespace std;

int main() {
    int M[5][5];
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> M[i][j];
        }
    }
    
    cout << "start" << endl;
    // PRE = M e' una matrice quadrata di interi di dimensione 5 x 5    

    int numneg=0;   //Costante negativa
    bool ver=true;
    //Ciclo costante negativa
    for (int j=0; j<5; j=j+1) { //R=(0<=j<=5)&&(numneg<=i)&&(ho contato gli interi negativi in [0...j-1])
        if (M[0][j]<0) {
            numneg=numneg+1;
        }
    }
    
    //Ciclo righe e colonne
    for (int i=0; i<5 && ver; i=i+1) { //R=(0<=i<=5)&&(ho controllato le righe [0...i-1])&&(ho controllato le colonne [0..i-1])&&(ver=true <=> le righe[0...i-1] e le colonne[0...i-1] hanno un numero di interi negativi pari a numneg)
        int neg_riga=0;
        int neg_col=0;
        for (int j=0; j<5; j=j+1) {   //R=(0<=j<=5)&&(neg_riga<=i)&&(neg_col<=i)&&(in riga i ho contato gli interi negativi in [0...j-1])&&(in colonna i ho contato gli interi negativi in [0..j-1])
            if (M[i][j]<0){
                neg_riga=neg_riga+1;
            }
            if (M[j][i]<0){
                neg_col=neg_col+1;
            }
        }
        if (neg_riga!=numneg || neg_col!=numneg){
            ver=false;    
        }
        
    }
    
    //Alternativamente si poteva descrivere un ciclo apposito per le colonne ed evitare di controllare la prima riga nel ciclo precedente,
    // elimininando chiaramente la parte che controlla le colonne.
    
    //Ciclo colonne
    /*for (int j=0; j<5 && ver; j=j+1) {        //R=(0<=j<=5)&&(ho controllato le colonne[0...j-1])&&(ver=true <=> tutte le righe e le colonne[0...j-1] hanno un numero di interi negativi pari a numneg)
        int neg_col=0;
        for (int i=0; i<5; i=i+1){              //R=(0<=j<=5)&&(neg_col<=i)&&(in colonna j ho contato gli interi negativi in [0...i-1])
            if (M[i][j]<0){
                neg_col=neg_col+1;
            }
        }
        if (neg_col!=numneg){
            ver=false;
        }
    }*/

    //Ciclo diagonali
    int neg_diag1=0;
    int neg_diag2=0;
    
    for (int i=0; i<5 && ver; i=i+1){ //R=(0<=i<=5)&&(neg_diag1<=i)&&(neg_diag2<=i)&&(ho contato gli interi negativi nei posti [0...i-1][0...i-1] e [0..i-1][0...4-(i-1)])&&(ver=true <=>tutte le righe e le colonne hanno un numero di interi negativi pari a numneg)
        if (M[i][i]<0){
            neg_diag1=neg_diag1+1;
        }
        if (M[i][4-i]<0){
            neg_diag2=neg_diag2+1;
        }
    }
    
    if (neg_diag1!=numneg || neg_diag2!=numneg){
        ver=false;
    }
    
    //Stampa
    if (ver){
        cout << numneg << endl;
    } else {
        cout << "Non e' un quadrato negativo" <<endl;
    }

    // POST = se M e' un quadrato negativo stampa il valore della costante negativa di M, altrimenti stampa "Non e' un quadrato negativo"
    cout << "end" << endl;
}
