#include <iostream>

using namespace std;

struct nodo {
    int chiave;
    nodo *next;
};

// PRE = (L = L_0, L_1, ... è una lista di interi)
int cerca(int k, nodo *L);
// POST = (ritorna il più piccolo indice i tale che L_i.chiave == k, oppure -1 se non esiste)

int main() 
{
    cout << "start" << endl;
    
    

    cout << "end" << endl;
}