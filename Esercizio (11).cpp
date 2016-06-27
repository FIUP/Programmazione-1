#include <iostream>
using namespace std;

int main(){

    int T[10][5], P[2];

    //popolo T da cin
    for(int i=0; i<10; i++)                             //R1=(0<=i<10) && (lette le prime 0..i-1 righe)
        for(int j=0; j<5; j++)                          //R2=(0<=j<5) && (letti i primi 0..j-1 elementi della riga i)
            cin >> T[i][j];

    //popolo P[0] e P[1] da cin
    cin >> P[0] >> P[1];

    int x, y;                                           //match diretti e match inversi
    int xmenoy;                                         //differenza tra diretti e inversi
    int xmenoyMax;                                      //differenza più grande
    int totX, totY, col;                                //match diretti maggiore, match inversi maggiore, indice colonna ricercata

    for(int i=0; i<10; i++){                            //R3=(0<=i<10) && (lette le prime 0..i-1 righe)
        x=0; y=0;                                       //azzero per ogni riga
        for(int j=0; j<4; j++){                         //R4=(0<=j<4) && (letti i primi 0..j-1 elementi della riga i)(fino a 4 perchè i match non sono sovrapposti)
            if(T[i][j]==P[0] && T[i][j+1]==P[1])        //confronto per match diretto elemento j e j+1 con P[0] e P[1]
                    x++;                                //match diretto trovato per ogni riga
            if(T[i][j]==P[1] && T[i][j+1]==P[0])        //confronto per match inverso elemento j e j+1 con P[1] e P[0]
                    y++;                                //match inverso trovato per ogni riga
        }
        xmenoy=x-y;                                     //calcolo differenza per ogni riga

        if(i==0){                                       //solo per la prima riga il valore xmenoy trovato diventa massimo
            xmenoyMax=xmenoy;
            totX=x;
            totY=y;
            col=i;
        }else if(xmenoy>xmenoyMax){                     //per righe successive salvo xmenoy,x,y e i sse (xmenoy maggiore di xmenoyMax)
            xmenoyMax=xmenoy;
            totX=x;
            totY=y;
            col=i;
        }else if(xmenoy == xmenoyMax && x>totX){        //se xmenoy è uguale a xmenoyMax && x>totX
                xmenoyMax=xmenoy;
                totX=x;
                totY=y;
                col=i;
            }//POST=(prendo xmenoy piu grande >> se sono uguali >> prendo x maggiore >> se sono uguali prendo quello con indice di colonna minore)
    }
    cout << "la riga richiesta e':" << col << " con " << totX << " match diritti e " << totY << " match rovesciati";
}
