#include<iostream>
using namespace std;
bool MT(char* T,char*P,int dim_P)
{
bool ok=true;
for(int i=0;i<dim_P&&ok;i++)
	if(T[i]!=P[i])
		ok=false;
return ok;
}
/*
PRE=(T[0..dim_P-1] e P[0..dim_P-1] sono completamente definiti e dim_P>0)
POST=(ok sse T[0..dim_P-1]=P[0..dim_P-1])
R1=(ok sse T[0..i-1]=P[0..i.1] && 0<=i<=dim_P)
*/
int nmatchS(char* T,int limite,char*P,int dim_P)
{
int nmatch=0,incr=1;
for(int i=0;i<limite-dim_P+1;i+=incr)
	if(MT(T+i,P,dim_P))
		{
		nmatch++;
		incr=dim_P;
		}
	else
		incr=1;
return nmatch;
}
/*
PRE=(T[0..limite-1] e P[0..dim_P-1] sono definiti e inoltre limite>0 e dim_P>0)
POST=(nmatch contiene il numero di match non sovrapposti di P in T[0..limite-1])
R1=(nmatch contiene il numero di match non sovrapposti di P in T[0..i-1] && 0<=i<=limite-dim_P+1)
*/ 
int F(char T[][15][15],int limite1,char P[],int dim_P)
{
bool trovato=false;
int indice=-1;			//non è ancora stato trovato lo strato
for(int i=0;i<limite1&&!trovato;i++)			//R1
	{
	int n=0;
	n=nmatchS(**(T+i),225,P,dim_P);
	if(n>=2)
		{
		trovato=true;
		indice=i;
		}
	}
return indice;
}
/*
PRE=(T è un array char T[limite1][15][15] completamente definito e limite1>0 e P[0..dim_P-1] è definito e dim_P>0)
POST=(indice contiene l'indice di uno strato di T avente almeno 2 match di P non sovrapposti, se tale
	strato non esiste indice=-1)
R1=(trovato sse T[0..i-1] contiene uno strato con almeno 2 match di P non sovrapposti e indice=i-1 && 0<=i<=limite1
	altrimenti indice=-1)
*/
main()
{
char T[10][15][15];
char P[10];
int index=F(T,10,P,10);
cout<<index<<endl;
}