//Solu<ione di S.Righetto
#include<iostream>
using namespace std;

int main()
{
	// delimitatore iniziale output del programma (stringa "start")
	// ATTENZIONE! Non cancellare l'istruzione sottostante
	cout << "start" << endl;

	// inserire qui il codice del programma
    
    int a, somma=0, k=0; //a è il carattere da verificare, k è il contatore
	do{
	    cin >> a;
    	if(a!=-1) 
    	    somma= somma +a;
	    k++;
	}while(k<10 && a!=-1);
	cout<< "Il valore della somma e': " << somma <<endl;

    
	// delimitatore finale output del programma (stringa "end")
	// ATTENZIONE! Non cancellare l'istruzione sottostante
	cout << "end" << endl;
}
