// soluzione di B.Cosentino
#include <iostream>
#include "code.h"

using namespace std;


void contr(coda &Q){
    
    char c;
    cin >> c;
    
    if (c=='.')
        return;
        
    if (c=='*'){
        cout << ' ';
        if (e_vuota(Q)){
            cout << "vuota";
        } else {
            cout << pop(Q);
        }
        cout << ' ';
    } else {
        push(c,Q);
    }
    
    contr(Q);
    
}

int main() 
{
    coda Q;
    
    cout << "start" << endl;
    
    /*
    while (c!='.'){
        if (c=='*'){
            cout << ' ';
            if (e_vuota(Q)){
                cout << "vuota";
            } else {
                cout << pop(Q);
            }
            cout << ' ';
        } else {
            push(c,Q);
        }
        
        cin >> c;
    }
    */
    
    contr(Q);
    
    
    cout << endl << "end" << endl;
}


