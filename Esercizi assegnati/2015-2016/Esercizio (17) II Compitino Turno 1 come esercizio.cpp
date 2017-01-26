#include<iostream>
using namespace std;
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
    for(int i=0;i<8;i++){
        for(int j=0;j<5;j++){
            ok=true;
        bool X[4][8]={};//Array di supporto inizializzato interamente a 0
		for(int k1=0; k1<4 && ok; k1++){//H-Fetta
			for(int k2=0; k2<5 && ok; k2++){
			ok=false;
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
		B[i][j]=ok;

            /*bool giusto=true;
            //scorro A per strato
            for(int z=0;z<4 && giusto;z++){
                bool ok=true;
                bool controllo[8]={false,false,false,false,false,false,false,false};
                //scorro A per colonne
                for(int x=0;x<5 && ok;x++){
                    ok=false;
                    //scorro A per righe
                    for(int y=0;y<8 && !ok;y++){
                        if(A[z][i][x]==A[z][y][j] && !controllo[y]){
                            ok=true;
                            controllo[y]=true;

                        }
                    }
                }

                if(ok){
                    giusto=true;
                }
                else{
                    giusto=false;
                }
            }
            if(giusto){
                B[i][j]=true;
            }else{
                B[i][j]=false;
            }
        */
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
