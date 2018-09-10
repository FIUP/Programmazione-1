//Soluzione di S.Righetto

#include<iostream>
using namespace std;

main() //H fette -> righe orizzontali , V fette -> colonne verticali
{                       //PRE=(cin contiene 60 interi, seguiti o dalla coppia "H" x o dalla coppia 'V' y dove x
                        //     sarà tra 0 e 3 e y tra 0 e 4)
    int A[3][4][5];
    for(int i=0; i<3; i=i+1)
        for(int j=0; j<4; j=j+1)
            for(int k=0; k<5; k=k+1)
                cin >> A[i][j][k];

    cout<<"start"<<endl;
    char c;
    int f;
    cin >> c >> f;
    if(c=='H' &&(f<=3)&&(0<=f)) //stampa righe
    {       //stampa H fetta f
        for(int i=0; i<3; i++){         //R (0<=i<=3) && (ho stampato i primi strati i)
            for(int j=0; j<5 ; j++){    //R (0<=j<=5) && (ho stampato i primi j elementi della riga f dello strato i)
                cout<<A[i][f][j] << ' ';
            }
            cout << endl;
        }
    }
    else    //stampa V fetta f // stampa colonne
        if(c=='V' &&(f<=4)&&(0<=f))
        {
            for(int i=0; i<3; i++){
                for(int j=0; j<4 ; j++){
                    cout<<A[i][j][f] << ' ';
                }
            cout << endl;
            }
        }
    
    
    cout<<"end"<<endl;
}                       //POST=(cout deve contenere gli elementi della fetta specificata dalla coppia letta)
