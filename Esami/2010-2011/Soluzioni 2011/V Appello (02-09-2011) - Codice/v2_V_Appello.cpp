#include <iostream>
using namespace std;

//iterativa
int *F(int *T,int n,int *P){
	int *R=new int[n],c=0,cont=0;
	bool stop=false;
	for(int i=0;i<n && !stop;i++){
		bool trovato=false;
		for(int j=c;j<n && !trovato;j++){
			if(T[j*n+i]==P[i]){
				R[i]=j;
				c=j;
				trovato=true;
				cont++;
			}			
		}
		if(!trovato)stop=true;
	}
	
	if(cont==n) return R;
	else return 0;
}

//ricorsiva
//int *Fric(int *T,int n,int* P,int *R,int indice){}

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
