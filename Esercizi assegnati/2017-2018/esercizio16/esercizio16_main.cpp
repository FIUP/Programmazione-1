#include<iostream>
using namespace std;
main()
{
    cout<<"start"<<endl;
    int A[6][8];
    bool B[6][8], b=true;
    for(int i=0; i<6; i=i+1)
        for(int j=0; j<8; j=j+1)
            cin >> A[i][j];
    //parte da fare
    
    
    for(int i=0; i<6; i=i+1){
    	for(int j=0; j<8; j=j+1)
            cout << B[i][j]<<' ';
        cout<<endl;
    }
    cout << "end"<<endl;
}

