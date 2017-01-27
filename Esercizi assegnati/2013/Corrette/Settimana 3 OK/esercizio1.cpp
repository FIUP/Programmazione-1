//Matteo Gazzato 594140  ESERCITAZIONE DEL 31/1/2013 SETTIMANA 3
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream IN("input1");
	ofstream OUT("output1");

	char A[5][10];
	int dim;

	if(IN)
	{
		IN>>dim;
		int k=0;
		while(k<dim)
		{IN>>*(*A+k);k++;}		
		
		IN.close();
	}
	else
	cout<<"Errore,impossbile aprire il file di input"<<endl;

	bool trovato=false;
	int cont=0,contariga=0,k=0,riga;
	
	while(k<dim && !trovato)//R
	{
		if(*(*A+k)=='a')
			cont++;
		k++;
		if(k==dim || !(k%10))
		{	
			if(!(cont%2))
			{trovato=true;riga=contariga;}

			contariga++;		
			cont=0;
		}
	
	}//fine while
//POST
if(trovato)
	OUT<<trovato<<" "<<riga;
else
	OUT<<trovato;

OUT.close();
}//fine main	


/*
PRE=(A e' un array definito contenente dim caratteri && 0<dim<=50)

R=(trovato=>la riga di indice contariga-1 contiene un numero di 
occorenze pari di 'a' && in A[0]..A[contariga-2] non esistono righe 
di A con un numero pari di 'a') && (!trovato=>in A[0]..A[contariga-1]
non esistono righe di A con un numero pari di occorrenze di 'a') &&
0<=k<dim && 0<=contariga<5 && cont è il numero di occorrenze di 'a'
della riga contariga-1)

POST=(trovato=>riga e' l'indice minimo della riga contenente un 
numero pari di 'a' && (!trovato=>non esistono righe di A con un 
numero pari di 'a' && k==dim))

CORRETTEZZA:
PRE<ini;while(B)C>POST

PRE <ini> R cond iniziale
R && B <C>R invarianza
R && !B=>POST condizione d'uscita

Condizione iniziale: !trovato,cont=0 e contariga=0=>in A[0]..A[-1]
non esistono righe valide di A=> R trivialmente verificata poichè 
devo ancora iniziare ad esaminare A
Invarianza: !trovato &&k<dim=>cont,che è il numero di occorrenze di 
'a' della riga contariga,non è pari=>ho finito di esaminare la riga
contariga e passo alla riga successiva (contariga++),
reinizzializzando a zera il contatore della 'a' cont => correttamente
si ha ancora che in A[0]..A[contariga-1] non esistonon righe di A
con un numero di occorrenze pari di 'a'=>R
trovato && k<dim => cont è pari=> la riga contariga ha un numero di
occorrenze pari di 'a'=>incremento contariga=>contariga-1 è la prima 
riga che ha un numero pari di occorrenze di 'a' e sono sicuro che 
in A[0]..A[contariga-2] non ci sono altre righe con un numero pari
di 'a' per quanto detto in precedenza=>R

Condizione di uscita:
caso1: trovato=>A[contariga-1] contiene un numero pari di 'a'=>
riga=contariga=>POST
caso2: k==dim => se trovato=>A[contariga] contiene un numero 
pari di 'a'=>riga=contariga=>POST
se !trovato=>non ci sono righe di A contenenti un numero pari di 'a'
=>POST
*/

		

