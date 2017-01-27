#include<iostream>
using namespace std;

/*
	--- ES: 1, settimana 1 ---
	
	--- Variante: questa versione del programma funziona con qualsiasi numeri, negativo, 0 e positivo.

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

*/

main (){
	int x,y,z,x_1,y_1;
	int maggiore, medio, minore;
	cout << "Inserire tre interi: ";
	cin >> x_1 >> y_1 >> z;

	// se nessuno dei tre numeri e' zero, posso procedere
	// intanto ordino i tre numeri dal maggiore al minore per facilitarmi le operazioni dopo	
	// controllo se uno o piu' numeri dati sono negativi (che siano = a 0 l'ho gia' controllato).

	// tre sono i numeri che possono essere 0, quanti sono? inizializzo le variabili a 0
	int primo_num_neg = 0;
	int secondo_num_neg = 0;
	int terzo_num_neg = 0;
	
	if (x_1 < 0){
		primo_num_neg = x_1;
		x_1 = 0 - x_1; // rendo x_1 positivo per i controlli successivi (che lo presuppongono tale)
	}
	if (y_1 < 0){
		// guardo se la variabile primo_num_neg e' gia' occupata o meno
		if (primo_num_neg < 0){
			secondo_num_neg = y_1;
		}else{
			primo_num_neg = y_1;
		}
		y_1 = 0 - y_1; // rendo y_1 positivo
	}
	if (z < 0){
		if (primo_num_neg < 0 and secondo_num_neg < 0){
			terzo_num_neg = z;
		}else if (primo_num_neg < 0){
			secondo_num_neg = z;
		}else{
			primo_num_neg = z;
		}
		z = 0 - z; // rendo z positivo
	}
	
	// faccio ora in modo che la variabile x contenga sempre il valore maggiore tra x_1 e y_1 dati in input
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
		
		// inizializzo tre variabili temporanee, dato che il controllo e' quando
		// sono uguali a 0, le inizializzo per sicurezza a -1 (tanto e' indifferente)
		int tmp_1=-1;
		int tmp_2=-1;
		int tmp_3=-1;
		// ok, ora se c'e' qualche numero negativo e' tempo di convertirlo,
		// cosa che non ha senso fare se first_match non è True
		if (primo_num_neg < 0 and first_match){
			tmp_1 = divisore + primo_num_neg;
			tmp_2 = divisore + secondo_num_neg;
			tmp_3 = divisore + terzo_num_neg;
			// se una di queste variabili temporanee e' zero, 
			// vuol dire che il divisore e' negativo dato che a + (-a) = 0
			if (tmp_1 == 0 or tmp_2 == 0 or tmp_3 == 0){
				divisore = 0 - divisore; // rendo il divisore negativo
			}
			tmp_1 = multiplo1 + primo_num_neg;
			tmp_2 = multiplo1 + secondo_num_neg;
			tmp_3 = multiplo1 + terzo_num_neg;			
			if (tmp_1 == 0 or tmp_2 == 0 or tmp_3 == 0){
				multiplo1 = 0 - multiplo1; // rendo il multiplo1 negativo
			}
			tmp_1 = multiplo2 + primo_num_neg;
			tmp_2 = multiplo2 + secondo_num_neg;
			tmp_3 = multiplo2 + terzo_num_neg;			
			if (tmp_1 == 0 or tmp_2 == 0 or tmp_3 == 0){
				multiplo2 = 0 - multiplo2; // rendo il multiplo2 negativo
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



		
