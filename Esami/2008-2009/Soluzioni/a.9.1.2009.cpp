#include <iostream>
using namespace std;
//PRE: T definito con R*C elementi, P[dimP] definito .. 
void *F(int *T, int R, int C, int *P, int dimP, int *O){
	int ind=0; int ricorda=0;
	
	for(int i=0; i<R; i++){
		bool esci=false; 
		for(int j=0; j<C && !esci; j++){
			if(P[ind]==*(T+i*C+j)){
				ind++;
			}
			else
			if(ricorda!=ind)
			esci=true;
		}
		O[i]=ind-ricorda;
		ricorda=ind;
	}
}
//POST: O[i] è definito più o meno a caso
main(){
	int T[15]={0,0,0, 1,1,2, 2,3,0, 0,0,0, 0,4,5}, R=5, C=3, P[6]={1,2,3,4,5,6}, dimP=6;
	int O[R];
	F(T, R, C, P, dimP, O);

	for(int i=0; i<R; i++)
		cout << O[i] << " ";

	cout << endl;
}
