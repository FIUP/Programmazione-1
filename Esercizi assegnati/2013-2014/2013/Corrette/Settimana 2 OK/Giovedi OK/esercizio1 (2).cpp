/*
  Esercitazione del 24 Gennaio 2013 (1)
  Corso: Programmazione
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int dim,x,y,A[100];
//x è il numero di occorrenze di y,y è il numero da cercare
	ifstream IN("input1");
	ofstream OUT("output1");
	
	if(IN)
	{
		IN>>dim;
			for(int k=0;k<dim;k++)
				IN>>A[k];
		IN>>x;
		IN>>y;
		
		IN.close();
	}
	else
		cout<<"Errore,impossibile aprire il file di input!"<<endl;
		
	int k=0,k1=0,Noccor=0,B[dim];
//B è un array di supporto attraverso il quale salvo le posizioni
// dei match 
	while(k<dim)//R
	{
		if(A[k]==y)
		{
			Noccor++;//incremento il numero di occorrenze trovate
			B[k1]=k;//salvo la posizione nell'array di supporto
			k1++;//incremento il contatore per l'array di supporto
			k++;//esamino il successivo valore di A			
		}
		else
			k++;
		
	}
	
	if(Noccor==x)
	{
		OUT<<"True ";
		for(int i=0;i<Noccor;i++)
			OUT<<B[i]<<" ";
	}
	else
		OUT<<"False "<<Noccor;
		
	OUT.close();
}//fine main
/*
PRE=(Il file input1.txt contiene in sequenza,con uno spazio tra un 
valore e l'altro,i seguenti valori:
dim,tale che 1<=dim<=100;dim interi, che vengono inseriti in 
A[0],A[1]..A[dim-1];due ulteriori interi che chiameremo x ed y,tali
che 0<=x<=dim.)

R=(Noccor è il numero di occorrenze di y trovate in A[0..k-1] && 
in B[0..k1-1] ci sono gli Noccor indici di A,compresi tra [0..k-1],
in cui ho trovato le occorrenze di y)

POST=(Il file output1.txt contiene il valore True e le x posizioni
(alias le Noccor trovate) di A che contengono y (separate da uno 
spazio) nel caso in cui A[0..dim-1] contenga esattamente x occorrenze
del valore y.Se A non soddisfa tale condizione output1.txt contiene
il valore False ed il numero di occorrenze Noccor di y in 
A[0..dim-1])

CORRETTEZZA:
condizione iniziale: k=0 =>Noccor trovate in A[0..-1] sono pari a 
zero =>R è trivialmente verificato

invarianza:esamino elemento k-esimo di A,se corrisponde ad y=>se 
Noccor era il numero di occorrenze di y in A[0..k-1]=>
Noccor+1 è il numero di occorrenze di A[0..k],salvo l'indice k 
nell'array di supporto B che quindi ora contiene correttamente
gli Noccor indici dell'array A in cui sono state trovate le Noccor 
di y,incremento k e quindi Noccor ora è il numero di occorrenze 
di A[0..k-1] e k<dim ancora=>vale ancora R

condizione di uscita:k=dim, Noccor è correttamente il numero di 
occorrenze di y in A[0..dim-1]=> 
-se Noccor=x => viene stampato True e gli Noccor indici contenuti
 in B[0..dim] che corrispondono alle posizioni di y in A
-se Noccor!=x viene stampato True ed il numero di occorrenze 
Noccor di y in A[0..dim-1]=>POST
*/
