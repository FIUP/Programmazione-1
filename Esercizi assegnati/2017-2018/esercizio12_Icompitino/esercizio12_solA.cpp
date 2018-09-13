//Soluzione di S.Righetto
#include<iostream>
using namespace std;

	// delimitatore iniziale output del programma (stringa "start")
	// ATTENZIONE! Non cancellare l'istruzione sottostante
	

	// inserire qui il codice del programma

int main(){
    
	cout << "start" << endl;
	int n,i=1;
	cin >> n;
	if(n<3)
		cout << "Altezza non valida"<<endl;
	else {
		int c=0;	
		while(c<(n-2)){ //stampa della prima riga
			cout<<'.';
			c++;
		}
		cout << 'x';
		c=0;
		while(c<(n-2)){
			cout<<'.';
			c++;
		}
		cout<<endl;
		
		while(i<=(n-2)){ //stampa del corpo centrale
			c=1;
			while(c<((n-i)-1)){
				cout << '.';
				c++;
			}
			cout << 'x';
			c=0;
			while(c<((2*i)-1)){
				cout << '.';
				c++;
			}
			cout << 'x';
			c=1;
			while(c<((n-i)-1)){
				cout << '.';
				c++;
			}
			cout<<endl;
			i++;
		}
		
		c=0;	
		while(c<(n-2)){ //stampa dell'ultima riga
			cout<<'.';
			c++;
		}
		cout << 'x';
		c=0;
		while(c<(n-2)){
			cout<<'.';
			c++;
		}
		cout<<endl;
	}

	// delimitatore finale output del programma (stringa "end")
	// ATTENZIONE! Non cancellare l'istruzione sottostante
	cout << "end" << endl;
}

