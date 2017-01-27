#include<iostream>
using namespace std;

/*
	--- ES: 1, settimana 1, ---

	--- CONSEGNA: ---

	1) Si chiede di scrivere un programma che legga dall'input standard 3 valori interi e stabilisca quale di
	questi tre casi è vero:
	a) uno dei 3 valori letti è divisore esatto degli altri 2;
	b) (a) è falso e uno dei valori letti è divisore esatto di uno degli altri 2;
	c) (a) e (b) sono falsi.
	Per eseguire questo calcolo il programma può usare solo le operazioni di somma e differenza. Non può
	usare né la divisione, né il modulo.
	Il programma deve stampare sull’output standard una frase che spieghi quali dei 3 casi è vero e, nel caso
	(a) e (b), deve anche scrivere in input quale valore è il divisore e quale/i valore/i sono i multipli del primo.

	--- AGGIUNTA del professore: i 3 numeri sono >= 0.

*/

int main(){
	int x,y,z;
	int maggiore, medio, minore;
	cout << "Inserire tre interi: ";
	cin >> x >> y >> z;
	maggiore = x;
	if (x-y < 0){
	    maggiore = y;
	    y = x;
	    x = maggiore;
	}
    if (x-z < 0){
        maggiore = z;
        z = x;
    }
    medio = z;
    if (maggiore-z > maggiore-y){
        medio = y;
        y = z;
    }
    minore = y;
    cout << maggiore << " " << medio << " " << minore;

	if (!maggiore){
		cout << "A: i tre numeri inseriti sono tutti e tre zero." << endl;
	}else if (!medio){
		cout << "A: \n- Divisore: " << maggiore << " \n- Primo multiplo: 0 \n- Secondo multiplo: 0" << endl;
	}
	bool match1 = false; bool match2 = false;
	int q = maggiore;
    int cont = 0, b;
    while(cont < 3){
        if (!minore){
            cont = 2;
        }
        q = maggiore;
        b = minore;
        if (cont == 1){
            if (match2){
                match1 = true;
                match2 = false;
            }
            q = medio;
        }else if (cont == 2 && !match2){
            b = medio;
        }
        match2 = true;
        while (q && match2){
            if (q < b){
                match2 = false;
            }
            q = q - b;
        }
        cont++;
    }
    if (match1 && match2){
        // opzione A
        cout << "A: \n- Divisore: " << minore << " \n- Primo multiplo: " << medio << " \n- Secondo multiplo: " << maggiore << endl;
    }else{
        if (match1 || (!match1 && match2)){
            // opzione B
            cout << "B: \n- Divisore: " << b << " \n- Multiplo: " << maggiore<< endl;
        }else{
            // opzione C
            cout << "C: nessun numero e' un divisore esatto degli altri numeri" << endl;
        }
    }
}
