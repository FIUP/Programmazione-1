#include <iostream>

using namespace std;

// PRE = S e' una stringa di lunghezza n >= 1
bool palindroma(char *S, int n);
// POST = ritorna true se e solo se S e' palindroma

int main() 
{
    int lung;
    char S[100];
    cin.getline(S, 100);        // legge una riga di caratteri da cin
    lung = cin.gcount() - 1;    // ritorna il numero di caratteri letti (compreso il terminatore '\0')
    cout << "start" << endl;


    cout << "end" << endl;
}