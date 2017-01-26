#include<iostream>
using namespace std;

struct M {int lung, inizioT; M(int a=0, int b=-1){lung=a; inizioT=b;}};

int conta(int* T, int* P, int dimP){
    if(dimP==0)
        return 0;
    if(*T==*P)
        return 1+conta(T+1,P+1,dimP-1);
    return 0;
}

M match(int*T, int dimT, int*P, int dimP, int iT){
    int match=0, maxMatch=0, maxDim=0, ultimoInizioT=-1, inizioT=-1;

    while(dimP>0){                                                  //ripeti fino a quando P ha elementi
        for(int i=iT; i<=(dimT-dimP); i++)                          //ripeti per ogni elemento di T fino a quando non si arriva alla fine e dimP non ci sta piu
            if(conta(T+i, P, dimP)==dimP){                          //entra se conta==dimP (match trovato a partire da T+i)
                match++;                                            //incremento il match
                ultimoInizioT=i;                                    //salvo ultimo inizio di match trovato
            }

        if(match>maxMatch){                                         //entra se match supera maxMatch
            maxMatch=match;                                         //aggiorno con i nuovi dati
            maxDim=dimP;
            inizioT=ultimoInizioT;
        }else if(match==maxMatch && match && dimP>=maxDim){         //se invece i match sono uguali controllo che match non sia 0 e che dimP>=maxDim
            maxMatch=match;
            maxDim=dimP;
            inizioT=ultimoInizioT;
        }
    iT=0;                                                           //azzero iT
    match=0;                                                        //azzero match
    dimP--;                                                         //escludo ultimo elemento di P
    }
    return M(maxDim, inizioT);
}

main(){
    int T[200]={}, P[20]={}, dimT, dimP;

    cin>>dimT;
    for(int i=0; i<dimT;i++)
        cin>>T[i];

    cin>>dimP;
    for(int i=0; i<dimP;i++)
        cin>>P[i];

    M x=match(T,dimT, P, dimP, 0);

    cout<<"[lung="<<x.lung<<" inizioT="<<x.inizioT<<']'<<endl;
    cout<<"end"<<endl;
}
