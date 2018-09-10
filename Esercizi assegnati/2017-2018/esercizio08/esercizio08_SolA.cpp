//Soluzione di S.Righetto
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

	if (n<3) 
		cout<<"Altezza non valida"<<endl;
	else {
		int i=1;
		int nspazi=n-2;
		int nstelle=1;
		int j=0;
		while (j<nspazi){ //stampa del tronco
			cout<<"b";
			j++;
		}
		cout<<"s" <<endl;

		nspazi=0;
		nstelle=((n-1)*2)-1;
		while (i<n){ //stampa delle foglie
			i++; // i=i+1;
			int k=0; //ri inizializzo il contatore
			while (k<nspazi){
				cout<<"b";
				k++;
			}
			int l=0; //ri inizializzo il contatore
			while (l<nstelle){
				cout<<"s";
				l++;
			}
			nspazi++;
			nstelle=nstelle-2;
			cout<<endl;
		}
	}

	// delimitatore finale output del programma (stringa "end")
	// ATTENZIONE! Non cancellare l'istruzione sottostante
	cout << "end" << endl;
}
