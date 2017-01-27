//Matteo Gazzato 594140  ESERCITAZIONE DEL 28/2/2013 SETTIMANA 6
/*
TEORIA:
Il problema risiede nella funzione g: all'inizio x punta a q (essendo un puntatore a puntatore), p viene inizializzato facendolo puntare 
a X+1 e successivamente con l'istruzione x=&p x viene fatto puntare  a p che e' variabile locale delle funzione g,la quale verra' deallocata
una volta eseguite le istruzioni della funzione. Proprio per tal motivo la seguente istruzione di return, return x, provoca DANGLING POINTER. 
Questo perche' nel main successivamente con *g(&q)==*x=&p tentero' di accedere ad un' area della memoria RAM che e' gia' stata deallocata.
*/

#include <iostream>
#include <fstream>

using namespace std;

bool match(int* T, int dim, int*P, int dimP)
{
	//casi base
	if(dimP==0)
		return true;
	if(*T!=*P) 
		return false;
	//passo induttivo
	else
	{
		return match(T+1,dim-1,P+1,dimP-1);
	}

}//fine match

int F(int*T, int dim, int *P, int dimP)
{
	//caso base
	if(dim<dimP)
		return 0;
	else//passi induttivi
	{
		if(match(T,dim,P,dimP))
			return 1+F(T+1,dim-1,P,dimP);
		else
			return F(T+1,dim-1,P,dimP);
	}
}//fine F

int F1(int*T, int dim, int *P, int dimP)
{
	//caso base
	if(dim<dimP)
		return 0;
	else//passi induttivi
	{
		if(match(T,dim,P,dimP))
			return 1+F1(T+dimP,dim-dimP,P,dimP);
//se c'è match avanzo di dimP elementi per non considerare eventuali 
//match sovrapposti
		else										
			return F1(T+1,dim-1,P,dimP);
	}
}//fine F1
//POST_F1=(F restituisce il n. di match di P in T non considerando i
//match sovrapposti)

int main()
{
	ifstream IN("input1");
	ofstream OUT("output1");

	int dim,T[100],dimP,P[20];
	
	if(IN)
	{
		IN>>dim;
		for(int i=0;i<dim;i++)
			IN>>T[i];
		IN>>dimP;
		for(int i=0;i<dimP;i++)
			IN>>P[i];

		IN.close();
		
	}
	else
		cout<<"Errore!Impossibile aprire il file di input!"<<endl;

	int nmatch=F(T,dim,P,dimP);

	OUT<<"Numero di match: "<<nmatch<<endl;
	nmatch=F1(T,dim,P,dimP);
	OUT<<"Numero di match non sovrapposti: "<<nmatch<<endl;
	
OUT.close();
}//fine main
/*
N.B: dim (1<=dim<=100) && (1<=dimP<=20)

CORRETTEZZA:
caso base: PRE<caso base>POST
passo induttivo: 
-ipotesi induttiva:le invocazione ricorsive sono corrette rispetto a
 PRE e POST
-vale PRE<caso non base >POST

funzione match:

PRE_match=(T da dim elementi definiti, P ha dimP elementi definiti)

POST_match=(match restituisce true sse c’è un match (completo e 
contiguo) di P in T a partire da T[0]).

funzione match:
casi base: (dimP==0) => array vuoto => ritorno true => POST_match è 
			trivialmente vera perchè il match di un array vuoto è 
			sempre verificato (*T!=*P) => ritorno false => POST_match
			è vera perchè se già il primo elemento della sequenza non
			combacia allora	non posso avere	un match completo e contiguo
			di P in T a partire da T[0]
			
passo induttivo: P non è vuoto e T[0]=P[0]
			Verifichiamo PRE_ric dell'invocazione ricorsiva.
			PRE_ric=(T+1 ha dim-1 elementi definiti, P-1 ha dimP-1 
			elementi definiti) che è vera perchè se l'array 
			T[0]..T[dim-1] e P[0]..P[dimP-1] soddisfano PRE_match,
			sono cioè definiti, necessariamente T[1..dim-1] e 
			P[1..dimP-1] (gli array considerati da PRE_ric) non possono 
			non soddisfare PRE_ric. Quindi si assume che anche 
			POST_ric=(match restituisce true sse c'e' un match (completo 
			e contiguo di P[1..dimP-1] in T[1..dim-1] a partire da T[1]) 
			sia vera.
			Se l'invocazione ritorna true significa che i successivi 
			elementi di T combaciano con quelli di P=>POST_match
			Se l'invocazione ritorna false significa che uno dei 
			successivi elementi di T non coincide con il 
			corrispondente elemento in P=>POST_match

PRE_F=(T ha dim elementi definiti, P ha dimP elementi definiti)

POST_F=(F restituisce il n. di match di P in T considerando anche
match sovrapposti)
			
funzione F:
caso base: il numero di elementi di T è minore del numero di elementi 
			di P=>impossibile che esista un match di P in T=>
			ritorno 0=>POST_F è verificata 	poichè il numero di match
			in questo caso è zero

passo induttivo: il numero dim di elementi di T è >= al numero di 
				elementi dimP di P (quindi potrebbe esistere un match 
				completo e contiguo di P in T). 
				Verifichiamo PRE_ric dell'invocazione ricorsiva.
				PRE_ric=(T+1 ha dim-1 elementi definiti, P-1 ha 
				dimP-1 elementi definiti) che è vera perchè se 
				l'array T[0]..T[dim-1] e P[0]..P[dimP-1] soddisfano
				PRE_F,sono cioè definiti, necessariamente T[1..dim-1]
				e P[1..dimP-1] (gli array considerati da PRE_ric) non
				possono	non soddisfare PRE_ric. 
				Quindi si assume che anche POST_ric=(match=true => 
				il numero di match di P in T[0]..T[dim-1] è 1 + il n 
				di match di P in T[1]..T[dim-1] && match=false => 
				il numero di match di P in T[0]..T[dim-1] è uguale al
				n di match di P in T[1]..T[dim-1]) sia vera.
				Se l'invocazione aggiunge uno al conteggio totale 
				dei match,significa che vi era match completo di P in
				T a partire da T[0] ed il numero totale di match di 
				P in T è stato correttamente incrementato=>POST_F
				In caso contrartio non avviene l'incremento ed il 
				numero di match è ancora corretto=>POST_F  
*/





