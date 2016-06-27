#include<iostream>
using namespace std;

int main(){                                             //PRE=("input" contiene 40 interi, seguiti o dalla coppia "H" x o dalla coppia 'V' y dove x sarà tra 0 e 3 e y tra 0 e 4)
    int X[2][4][5];
    char indiceL;
    int indiceN;

    //popolo X
    for(int z=0; z<2; z++)                              //R1=(0 <= z < 2) && (letti i primi 0..z-1 strati)
        for(int i=0; i<4; i++)                          //R2=(0 <= i < 4) && (lette le prime 0..i-1 righe dello strato z)
            for(int j=0; j<5; j++)                      //R3=(0 <= j < 5) && (letti i primi 0..j-1 elementi della riga i)
                cin >> X[z][i][j];

    //input indice lettera, indice numero con controlli
    do{                                                 //ripeti se indiceL non e' H o V
    cin >> indiceL;
    }while(indiceL!='H' && indiceL!='V');
    do{                                                 //ripeti se indiceL e' H e indiceN non e' compreso tra 0..4, se indiceL e' V e indiceN non e' compreso tra 0..3
    cin >> indiceN;
    }while(indiceN<0 && ((indiceL=='H' && indiceN>4) || (indiceL=='V' && indiceN>3)));

    for(int z=0; z<2; z++){                             //R4=(0 <= z < 2) && (letti i primi 0..z-1 strati)
        if(indiceL=='H'){                               //se orizontali
            for(int j=0; j<5; j++){                     //R5=(0 <= j < 5) && (letti i primi 0..j-1 elementi della riga indice)
                cout << X[z][indiceN][j] << " ";
            }cout << endl;
        }else if(indiceL=='V'){                         //se verticali
            for(int i=0; i<4; i++){                     //R6=(0 <= i < 4) && (letti i primi indiceN elementi delle 0..i-1 righe)
                cout << X[z][i][indiceN] << " ";
            }
        }cout << endl;
    }
}                                                       //POST=("output" deve contenere gli elementi della fetta specificata dalla coppia letta)
