/*Integrazione sei crediti parte di correttezza non inclusa
Essendo molto simile al primo compitino si rimanda ai commenti di quello*/
#include<iostream>
#include<fstream>
using namespace std;
struct tripla{int prof, riga, colonna; tripla(int a=0, int b=0, int c=0){prof=a; riga=b; colonna=c;}}; //per modellare posizione in sotto-array

tripla ritornaPos(int index, int l, int h, int lim1, int lim2, int lim3){
	int strato = index/(l*h);
	int rimus =index%(l*h);
	int riga = rimus/l; 	
	int colonna = index%l;

	tripla pos(strato, riga, colonna);
	return pos;
}

bool match (int*X, int r, int c, int h, int l, int lim1, int lim2, int lim3, int* P, int dimP, int e, ofstream& out){
    int inizio = r*lim3+c;	//distanza iniziale del primo elemento dell'array
	tripla pos = ritornaPos(e, l, h, lim1, lim2, lim3);
	int dist = inizio + pos.prof*(lim2*lim3)+pos.riga*(lim3)+pos.colonna;
	//out << e << " pos strato " << pos.prof << ", riga " << pos.riga << ", colonna " << pos.colonna << " distanza "<< dist << endl;
	int i=e;
	bool ok = true;
	for(int j = 0; j < dimP && ok; j++){
		if(X[dist] != P[j]){
			ok = false;
		}
		else{
			//out << " elemento trovato = " << X[dist] << " p " << P[j] << " distanza "<< dist << " "; 
			i++;;
			pos = ritornaPos(i,l,h,lim1,lim2,lim3);
			dist = inizio + pos.prof*(lim2*lim3)+pos.riga*(lim3)+pos.colonna;
			//out << i << " pos succ: " << pos.prof << " pos riga " << pos.riga << " pos colonna " << pos.colonna <<endl;
		}
    }
    return ok;
}


main(){
  ifstream IN("input");
  ofstream OUT("output");

  if(IN && OUT) { 
   
   int X[400],P[50], n_el, dimP, lim1,lim2,lim3;   
   IN>>lim1>>lim2>>lim3;
   IN>>n_el;

   for(int i=0; i<n_el; i++)
     IN >> X[i];
   int r,c,h,l;
   IN>>r>>c>>h>>l; //definisce sotto-array
   
   IN>>dimP;
   for(int i=0; i<dimP; i++)
     IN>>P[i];

//pattern match sul sottoarray  pieno con ordinamento per V-fette 

   //inizializzazione
    int dimSA = lim1*h*l;
    int matchvf=0;
	int jump=1;
	
   //for(esame elementi del sotto-array in ordine per  V-fette da cui può iniziare un match con P)
	for(int e = 0; e < (dimSA-dimP)+1; e+=jump){
		if(match(X,r,c,h,l,lim1,lim2,lim3,P,dimP,e, OUT)){ 
			matchvf++;
			OUT<<"trovato match a partire dall'elemento "<<e<<endl;
			jump = dimP;
		}
		else{ 
			OUT<<"a partire dall'elemento "<<e<<" non c'e' match"<<endl;
			jump=1;
		}
	}
	OUT<<"n. totale match="<< matchvf <<endl;
    IN.close(); OUT.close(); 
  }
  else
   cout<<"errore con i files";
}
