#include<iostream>
using namespace std;

//PRE=(0<=f<lim3, n_el >0)
bool fetta_vuota(int f, int n_el){

    if(n_el<=f)
        return true;
    else
        return false;
}//POST=(restituisce true sse la V-fetta f in un array Y[lim1][lim2][lim3] che contiene n_el elementi inseriti per strati non contiene alcun elemento definito)

//PRE=(0<=f<lim3, e la V-fetta f di Y[lim1][lim2][lim3] con n_el valori inseriti per strati contiene qualche elemento definito)
void match_fetta(int* X, int lim1, int lim2, int lim3, int n_el, int f, int* P, int dimP){

    int k=0, match=0;

    for(int i=0; i<lim1; i++){
        for(int j=0; j<lim2; j++){
            if(X[(i*lim2*lim3)+(j*lim3)+f]==P[k] && ((i*lim2*lim3)+(j*lim3)+f)<n_el){
                if(k+1==dimP){
                    match++;
                    k=-1;
                }
            k++;
            }else
                k=0;
        }
    }
    cout<<"V-fetta "<<f<<"="<<match<<" match"<<endl;
}//POST=(se sulla V-fetta f di Y[lim1][lim2][lim3] ci sono n match (n>=0) di P contigui e non sovrapposti, allora stampa su cout la frase "V-fetta f = n match")


main(){

   int X[400]={}, P[50], n_el, dimP, lim1, lim2, lim3;

   cin>>lim1>>lim2>>lim3;
   cin>>n_el;

   for(int i=0; i<n_el; i++)
     cin >> X[i];
   cin>>dimP;
   for(int i=0; i<dimP; i++)
   cin>>P[i];


    for(int f=0; f<lim3 && !fetta_vuota(f,n_el); f++)
        match_fetta(X, lim1,lim2,lim3,n_el,f, P, dimP);

    cout<<"end"<<endl;
}
