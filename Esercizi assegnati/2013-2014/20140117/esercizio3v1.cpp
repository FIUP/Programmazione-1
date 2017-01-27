//PRE3=("input" contiene n>=0, seguito da (almeno) n interi)

#include<iostream>
#include<fstream>
#include<climits>
using namespace std;

main(){
	ifstream IN("input");
	ofstream OUT("output3v1");
	if(IN&&OUT){
		int n;
		IN>>n;
		if(n==0)
			OUT<<n<<" "<<INT_MIN<<" "<<INT_MAX;
		else{
			int x;
			IN>>x;
			int max=x, min=x, i=1;
			while(i<n){
				IN>>x;
				if(x>max)
					max=x;
				else if(x<min)
						min=x;
				i++;
			 }
			OUT<<n<<" "<<max<<" "<<min;
		 }		
	 }
	else
		cout<<"Errore nell'apertura dei file"<<endl;
	IN.close();
	OUT.close();
 }

/*POST3v1=("output" contiene sempre n, che, a seconda del valore di n, è seguito dai seguenti valori:
i) se n=0, è seguito da INT_MIN e INT_MAX,
ii) se n>=1, è seguito dal massimo e dal minimo dei valori che seguono n su "input")*/
