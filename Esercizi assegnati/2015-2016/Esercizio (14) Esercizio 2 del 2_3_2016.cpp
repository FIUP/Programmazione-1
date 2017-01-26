#include<iostream>
using namespace std;

int main(){

    //dichiaro i 2 vettori int e bool
    int A[6][8];
    bool B[8][6];

    //popolo A da cin scorrendo i e j
    for(int i=0; i<6; i++)              //R1=(0<=i<6) && (lette le prime 0..i-1 righe)
        for(int j=0; j<8; j++)          //R2=(0<=j<8) && (letti i primi 0..j-1 elementi della riga i)
            cin >> A[i][j];

    //i e j scorrono ciascun elemento di B[8][6] (i righe, j colonne) dentro scrivo istruzioni per decidere come popolare vettore B (bool)
   for(int i=0; i<8; i++)
        for(int j=0; j<6; j++){
            //continua usato per trovare elementi uguali in A[6][8] confrontando righe (j) e colonne (i)
            //C[8] è usato per eliminare elementi già confrontati di una certa riga (j)
            bool continua = true;
            bool C[8]={0};
            //z e k scorrono elementi di A (z righe, i colonne; j righe, k colonne)
            for(int z=0; z<6 && continua; z++){
                continua = false;
                for(int k=0; k<8 && !continua; k++){
                    if(A[z][i]==A[j][k] && !C[k]){
                        continua=true;
                        C[k]=true;
                    }//continua=true sse (A[z][i] è stato trovato nella riga j) && (non era già stato trovato in precedenza)
                }//POST=(continua=true sse A[i] e' nella colonna A[j])
            }
            if(continua)
                B[i][j]=true;
            else
               B[i][j]=false;
        }

    //stampa B
    for(int i=0; i<8; i++){             //R3=(0<=i<8) && (lette le prime 0..i-1 righe)
        for(int j=0; j<6; j++)          //R4=(0<=j<6) && (letti i primi 0..j-1 elementi della riga i)
            cout << B[i][j] << " ";
        cout << endl;
    }
    //stampa end finale
    cout << "end";
}
