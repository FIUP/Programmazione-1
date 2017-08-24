// soluzione di B.Cosentino
#include<iostream>
using namespace std;

// PRE = (A contiene una sequenza di sottosequenze che finiscono con -1 e essa conclude con un -2) & (0<=a)
int S(int *A, int a){
    int ind=0;
    // PRE1 = (ind=0) & (a>=0) & (A e' definito come descritto sopra)
    while (A[ind]!=-2 && a>0){
    // R1 = (a>=0) & (0<=ind<=x, dove A[x]=-2 e' l'ultimo elemento di A) & (a==(valore iniziale di a) - (numero di sequenze trovate da 0 a ind-1))
        if (A[ind]==-1)
            a=a-1;
        ind=ind+1;
    }
    // POST1 = (se A contiene la sottosequenza a, ind contiene l'indice in cui la sottosequenza (valore iniziale di a) inizia. Altrimenti contiene l'indice dell'ultimo elemento di A)
    
    if (A[ind]==-2) //se ho ottenuto l'ultimo elemento di A restituisco al chiamante -2
        return -2;
    return ind; // altrimenti restituisco l'indice della sottosequenza
}
// POST = (se A contiene la sottosequenza a, allora S restituisce l'indice di A in cui la sottosequenza a inizia. Altrimenti S restituisce -2)

// PRE <ind=0> PRE1 : banale

// PRE1 -> R1 : (ind=0) & (a>=0) & (A contiene una sequenza di sottosequenze che finiscono con -1 e essa conclude con un -2) -> 
//              -> (a>=0) & (0<=ind<=x, dove A[x]=-2 e' l'ultimo elemento di A) & (a==valore iniziale di a) -> R valida

// R1 & B <C> R1 : (a>=0) & (0<=ind<=x, dove A[x]=-2 e' l'ultimo elemento di A) & (a==(valore iniziale di a) - (numero di sequenze trovate da 0 a ind-1)) & (A[ind]!=-2) & (a>0) -> 
//              -> (a>0) & (0<=ind<x, dove A[x]==-2) & (a==(valore iniziale di a) - (numero di sequenze trovate da 0 a ind-1))
//              <C>
//              Se A[ind]==-1 allora e' finita una sequenza. Quindi a viene decrementato e vale(a==(valore iniziale di a) - (numero di sequenze trovate da 0 a ind))
//              Infine, ind viene incrementato -> R1 valida

// R1 & !B -> POST1 : (a>=0) & (0<=ind<=x, dove A[x]=-2 e' l'ultimo elemento di A) & (a==(valore iniziale di a) - (numero di sequenze trovate da 0 a ind-1)) & ((A[ind]==-2) || (a<=0)) ->
//                  -> 2 casi:
//                  1) (a>=0) & (A[ind]==-2) & (0<=ind<=x, A[x]=-2 e' l'ultimo elemento di A) & (a==(valore iniziale di a) - (numero di sequenze trovate da 0 a ind-1)) ->
//                  -> ((valore iniziale di a) - (numero di sequenze trovate da 0 a ind-1)>=0) & (ind==x, ovvero l'ultimo indice di A) -> POST1 vera
//                  2) (a==0) & (0<=ind<=x, dove A[x]=-2 e' l'ultimo elemento di A) & (a==(valore iniziale di a) - (numero di sequenze trovate da 0 a ind-1)) ->
//                  -> ((valore iniziale di a) - (numero di sequenze trovate da 0 a ind-1)==0) & (0<=ind<=x, dove A[x]=-2 e' l'ultimo elemento di A) ->
//                  -> ((valore iniziale di a)==(numero di sequenze trovate da 0 a ind-1)) (0<=ind<=x, dove A[x]=-2 e' l'ultimo elemento di A) -> 
//                  -> (ho trovato la sottosequenza (valore iniziale di a)) & (ind contiene l'indice di inizio della sottosequenza) -> POST1 verificata.

// POST1 <if> POST : Se A[ind] == -2 allora la funzione restituisce -2 -> POST
//                   Altrimenti, ind e' l'indice della sottosequenza cercata e viene restituito -> POST

main()
{
    int X[400];
    cin>>X[0];
    
    for(int i=1; i<400 && X[i-1]!=-2; i++)
        cin >>X[i];
    
    int a;
    cin>>a;
    
    cout<<"start"<<endl;
    
    int b=S(X,a); // da fare
    if(b==-2)
        cout<<"sottosequenza "<<a<<" non presente"<<endl;
    else
        cout<<"inizio sottosequenza "<<a<<" indice="<<b<<endl;
    
    cout<<"end"<<endl;
 }
