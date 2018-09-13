//Soluzione di S.Righetto

#include<iostream>
using namespace std;

int S(int *A, int n){
    int m=0,s=0;
    bool trovato=false;
    
    for(int i=0; i<400 &&A[i]!=-2&&!trovato; i++){
        //if(s!=0) m=i;
        if(s==n) {
            trovato=true;
            m=i;
        }
        if(A[i] ==-1) {
            s++;
            }
        }
    if(trovato) return m;
    return -2;
}


main()
{
   int X[400];
   cin>>X[0];
   for(int i=1; i<400 && X[i-1]!=-2; i++)
   cin >>X[i];
    
    int n;
    cin>>n;
    cout<<"start"<<endl;
    int b=S(X,n); // da fare

    if(b==-2)
     cout<<"sottosequenza "<<n<<" non presente"<<endl;
    else
     cout<<"inizio sottosequenza "<<n<<" indice="<<b<<endl;
    cout<<"end"<<endl;
 }
