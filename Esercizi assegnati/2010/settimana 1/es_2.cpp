#include<iostream>
using namespace std;

/*

--- ES: 2, settimana 1 ---

--- CONSEGNA ---

2) Scrivere un programma che legga dall’input standard dei caratteri e man mano che li legge li scrive sull’output standard. Il programma deve continuare a leggere e stampare caratteri per tutto il tempo in cui nessuna delle seguenti 3 condizioni è vera (cioè la lettura termina quando una delle 3 condizioni diventa vera):
a) ha letto 2 caratteri ‘a’ (anche non di seguito);
b) ha letto 2 caratteri ‘b’ (anche non di seguito);
c) ha letto un carattere ‘a’, un ‘b’ ed un ‘c’ (anche non di seguito e non necessariamente nell’ordine specificato, quindi il caso si applica anche se è stato letto prima ‘c’, poi ‘a’ e poi ‘b’).
Non appena una di queste condizioni è vera, il programma deve terminare stampando la corrispondente frase “caso a”, “caso b” o “caso c” a seconda del caso che è diventato vero. Il programma deve sempre stampare tutti i caratteri che legge dall’input standard.

*/

main(){
    // inizializzo la variabile di input con un carattere spazio
    char input = ' ';
    
    // inizializzo le variabili che usero' per capire quando uscire dal while
    int a_input = 0;
    int b_input = 0;
    int c_input = 0;

    // condizione per cui il while rimane attivo
    bool ciclo_attivo = true;
    
    while (ciclo_attivo){
        cout << "Inserisci un carattere: ";
        cin >> input;
        cout << "Carattere letto: " << input << endl;
        // se leggo una a, b o c, incremento la variabile corrispondente
        if (input == 'a'){
            a_input = a_input + 1;
        }else if (input == 'b'){
            b_input = b_input + 1;
        }else if (input == 'c'){
            c_input = c_input + 1;
        }
        // caso A: 2 a, quindi esci
        if (a_input == 2){
            cout << "caso A: 2 caratteri 'a'" << endl;
            ciclo_attivo = false;
        // caso B: 2 b, quindi esci
        }else if (b_input == 2){
            cout << "caso B: 2 caratteri 'b'" << endl;
            ciclo_attivo = false;
        // caso C: a, b, c (anche non in ordine), esci.
        }else if (a_input == 1 and b_input == 1 and c_input >= 1){
            cout << "caso C: 1 car 'a', 1 car 'b', 1 car 'c'" << endl;
            ciclo_attivo = false;
        }
    }
}








