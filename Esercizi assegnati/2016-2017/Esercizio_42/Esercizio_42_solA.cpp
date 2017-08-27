// soluzione di B.Cosentino
#include <iostream>

using namespace std;

// PRE = S e' una stringa di lunghezza n >= 0
bool palindroma(char *S, int n){
    
    if (n<=1)
        return true;
    
    // n>=2
    
    if (S[0]!=S[n-1])
        return false;
    
    // S[0]==S[n-1] 
    
    // PRE_ric = S[1...n-2] e' una stringa di lunghezza n-2>=0 
    return palindroma(S+1,n-2);
    // POST_ric = ritorna true se e solo se S[1...n-1] e' palindroma
}
// POST = ritorna true se e solo se S e' palindroma

/**********************************************
DIMOSTRAZIONE

Casi base:
    Sappiamo dalla PRE che n>=0.
    1) se la lunghezza n<=1, allora n==0  o n==1.
        
        se n==0 -> S e' una stringa vuota -> restituisco true -> POST valida
        
        se n==1 -> S e' una stringa di lunghezza 1. Quindi, se S[0]==S[1-1](=S[0]) allora la stringa e' palindroma e restituisco true -> POST valida
        
    2) se la lunghezza e' !(n<=1) allora n>=2 e confronto il primo elemento di S e l'ultimo.
        se S[0]!=S[n-1] allora la parola non e' palindroma-> restituisco false -> POST valida

Caso induttivo:
    So che S[0]==S[n-1] e che n>=2 -> n-2>=0 . Inoltre, S[1...n-2] e' una stringa di lunghezza n-2>=0 ->
    -> S[1...n-2] e' una stringa di lunghezza n-2>=0 -> PRE_ric
    Quindi, vale POST_ric. La stringa S[0...n-1] e' palindroma sse la stringa S[1...n-2] e' palindroma.
    Per cui, restituisco palindroma(S+1, n-2).

**********************************************/

int main() 
{
    int lung;
    char S[100];
    cin.getline(S, 100);        // legge una riga di caratteri da cin
    lung = cin.gcount() - 1;    // ritorna il numero di caratteri letti (compreso il terminatore '\0')
    
    cout << "start" << endl;
    
    if (palindroma(S,lung))
        cout << "la stringa e' palindroma" << endl;
    else
        cout << "la stringa non e' palindroma" << endl;

    cout << "end" << endl;
}
