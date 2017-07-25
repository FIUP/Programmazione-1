// soluzione di B.Cosentino
#include <iostream>

using namespace std;

// PRE = n >= 0
void stampa_verticale(int n){
    
    if (n<10) 
        cout << n << endl;
    else { // n >= 10
        
        // PRE_ric = n/10>=0
        stampa_verticale(n/10);
        // POST_ric = stampa il numero n/10 in verticale, con ogni cifra decimale in una riga diversa
        
        cout << n%10 << endl;
        
    }
    
    
}
// POST = stampa il numero n in verticale, con ogni cifra decimale in una riga diversa

/*********************************************************
DIMOSTRAZIONE

Caso base:
    se n<10, allora ha un'unica cifra. Stampandola, avro' stampato tutto il numero in verticale -> POST e' verificata

Caso induttivo: 
    sappiamo che se !(n<10) allora n>=10. Quindi, la PRE_ric e' verificata. -> POST_ric
    Quindi, dopo stampa verticale(n/10) avremo stampato tutte le cifre di n tranne l'ultima. 
    Essa e' n%10 e percio' la stampiamo andando poi a capo (cout << n%10 << endl;) ->
    -> POST valida
*********************************************************/


int main() 
{
    cout << "start" << endl;
    
    int N;
    cin >> N;
    
    stampa_verticale(N);

    cout << "end" << endl;
}
