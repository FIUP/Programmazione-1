#include<iostream>
using namespace std;

bool MATCH_RAW(int* T,int* P,int n, int col, int& indice){

    for(int raw=indice;raw<n;raw++){
        if(T[(raw*n)+col]==P[col])
        {
            indice=raw;
            return true;
        }
    }
    return false;
}

int* F(int* T,int* P,int n){
    int* R= new int[n];
    int indice=0;

    for(int col=0;col<n;col++){
        if(MATCH_RAW(T,P,n,col,indice))
            R[col]=indice;
        else
            return 0;
    }
    return R;
}

bool MATCH_RAWR(int *T,int * P, int n, int& indice, int pos){
    if(pos==n)
        return false;
    if(T[pos*n]==*P){
        indice=pos;
        return true;
    }
    return MATCH_RAWR(T,P,n,indice,pos+1);
}

int * Fric (int *T,int n,int * P,int *R,int indice,int col,bool OK) {
    if(col==n){
        if(OK)
            return R;
        return 0;
    }
    OK=MATCH_RAWR(T+col,P,n,indice,indice);
    if(OK){
        R[col]=indice;
        Fric(T,n,P+1,R,indice,col+1,OK);
    }
    else
        return 0;
}

main(){

    int n=3;
    int T[9]={7,9,2,8,8,4,10,8,10};
    int P[3]={8,8,10};
    int *R=new int[n];

    R=Fric(T,n,P,R,0,0,0);

    if(R){
    for(int i=0;i<n;i++){
            cout<<R[i]<<" ";
        }
    }
    else
        cout<<"non esiste match"<<endl;
}
