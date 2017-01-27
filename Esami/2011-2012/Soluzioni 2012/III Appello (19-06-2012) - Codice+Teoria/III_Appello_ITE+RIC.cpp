 #include <iostream>
using namespace std;

//iterativa
int matchR(int *T,int dimR,int *P,int dimP){
	int i=0,cont=0;
	while(i<dimR && T[i]!=P[0])
		i++;
		
	if(i<dimR){
		cont++;
		for(int j=i+1;j<dimR && cont<dimP && T[j]==P[cont];j++)
			cont++;
	}
	return cont;
}
/*Alternativa matchR
int matchR(int *T, int dimr,int *P,int dimP){
	int x=0;
	bool match=false,stop=false;
	for(int i=0;i<dimr && dimP>0 && !stop;i++){
		if(T[i]==*P){
			x++;
			*P=*P+1;
			dimP--;
			match=true;
		}
		else{
			if(match) stop=true;
		}	
	}
	return x;
}
*/

void F(int *T,int R,int C,int *P,int dimP,int *Q){
	int scorri=0;
	for(int i=0;i<R && scorri<dimP;i++){
		int x=matchR(T+i*C,C,P+scorri,dimP-scorri);
		Q[i]=x;
		scorri=scorri+x;
	}
}




//ricorsiva
int trova(int *T,int C,int val,int indice=0){
	if(indice>=C) return C;
	
	if(T[indice]==val){
		return indice;
	}
	else{
		return trova(T,C,val,indice+1);
	}
}

int resto(int *T,int C,int *P,int dimP){
	if(!C || !dimP) return 0;
	
	if(*T==*P) return 1+resto(T+1,C-1,P+1,dimP-1);
	else return 0;
}

int matchRR(int *T,int C,int *P,int dimP){
	int inizio=0;
	inizio=trova(T,C,P[0]);
	
	if(inizio<C){
		return 1+resto(T+inizio+1,C-inizio-1,P+1,dimP-1);
	}
	else
		return 0;
}

void FR(int *T,int dimT,int C,int *Q,int *P,int dimP){
	if(!dimT || !dimP) return;
	int x=matchRR(T,C,P,dimP);
	*Q=x;
	FR(T+C,dimT-C,C,Q+1,P+x,dimP-x);
}




int main(){
	int T[15]={0,0,0,1,1,2,2,3,0,0,0,0,0,4,5};
	int R=5,C=3,P[6]={1,2,3,4,5,6},dimP=6,Q[5]={};
	
	F(T,R,C,P,dimP,Q);
	FR(T,R,C,QQ,P,dimP);
	
	cout<<"Iterativa"<<endl;
	for(int i=0;i<5;i++)
    {
		cout<<Q[i]<<" ";
	}
	cout<<endl;
	
	cout<<"Ricorsiva"<<endl;
	for(int i=0;i<5;i++){
		cout<<QQ[i]<<" ";
	}
	cout<<endl;
}
