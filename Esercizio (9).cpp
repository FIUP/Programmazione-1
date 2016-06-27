#include<iostream>
//#include <stdlib.h>
using namespace std;

main()
{
    int T[10][5], P[10];
    int p;

    //PRE=(T[10][5])
    for(int i=0; i<10; i++){
        for(int j=0;j<5;j++){
            cin>>T[i][j];
        }
    }
    //POST=(T)

    //PRE P
    p=0;    //azzero p per scorrere vettore P[10]
    while(p<10){
        cin>>P[p];
        p++;
    }
    //POST P

    //PRE=(T[10][5])
    int j,i, contaC=0;
    bool stop;
    j=0;    //azzero j per scorrere righe di T
    while(j<5)
    {   //R=(0<=j<5)
        i=0;    //azzero i per scorrere colonne di T e P
        stop=false;
        while(i<10 && !stop)
        {   //R=(0<=i<10 && stop è falso)
            if(T[i][j]!=P[i]){  //stop diventa vero appena T[i][j] è diverso da P[i] con 0<=j<5
                stop=true;
            }
            i++;
        }
        if(i==10 && !stop)
        {   //R=(i==0 && stop è falsa)
            contaC++;
        }
        j++;
    }
    //POST=(n. colonne di T[0..10-1][j] uguali a P[0..10-1] con 0<=j<=5-1)

    cout << "n. di colonne uguali a P e': " << contaC << endl;

    //PRE
    int contaMiss, piuMiss, colonnaMenoMiss;
    j=0;
    colonnaMenoMiss=-1;
    piuMiss=10;
    while(j<5)
    {   //R=(0<=j<5)
        i=0;    //azzero i per scorrere colonne di T e P
        contaMiss=0;
        while(i<10)
        {   //R=(0<=i<10)
            if(T[i][j]!=P[i]){
                contaMiss++;
            }
            i++;
        }
        if(i==10 && (contaMiss<piuMiss))
        {   //R=(i==0 && (0<=contaMiss<piuMiss))
            piuMiss=contaMiss;
            colonnaMenoMiss=j;
        }
        j++;
    }
    //POST

    cout << "la prima colonna con meno errori e' la " << colonnaMenoMiss << " con " << piuMiss << " errori";
}
