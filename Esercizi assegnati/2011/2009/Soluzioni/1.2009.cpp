#include<iostream>
#include<fstream>
using namespace std;

main()
try // apertura file
{
ifstream IN("input1.txt");
ofstream OUT("output.txt");
if(! IN || ! OUT)
throw (0);

char prendi;
double numero =0; int n=0;
IN>>prendi;
while (prendi != ';')
	{ 
	 numero=numero*10 + (prendi - '0'); n++;
	 IN>>prendi;
	}
int j=0;
 while(j<n) 
	{ numero = numero/10;
	  j++;
	}
OUT<< numero<<endl;
IN.close();
int i=0;
  while(numero!=0 && i<23)
	{
		numero=numero*2;
		if(numero>=1) 
		{numero--;
		 OUT<< "1";
		 }
		else
		 OUT<<"0";
		i++;
	}
OUT.close();

}
catch(int x){cout<<"problemi con i file"<< x <<endl;}

