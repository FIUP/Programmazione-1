#include<iostream>
using namespace std;
//PRE=(cin contiene un intero conta > 0, seguito da conta valori)
main()
{
    int A[20], conta;
    cin>>conta;
    for(int i=0; i<conta; i++){
        cin>>A[i];
    }

    int maxocc= 0, vr;
    for(int i=0; i<conta; i=i+1){
    //R=(0<=i<=conta)&&(se maxocc>0 allora e' il max n. di occ. tra gli elemeti in
    // A[0..i-1] alla loro destra e vr e' il valore piu' a sin. che appare maxocc volte
    //alla sua destra)&&(se maxocc=0 true)

        int cocc=1;
        for(int j=i+1; j<conta; j++){
        //R=(i+1<=j<=conta) &&(cocc conta il numero di occorrenze di A[i] in A[i..j-1])
            if(A[i]==A[j]){
                cocc=cocc+1;
            }
        }
        if(cocc>maxocc){
            maxocc=cocc;
            vr=A[i];
        }
    }

    for (int i=0; i<conta; i++){
            if(A[i]==vr){
                conta--;

                for(int j=0; j<conta; j++){
                    A[i]=A[i+1];
                    i++;
                }
                i=-1; //-1 perche alla fine del ciclo for i diventa i++, ma a me serve che riparta da 0
            }
    }

    cout << "il valore che occorre di piu' e' " << vr << " e ripete " << maxocc << " volte" << endl;
    cout << "il nuovo A contiene i seguenti " << conta << " valori:";

    for(int i=0;i<conta;i++){
       cout << " " << A[i];
    }

    //POST=(vr e' l'elemento di A che appare piu' volte e appare maxocc
    //volte, in caso di parita' vr e' il primo da sinistra con questa proprieta')
}
