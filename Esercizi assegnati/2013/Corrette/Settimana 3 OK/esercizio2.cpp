//Matteo Gazzato 594140  ESERCITAZIONE DEL 31/1/2013 SETTIMANA 3
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream IN("input2");
	ofstream OUT("output2");

	char A[5][10];
	int dim;

	if(IN)
	{
		IN>>dim;
		int k=0;
		while(k<dim)
		{
			IN>>*(*A+k);
			k++;
		}		
		
		IN.close();
	}
	else
	cout<<"Errore,impossbile aprire il file di input"<<endl;

	bool trovato=false;
	int cont=0,k=dim-1,riga;
	
	while(k>=0 && !trovato)//R
	{
		if(*(*A+k)=='a')
			cont++;
		
		if(!k || !(k%10))
		{	
			if(!(cont%2))
				{trovato=true;riga=k/10;}		
			cont=0;
		}
		k--;
	
	}//fine while
//POST
if(trovato)
	OUT<<trovato<<" "<<riga;
else
	OUT<<trovato;

OUT.close();
}//fine main	


/*
N.B. uso la notazione ultimariga per indicare l'ultima riga definita
(che ha quindi almeno un elemento) di A

PRE=(A e' un array definito contenente dim caratteri && 0<dim<=50)

R=((!trovato && k>=0 =>in A[(k+1)/10]..A[ultimariga] non ci sono 
righe di A con un numero di occorrenze pari di'a') &&
(trovato && k>=0 => la riga (k+1)/10 contiene un numero pari di 
di occorrenze di A && in A[(k+2)/10]..A[ultimariga] non ci sono altre
righe con un numero di occorrenze pari di 'a'))

POST=(trovato=> riga=k/10 e' l'indice massimo della riga contenente 
un numero pari di 'a' && !trovato=>non esistono righe di A con un 
numero pari di 'a' )

ORRETTEZZA:
PRE<ini;while(B)C>POST

PRE <ini> R cond iniziale
R && B <C>R invarianza
R && !B=>POST condizione d'uscita

Condizione iniziale: k=dim-1 => in A[(k+1)/10]..A[ultimariga] non 
possono	esserci righe => R trivialmente verificata

Invarianza:!trovato && k>=0 =>alla riga k/10 ho un numero di 
occorrenze di 'a' uguale a cont e cont non è pari,decremento k e 
quindi in A[(k+1)/10]..A[ultimariga] non ci sono righe di A con un 
numero pari di occorrenze di 'a' => vale R
trovato && k>=0 =>il precedente valore di cont per k+1 mi indica che 
alla riga (k+1)/10 avevo un numero di occorrenze pari di 'a' =>R

Condizione di uscita: 
-trovato=>A[(k+1)/10]=A[riga] è la prima riga tra 
A[(k+1)/10]..A[ultimariga] ad avere un numero pari di occorrenze di 
'a' (riga è quindi l'indice massimo della riga contenente un numero
di occorrenze pari di 'a') =>POST
-!trovato && k=-1 =>A[(k+1)/10]..A[ultimariga] non ci sono righe con
un numero pari di occorrenze di 'a'=>POST

*/
