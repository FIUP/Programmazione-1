#include<iostream>
using namespace std;

/*
	--- ES: 1, settimana 1 ---

	--- CONSEGNA: ---

	1) Si chiede di scrivere un programma che legga dall’input standard 3 valori interi e stabilisca quale di
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

main (){
	int x,y,z,x_1,y_1;
	int maggiore, medio, minore;
	cout << "Inserire tre interi: ";
	cin >> x_1 >> y_1 >> z;
	
	// se nessuno dei tre numeri e' zero, posso procedere
	// intanto ordino i tre numeri dal maggiore al minore per facilitarmi le operazioni dopo
	// innanzi tutto faccio in modo che la variabile x contenga sempre il valore maggiore tra x_1 e y_1 dati in input
	if(x_1 >= y_1){
		x = x_1;
		y = y_1;
	}
	else{
		x = y_1;
		y = x_1;
	}
	// adesso che ho forzato le variabili in modo che x > y, guardo z dove si colloca, se prima, tra loro o dopo.
	if(z >= x){
		// z e' il numero maggiore e gli altri seguono
		maggiore=z;
		medio=x;
		minore=y;
	}
	else if(z >= y){
		// z e' in mezzo tra i due
		maggiore=x;
		medio=z;
		minore=y;
	}
	else{
		// z e' il numero minore
		maggiore=x;
		medio=y;
		minore=z;
	}
	
	// inizializzo una variabile temporanea che utilizzo poi nei calcoli nei cicli while
	int temp_result = 1;
	// inizializzo due variabili bool per capire se sono nel caso A (entrambe true) o nel caso B (solo first_match true)
	bool first_match = false;
	bool second_match = false;

	// inizializzo gli output a zero
	int divisore = 0;
	int multiplo1 = 0;
	int multiplo2 = 0;
	
	// gestisco lo zero (se solo un numero e' zero, lo gestisco dopo)
	if (maggiore == 0){
		cout << "A: i tre numeri inseriti sono tutti e tre zero." << endl;
	}else if (medio == 0){
		cout << "A: \n- Divisore: " << maggiore << " \n- Primo multiplo: 0 \n- Secondo multiplo: 0" << endl;
	}else if (minore == 0){
		minore = medio;
		medio = maggiore;
		maggiore = 0;
		divisore = minore;
		multiplo1 = 0;
		first_match = true;	
	
		// faccio assumere a temp_result il valore del numero maggiore, in modo che il ciclo while non vada ad
		// infinito (cosa che succederebbe se sotto mettessi maggiore invece che temp_result prima di "- minore"
		temp_result = maggiore;
		while(temp_result > 0){
			temp_result = temp_result - minore;
			if (temp_result == 0){
				// abbiamo un match, passo quindi la prima variabile bool a true e inserisco i dati trovati nelle variabili in output
				first_match = true; 
				divisore = minore;
				multiplo1 = maggiore;
			}
		}
		// uso lo stesso "trucco" di prima
		temp_result = medio;
		while(temp_result > 0){
			temp_result = temp_result - minore;
			if (temp_result == 0){
				// se il primo while non ha avuto successo
				// vuol dire che abbiamo solo un caso ok (cioe' questo)
				// quindi salviamo nel primo match (caso B), 
				// se invece anche il primo while ha successo
				// salviamo nel secondo match (caso A)
				if (first_match == true){
					second_match = true;
					multiplo2 = medio;
				}else{
					first_match = true;
					divisore = minore; 
					multiplo1 = medio;
				}
			}
		}
		// ultimo caso: se il minore non divide uno degli altri due o entrambi
		// allora proviamo a vedere se per caso il medio divide il maggiore
		if (!first_match){
			temp_result = maggiore;
			while(temp_result > 0){
				temp_result = temp_result - medio;
				if (temp_result == 0){
					// ok, i due numeri si possono dividere tra loro
					first_match = true; 
					divisore = medio;
					multiplo1 = maggiore;
				}
			}
		}
		
		// ora abbiamo i dati, passiamo a mandarli in output. Se entrambi i match sono veri
		// ci troviamo nel caso A, se solo il primo e' vero siamo nel caso B, senno' in C
		if (first_match and second_match){
			// opzione A
			cout << "A: \n- Divisore: " << divisore << " \n- Primo multiplo: " << multiplo1 << " \n- Secondo multiplo: " << multiplo2 << endl;
		}else if (first_match){
			// opzione B
			cout << "B: \n- Divisore: " << divisore << " \n- Multiplo: " << multiplo1 << endl;
		}else{
			// opzione C
			cout << "C: nessun numero è un divisore esatto degli altri numeri" << endl;
		}
	}
}



		
