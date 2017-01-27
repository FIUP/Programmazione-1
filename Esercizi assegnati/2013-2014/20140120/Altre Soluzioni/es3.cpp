#include<iostream>
#include<fstream>
using namespace std;

main(){
	ifstream in("input");
	ofstream out("output");
	int n , a , b , n_use; 
	bool due0 = 0; 
	
	in>>n;
	
	if(!n) out<<n;
	if(n==1) {
		in>>a;
		out<<n<<" "<<a;
	}
	if(n==2) {
		in>>a;
		in>>b;
		if( (a && b) || (!a && b) || (a && !b))	out<<n<<" "<<a<<" "<<b;
		else out<<n;
	} else {
	
		in>>a;
		n_use = n-1;
		out<<n<<" ";
		
		while(n_use && !due0){
			in>>b;
			if(!b){
				if(!a) due0 = 1;
				else {
					out<<a<<" ";
					a = b;
				}
			} else {
					out<<a<<" ";
					a = b;
				}
			n_use--;	
			if(!n_use && !due0) out<<b;
		}
		in.close();
		out.close();
	}
}
