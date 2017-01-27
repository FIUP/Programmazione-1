//Matteo Gazzato 594140  ESERCITAZIONE DEL 23/1/2013 SETTIMANA 2
#include <iostream>
#include <fstream>

using namespace std;
//PRE1
int main()
{
	int dim,dimP;
	char T[100],P[20];
	
	ifstream IN("input1.txt");
	ofstream OUT("output1.txt");
	if(IN!=0)
	{
		IN>>dim;
		IN>>dimP;
			for(int k=0;k<dim;k++)
				IN>>T[k];
			for(int k=0;k<dimP;k++)
				IN>>P[k];
		IN.close();
	}
	else
		cout<<"Errore,impossibile aprire il file di input!"<<endl;
		
	bool trovato=false;
	int p=0,indice,k=0;
while(k<(dim-dimP+1) && !trovato)//R1
{
	if(T[k]==P[p])
	{
			int k1=k;
			p++;
			k1++;
			bool ok=true;
			while(p<dimP && ok)//R2
			{
				if(T[k1]==P[p])
					{p++;k1++;}
//k1<k+dimP perchè rispetto all'indice k-esimo da cui inizia il 
//possibile match al massimo potrò arrivare a k+dimP-1 in caso di
//match completo 
				else			
					ok=false;
			}
			//POST2
			if(ok)
			{trovato=true;indice=k;}
			else
				{k=k+1;p=0;}
	
	}
	else
	{
		p=0;
		k++;
	}
		
	
}
	
if(trovato)
{
	OUT<<trovato<<" ";
	OUT<<indice;
}
else
	OUT<<trovato;
OUT.close();
}//fine main
//POST1

/*
PRE1=(T è un array di dimensione 100 contenente dim caratteri, con 
1<=dim<=100.P è un array di dimensione 20 contenente dimP caratteri, 
con 1<=dimP<=20.I dim e dimP caratteri sono presi dal file 
input1.txt.)

R1=(0<=k<dim-dimP+1 && (!trovato=>non esiste match con inizio in 
[0..k-1] && in T[0..k-1] non c'è match) && (trovato=> esiste match
 con inizio in T[inizio] ed è l'unico match che inizia in 
T[0..inizio-1]))

R2=(ok=>T[k..k+k1-1]=P[0..p-1] && !ok=>T[k1]!=P[p] && k<=k1<(k+dimP)
&& 0<=p<dimP )

POST2=(ok=>trovato=true (match valido a partire da k) && !ok=>k=k+1,
p=0 (non c'è match valido a partire da k,riprendo la ricerca dal
successivo))

POST1=(trovato=>esiste un match,il primo match valido trovato è 
quello da T[indice] && !trovato=>non esiste alcun match di P in T)

CORRETTEZZA (R2,POST2):

invarianza: se c'è match tra T[k1] e P[p] incremento p e k1=>ancora
 si ha che T[k..k+k1-1]=P[0..p-1] && p<dimP,ok non è stato variato
=>ok =>vale ancora R2

caso di uscita: -p=dimP && ok=>ho trovato un match completo a partire
da k,in particolare T[k..dimP-1]=P[0..dimP-1]=>POST2
-ok=false && p<dimP => non c'è match completo a partire da k,poichè 
T[k1]!=P[p],riprendo la ricerca da T[k+1] =>POST2

CORRETTEZZA (PRE1,R1,POST1):

caso iniziale:k=0,trovato=false trivialmente corretta in quanto in 
T[0..-1] non possono esistere match =>R1				

invarianza:controllo l'elemento k-esimo di T dal quale può ancora 
iniziare un match,in caso di match non valido (incompleto) incremento
 k,che è ancora un indice di T da cui può iniziare un match valido 
(k<dim-dimP+1) && !trovato=>R1  
Se invece da POST2 ottengo ok=true =>trovato=>c'è un match valido e
completo a partire da T[inizio] ed è l'unico che inizia in 
T[0..inizio-1]=>R1

caso di uscita:trovato=>ho trovato un match valido e completo a 
partire da T[inizio] ed è il primo che è stato trovato=>POST1
-k=dim-dimP+1 && !trovato =>non è stato trovato alcun match valido
 di P in T tra T[0]..[k-1] tra T[0..dim-dimP+1]=>POST1
*/
