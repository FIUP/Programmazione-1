//PRE1=("input" contiene n>=0 seguito da n interi)

#include<iostream>
#include<fstream>
using namespace std;

main(){
	ifstream IN("input");
	ofstream OUT("output4v1");
	if(IN&&OUT){
		int n;
		IN>>n;
		if(n>=2){
			int primo, x;
			IN>>primo;
			int i=1, secondo=primo;
			while(i<n){
				IN>>x;
				if(x>primo){
					secondo=primo;
					primo=x;
				 }
				else if(x>secondo)
						secondo=x;
				i++;
			 }
			OUT<<secondo;
		 }
		else{
			if(n==0)
				OUT<<"error 0";
			else //n==1
				OUT<<"error 1";
		 }
	 }
	else 
		cout<<"Errore nell'apertura dei file"<<endl;
	IN.close();
	OUT.close();
 }

/*POST4v1=(l'output contiene:
i) il secondo valore più grande se n>2
ii) "error 1" se c'è solo un elemento
iii) "error 0" se non ci sono elementi)*/
