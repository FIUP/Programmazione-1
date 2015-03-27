/*Integrazione 6 crediti*/
#include<fstream>
#include<iostream>
using namespace std;

//PRE = r punta al primo elemento della riga da stampare, dimR, dimC non nulli
void stampaRiga(int *r, int dimR, int dimC, int vfp, ofstream& out){
	for(int i =0; i<dimC && i<=vfp; i++){
		out << *(r+i) << " ";
	}
	out << endl; 
}
 //POST = su out son stati stampati gli elementi della riga puntata da r
 
 //PRE = s punta al primo elemento dello strato da stampare, dimS, dimr, dimc, vfp, non nulli
 // rim eventualmente nullo, vfp (vfette piene, rim elementi rimanenti)
 void stampaStrato(int * s, int dimS, int dimr, int dimc, int vfp, int &rim, ofstream& out){
	int * pr=s;
	for(int j=0; j<dimr; j++){
		if(rim !=0){
			stampaRiga(pr, dimr,dimc, vfp, out);
			rim--;
		}
		else 
			stampaRiga(pr, dimr, dimc, vfp-1, out);
		pr +=dimc;
	}	
}
 //POST = su out son stati stampati gli elementi della strato puntato da s

main(){
	int X[400], *p=X, *q=p;			//va visto come Y[3][6][5]
	int lim1, lim2, lim3, n_el;		// lim1 = strati, lim2= righe, lim3 = colonne 
	ifstream IN("input");
	ofstream OUT("output");
	
if(IN && OUT){
	IN >>lim1 >> lim2 >> lim3 >> n_el;
	int vfp = n_el/(lim1*lim2);
	int rim = n_el%(lim1*lim2); 
	if(n_el >0 && n_el < 401 && lim1 >0 && lim2 >0 && lim3 >0){
		for(int c =0; c< lim3; c++)	
			for(int i = 0; i < lim1; i++){
				for(int j=0; j<lim2;j++)
					IN >> p[i*lim2*lim3+j*lim3+c];
	}
		
	IN.close();
	
	for(int i =0; i<lim1; i++){
		OUT << "strato " << i << endl;
		stampaStrato(q, lim1, lim2, lim3, vfp, rim, OUT); 
		q +=(lim2*lim3);
	}	
	OUT <<"fine";
	
	OUT.close();
	} else OUT << "Errore valori non validi"; 
} else cout << "Errore con i file";
			

}