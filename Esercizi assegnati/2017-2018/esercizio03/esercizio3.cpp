#include<iostream>

using namespace std;

int main() {
    // delimitatore iniziale output del programma (stringa "start")\
	// ATTENZIONE! Non cancellare l'istruzione sottostante
	cout << "start" << endl;

	// inserire qui il codice del programma

    int a, b, c;
	cin >> a >> b >> c;

	if (a > 0 && b > 0 && c > 0) {
		if (a < c && b < c) {
			if (a+b > c)
				cout << "Si" << endl;
			else
				cout << "No" << endl;
		}
		if (a < b && c < b) {
			if(a+c > b)
				cout << "Si" << endl;
			else
				cout << "No" << endl;
		}
		if (c < a && b < a) {
			if (c+b > a)
				cout << "Si" << endl;
			else
				cout << "No" << endl;
		}
	}
	else
		cout << "Input sbagliato" << endl;

	// delimitatore finale output del programma (stringa "end")
	// ATTENZIONE! Non cancellare l'istruzione sottostante
	cout << "end" << endl;

	return 0;
}
