/*Integrazione 6 crediti*/
#include<fstream>
#include<iostream>
using namespace std;

//PRE = r punta al primo elemento della riga da stampare, dimR, dimC non nulli
void stampaRiga(int *r, int dimR, int dimC, ofstream& out){
	for(int i =0; i<dimC; i++){						//dimC è il numero di elementi della riga
		out << *(r+i) << " ";						//tramite l'aritmetica dei puntatori scriviamo in output l'elemento
	}
	out << endl; 
}
 /*POST = su out son stati stampati gli elementi della riga puntata da r
 
 PRE = s punta al primo elemento dello strato da stampare, dimS, dimr, dimc, non nulli*/
void stampaStrato(int * s, int dimS, int dimr, int dimc, ofstream& out){
	int * pr=s;										//pr punta all'inizio delle righe
	for(int j=0; j<dimr; j++){						//in uno strato ci sono dimr righe
		stampaRiga(pr, dimr,dimc, out);				//stampiamo invocando stampaRiga
		pr +=dimc;									//e aggiorniamo il puntatore per farlo puntare alla riga successiva
	}	
}

main(){
	int X[400], *p=X, *q=p, inseriti =0;			//va visto come Y[3][6][5]
	bool continua =true;
	int lim1, lim2, lim3, n_el;						// lim1 = strati, lim2= righe, lim3 = colonne 
	ifstream IN("input");
	ofstream OUT("output");
	
	for(int i=0; i<400; i++)						//carica di default tutto X a -1
		X[i] = -1;
	
if(IN && OUT){
	IN >>lim1 >> lim2 >> lim3 >> n_el;				//leggiamo le dimensioni da input
	for(int c =0; c< lim3 && continua; c++)			//l'inserimento va fatto per v-fette quindi prima passiamo le colonne
		for(int i = 0; i < lim1 && continua; i++)	//poi gli strati
			for(int j=0; j<lim2 && continua;j++){	//ed infine le righe
				IN >> p[i*lim2*lim3+j*lim3+c];		//nell'elemento corrente carichiamo da file input 
				inseriti++;							//e aumentiamo il numero di elementi inseriti di uno
				if(inseriti == n_el)				//se abbiamo inserito n_el elementi
					continua = false;				//blocchiamo l'inserimento
			}										//i*lim2*lim3+j*lim3+c rappresenta i strati considerati, j righe considerate e c colonne
													//considerate quindi i va moltiplicato per la dimensione di uno strato (lim2*lim3) 
													//j per le dimensioni di una colonna (lim3) e c è monodimensionale, dunque non va moltiplicato
													//per niente, sommando il tutto arriviamo nella giusta posizione in memoria
	IN.close();	
				
	for(int i =0; i<lim1; i++){						//stampiamo gli elementi per strato
		OUT << "strato " << i << endl;				//etichettando ogni strato
		stampaStrato(q, lim1, lim2, lim3, OUT); 	//tramite l'invocazione della funzione stampaStrato
		q +=(lim2*lim3);							//q punta al primo elemento di ogni strato e va incrementato di lim2*lim3 elementi
	}	
	OUT <<"fine";									

	OUT.close();
} else cout << "Errore con i file";
			

}