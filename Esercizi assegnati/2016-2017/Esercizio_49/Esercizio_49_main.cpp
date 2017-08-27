#include <iostream>

using namespace std;

struct nodo {
    int chiave;
    nodo *next;
};

// PRE = (L è una lista ordinata in modo crescente)
nodo* inserisci_in_ordine(int k, nodo *L);
// POST = (inserisce k in L mantenendo l'ordine e ritorna la lista aggiornata)

int main() 
{
    cout << "start" << endl;
    
    

    cout << "end" << endl;
}