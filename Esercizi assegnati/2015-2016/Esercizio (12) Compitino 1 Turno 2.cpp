#include <iostream>
using namespace std;

int main(){

    int T[8][6], P[2], Pinv[2];

    for(int i=0; i<8; i++)
        for(int j=0; j<6; j++)
            cin >> T[i][j];

    cin >> P[0] >> P[1];

    int x, y;                                               //match diretti e match inversi
    int xmenoy;                                             //x - y
    int xmenoyMax;                                          //x - y piu grande
    int totX, totY, col;                                    //X piu grande, Y piu grande, indice colonna ricercata
    for(int i=0; i<6; i++){                                 //scorro colonne con i
        xmenoy=0;
        x=0;
        y=0;
        for(int j=0; j<7; j++){         //scorro righe con j
            if(T[j][i]==P[0] && T[j+1][i]==P[1])          //confronto per match diretto
                x++;
            if(T[j][i]==P[1] && T[j+1][i]==P[0])
                y++;
        }

        xmenoy=x-y;                     //x-y per ogni riga

        if(i==0){                       //solo per la prima riga i valori diventano massimi
        xmenoyMax=xmenoy;
        totX=x;
        totY=y;
        col=i;
        } else if(xmenoy>xmenoyMax){     //per righe successive se x-y è maggiore del Massimo
            xmenoyMax=xmenoy;
            totX=x;
            totY=y;
            col=i;
        } else if(xmenoy==xmenoyMax && y<totY){     //se sono uguali prendo quello con match inverso minore
            totX=x;
            totY=y;
            col=i;
        }
		//prendo x-y piu grande >> se sono uguali >> prendo y minore >> se sono uguali prendo quello con indice di colonna minore
    }
    cout << "la colonna richiesta e':" << col << " con " << totX << " match diritti e " << totY << " match rovesciati";
}
