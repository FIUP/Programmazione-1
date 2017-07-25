#include<iostream>
using namespace std;
main(){
	int C[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int x=0,cont=0,i=0;
	bool fine = false;
	
	cout << "Inserire 20 interi: " << endl;
	cin >> x;
	while(!fine && i<20){
		if(x==-1)
			fine = true;
		else {
			C[i] = x;
			cout << C[i] << " ";
			cont++;
			cin >> x;
		}
		i++;
	}
	
	cout << endl;
	cout << "Valori letti " << cont << endl;
	
	cin.clear();
	cin.ignore(255, '\n');
	cin.get();
}