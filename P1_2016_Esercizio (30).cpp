#include <iostream>
#include <fstream>
using namespace std;

struct nodoM {int lung, inizioT; nodoM* next; nodoM(int a=0, int b=-1, nodoM* c=0){lung=a; inizioT=b; next=c;}};

int conta(int* T, int* P, int dimP){
    if(dimP==0)
        return 0;
    if(*T==*P)
        return 1+conta(T+1,P+1,dimP-1);
    return 0;
}

nodoM* match(int* T, int dimT, int* P, int dimP, int iT){
    if(iT>dimT)				    //se si supera ultimo elemento
        return 0;				//ritorna zero
    if(*T == *P)				//compara T e P con rispettivo iTesimo elemento
        nodoM* temp = new nodoM(conta(T,P,dimP),iT,match(T+1,dimT,P,dimP,iT+1));				//uso variabile temp di tipo nodoM per creare la funzione ricorsiva
    else				        //se T e P non sono uguali passo ad elemento successivo
        return match(T+1,dimT,P,dimP,iT+1);
}

void stampa(nodoM*a){
    if(a){
        cout<<"[lung="<<a->lung<<" inizioT="<<a->inizioT<<']';
        if(a->next){
            cout<<"->"; stampa(a->next);
        }else{
            cout<<endl;
        }
    }else{
        cout<<"[]"<<endl;
    }
}

main(){
    int T[200]={}, P[20]={}, dimT, dimP;

    cin>>dimT;
    for(int i=0; i<dimT;i++)
        cin>>T[i];

    cin>>dimP;
    for(int i=0; i<dimP;i++)
        cin>>P[i];

    nodoM* x=match(T,dimT, P, dimP, 0);                 // funzione ricorsiva da fare

    stampa(x);                                          //data
    cout<<"end"<<endl;
}
