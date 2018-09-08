#include<iostream>
using namespace std;

//pre:

int main() {

    cout << "start" << endl;

	//punti Q e P
	int x1, x2;
	int y1, y2;
	cin >> x1 >> y1;
	cin >> x2 >> y2;

	int d1, d2;
	d1 = x2-x1;
	d2 = y2-y1;

	if (d1 < 0)
		d1 = d1 * (-1);
	if (d2 < 0)
		d2 = d2 * (-1);

	int nrighe, spazi;
	if (d1 == d2) {
		nrighe = d1;
		if (((x2>x1) && (y2>y1)) || ((x2<x1) && (y2<y1))) {
    		while (nrighe > 0) {
    			spazi = nrighe-1;
    			while(spazi > 0) {
    				cout << "b";
    		    	spazi--;
    			}
    			cout << "s" << endl;
    			nrighe--;
    		}
		}
		else if (((x2<x1) && (y2>y1)) || ((x2>x1) && (y2<y1))) {
			int i = 0;
			while (nrighe > 0) {
				spazi = 0;
				while(spazi < i) {
					cout << "b";
			    	spazi++;
				}
				i++;

				cout << "s" << endl;
				nrighe--;
		    	}
	    	}
	}
	else
		cout << "Le coordinate immesse non formano la diagonale di un quadrato" << endl;
	cout<< "end";

	return 0;
}
