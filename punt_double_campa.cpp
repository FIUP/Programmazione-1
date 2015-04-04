#include <iostream>
using namespace std;
main(){
	double F[3][5][7][9];
	cout << "Dimensione di F: " <<  sizeof(F) << endl;
	cout << "Dimensione di *F: " << sizeof(*F) << endl;
	cout << "Dimensione di **F: " << sizeof(**F) << endl;
	cout << "Dimensione di ***F: " << sizeof(***F) << endl;
	cout << "Dimensione di ****F: " << sizeof(****F) << endl;
	cout << "Dimensione di un double: " << sizeof(double) << endl;
		//istruzioni per impedire l'immediata chiusura della finestra
	cin.clear();
	cin.ignore(255, '\n');
	cin.get();
}