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
bool matchF(char*T,int dim,char *P,int dim_P)
{
bool trovato=false;
for(int c=0;c<dim-dim_P+1&&!trovato;c++)	//R1
	if(MT(T+c,P,dim_P))
		trovato=true;
return trovato;
}
/*
PRE=(T[0..dim-1] e P[0..dim_P-1] sono definiti e dim>0 e dim_P>0)
POST=(trovato sse T[0..dim-1] contiene un match di P)
R1=(trovato sse T[0..c-1] contiene un match di P && 0<=c<=dim-dim_P+1)
*/
bool G(char T[][15][15],int limite1,char* P,int dim_P)
{
bool trovato=false;
for(int f=0;f<15&&!trovato;f++)						//R1
	for(int s=0;s<limite1&&!trovato;s++)			//R2
		trovato=matchF(T[s][f],15,P,dim_P);
return trovato;
}
/*
PRE=(T è un array char [limite1][15][15] ed è definito e limite1>0 e P[0..dimP-1] è definito e dimP>0)
POST=(trovato sse T contiene una fetta tale che T[..][f] contiene un match di P)
R1=(trovato sse T contiene una fetta tale che T[..][0..f-1] contiene un match di P && 0<=f<=15)
R2=(trovato sse T contiene un match di P in T[0..s-1][f][0..14] && 0<=s<=15)
*/
main()
{
char T[10][15][15];
char P[10];
bool trovato=G(T,10,P,10);
if(trovato)
	cout<<"trovato un match di P su una fetta di T"<<endl;
else
	cout<<"non trovato nessun match di P su una fetta di T"<<endl;
}