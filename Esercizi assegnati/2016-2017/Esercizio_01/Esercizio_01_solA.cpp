// soluzione di B.Cosentino
#include<iostream>

using namespace std;



int main()
{
    int x,y,z,M;
    cin >> x >> y >> z;
	if (x>=y){
			M=x;
	}else{
		M=y;
	}
	if (M<z){
		M=z;
	}
	cout << "il massimo e': ";
	cout << M << endl;
    cout << "end" << endl;
}
