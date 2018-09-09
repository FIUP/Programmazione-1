#include<iostream>

using namespace std;

int main() {
	// delimitatore iniziale output del programma (stringa "start")
	// ATTENZIONE! Non cancellare l'istruzione sottostante
	cout << "start" << endl;

	// inserire qui il codice del programma
	int h;
	
	cin >> h; 
	
	if (h < 3)
	    cout << "Altezza non valida" << endl;
	else {
	    int x = 3;
		int b = h-2;
		int a = ((2*h) + 1);
	    
	    //1^ riga
	    for (int i = 0; i < a; i++)
	        cout << "x" ;
	    cout << endl;     
	        
	   //corpo centrale
	    for (int i = 0; i < h-2; i++) {
	    	cout << 'x';
	    	
	        //stampa b
	        for (int i = b; i > 0; i--)
	            cout << "b";
	        
	        
	        //stampa x
	        for (int i = 0; i < x; i++)
	            cout <<  "x";
	       
	        
	        //stampa b
	        for (int i = b; i > 0; i--)
	            cout << "b";
	        
			cout << 'x' ;    
	            
	        cout << endl;
	       
	      	b--;
	        x += 2;
	    }
	    
	    
	    //ultima riga
	    for(int i = 0; i < a; i++)
	        cout << "x";
	    cout << endl;
	}
	

	// delimitatore finale output del programma (stringa "end")
	// ATTENZIONE! Non cancellare l'istruzione sottostante
	cout << "end" << endl;

	return 0;
}
