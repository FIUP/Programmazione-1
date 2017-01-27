//L'irganizzazione sta in piedi. Errori nel calcolo degli indici per T e confusione in match
// per il test del ciclo.  


#include<iostream>
#include<fstream>
using namespace std;

//PRE_match= PRE_F && (r in [0..R-1], c in [0..C-1], inizio in [0..dimP-1])
int match(int*T, int r, int c, int R, int C, int*P, int dimP, int inizio) 
{
	bool stop=false;
	int cont=0;
	for (int i=inizio; i<R && r<dimP && !stop; i++) {//i<R e r<dimP  non hanno senso. semmai i<dimP e r<R

		if (T[0]==P[0]) {
			T=T+R; // T+C visto che una riga e' lunga C
			P=P+1;
			cont++;
		}else{
			stop=true;
		}
		r++;
	}
	return cont;
}
//POST_mach= (la funzione restituisce la lunghezza del match massimo del pattern P[inizio..dimP-1]tale che il
//			  match inizia nella posizione T[r][c] della colonna c e che si estende il più possibile in questa colonna, cioè
//			  in T[r..R-1][c])

//PRE_F=(T ha R*C elementi definiti, P ha dimP elementi definiti, R, C e dimP sono maggiori di 0, Q ha C
//		 elementi di valore qualsiasi)
void F(int *T, int R, int C, int* P, int dimP, int*Q) {
	int inizio=0;
	for (int i=0; i<C; i++) {  //R1
		int temp=0, lungh=0;
		for (int j=0; j<R; j++) {	//R2
			temp=match(T+j*R+i, j, i, R, C, P+inizio, dimP, inizio);//j*R non va, j*C
			if (temp>lungh) {
				lungh=temp;
			}
		}
		Q[i]=lungh;
		inizio=(inizio+lungh)%dimP;
	}
}
//POST_F=(Q[0] è il massimo match di P nella colonna 0 di T, Q[1] il massimo match del resto di P nella
//		  colonna 1 e così via. Se il resto di P risulta vuoto allora si ricomincia con l'intero P)


//R1: 0<=i<=C, Q[i-1] contiene il massimo match contiguo di P nella colonna i-1 di T, //e' contenuto nella prossima riga 
//    Q[0...i-1] contiene il massimo match contiguo di P nelle colonne 0...i-1 di T, 
//    inizio contiene la prossima posizione di P da cui ripartire per cercare il match //inizio= somma su Q % dimP

//R2: 0<=j<=R, temp contiene la lunghezza del match contiguo di P a partire dalla posizione j-1 della colonna i di T,
//    lungh contiene la lunghezza del massimo match contiguo di P a partire dalle posizioni 0...j-1 della colonna i di T //OK !!

//DIMOSTRAZIONE DI CORRETTEZZA: // RAGIONEVOLE 
// 1) PRE --> ok R1
//	  i==0 --> ok; Q[-1] contiene il massimo match contiguo di P nella colonna -1 di T --> ok perchè la colonna -1 non esiste;
//	  inizio==0 --> ok perchè dobbiamo iniziare a cercare il match per la prima volta e quindi partiamo dall'inizio
// 2) R1 && (condizione ciclo), poi eseguo corpo --> ok R1
//	  0<=i<C
//	  eseguo il corpo: lungh conterra la lunghezza del match massimo in quella colonna, la pongo in Q[i], 
//a inizio sommo il valore della  lunghezza del match trovato, iniziero quindi a cercare da quella posizione inizio in poi 
//(se inizio==dimP l'operazione
//					   modulo mi fara diventare inizio=0 e quindi partiro a cercare dall'inizio di P)
//					   i viene aumentato di 1
//	  i diventera al piu =C --> ok R1
//	  Q[i-1] contiene la lunghezza del match massimo nella colonna i-1 --> ok R1 //e le posizioni precedenti le 
//abbiamo per la R1 all'inizio.
//	  inizio contiene la posizione di P da cui iniziare a cercare (vedere 5 righe sopra per spiegazione) --> ok R1
// 3) R1 && !(condizione ciclo) --> POST
//	  i=C
//	  per R1: Q[0...i-1] contiene il massimo match contiguo di P nelle colonne 0...i-1 di T --> ok POST


main()
{
  ifstream INP("input1");
  ofstream OUT("output1");
  if(INP && OUT)
   {
    int R,C, dimP;
    INP>>R>>C>>dimP;
    int *T=new int[R*C];
    int *Q=new int[C];
    int *P=new int[dimP];
    for(int i=0; i<R*C; i++)
     {INP>>T[i];cout<<T[i]<<' ';}
    cout<<endl;
    for(int i=0; i<dimP; i++)
     {INP>>P[i];cout<<P[i]<<' ';}
    cout<<endl;
    
    F(T,R,C,P,dimP,Q);//da fare 

    for(int i=0; i<C; i++)
     OUT<<Q[i]<<' ';
    OUT<<endl;
    INP.close();
    OUT.close();
  }
 else 

  cout<<"errore apertura file"<<endl;
}
