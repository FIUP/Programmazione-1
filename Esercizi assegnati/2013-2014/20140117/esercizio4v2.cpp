//PRE2=("input" contiene n>1 seguito da n interi)

#include<iostream>
#include<fstream>
using namespace std;

main(){
	ifstream IN("input");
	ofstream OUT("output4v2");
	if(IN&&OUT){
		int n, primo, x;
		IN>>n>>primo;
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
	else 
		cout<<"Errore nell'apertura dei file"<<endl;
	IN.close();
	OUT.close();
 }

//POST4v2=(l'output contiene il secondo più grande)
