#include<iostream>
using namespace std;

main() {
	int x=3, *pi; double y=3.1,*pd=&y;
	cout << "Prima: "<<endl;
	cout << " x = " << x<<endl;
	cout << " y = " << y<<endl;	
	cout << "Dopo: "<<endl;
	x=y; pi=reinterpret_cast<int*>(pd);
	cout << " x = " << x<<endl;
	cout << " pd = " << *pd<<endl;	
	cout << " pi = " << *pi<<endl;	
	//istruzioni per impedire l'immediata chiusura della finestra
	cin.clear();
	cin.ignore(255, '\n');
	cin.get();
}