#include<iostream>
#include<fstream>
#include<climits>
using namespace std;

main(){
ifstream in("input");
ofstream out("output");

int n , n_use , a = INT_MAX, b = INT_MAX, c = INT_MAX , input;
int x1 , x2 , x3 ; // variabile necessarie per lo switch di variabile 

if(in && out){
	in>>n;
	n_use = n;
	if(n>2){	//PRE
		while ( n_use ) {
		in>>input;
			if(input < a){
				x1 = a;
				a = input;
				x2 = b; 
				b = x1; 
				x3 = c; 
				c = x2;
			} else {
				if(input < b){
					 x2 = b; 
					 b = input;
					 x3 = c;
					 c = x2;
				} else {
					if(input < c){
						x3 = c ; 
						c = input;
					}
				}
			}
			n_use--;
		}
		out<<n<<" "<<c;	//POST ii
	} else out<<n<<" problema impossibile"<<endl; 	//POST i
	in.close();
	out.close();
} else cout<<"problemi con i file di lettura / scrittura "<<endl;

}

/*
PRE =("input contiene un intero n qualsiasi seguito da n interi ")

R = ( n_use >= 0 && 0<=n_use<=n n-n_use valori && a <= b <= c ) 
POST=("output" contiene n, seguito da:
i) se n<=2, la stringa "problema impossibile"
ii) se n>2, il terz'ultimo valore de gli n letti)
*/
