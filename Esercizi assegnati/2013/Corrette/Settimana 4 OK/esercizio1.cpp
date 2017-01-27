//Matteo Gazzato 594140  ESERCITAZIONE DEL 7/2/2013 SETTIMANA 4
/*
TEORIA:
	int A[5][10][20] ha tipo int(*)[10][20] e dimensione 10*20*4 byte
	(*A)[2] ha tipo int(*)[20] e valore A+2*20*4
	(A[-10])+1==*(A-10)+1 ha tipo int(*)[20] e valore A-(10*10*20*4)+1*20*4  
	(**A)-20 ha tipo int(*) e valore A-20*4
*/

#include <iostream>
#include <fstream>

using namespace std;

void R(int *A,int dim,int lim1,int lim2,int r,ofstream& OUT)
{
	int X[lim1][lim2],k=0;

	for(int i=0;i<lim1 && k<dim;i++)
	{//R1
		for(int j=0;j<lim2 && k<dim;j++)
		{//R2
			X[i][j]=*(A+k);
			k++;	
		}	
	}
//R1=(le righe 0..i-1 di X sono state riempite con i primi 
//lim2*(i-1) elementi di A && k<dim && 0<=i<lim1)
//R2=(X[i][0]=A[lim2*(i-1)+1],X[i][1]=A[lim2*(i-1)+2]...X[i][j-1]=
//A[lim2*(i-1)+k-1] && k<dim && 0<=j<lim2)
//POST1=(X[lim1][lim2] è stato riempito con i primi k elementi di A)

//(dim/lim2) e' il numero di righe completamente riempite di X
//(dim%lim2) sono il numero di elementi dell'ultima riga parzialmente
// riempita
		

//r è l'indice di una riga definita (totalmente o parzialmente)
	if(r<=dim/lim2)
	{
//r è l'indice della riga parzialmente definita(l'ultima riga) && 
//c'è almeno un elemento in tale riga		
//=> considero solo i primi dim%lim2 elementi 
			if(r==dim/lim2 && dim%lim2>0)											
			{							 		
				for(int i=0;i<(dim%lim2);i++)
				OUT<<X[r][i]<<" ";			
			}
			else
//r è l'indice di una riga completamente definita=>
//considero gli elementi da 0..lim2-1
			{		
				for(int i=0;i<lim2;i++)
				OUT<<X[r][i]<<" ";
			}	
	}//r è l'indice di una riga non definita	
	else
		OUT<<"-"<<r<<" ";
	
	
}//fine R

void C(int *A,int dim,int lim1,int lim2,int c,ofstream& OUT)
{
	int X[lim1][lim2],k=0;

	for(int i=0;i<lim1 && k<=dim;i++)
	{//R1
		for(int j=0;j<lim2 && k<=dim;j++)
		{//R2
			X[i][j]=*(A+k);
			k++;	
		}	
	}

	//(dim/lim2) "altezza" massima delle colonne  
	//(dim%lim2): le colonne 0..(dim%lim2)-1 hanno "altezza" dim/lim2 

	if(c<dim%lim2) //c è l'indice di una colonna di "altezza massima"
	{
		for(int i=0;i<=(dim/lim2);i++)
		OUT<<X[i][c]<<" ";
	}
	else
	{	
//caso in cui ho colonne non definite,cioè solo la prima riga di X è 
//parzialmente definita		
		if(!(dim/lim2)) 
			OUT<<"-"<<c<<" ";
		else
		{
			for(int i=0;i<(dim/lim2);i++) 
				OUT<<X[i][c]<<" ";
		}
	}

}//fine C

int main(){

	ifstream IN("input1");
	ofstream OUT("output1");
	int A[400],dim,lim1,lim2,r1,r2,c1,c2; 

	if(IN)
	{
		IN>>dim;
		for(int k=0;k<dim;k++)
			IN>>A[k];
		
		IN>>lim1;IN>>lim2;IN>>r1;IN>>r2;IN>>c1;IN>>c2;
		
		IN.close();
	}
	else
		cout<<"Errore,impossibile aprire il file di input!"<<endl;

	R(A,dim,lim1,lim2,r1,OUT);
	R(A,dim,lim1,lim2,r2,OUT);
	C(A,dim,lim1,lim2,c1,OUT);
	C(A,dim,lim1,lim2,c2,OUT);
	
OUT.close();
}//fine main

/*
PRE_R=(A[0..dim-1] definita,dim>0, lim1>0, lim2>0, r in [0..lim1-1])

R_R=(X è stato riempito con i primi k elementi di A && dim/lim2 e' 
il numero di righe completamente riempite di X && dim%lim2 sono il 
numero di elementi dell'ultima riga parzialmente riempita && 
(r==dim/lim2 && dim%lim2>0=>per ogni x∈X[r][0]..X[r][i-1] x è stato 
stampato su OUT && X[r][0]..X[r][i-1] sono elementi definiti && 
0<=i<dim%lim2) && (r<dim/lim2=>per ogni x∈X[r][0]..X[r][i-1] x è 
stato stampato su OUT && X[r][0]..X[r][i-1] sono elementi definiti 
&& 0<=i<lim2)

POST_R=(stampa su OUT gli elementi definiti della riga r di X)

PRE_C è simile alla PRE_R con c in [0..lim2-1] al posto di r.

R_C=(X è stato riempito con i primi k elementi di A && dim/lim2 è 
"l'altezza" massima delle colonne di X && dim%lim2 sono le colonne 
che hanno "altezza" dim/lim2  && (c<dim%lim2=>per ogni 
x∈X[0][c]..X[i-1][c] x è stato stampato su OUT && X[0][c]..X[i-1][c]
sono elementi definiti && 0<=i<=dim/lim2) && 
(c>=dim%lim2=>per ogni x∈X[0][c]..X[i-1][c] x è stato stampato su OUT 
&& X[0][c]..X[i-1][c] sono elementi definiti && 0<=i<dim/lim2))

POST_C=(stampa su OUT gli elementi definiti della colonna c)
*/ 
