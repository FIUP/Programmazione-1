//Soluzione di S.Righetto
#include<iostream>
using namespace std;

int main(){
    cout << "start" << endl;
    
    int array[10];
    
    for (int i=0; i<10; i++){
        cin >> array[i];    
    }
    
    for (int i=9; i>=0; i--){
        cout << array[i] << " ";
    }
     cout << "end" << endl;
    
    }

