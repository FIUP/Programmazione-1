//Soluzione di S.Righetto

#include<iostream>
using namespace std;

int Sric(int *A, int i, int n){
    int b=0; //b è la variabile che contiene il risultato
    if (A[i]==-2) {
        b = -2;
    } else {
        if (n == 0) 
        	b = i;
        else {
            if(A[i]==-1)
                b = Sric(A, i+1, n-1);
            else
                b = Sric(A,i+1,n);
        }
    }
    return b;
}

/*
int Sric(int *A, int i, int n){ //senza allocare b
    if (A[i]==-2)
        return -2;
	if (n == 0) 
        return i;
    if(A[i]==-1)
        return Sric(A, i+1, n-1);
    else
        return Sric(A,i+1,n);
}
*/


main()
{
   int X[400];
   cin>>X[0];
   for(int i=1; i<400 && X[i-1]!=-2; i++)
   cin >>X[i];
    
    int n;
    cin>>n;
    cout<<"start"<<endl;
    int b=Sric(X,0,n); // da fare
    
    if(b==-2)
     cout<<"sottosequenza "<<n<<" non presente"<<endl;
    else
     cout<<"inizio sottosequenza "<<n<<" indice="<<b<<endl;
    cout<<"end"<<endl;
 }
