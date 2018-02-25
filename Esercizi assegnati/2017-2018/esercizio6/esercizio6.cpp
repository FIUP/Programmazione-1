#include<iostream>

using namespace std;

int main()
{
	// delimitatore iniziale output del programma (stringa "start")
	// ATTENZIONE! Non cancellare l'istruzione sottostante
	cout << "start" << endl;

	// inserire qui il codice del programma

    char c;
	int count=0;
	bool ok = true;
	int end = 0;
	do {
		cin >> c;
		
		if(c != 'e' && c != 'n' && c != 'd') {
    		if (end != 0)
    		    end = 0;
    		    
    		if (c=='(')
    			count ++;
    			
    		else if (c==')') {
    		    count --;
    		}
    		if (count < 0)
    		    ok = false;
		}
		else {
		    //incrementa end nel modo corretto
		    if (c == 'e' && end == 0)
		        end++;
		    else if (c == 'n' && end == 1)
	            end++;
            else if (c == 'd' && end == 2)
                end++;
		}
	} while(c!='0' && ok && end != 3);
	
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
