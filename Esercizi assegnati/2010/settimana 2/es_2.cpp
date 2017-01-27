#include<iostream>
#include<fstream>
using namespace std;

/*

--- CONSEGNA: ---

2) Scrivere un programma che risolva un esercizio simile all'(1), ma in cui la condizione e': B[i][j] e' true se la
riga i-esima di C e' m-contenuta nella colonna j-esima di C e altrimenti e' false (quindi qui, riga e colonna
sono visti come multi-insiemi).

*/


// PRE: input contiene 30 interi, k1, k2, ... k30
main()
{
	// apro il file di input
    ifstream input(/*"input.tx*/t");

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

    bool B[6][5], var;
    int num, num2;

	// R1 = (per ogni k in [0..a-1] e t in [0..4] B[k][t]==true <=> rowC[t] e' contenuta in colC[k])
	for(int a=0;a<6;a++)
	{
		// R2 = (per ogni t [0..b-1] B[x][t]==true <=> rowC[t] e' contenuta in colC[x])
		for(int b=0;b<5;b++)
		{
			// ora devo controllare che ogni riga sia m-contenuta in ogni
			// colonna. Quindi ciclo in modo tale da contare quanti valori
			// uguali ci sono in entrambi gli array da confrontare e, quando
			// il numero dei valori uguali nella colonna e' >, continua a ciclare,
			// appena questo numero diventa inferiore, non si entra piu' nell'if e
			// si salva nella matrice il valore false.
			var=true;
			// R3 = (ad ogni elemento C[x][a] corrisponde uno e un solo elemento C[b][y] con 0<=a<d-1 e 0<=b<6)
			for(int d=0;d<5;d++)
			{
				if (var){
					num = 0;
					// R4 = (non esiste nessun elemento su colC[y] t.c. C[x][i] == C[b][y] && t[b]==false per ogni b in [0..e-1]
					for(int e=0;e<5;e++)
					{
						if(C[a][d]==C[a][e]){
							num++;
						}
					}
					num2 = 0;
					// 0 <=e<6
					for(int e=0;e<6;e++)
					{
						if(C[a][d]==C[e][b]){
							num2++;
						}
					}
					if(num > num2){
						var = false;
					}
				}
			}
			B[a][b]=var;
		}
	}

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
}
// POST: per ogni i in [0,5] e j in [0,4], B[i][j] <=> C[i] è m-contenuta in C[..][j])
