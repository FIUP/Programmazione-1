#include<iostream>

using namespace std;

int main()
{
	// delimitatore iniziale output del programma (stringa "start")
	// ATTENZIONE! Non cancellare l'istruzione sottostante
	cout << "start" << endl;

	// inserire qui il codice del programma
    int n;
	cin>>n;

	if (n<3) {cout<<"Altezza non valida"<<endl;}
	else {
		int i=1;
		int nspazi=n-2;
		int nstelle=1;
		while (i<n){
			i++; // i=i+1;

			int j=0;
			while (j<nspazi){
				cout<<"b";
				j++;
			}

			int l=0;
			while (l<nstelle){
				cout<<"s";
				l++;
			}

			nspazi--;
			nstelle=nstelle+2;

			cout<<endl;
		}

		nspazi=n-2;
		int j=0;
		while (j<nspazi){
			cout<<"b";
			j++;
		}

		cout<<"s" << endl;
	}

	// delimitatore finale output del programma (stringa "end")
	// ATTENZIONE! Non cancellare l'istruzione sottostante
	cout << "end" << endl;
}
