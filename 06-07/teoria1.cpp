#include<iostream>
using namespace std;

int* f(int *& p){
	int b=0,*x=&b; 
	x=p+2; 
	p++; 
	return x-3; 
}
main() {
	int b[]={1,2,3,4,5},*q=b+2;
	*f(q)=*q; 
	cout<<b[0]<<b[1]<<b[2]<<b[3]<<b[4];
	//istruzioni per impedire l'immediata chiusura della finestra
	cin.clear();
	cin.ignore(255, '\n');
	cin.get();
}