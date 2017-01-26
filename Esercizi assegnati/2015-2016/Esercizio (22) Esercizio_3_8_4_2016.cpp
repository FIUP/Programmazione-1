#include<iostream>
#include<fstream>
using namespace std;

bool F2(int M[][2], int contaM, int A){
    if(contaM==0)
        return true;
    for(int i=0; i<contaM;i++){
        if(M[i][0]==A)
            return false;
    }
    return true;
}

int F1(int A[], int n, int M[][2]){
    int conta;
    int contaM=0;

    for(int i=0; i<n; i++){             //scorre tutti gli el di A
        conta=0;                        //azzera conta
        if(F2(M, contaM, A[i])){        //se A[i] non è presente in M
            for(int j=i; j<n; j++){     //scorro tutti gli el di A partendo da A[i]
                if(A[i]==A[j])          //se A[i]==A[j]
                    conta++;            //conto el
            }
            M[contaM][0]=A[i];
            M[contaM][1]=conta;
            contaM++;
        }else
            i++;
    }
    return contaM;
}

main(){
    int n_el, A[100], M[100][2], n=0;
    cin>> n_el;
    for(int i=0; i<n_el; i++)
        cin>>A[i];
    n=F1(A,n_el,M);
    cout<<"M contiene:"<<endl;
    for(int i=0; i<n; i++){
        cout<<M[i][0]<<" appare "<<M[i][1]<<" volte"<<endl;
    }
    cout<<"end";
}
