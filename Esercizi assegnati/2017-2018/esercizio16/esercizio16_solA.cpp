//Soluzione di S.Righetto
#include<iostream>
using namespace std;
main()
{
    cout<<"start"<<endl;
    int A[6][8];
    bool B[6][8], b=true; //b sentinella
    for(int i=0; i<6; i=i+1)
        for(int j=0; j<8; j=j+1)
            cin >> A[i][j];
    //parte da fare
    for(int i=0; i<6;i++){
        for(int j=0; j<8;j++){
            for(int l=0; l<8; l++){
                for(int k=0; k<6; k++){
                    if( (A[i][l]==A[k][j]) && (A[i][l]!=A[i][j]) )
                        b=false;
            	}        
            }
            if(b) B[i][j]=true;
            else B[i][j]=false;
            b=true;
        }
    }
    for(int i=0; i<6; i=i+1){ //stampa
    	for(int j=0; j<8; j=j+1)
            cout << B[i][j]<<' ';
        cout<<endl;
    }
    cout << "end"<<endl;
}

