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



    // POST = se M e' un quadrato negativo stampa il valore della costante negativa di M, altrimenti stampa "Non e' un quadrato negativo"
    cout << "end" << endl;
}
