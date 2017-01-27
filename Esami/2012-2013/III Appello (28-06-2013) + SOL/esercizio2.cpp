#include<iostream>
#include<fstream>
using namespace std;
// Soluzione ottima !!
//PRE_conta: T array di C>=0 elementi definiti, P array di dimP>=0 elementi definiti
int conta(int *T, int C, int *P, int dimP) {
	if (!C) {
		return 0;
	}
	if (!dimP) {
		return 0;
	}
	if (T[0]==P[0]) {
		return 1+conta(T+1, C-1, P+1, dimP-1);
	}else{
		return 0;
	}
}
//POST_conta: conta ritorna la lunghezza del match di P[0...dimP-1] a partire dalla posizione T passata

//PRE_R1: T ha C elementi definiti, P ha dimP elementi definiti
int R1(int*T, int C, int*P, int dimP) {
	if (!C) {
		return 0;
	}
	if (!dimP) { // inutile non deve mai succedere
		return 0;
	}
	int count;
	int temp=R1(T+1, C-1, P, dimP);
	count=conta(T, C, P, dimP);
	if (count>temp) {
		return count;
	}else{
		return temp;
	}
}
//POST_R1: la funzione restituisce la lunghezza del match massimo di P[0..dimP-1] in T[0..C-1]

//PROVA INDUTTIVA:// convincente ! BENE 

//PASSO BASE: se la riga è finita ritorno 0, in quanto non ho match in una riga vuota
//			  se dimP è 0 ritorno 0, in quanto il match è finito
//PASSO INDUTTIVO: assumo vere PRE_ric e POST_ric rispetto a PRE e POST 

//alla chiamata ricorsiva passo T+1 che è array di C-1 elementi definiti, e passo P che è array di dimP elementi definiti --> ok PRE
//				   la chiamata ricorsiva mi restituisce la lunghezza del match massimo di P[0..dimP-1] a partire dalla posizione T+1 e esaminando le posizioni successive fino a fine riga e pongo il risultato dentro temp
//				   conta mi restituisce la lunghezza del match di P[0...dimP-1] dalla posizione T e pongo il risultato dentro count
//				   se count>temp allora il match massimo è nella posizione T e restituisco count che è lunghezza di questo match --> ok POST
//				   se count<temp allora il match massimo è dalla posizione T+1 alla fine della riga e restituisco temp che è lunghezza di questo match --> ok POST


/*PRE_FR=(T ha R*C elementi definiti, P ha dimP elementi definiti, 0<=inizio<dimP, Q ha R elementi il cui valore e' arbitrario)*/
void FR(int*T, int R, int C, int*P, int dimP, int inizio, int*Q)
{
  if(!R)
     return;
  int MAX=R1(T,C, P+inizio, dimP-inizio); // da fare
  *Q=MAX;
  inizio=inizio+MAX;
  if(inizio==dimP)
   inizio=0;
  FR(T+C, R-1,C,P,dimP,inizio, Q+1);
}
/*POST_FR=(Q[0] contiene la lunghezza del massimo match del pattern P[inizio..dimP-1] nella prima riga di T,  T[0..C-1], 
se inizio+Q[0]=dimP, allora Q[1] contiene la lunghezza del massimo match di tutto il pattern P nella prossima riga di T,  
se invece inizio+Q[0]<dimP, allora Q[1] sarà la lunghezza del massimo match di P[inizio+Q[0]..dimP-1] nella prossima riga di T, 
e cosi' di seguito per tutti gli  R elementi di Q) */

main()
{
  ifstream INP("input2");
  ofstream OUT("output2");
  if(INP && OUT)
   {
    int R,C, dimP;
    INP>>R>>C>>dimP;
    int *T=new int[R*C];
    int*Q=new int[R];
    int* P=new int[dimP];
    for(int i=0; i<R*C; i++)
     {INP>>T[i];cout<<T[i]<<' ';}
    cout<<endl;
    for(int i=0; i<dimP; i++)
     {INP>>P[i];cout<<P[i]<<' ';}
    cout<<endl;
    
    FR(T,R,C,P,dimP,0,Q);

    for(int i=0; i<R; i++)
     OUT<<Q[i]<<' ';
    OUT<<endl;
    INP.close();
    OUT.close();
  }
 else 

  cout<<"errore apertura file"<<endl;
}
