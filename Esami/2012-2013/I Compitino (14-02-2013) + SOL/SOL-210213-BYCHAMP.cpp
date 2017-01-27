#include<iostream>
#include<fstream>
using namespace std;
/*
A array
ins valore inserito
num # di valori inseriti
*/
//PRE = A[0,num-1] definito
int round(int *A, int ins, int num){
//cout<<"ROUND : (ins "<<ins<<",num"<<num;
	int mod;
	if(num>10)
	{
		mod=(num%10)-1; // indice rappresentante la cella da cui
		A[mod]=ins;
	}else{
		A[num-1]=ins;
	}	
	cout<<",mod "<<mod<<")"<<endl;
	return mod;

}
//POST = mod = all'indice rappresentante la cella più vecchia dell'array ( il primo elemento ) 

//PRE = A[0,9] definito e se num>10 A[index,...,10] meno recenti dei valori in A[0,...,index-1], mentre con num < 10 A[0,num-1] definito
void stampa(int * A, int index,int num){
//cout<<"STAMPA : (index "<<index<<",num"<<num<<")"<<endl;
	if(num>10)
	{
		for(int i=index; i<10;i++){
			cout<<"|"<<A[i]<<"|";
		}
		for(int i=0;i<index;i++){
			cout<<"|"<<A[i]<<"|";
		}		
	} else 
	{
		for(int i=0;i<num;i++)
		{
			cout<<"|"<<A[i]<<"|";
		}
	}
	cout<<endl<<endl;
}
//POST = ( stampa da A[0] ad A[9] sse num <= 10 ) || ( stampa da A[index,...,9] e poi da A[0, index-1] se n > 10 

/*
X array
inserito valore in input
test variabile necessaria per il controllo
index valore rappresentante il primo valore non sovrascritto
num # dei valori inseriti
*/
main(){

int X[10], inserito, test=2;
test = test*(-1);
int index=0;
int num=0;

cout<<"INSERIRE QUANTI NUMERI SI DESIDERA"<<endl;

cin>>inserito;
while(inserito!=-2){
	num++;
	index = round(X,inserito,num);
	cin>>inserito;
} 
stampa(X,index,num);
}
	
