/*Integrazione 6 crediti*/
#include<fstream>
#include<iostream>
using namespace std;

//PRE = r punta al primo elemento della riga da stampare, dimR, dimC non nulli
void stampaRiga(int *r, int dimR, int dimC, int vfp, ofstream& out){
	for(int i =0; i<dimC && i<=vfp; i++){						//la riga va bloccata al punto giusto in base a vfp, v-fette piene
		out << *(r+i) << " ";
	}
	out << endl; 
}
/*POST = su out son stati stampati gli elementi della riga puntata da r
 
PRE = s punta al primo elemento dello strato da stampare, dimS, dimr, dimc, vfp, non nulli
rim eventualmente nullo, vfp (vfette piene, rim elementi rimanenti)*/
 void stampaStrato(int * s, int dimS, int dimr, int dimc, int vfp, int &rim, ofstream& out){
	int * pr=s;													//pr punta alle righe 
	for(int j=0; j<dimr; j++){									//navighiamo tra righe
		if(rim !=0){											//se ci sono elementi rimanenti
			stampaRiga(pr, dimr,dimc, vfp, out);				//stampiamo la riga che avrà vfp elementi, tramite stampaRiga
			rim--;												//e scaliamo rim di uno
		}
		else 													//altrimenti
			stampaRiga(pr, dimr, dimc, vfp-1, out);				//stampiamo le righe con vfp-1 elementi
		pr +=dimc;												//aggiorniamo il puntatore alla riga successiva
	}	
}
 //POST = su out son stati stampati gli elementi della strato puntato da s

main(){
	int X[400], *p=X, *q=p, inseriti =0;	
	bool continua =true;
	int lim1, lim2, lim3, n_el;									// lim1 = strati, lim2= righe, lim3 = colonne 
	ifstream IN("input");
	ofstream OUT("output");
	
if(IN && OUT){													
	IN >>lim1 >> lim2 >> lim3 >> n_el;							
	int vfp = n_el/(lim1*lim2);									//vfp = v-fette piene, rappresenta la dimensione base di una riga
	int rim = n_el%(lim1*lim2); 								//rim = elementi rimanenti, righe con un elemento in più
	for(int c =0; c< lim3 && continua; c++)						//inseriamo per v-fette passando prima le colonne
		for(int i = 0; i < lim1 && continua; i++)				//poi gli strati
			for(int j=0; j<lim2 && continua;j++){				//ed infine le righe
				IN >> p[i*lim2*lim3+j*lim3+c];					//leggendo da input
				inseriti++;										//incrementando il contatore degli elementi inseriti
				if(inseriti == n_el)							//se abbiamo inserito n_el elementi
					continua = false;							//non continuiamo
			}
		
	IN.close();
		
	for(int i =0; i<lim1; i++){									//stampiamo per strato come negli esercizi precedenti
		OUT << "strato " << i << endl;
		stampaStrato(q, lim1, lim2, lim3, vfp, rim, OUT); 
		q +=(lim2*lim3);
	}	
	OUT <<"fine";
	
	OUT.close();
} else cout << "Errore con i file";
			

}