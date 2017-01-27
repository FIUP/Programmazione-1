#include <iostream>
#include<fstream>
#include<limits.h>
using namespace std;

main ()
{ ifstream IN("input2.txt");
  ofstream OUT("output.txt");

  int x, max=INT_MIN, i=0,secondo;
	while(x!=-1)
	{
		IN >> x;
		i++;
		if(x>max)
		 max=x;
		if(i==2) 
		 secondo=x;
	}	
	if(i==1)
	OUT<<"non c'è nessun numero"<<endl;
	if(i==2)
	OUT<<"il massimo è "<< max<<" e non c'è il secondo numero"<<endl;
	if(i>2)
	OUT<<"il massimo è "<< max<<" il secondo numero è "<<secondo<<endl;

	IN.close();
	OUT.close();
	
}
