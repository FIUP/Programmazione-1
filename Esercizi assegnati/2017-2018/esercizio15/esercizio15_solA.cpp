//Soluzione di S.Righetto
#include<iostream>
using namespace std;
int main(){
    //se ho doppioni devo togliere tutti i valori che si ripetono, lasciando solo quello più a sinistra
    //non devo allocare nessun nuovo array, ma vado a modificare il presente
    // se ho un array formato da [3 2 (2 5)] andrò a sovrascrivere l'array così [3 (2 5)]
    //di fatto quando trovo un valore che si ripete vado a sovrascriverlo con la coda dell'array
    
    cout << "start"<< endl;
    int n, N, array[100];
    cin >>N; //dimensione dell'array
    if((N<100)&&(N>0)){ //se la dimensione è compresa tra zero e cento riempio l'array
        for(int i=0; i<N;i++){
            cin >> n; //intero da inserire nell'array
            array[i]=n;
        }
    }
    int pos=0; //posizione che vado a togliere ogni volta che trovo un doppione
    for(int i=0; i< (N-1-pos); i++){ //controllo da 0 alla fine dell'array meno le posizioni tolte (all'inizio 0)
        for(int k=i+1; k<(N-pos); k++){ //controllo dalla posizione successiva al primo ciclo
        //se ho [3 2 2 5] i punta al 3, mentre k dovrà puntare ai valori restanti successivi ossia 2 2 5, quindi k punterà a 2
            if(array[i]==array[k]){ //controllo che i valori nella posizione i e k siano uguali nell'esempio 3 = 2 ?
                pos++; // se questi lo sono allora andrò ad aumentare pos(i numeri tolti finora)
                for(int j=k; j<(N-pos); j++){ //vado a spostare la coda dell'array scrivendo sopra al doppione
                    array[j]=array[j+1]; 
                }
                k--; //tolgo un k perchè ovviamente devo andare a ricontrollare che il primo valore della coda non sia di nuovo un doppione
            }//se i valori sono diversi non devo fare nulla, vado avanti a controllare i successivi
        }
    }
    cout << "m = " << N-pos << endl << "A = " ;  
    for(int i=0; i<N-pos; i++) //stampa dell'array senza ripetizioni
        cout<< array[i] << ' ';
    cout<< endl << "end";
}

