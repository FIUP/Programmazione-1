#include<iostream>
#include<fstream>
using namespace std;
main()
try
{
ifstream IN("inputarray.txt");
if(!IN)
	throw(0);
int B[7][8],C[7][8];
for(int i=0;i<7;i++)			//R	
	for(int j=0;j<8;j++)		//R'
		IN>>C[i][j];
IN.close();
//terminato di riempire l'array
for(int i=0;i<7;i++)						//R1
	for(int j=0;j<8;j++)					//R2
		{
		int somma=0;
		for(int k=0;k<8;k++)				//R3
			{
			bool trovato=false;
			for(int z=0;z<7 &&!trovato;z++)	//R4
				if(C[i][k]==C[z][j])
					trovato=true;
			if(!trovato)
				somma=somma+C[i][k];
			}
		B[i][j]=somma;
		}
}
catch(int x)
{
if(x==0)
	cout<<"errore nell'apertura del file di input"<<endl;
}
/*
PRE=(inputarray contiene almeno 56 interi)
POST=(per ogni a£[0..6] e per ogni b£[0..7] C[a][b] è definito)
R=(per ogni a£[0..i-1] e per ogni b£[0..7] C[a][b] è definito && 0<=i<=7)
Q=(per ogni b£[0..7] C[i][b] è definita)
R'=(per ogni b£[0..j-1] C[i][b] è definita && 0<=j<=8)
POST1=(per ogni a£[0..6],b£[0..7] B[a][b] è la somma degli elementi di C[a] che non sono anche in C[..][b])
R1=(per ogni a£[0..i.1],b£[0..7] B[a][b] è la somma degli elementi di C[a] che non sono anche in C[..][b] && 0<=i<=7)
POST2=(per ogni b£[0..7] B[i][b] è la somma degli elementi di C[i] che non sono anche in C[..][b])
R2=((per ogni b£[0..7] B[i][b] è la somma degli elementi di C[i] che non sono anche in C[..][b] && 0<=j<=8)
POST3=(per ogni a£[0..6],b£[0..7] somma contiene la somma di C[i][b] che non stanno anche in C[a][j])
R3=(per ogni a£[0..6],b£[0..k-1] somma contiene la somma di C[i][b] che non stanno anche in C[a][j] && 0<=k<=8)
POST4=(trovato sse esiste un a£[0..6] tale che C[i][b]==C[a][j])
R4=(trovato sse esiste un a£[0..z-1] tale che C[i][b]==C[a][j] && 0<=z<=7)
*/