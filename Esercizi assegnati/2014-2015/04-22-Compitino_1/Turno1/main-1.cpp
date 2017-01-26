/*Integrazione sei crediti parte di correttezza non inclusa
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
#include<iostream>
#include<fstream>
using namespace std;
struct tripla{int prof, riga, colonna; tripla(int a=0, int b=0, int c=0){prof=a; riga=b; colonna=c;}}; //per modellare posizione in sotto-array

tripla ritornaPos(int index, int l, int h, int lim1, int lim2, int lim3){	//ritorna la posizione dell'elemento da matchare dove l è la lunghezza del sottoarray e h la sua altezza
	int lungvf = lim1*h;													//calcoliamo la lunghezza di una v-fetta (numero di strati*altezza sottoarray)
	int colonna = index/lungvf;												//calcoliamo la colonna
	if(index >= lungvf){													//se l'indice è maggiore o uguale alla lunghezza della v-fetta
		index -=colonna*lungvf;												//lo aggiustiamo per far quadrare i conti
	}
	int strato = index/h;													//dividendo index per h otteniamo in quale strato siamo
	int rimus = index%(l*h);												//calcoliamo gli elementi rimanenti dell'ultimo strato
	int riga = rimus%h;														//e la riga 

	tripla pos(strato, riga, colonna);										//mettiamo il tutto in una tripla
	return pos;																//e la ritorniamo
}

bool match (int*X, int r, int c, int h, int l, int lim1, int lim2, int lim3, int* P, int dimP, int e, ofstream& out){
    int inizio = r*lim3+c;														//distanza iniziale del primo elemento dell'array
	tripla pos = ritornaPos(e, l, h, lim1, lim2, lim3);							//calcoliamo la tripla riferita all'elemento da considerare
	int dist = inizio + pos.prof*(lim2*lim3)+pos.riga*(lim3)+pos.colonna;		//e la usiamo per calcolare la distanza dall'inizio di X
	//out << e << " pos strato " << pos.prof << ", riga " << pos.riga << ", colonna " << pos.colonna << " distanza "<< dist << endl;
	int i=e;																	//e ultima posizione valida per il match
	bool ok = true;																//impostiamo un bool per interrompere prima il ciclo, se serve
	for(int j = 0; j < dimP && ok; j++){										//finché c'è pattern da  cercare
		if(X[dist] != P[j]){													//se l'elemento considerato non coincide con quello del pattern da matchare
			ok = false;															//ci fermiamo
		}
		else{																	//altrimenti
			//out << " elemento trovato = " << X[dist] << " p " << P[j] << " distanza "<< dist << " "; 
			i++;;																//incrementiamo l'indice
			pos = ritornaPos(i,l,h,lim1,lim2,lim3);								//calcoliamo la posizione del successivo tramite ritornaPos
			dist = inizio + pos.prof*(lim2*lim3)+pos.riga*(lim3)+pos.colonna;	//e ricalcoliamo la distanza dall'inizio di X
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
    int dimSA = lim1*h*l;													//imposta la dimensione del sotto-array
    int matchvf=0;															//matchvf conta quanti match ci sono nella v-fetta
	int jump=1;																//jump è l'incremento del ciclo
	
   //for(esame elementi del sotto-array in ordine per  V-fette da cui può iniziare un match con P)
	for(int e = 0; e < (dimSA-dimP)+1; e+=jump){							//navighiamo nel sotto-array
		if(match(X,r,c,h,l,lim1,lim2,lim3,P,dimP,e, OUT)){ 					//se c'è match nella v-fetta
			matchvf++;														//incrementiamo il contatore
			OUT<<"trovato match a partire dall'elemento "<<e<<endl;			//e stampiamo dove inizia
			jump = dimP;													//i match devono essere non sovrapposti quindi saltiamo dimP posizioni
		}
		else{ 																//altrimenti se non c'è match
			OUT<<"a partire dall'elemento "<<e<<" non c'e' match"<<endl;	//stampiamo un messaggio
			jump=1;															//e controlliamo dalla prossima posizione
		}
	}	
	OUT<<"n. totale match="<< matchvf <<endl;								//stampiamo il numero totale di match trovati
    IN.close(); OUT.close(); 												//e chiudiamo i file
  }
  else
   cout<<"errore con i files";
}
