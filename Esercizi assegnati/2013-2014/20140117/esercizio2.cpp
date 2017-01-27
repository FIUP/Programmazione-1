//PRE2=("input" contiene un intero n>=0, seguito da n interi)

#include<iostream>
#include<fstream>
using namespace std;

main(){
	ifstream IN("input");
	ofstream OUT("output2");
	if(IN&&OUT){
		int n;
		IN>>n;
		if(n==0)
			OUT<<"n=0";
		else{
			int x;
			IN>>x;
			int max=x, i=1;
			while(i<n){
				IN>>x;
				if(x>max)
					max=x;
				i++;
			 }
			OUT<<n<<" "<<max;
		 }		
	 }
	else
		cout<<"Errore nell'apertura dei file"<<endl;
	IN.close();
	OUT.close();
 }

//POST2=(se n=0, "output" deve contenere la stringa "n=0", se n>0, "output" deve contenere n seguito dal massimo degli n valori che seguono su "input" il valore n)
