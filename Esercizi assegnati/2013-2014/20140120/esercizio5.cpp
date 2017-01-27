#include<iostream>
#include<fstream>
#include<climits>
using namespace std;

main(){
  ifstream IN("input");
  ofstream OUT("output");
  if(IN){
//PRE=("input" contiene un intero n>=0 seguito da x1...xn)
 
	int n, x, min1=INT_MAX, min2=INT_MAX, min3=INT_MAX;
	IN>>n;
	OUT<<n<<" ";
	if(n>2){
		while(n>0){
			IN>>x;
			if(x<min3)
			if(x<min2)
			if(x<min1){
			min3=min2;
			min2=min1;
			min1=x;
			}
			else{
			if(x!=min1){
			min3=min2;
			min2=x;
			}
			}
			else
			if(x!=min2)
     	min3=x;
      n=n-1;
		}
		OUT<<min3<<endl;
	}
	else
		OUT<<"Problema impossibile"<<endl;
	IN.close();
	OUT.close();
	}
	else
		cout<<"Errore nell'apertura del file"<<endl;
}

/* POST=("output" contiene n seguito da:
i) se in x1...xn ci sono almeno 3 valori distinti, allora su "output" va stampato il terz'ultimo valore di x1...xn (come definito prima))
ii) se in x1...xn ci sono meno di 3 valori distinti, allora su "output" va stampato INT_MAX)*/
