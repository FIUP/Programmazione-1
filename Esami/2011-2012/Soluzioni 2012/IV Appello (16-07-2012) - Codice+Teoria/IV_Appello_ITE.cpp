#include<iostream>
using namespace std;
bool M(char* T,int dimT,char* P,int dimP,int inizio,int &fine)
{
if(T[inizio]!=P[0])
	return false;
int p=1;
for(int i=inizio+1;i<dimT&&p<dimP;i++)	//R
	if(T[i]==P[p])
		{
		p++;
		fine=i;
		}
if(p==dimP)
	return true;
else
	return false;
}
/*
PRE=(T e P sono array di caratteri,rispettivamente, di dimT e dimP elementi tutti definiti,inizio è in T[0..dimT-1])
POST=(la funzione restituisce true sse esiste un match completo e tale che T[inizio]=P[0];inoltre in questo caso, T[fine]=P[dimP-1]
      e quello trovato è il match a bilancio minimo che inizia nella posizione inizio)
R=(trovato match di P[0..p-1] in T[inizio..i-1] e questo match è a bilancio minimo)

*/
int match(char*T,int dimT,char*P,int dimP)
{
int x=-1;
for(int i=0;i<dimT-dimP+1&&x!=0;i++)
	{
	int fine;
	bool b=M(T,dimT,P,dimP,i,fine);
	if(b)
		{
		int bil=(fine-i)+1-dimP;
		if(x=-1||x>bil)
			x=bil;
		}
	}
return x;
}
/*
PRE=(T e P sono array di caratteri ed hanno rispettivamente dimT e dimP elementi dove dimT>0 e dimP>0)
POST=(la funzione restituisce un intero x tale che se x>=0 allora esiste in T almeno un match di P e x è il bilancio minimo
      tra i match esistenti,se invece x=-1 allora non esiste alcun match)
*/
main()
{

}
