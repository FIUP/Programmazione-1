#include<iostream>

using namespace std;

// Prototipi delle funzioni da implementare
void leggiM(float *a, int &m, int &n);

void stampaM(float *a, int m, int n);

bool controllo_somma(int m1, int n1, int m2, int n2);
void somma(float *a, float *b, float *c, int m, int n);

bool controllo_prodotto(int m1, int n1, int m2, int n2);
void prodotto(float *a, float *b, float *c, int m, int n, int p);

void trasponi(float* a, float *b, int m, int n);

int main() {
    float a[100], b[100], c[100];   // array con i dati
    int ma, na, mb, nb, mc, nc;     // dimensioni delle tre matrici
    char operazione;                // operazione da eseguire
    
    leggiM(a, ma, na);
    cin >> operazione;
        
    cout << "start" << endl;
    
    

    cout << "end" << endl;
}
