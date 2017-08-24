// soluzione di B.Cosentino
#include<iostream>
using namespace std;

int teo;
int pra;

int main()
{
	cin >> teo;
	cin >> pra;
	
	if (teo + pra >= 18 && teo < 1) { 
		// fin >= 18 e teo < 1
		cout << "smanettone: bocciato, devi studiare di piu' la teoria"	<< endl;
	} else {
		// fin < 18 O teo >= 1	
		if (teo<=0 && teo+pra<18) {
			 //(TEO <= 0 && TEO + PRA < 18) && !(FIN > 18 && TEO < 1)
			 cout << "bocciato: devi studiare ed esercitarti di piu'" <<endl;
		}
		
		if (teo>0 && pra<18) {
			//(TEO > 0 && PRA < 18) && !(FIN > 18 && TEO < 1)
			cout << "bocciato: devi esercitarti di piu'" <<endl;
		}
		if (teo+pra>30) {
			// (FIN > 31) && !(FIN > 18 && TEO < 1)
			cout << "congratulazioni: 30 e lode" <<endl;
		} else {
		    // teo + pra <= 30
		    if (teo>=1 && pra>=18) {
    		    //(TEO > 1 && PRA>=18 && FIN <= 30) && !(FIN > 18 && TEO < 1)
	    	    cout<<"il tuo voto e'" << teo+pra << endl;
		    }
		}
	}
       
	cout << "end" << endl;  
	
}
