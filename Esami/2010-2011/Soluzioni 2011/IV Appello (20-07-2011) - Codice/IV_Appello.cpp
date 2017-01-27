#include <iostream>
using namespace std;

//iterativo
void stampa(int indice,int *M,int k){
	for(int i=indice;i<k;i++){
		cout<<M[i]<<" ";
	}
}

void G(int k){
	int x=0,indice=0, *M=new int[k];
	
	cin>>x;
	
	while(x!=-2){
		if(indice<k){
			M[indice]=x;
		}
		else{
			indice=0;
			M[indice]=x;
		}
		indice++;
		cin>>x;
	}
	
	if(indice>0)
		stampa(indice,M,k);
	stampa(0,M,indice);
}

//ricorsivo
void stamparic(int index,int *M,int k){
	if(index<k){
		cout<<M[index]<<" ";
		stamparic(index+1,M,k);
	}
}

void Gric(int k,int *M,int index, int count){
	int x=0;
	cin>>x;
	if(x==-2){
		if(count>k) stamparic(index,M,k);
		stamparic(0,M,index);
	}
	else{
		if(index==k) index=0;
		M[index]=x;
		Gric(k,M,index+1,count+1);
	}
}

int main(){
	int k=2,index=0,count=0;
	int *M2=new int[k];
		
	//G(k);
	Gric(k,M2,index,count);
}
