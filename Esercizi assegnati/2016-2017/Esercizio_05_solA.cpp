// soluzione di B.Cosentino

//Verifica la disuguaglianza triangolare stretta, ovvero siano a,b,c lati di un triangolo ogni lato è minore della somma deglia altri due

#include<iostream>
using namespace std;

int main()
{
//Inizializzazione variabili. a,b,c sono le lunghezze dei lati del triangolo
int a,b,c;
cin >>a >>b >>c;

//Inizio flusso
if (a<=0 or b<=0 or c<=0){ //a,b,c devono essere lunghezze POSITIVE
		
		cout << "Input sbagliato" <<endl;
	} else {
		//a,b,c>0
		if ((a<b+c) && (b<a+c) && (c<a+b)){ //Verifica della disuguaglianza nei vari casi
		
			cout << "Si" <<endl;
		} else {
			//a>b+c or b>a+c or c>b+c
			cout << "No" <<endl;
			
		}
	}
cout << "end" <<endl;
}
