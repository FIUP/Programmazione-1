//Soluzione di S.Righetto
#include<iostream>
using namespace std;

int main()
{
	// delimitatore iniziale output del programma (stringa "start")
	// ATTENZIONE! Non cancellare l'istruzione sottostante
	cout << "start" << endl;

	// inserire qui il codice del programma
	int h;
	cin >> h; 
	if(h<3)
	    cout << "Altezza non valida" << endl;
	else {
	    int x=3, b=h-2, a=((2*h)+1);
	    //1 riga
	    for(int k=0; k<a ; k++)
	        cout << "x" ;
	    cout << endl;     
	    
	   //corpo centrale
	    for(int k=0; (k<(h-2)) ; k++){
	    	cout << 'x' ;
	        //stampa b
	        for(int k=b; k>0 ; k--)
	            cout<< "b";
	        //stampa x
	        for(int k=0; k<x ; k++)
	            cout <<  "x" ;
	        //stampa b
	        for(int k=b; k>0 ; k--)
	            cout<< "b";
			cout << 'x' << endl;   
	      	b--;
	        x+=2;
	    }
	    //ultima riga
	    for(int k=0; k<a ; k++)
	        cout << "x" ;
	    cout << endl;
	}
	// delimitatore finale output del programma (stringa "end")
	// ATTENZIONE! Non cancellare l'istruzione sottostante
	cout << "end" << endl;
}
