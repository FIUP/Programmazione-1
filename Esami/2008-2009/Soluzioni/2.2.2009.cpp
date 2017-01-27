#include<iostream>
using namespace std;
main(){
		int x=500,a=250, risp;
		char pensato;
	cout << "Houdini: Pensa un numero tra 0 e 1000 :)" << endl;
	cout << "Houdini: Fatto?? allora premi un tasto magico e invio!"<<endl;
	cin>>pensato;
	cout << "Houdini: il numero è " << x << "?"<< "  (SI = 0 / NO è maggiore = 1 / NO è minore = -1)"<<endl;
	cin >> risp;
	while(risp !=0)
	{
	if(risp==-1)
	{x=x-a; cout << "Houdini: il numero è " << x << "?"<<endl;}
	if(risp==1)
	{x=x+a; cout << "Houdini: il numero è " << x << "?"<<endl;}
	if(a>1)
	a=a/2;
	cin >> risp;
	}
cout<< "Houdini: il numero magico è "<< x <<endl<<"GRANDE MAGO!!!!"<< endl;
}
