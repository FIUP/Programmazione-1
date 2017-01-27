//Matteo Gazzato 594140  ESERCITAZIONE DEL 23/1/2013 SETTIMANA 2
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int dim,dimP;
	char T[100],P[20];
	
	ifstream IN("input2.txt");
	ofstream OUT("output2.txt");
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
int p=0,k=0,Nmatch=0;

while(k<dim-dimP+1)//R1
{
	if(T[k]==P[p])
	{
//mi ricordo dove sono arrivato ad analizzare in T,in caso di mancato
//match
		int k1=k;
		k1++;
		p++;
		bool ok=true;
		while(p<dimP && ok)//R2
		{
			if(T[k1]==P[p])
//vedo se c'è match completo o solo parziale
			{k1++;p++;}
			else
				ok=false;
		}
		if(ok)
			{Nmatch++;k=k+dimP;}
//se va bene conto il match e salto di dimP posti
//poichè i match non possono essere sovrapposti	
		else					
			{k=k+1;p=0;}
	}
	else
	{k++;p=0;}
}
OUT<<Nmatch;
OUT.close();	
}//fine main

/*
NB:due match T[i1..j1] e T[i2..j2] non sono sovrapposti se i2>j1 
oppure se i1>j2

PRE=(T è un array di dimensione 100 contenente dim caratteri, con 
1<=dim<=100.P è un array di dimensione 20 contenente dimP caratteri,
con 1<=dimP<=20.I dim e dimP caratteri sono presi dal file 
input2.txt.)

R1=(0<=k<dim-dimP+1 && Nmatch è il numero di match non sovrapposti 
di P in T trovati in T[0..k-1]

R2=(ok=> T[k..k+k1-1]=P[0..p-1]..T[k1] && !ok=>T[k1]!=P[p] && 
1<=p<dimP && k<=k1<k+dimP)

POST2=(ok=>ho trovato un match valido e lo conto incrementando Nmatch
&& continuo ad esaminare T dall'indice k+dimP per non trovare match 
sovrapposti)

POST=(Il file output2.txt contiene gli Nmatch match non sovrapposti 
di P in T)
*/




