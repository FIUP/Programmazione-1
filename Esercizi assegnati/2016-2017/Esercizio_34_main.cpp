#include<iostream>

using namespace std;

// PRE = (P e' un pattern che termina con '\0' && S e' una sequenza di char che termina con '\0')
bool match(char* P, char* S);
// POST = (la funzione ritorna true se e solo se P occorre in S a partire dalla posizione 0)

// PRE = (cin contiene un pattern P, seguito un intero n_righe, seguito da un testo T lungo n_righe righe)
int main() {
    char P[100], T[100][100];
    int n_righe = 0;
    
    cin.getline(P, 100);
    cin >> n_righe;
    cin.ignore();       // ignora il carattere "a capo" dopo la lettura del numero di righe 
    for(int i = 0; i < n_righe; i++) {
        cin.getline(T[i],100);
    }
    cout << "start" << endl;
    
    cout << "end" << endl;
}
// POST = (stampa "riga: i colonna: j" per ogni occorrenza i,j di P in T, 
//         oppure "Pattern non trovato" se P non occorre in T)
