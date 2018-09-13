#include<iostream>
using namespace std;

int main (){
    cout << "start" <<endl;
	int n, i=0; // i come contatore
	cin >> n;
	while (n>0) {
		char G1, G2;
		cin>> G1 >> G2;
		if ((G1 == 's' || 'c' || 'f') && (G2 == 's' || 'c' || 'f')){
			n--;
			if (G1==G2)
				cout << endl;
			else 
				if(G1=='f'){
					if(G2=='c')
						i++;
					else
						i--;
				}
				else 
					if(G1=='c'){
						if(G2=='s')
							i++;
						else
							i--;
					}
					else 
						if(G1=='s'){
							if(G2=='f')
								i++;
							else 
								i--;
						}
        }
	else 
		cout << "I valori non sono corretti" << endl;

	}
	if (i>0) 
		cout << "Vince il giocatore 1" << endl; 
	else 
		if (i<0) 
			cout << "Vince il giocatore 2" << endl;
		else 
			cout << "Pareggio" << endl;
    cout <<"end"; 
}




