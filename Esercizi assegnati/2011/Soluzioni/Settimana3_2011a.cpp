#include<iostream>
using namespace std;
bool uguali(int*A,int*B,int ele)
{
bool ok=true;
for(int i=0;i<ele && ok;i++)			//R1
	if(A[i]!=B[i])
		ok=false;
return ok;
}
/*
PRE=(A[0..ele-1] e B[0..ele-1] sono definiti e ele>0)
POST=(ok sse A[0..ele-1]=B[0..ele-1])
R1=(ok sse A[0..i-1]=b[0..i-1] && 0<=i<=ele)
*/
bool F(int A[][8][9],int B[][8][9],int limite_1,int n_ele)
{
int nsp=n_ele/(8*9);
int eus=n_ele%(8*9);
bool trovato=false;
for(int i=0;i<nsp&&!trovato;i++)			//R1
	for(int j=i;j<nsp&&!trovato;j++)		//R2
		if(uguali(**(A+i),**(B+j),8*9))
			trovato=true;
if(!trovato && eus>0)
	trovato=uguali(**(A+nsp),**(B+nsp),eus);
return trovato;
}
/*
PRE=(A e B sono due array int [limite_1][8][9] con limite_1>0 e solo i primi n_ele di A e B sono definiti && 0<=ele<=limite_1*8*9)
POST=(trovato sse esistono due strati a e b tali che A[a]=B[b] per ogni elemento e a,b£[0..strp-1] e a,b sono strp)
R1=(trovato sse esistono due indici a,b£[0..nsp-1] tali che A[a][0..7][0..8]=B[b][0..7][0..8])
R2=(trovato sse esiste un indice b£[i..nsp-1] tale cha A[i][0..7][0..8]=B[b][0..7][0..8])
*/
main()
{
int A[4][8][9],B[4][8][9];
int ele;
cin>>ele;
bool find=F(A,B,4,ele);
if(find)
	cout<<"sono presenti due strati uguali"<<endl;
else
	cout<<"non sono presenti due strati uguali"<<endl;
}