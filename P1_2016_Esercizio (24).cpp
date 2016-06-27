#include<iostream>
using namespace std;

//da true sse M sta in N
bool G(int M[][2],int dimM,int N[][2],int dimN){
    bool continua = true;

    if(dimM>dimN)
        return false;
    for(int i=0; i<dimM && continua; i++){
        for(int j=0; j<dimN && continua; j++){
            if(M[i][0]==N[j][0]){
                if(M[i][1]>N[j][1])
                    continua=false;
                else
                    j=dimN-1;
            }else if(j==(dimN-1))
                continua=false;
        }
    }
    if(continua)
        return true;
    else
        return false;
}

//controlla che int A non sia presente in M[][]
bool F2(int M[][2], int contaM, int A){
    if(contaM==0)
        return true;
    for(int i=0; i<contaM;i++){
        if(M[i][0]==A)
            return false;
    }
    return true;
}

int F1(int A[], char lettera, int rigaI, int lim1, int lim2, int lim3, int n, int M[][2]){
    int conta;
    int contaM=0;

    if(lettera=='H'){//0..lim2
        for(int x=0;x<lim1;x++){
            for(int i=0; i<lim3; i++){          //scorre  gli el di A della riga rigaI
                if(((x*lim2*lim3)+(lim3*rigaI)+i)<n){
                    conta=0;                        //azzera conta
                    if(F2(M, contaM, A[(x*lim2*lim3)+(lim3*rigaI)+i])){         //se A[] non è presente in M
                        for(int k=x;k<lim1;k++){
                            for(int j=0; j<lim3; j++){
                                if(A[(x*lim2*lim3)+(lim3*rigaI)+i]==A[(k*lim2*lim3)+(lim3*rigaI)+j])
                                    conta++;            //conto el
                            }
                        }
                        M[contaM][0]=A[(x*lim2*lim3)+(lim3*rigaI)+i];
                        M[contaM][1]=conta;
                        contaM++;
                    }
                }
            }
        }
        return contaM;
    }else if(lettera=='V'){//rigaI 0..lim3
        for(int x=0;x<lim1;x++){
            for(int i=0; i<lim2; i++){          //scorre  gli el di A della colonna i
                if(((x*lim2*lim3)+(lim3*rigaI)+i)<n){
                    conta=0;                        //azzera conta
                    if(F2(M, contaM, A[(x*lim2*lim3)+(lim3*i)+rigaI])){         //se A[] non è presente in M
                        for(int k=x;k<lim1;k++){
                            for(int j=0; j<lim2; j++){
                                if(A[(x*lim2*lim3)+(lim3*i)+rigaI]==A[(k*lim2*lim3)+(lim3*j)+rigaI])
                                    conta++;            //conto el
                            }
                        }
                        M[contaM][0]=A[(x*lim2*lim3)+(lim3*i)+rigaI];
                        M[contaM][1]=conta;
                        contaM++;
                    }
                }
            }
        }
        return contaM;
    }
}

main(){
    int X[400], lim1, lim2, lim3, n_el;

    cin>>lim1>>lim2>>lim3>>n_el;
    bool B[lim2][lim3];

    for(int i=0; i<n_el; i++)
        cin>>X[i];
    //controllare
    if(n_el > lim1*lim2*lim3)
        n_el=lim1*lim2*lim3;

    for(int i=0; i<lim2; i++){//0..5
        for(int j=0; j<lim3; j++){//0..4

            //costruisco M per H-fetta i
            int M[lim1*lim3][2];
            int dimM=F1(X,'H',i,lim1,lim2,lim3,n_el,M);

            //costruisco N per V-fetta j per comparare con M
            int N[lim1*lim2][2];
            int dimN=F1(X,'V',j,lim1,lim2,lim3,n_el,N);

            //da true sse M sta in N
            B[i][j]=G(M, dimM, N, dimN);
        }
    }

    for(int i=0; i<lim2; i++){
        for(int j=0; j<lim3; j++)
            cout<<B[i][j]<<' ';
        cout<<endl;
    }
    cout<<"end";

}
