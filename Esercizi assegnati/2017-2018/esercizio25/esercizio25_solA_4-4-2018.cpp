//Soluzione di S.Righetto

#include <iostream>

using namespace std;

// PRE = S e' una stringa di lunghezza n >= 1
bool palindroma(char *S, int n){
	if(n<2) return true;
	if(S[0] != *(S+(n-1))) return false;
	else palindroma(S+1, n-2);
}
// POST = ritorna true se e solo se S e' palindroma

int main() 
{
    int lung;
    char S[100];
    cin.getline(S, 100);        // legge una riga di caratteri da cin
    lung = cin.gcount() - 1;    // ritorna il numero di caratteri letti (compreso il terminatore '\0')
    cout << "start" << endl;

	if(palindroma(S,lung)) cout<< "e' palindroma";
	else cout << "non e' palindroma";
    cout<< endl << "end" << endl;
}
