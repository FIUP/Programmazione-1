//PRE3=("input" contiene n>1 seguito da n valori interi)

#include<iostream>
#include<fstream>
using namespace std;

main(){
	ifstream IN("input");
	ofstream OUT("output3v3");
	if(IN&&OUT){
		int n, x;
		IN>>n>>x;	
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
	else
		cout<<"Errore nell'apertura dei file"<<endl;
	IN.close();
	OUT.close();
 }

/*POST3v3=("output" contiene n seguito dal massimo e dal minimo degli n valori che seguono n su "input")*/
