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



    // POST = se M e' un quadrato magico stampa il valore della costante magica di M, altrimenti stampa "Non e' un quadrato magico"
    cout << "end" << endl;
}