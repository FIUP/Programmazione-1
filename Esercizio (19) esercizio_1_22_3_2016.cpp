#include<iostream>
#include<fstream>
using namespace std;

int S(int *X, int n){
    int i, conta=0;
    for(i=0; (X[i]!=-2) && (conta<n);i++)
        if(X[i]==-1)
            conta++;

    if(conta==n && X[i]!=-2)
        return i;
    else
        return -2;
}

main(){

    int X[100];

    cin>>X[0];

    for(int i=1; i<100 && X[i-1]!=-2; i++){
       cin>>X[i];
    }

    int a;

    cin>>a;

    int b=S(X,a); // funzione da fare

    if(b==-2)
        cout<<"sottosequenza "<<a<<" non presente"<<endl;
    else
        cout<<"inizio sottosequenza "<<a<<" indice="<<b<<endl;

    cout<<"end"<<endl;

}
