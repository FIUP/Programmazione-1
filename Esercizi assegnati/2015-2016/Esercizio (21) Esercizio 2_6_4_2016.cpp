#include<iostream>
using namespace std;

bool F1(int i, int j, int A[][8][5]){
    bool ok=true;

    bool X[4][8]={};//Array di supporto inizializzato interamente a 0
		for(int k1=0; k1<4 && ok; k1++){//H-Fetta
			for(int k2=0; k2<5 && ok; k2++){
			ok=false;
			//serve F2 che contiene questi 2 cicli
				for(int z1=0; z1<4 && !ok; z1++){//V-Fetta
 					for(int z2=0; z2<8 && !ok; z2++){
						if(!X[z1][z2] && A[k1][i][k2]==A[z1][z2][j]){
				 			ok=true;
 							X[z1][z2]=true;
						 }
				 	}
				}
 			}
		}
    return ok;
}


main(){
    int A[4][8][5];
    bool B[8][5];
    bool ok=true;

    //popolo A da cin con 160 elementi strato riga colonna
    for(int z=0;z<4;z++)
        for(int i=0;i<8;i++)
            for(int j=0;j<5;j++)
                cin >> A[z][i][j];

    //scorro B per riga colonna
    for(int i=0;i<8; i++){
        for(int j=0; j<5; j++){
            B[i][j]=F1(i, j, A); //da fare
        }
    }

    //Stampa B con "end" alla fine
    for(int i=0;i<8;i++){
        for(int j=0;j<5;j++){
            cout << B[i][j] << " ";
        }cout << endl;
    }
    cout << "end" << endl;
}
