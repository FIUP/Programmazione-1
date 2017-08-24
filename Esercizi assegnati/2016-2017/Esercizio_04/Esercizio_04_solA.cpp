// soluzione di B.Cosentino

//L'Ultimo Teorema di Fermat dice che non è possibile trovare tre numeri interi a,b e c tali che (a^n)+(b^n)=(c^n) se n>2

#include<iostream>
#include<math.h>
using namespace std;


int main()
{
// Inizializzazione variabili a,b,c basi delle potenze e n l'esponente
int a, b, c, n; 
cin >>a >>b >>c >>n;


//Inizio flusso
if (a<=0 or b<=0 or c<=0){ //Verifica delle condizioni iniziali
	
		cout << "Input sbagliato" <<endl;
	} else {
		//a,b,c>0
		if (pow(a,n)+pow(b,n)==pow(c,n)){ //Verifica dell'equazione
			
			cout << "Si" <<endl;
			if (n>2){ //Verifica potenza
			
				cout << "Fermat si sbagliava" <<endl;
			}
		} else {
			//(a^n)+(b^n)!=(c^n)
			cout << "No" <<endl;
			
		}
	}	

cout << "end" <<endl;
}
