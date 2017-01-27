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
for(int i=0;i<7;i++)			//R1
	for(int j=0;j<8;j++)		//R2
		{
		int somma=0,sommariga=0,sommacol=0;			//sommacol e sommariga usati per rendere più facili gli invarianti
		for(int k=0;k<8;k++)		//R3
			sommariga=sommariga+C[i][k];
		for(int z=0;z<7;z++)		//R4
			sommacol=sommacol+C[z][j];
		somma=sommariga-sommacol;
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
POST1=(per ogni a£[0..6],b£[0..7] B[a][b]=somma(C[a])-somma(C[..][b])
R1=(per ogni a£[0..i-1],b£[0..7] B[a][b]=somma(C[a])-somma(C[..][b] && 0<=i<=7)
POST2=(per ogni b£[0..7] B[i][b]=somma(C[i])-somma(C[..][b])
R2=(per ogni b£[0..j-1] B[i][b]=somma(C[i])-somma(C[..][b]) && 0<=j<=8)
POST3=(sommariga contiene la somma di C[i][0..7])
R3=(sommariga contiene la somma di C[i][0..k-1] && 0<=k<=8)
POST4=(sommacol contiene la somma di C[0..6][j])
R4=(sommacol contiene la somma di C[0..z-1][j] && 0<=z<=7)
 */