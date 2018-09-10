//Soluzione di S.Righetto

#include <iostream>
using namespace std;

void minimo(int *A, int lung, int i){
    int temp;
    if(i<lung-1){ 
        minimo(A,lung,i+1); //faccio tutte le chiamate, quindi tornando indietro ho sempre un valore in più da inserire correttamente nell'array
        if(A[i+1]<A[i]){ //se il prossimo è piu piccolo dell'attuale
            temp=A[i]; //scambio il successivo con l'attuale 
            A[i]=A[i+1];
            A[i+1]=temp;
        }
    }
}

void ordina(int *A, int lung){
    int i=0;
    if(lung>2)
        ordina(A,lung-1); //faccio tutte le chiamate finchè non ho al più due valori da confrontare
    minimo(A,lung,i); //inserisco il numero nella posizione corretta
    i++; //aumento di uno per il numero appena inserito
}
    
void stampa(int *A, int lung,int i){
    if(i<lung){
    cout << A[i] << ' ';
    stampa(A,lung,i+1);
    }
}    

int main() 
{
    int lung;
    int A[100];
    cin >> lung;
    for(int i = 0; i < lung; i++) { 
        cin >> A[i];
    }
    cout << "start" << endl;

    ordina(A,lung);
    stampa(A,lung,0);

    cout<< endl << "end" << endl;
}
