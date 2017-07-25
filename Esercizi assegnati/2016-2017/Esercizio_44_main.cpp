#include <iostream>

using namespace std;


// PRE = A è un array di int di lunghezza lung >= 1
void ordina(int *A, int lung);
// POST = A è ordinato in modo crescente

int main() 
{
    int lung;
    int A[100];
    cin >> lung;
    for(int i = 0; i < lung; i++) { 
        cin >> A[i];
    }
    cout << "start" << endl;

    cout << "end" << endl;
}