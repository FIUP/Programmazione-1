#include<iostream>
#include<fstream>
using namespace std;

/*
--- CONSEGNA: ---

1) Scrivere un programma che apra un file 'input' e legga 30 interi da questo file in un
array int C[6][5]. Si deve fare l'ipotesi che i 30 interi siano presenti su 'input'.
Il programma deve dichiarare un array bool B[6][5] e lo deve riempire con valori
true/false che soddisfino la seguente condizione: B[i][j] è true se la riga i-esima di
C è contenuta nella colonna j-esima di C e altrimenti è false (quindi qui, riga e colonna
sono visti come insiemi).
*/


// PRE: input contiene 30 interi, k1, k2, ... k30
int main()
{
	// apro il file di input
    ifstream input("input.txt");

	// definisco le variabili che usero' nel ciclo seguente
    int C[6][5],rig_sel = 0, col_sel = 0, x;
    // stampo la matrice mentre la carico
    cout << "Matrice C:" << endl;
    // R1 = {Vk€[0,i-1], C[k/5][j%5] e' definito} {0 <= i <= 30}
    for(int i = 0;i<30;i++){
		input >> x;
		cout << x << " ";

        C[rig_sel][col_sel] = x;
        col_sel++;
        // se la colonna assume il valore 5, aumento di uno la riga
        // e azzero la colonna
        if (col_sel == 5){
			cout << endl;
            col_sel = 0;
            rig_sel++;
        }
    }
    // POST 0 = {Vi€[0,29] C[i/5][i%5] e' definito}
    input.close();

    bool B[6][5], var, var2;

	// R1 = {Vr€[0,a-1] e Vb€[0,4], B[r][b] <=> C[r] e' contenuta in C[..][b]}, {0 <= a <= 6}
	for(int a=0;a<6;a++)
	{
		// R2 = {Vc€[0,b-1], B[r][c] <=> C[r] e' contenuto in C[..][c]}, {0 <= b <= 5}
		for(int b=0;b<5;b++)
		{
			// ciclo in modo tale che ogni variabile
			// trovi almeno un valore corrispondente nell'altro
			// array, succede quindi che var rimane a true
			// finche' ogni variabile viene
			// collegata ad un altra variabile della colonna,
			// appena cio' non succede, passa a false e rimane cosi'
			var=true;
			// R3 = {0 <= d <= 5, var <=> Vz€[r][z] e' nella colonna b di C, Vr€[0,r-1}
			for(int d=0;d<5;d++)
			{
				var2=false;
				// R4 = {0 <= e <= 6, var2 <=> §k€[0,e-1], C[a][d] == C[k][b]}
				for(int e=0;e<6;e++)
				{
					if(C[a][d]==C[e][b]){
						var2=true;
					}
				}
				// POST 4 = {var2 <=> §k€[0,5] t. c. C[a][d] == C[k][b}
				if(var2==false){
					var=false;
				}
			}
			// POST 3 = {var <=> Vz € [0,4], C[r][z] e' nella colonna b dell'array C}
			B[a][b]=var;
		}// POST 2 = Vw€[0,4], B[i][w] <=> C[i] e' contenuto in C[..][w] || leggasi: ho riempito una riga
	}// POST 1 = {Vl€[0,5] e Vn€[0,4], B[l][n] <=> C[l] e' contenuta in C[..][n]
     //                                 se C[l] e' contenuta, B[l][n] si riempie, altrimenti no (tradotto in: <=>).
     //                                 cioe', ho riempito B.

    // causa d'uscita:
    // R3 && !(d<5 and var) => POST
    // che e' uguale a : R3 && (d == 5 || !var) => POST

    // casi possibili:
    // 1) var = false || c'e' un elemento della riga non nella colonna
                    // perche' se var e' true, R3 e' false, cioe'
                    // "Vz€[r][z] e' nella colonna c di C" e' false!
    // 2) var and d == 5 || var2 e' true, la riga e' contenuta nella colonna e finisco l'iterazione


	// stampo la matrice B
	col_sel = 0;
	rig_sel = 0;
    cout << endl << "Matrice B:" << endl;
    // 0 <= i < 30
	for(int i = 0;i<30;i++){

        cout << B[rig_sel][col_sel] << " ";
        col_sel++;
        if (col_sel == 5){
			cout << endl;
            col_sel = 0;
            rig_sel++;
        }
    }
    return 0;
}
// POST: per ogni i in [0,5] e j in [0,4], B[i][j] <=> C[i] è contenuta in C[..][j]
