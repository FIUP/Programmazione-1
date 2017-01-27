
//soluzione by: Federico S. B.

/*Integrazione 6 crediti parte di correttezza non richiesta*/

/*
Parte di Teoria:

1) Dato il seguente codice
int **F(int *x){
	int **p=&x;
	(*x)++;
	return x;
}
main(){
	int a = 2, *q = &a;
	**F(q) = 4;
	cout <<a<<endl;
}
E' corretto? Cosa stampa?
Non è corretto, il tipo ritornato di x non coincide con il tipo di ritorno della funzione. 
Da errore in compilazione.

2) Dato int T[3][5][6] qual è il tipo di *(T[8]-2)?
*(T[8]-2) = *(*(T+8)-2) = int(*)
il suo valore è T+8(tipo di T)*sizeof(int)-2(tipo di *T)*sizeof(int)
quindi T+8(5*6)*4-2(6)*4 

3) Dato il seguente codice:
main(){
int x=0;
for(int i =0; i<10; i++){
	cout <<x<<endl;
	if(x>0)
		break;
	else 
		continue;
	x++;
}
}
Cosa stampa?
10 volte 0 in colonna
*/


//Parte di Programmazione
#include<iostream>
#include<fstream>
using namespace std;
struct tripla{int prof, riga, colonna; tripla(int a=0, int b=0, int c=0){prof=a; riga=b; colonna=c;}}; //per modellare posizione in sotto-array

tripla ritornaPos(int index, int l, int h, int lim1, int lim2, int lim3){
	int lungvf = lim1*h;
	int colonna = index/lungvf;
	if(index >= lungvf){
		index -=colonna*lungvf;
	}
	int strato = index/h;
	int rimus = index%(l*h);
	int riga = rimus%h;

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
			//out << e << " pos succ: " << pos.prof << " pos riga " << pos.riga << " pos colonna " << pos.colonna <<endl;
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
