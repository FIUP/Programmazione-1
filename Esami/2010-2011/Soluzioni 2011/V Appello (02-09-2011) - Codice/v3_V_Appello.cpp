#include <iostream>
using namespace std;
int* F(int*T, int n, int* P);

int main(){
	int n=3, T[9]={7,9,2,8,8,4,10,8,10}, P[3]={8,8,10};
	
	int *R=F(T,n,P);
	
	if(R){
		for(int i=0;i<n;i++)
			cout<<R[i]<<" ";
		cout<<endl;
	}
	else cout<<"No match"<<endl;
}

int* F(int*T, int n, int* P){
	cout<<"prova";
	int R[n];
	for(int i=0; i<n;i++){
		bool found = false;
		for(int j= i;j<n && !found;j++){
			cout<<i<<" "<<j<<endl;
			if(T[i*j*n]==P[j];){
				cout<<"found"<<endl;
				R[j]=i;
				found = true;
			}
		}
	}
}