//Soluzione di S.Righetto

#include <iostream>
using namespace std;

// PRE = n >= 0
void stampa(int n){
	if(n<10){
		cout << n << endl;
	} else{
		stampa(n/10);
		stampa(n%10);
	}
}
// POST = stampa il numero n in verticale, con ogni cifra decimale in una riga diversa

int main() 
{
    cout << "start" << endl;
    int n=0;
	cin >> n;
	stampa(n);
    cout << "end" << endl;
    
}
