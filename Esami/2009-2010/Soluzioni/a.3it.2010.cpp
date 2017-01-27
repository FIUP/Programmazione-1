#include<iostream>
#include<limits.h>
using namespace std;

void M(int (*A)[20], int* Inizio, int limite, int & r, int & k)
{	
	int rigaM=0, min=INT_MAX;
									  //R: 0<=i<=limite,  per ogni a in [0..i] min è l'elemento minimo tra elementi A[a][inizio[a]] 
									//e rigaM = è l'indice di min
	for(int i=0;i<limite;i++)		 
		if(Inizio[i]<20)	 		  //POST: per ogni a in [0..limite-1] min è l'elemento minimo tra elementi A[a][inizio[a]] e rigaM = è l'indice
		  if(A[i][Inizio[i]]<min)	  // di min
			{min=A[i][Inizio[i]];
			 rigaM=i;
			}

	r=rigaM;
	k=Inizio[rigaM];
	Inizio[rigaM]++;
}

int * F(int(*A)[20],int limite)
{
int *R=new int[limite*20], *Inizio=new int[limite], r=0,k=0;
for(int i=0; i<limite; i++) 
	Inizio[i]=0;
for(int i=0; i<limite*20; i++)
  {
	M(A,Inizio,limite,r,k);
	R[i]=A[r][k];
  }
delete[] Inizio;
return R;
}

main()
{
    int A[10][20];
	for(int i=0;i<10;i++)
		for(int j=0;j<20;j++)
			A[i][j]=j;
		
     for(int i=0;i<10;i++)
		{for(int j=0;j<20;j++)
			cout<<A[i][j]<<" ";
		    cout<<endl;
}
    int *R= F(A, 10);
    for(int i=0;i<10;i++)
    {		
         for(int j=0;j<20;j++)
         cout<<R[i*20+j]<< " ";
	     cout<<endl;
    }
    system("PAUSE");
}
