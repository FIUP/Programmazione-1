// soluzione di B.Cosentino
#include<iostream>
using namespace std;
//PRE: cin contiene 10 interi
int main() {
	int X[10];
	
	for (int i=0; i<10; i=i+1) { //R: 0<=i<=10 && (ho letto gli interi da X[0] a X[i-1])
		cin >> X[i];
	 }
	for (int i=9; i>=0; i=i-1) { //R: -1<=i<=9 && (ho scritto gli interi da X[9] a X[i+1])
		cout << X[i] << " ";
	}


    cout << endl << "end" << endl;
}
//POST: ho scritto gli interi da X[9] a X[0] in ordine inverso 
