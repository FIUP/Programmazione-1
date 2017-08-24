#include <iostream>

using namespace std;

// PRE = i <= j
void inverti(int *A, int i, int j);
// POST = A viene modificato invertendo l’ordine degli elementi nel sottoarray A[i,...,j]

int main() 
{
    int lung, primo, ultimo;
    int A[100];
    cin >> lung >> primo >> ultimo;
    for(int i = 0; i < lung; i++) { 
        cin >> A[i];
    }
    cout << "start" << endl;


    cout << "end" << endl;
}