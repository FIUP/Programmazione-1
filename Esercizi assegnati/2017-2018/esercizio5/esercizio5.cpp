#include<iostream>

using namespace std;

int main()
{
	// delimitatore iniziale output del programma (stringa "start")
	// ATTENZIONE! Non cancellare l'istruzione sottostante
	cout << "start" << endl;

	// inserire qui il codice del programma

    char c;		
	int count=0;	//contatore
	bool ok = true;	//controllo booleano 
	do {
		cin >> c;
		
		if (c=='(')
			count ++;
			
		else if (c==')') {
		    count --;
		}
		if (count < 0)
		    ok = false;
		
	} while(c!='0' && ok);
	
	if(count ==0)
		cout << "la sequenza e' bilanciata";
		else{
			cout << "la sequenza non e' bilanciata";
			if (count<0) 
		    	{cout << ": ci sono parentesi chiuse senza match";}
		    	else {cout<< ": ci sono parentesi aperte senza match";}
		}
	
	
 cout <<endl;
	// delimitatore finale output del programma (stringa "end")
	// ATTENZIONE! Non cancellare l'istruzione sottostante
	cout << "end" << endl;
}
