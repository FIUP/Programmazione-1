#include <iostream>
#include <limits.h>
using namespace std;

int match(char *T, int dim_T,char *P, int dim_P,int i)
{int temp=0; bool trovato;
 for(int j=1;j<dim_P;j++)
	{ trovato=false;
	for(int k=i+1;k<dim_T-(dim_P-j-1) && !trovato;k++)
		if(P[j]==T[k])
		{trovato=true;
		 temp=temp+ (k-1-i);
		 i=k;
		}
	}
 if(!trovato) temp=INT_MAX;
	return temp;
}

bool F(char *T, int dim_T,char *P, int dim_P,int &min,int &indice){
	int lung;
	bool trovato=false,stop=false;
	for(int i=0; i<dim_T-dim_P+1; i++)//&&!stop
		if(T[i]==P[0])
		 { lung= match(T,dim_T,P,dim_P,i);
		   if(lung<min)
			{min=lung;
			 indice=i;
			trovato=true;
			}
			//if(lung =INT_MAX)
			//stop=true;
		}	
	return trovato;
}
 
main()
{
char T[7]={'a','b','b','a','b','a','b'}, P[3]={'a','a','b'};
int dim_T=7, dim_P=3, min=INT_MAX,indice=-1;
	cout<< F(T, dim_T, P, dim_P, min, indice);
	cout <<" "<<min << " " << indice << endl;
}
