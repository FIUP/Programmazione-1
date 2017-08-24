// soluzione di B.Cosentino
#include <iostream>
#include "rational.h"

using namespace std;
using namespace Numbers;


// PRE = (viene passato un razionale)
Rational maxunitaria(Rational fr){      // restituisce la maggiore frazione unitaria ma < fr 
    
    Rational ma(1,2);
    // PRE_while = (ma=1/2) & (fr e' un razionale)
    while (Numbers::less(fr,ma)){
    // R_while = (2 <= ma.denominator <= n, dove 1/n <= fr)
        
        ma.denominator=ma.denominator+1;  // incremento il denominatore di 1
    }
    // POST_while = (ma = 1/n) & (ma=1/n <= fr)
    return ma;
}
//***********************************************************
// DIMOSTRAZIONE

// PRE_while -> R_while : (ma=1/2) & (fr=a/b) -> (ma.denominator=2) -> (2 <= ma.denominator) -> R_while valida

// R_while & B <C> R_while : (2 <= ma.denominator <= n, dove 1/n <= fr) & (fr<ma) -> (ma!=1/n) & (2 <= ma.denominator < n, dove 1/n <= fr)
//                          <C>
//                          ma.denominator=ma.denominator+1; 
//                          Quindi (2 <= ma.denominator -1 < n, dove 1/n <= fr) -> (2 <= ma.denominator < n+1, dove 1/n <= fr) ->
//                          -> (2 <= ma.denominator <= n, dove 1/n <= fr) -> R_while valida

// R_while & !B -> POST_while : (2 <= ma.denominator <= n, dove 1/n <= fr) & (ma <= fr) -> (2 <= ma.denominator <= n, dove 1/n <= fr) & (1/ma.denominator <= fr) ->
//                          -> (ma.denominator=n, dove 1/n <= fr) -> (1/n=ma) & (ma=1/n <= fr) -> POST_while valida
//***********************************************************

int main() 
{
    cout << "start" << endl;
    
    int N,D;
    cin >> N >> D;
    
    Rational fraz(N,D);
    Rational diff(1,1);

    if ((N<=0 || D<=0) || !(Numbers::less(fraz,diff)) ){
        cout << "Input non corretto" << endl;
    } else {
        // PRE = (fr=N/D < 1 ) & (diff=1) & (N>0,D>0)
        while (fraz.numerator!=1){
        // R = (N>=fraz.numerator>=1) & (1>=diff>=1/n, dove 1/n>fraz) & (ho stampato tutte le frazioni unitarie della rappresentazione egiziana >= di diff)
            diff=maxunitaria(fraz);
            cout << diff << " + ";
            fraz=sub(fraz,diff);
            fraz=reduce(fraz);  // ho aggiunto quest'istruzione, ma andava in loop nella prima istanza di invocazione diff=maxunitaria(fraz) che e' precedente!
        }
        // POST = (stampa tutte le frazioni della rappresentazione egiziana > fraz) & (fraz=ultima frazione unitaria)
        cout << fraz << endl;
       
    }
    
    cout << "end" << endl;
}

//***********************************************************
//DIMOSTRAZIONE

// PRE -> R : (fr=N/D < 1 ) & (diff=1) & (N>0,D>0) -> (N>=fraz.numerator>=1) & (1>=diff>=1/n, dove 1/n>fraz) & (non esistono frazioni unitarie >= diff=1) ->
//          -> (N>=fraz.numerator>=1) & (1>=diff>=1/n, dove 1/n>fraz) & (ho stampato tutte le frazioni unitarie della rappresentazione egiziana >= diff=1) ->
//          -> R valida

// R & B <C> R : (N>=fraz.numerator>=1) & (1>=diff>=1/n, dove 1/n>fraz) & (ho stampato tutte le frazioni unitarie della rappresentazione egiziana >= diff) &
//              & (fraz.numerator!=1) ->
//              -> (N>=fraz.numerator>1) & (1>=diff>=1/n, dove 1/n>fraz) & (ho stampato tutte le frazioni unitarie della rappresentazione egiziana >= diff)
//              <C>
//              diff=maxunitaria(fraz); diff contiene la massima frazione unitaria minore di fraz
//              ***qui non vale piu' l'invariante poiche' ancora non ho stampato la frazione unitaria diff***
//              cout << diff << " + ";  stampo la frazione unitaria = diff (ovvero l'ultima)
//              ***qui vale di nuovo l'invariante***
//              fraz=sub(fraz,diff);    sottraggo a fraz diff (fraz > 0) -> fraz.numerator >=1
//              fraz=reduce(fraz);      la riduco ai minimi termini
//              -> (N>=fraz.numerator>=1) & (1>=diff>=1/n, dove 1/n>fraz) & (ho stampato tutte le frazioni unitarie della rappresentazione egiziana >= diff) -> R valida

// R & !B -> POST : (N>=fraz.numerator>=1) & (1>=diff>=1/n, dove 1/n>fraz) & (ho stampato tutte le frazioni unitarie della rappresentazione egiziana >= diff) &
//              & (fraz.numerator=1) ->
//              -> (fraz.numerator=1) & (1>=diff>=1/n, dove 1/n>fraz) & (ho stampato tutte le frazioni unitarie della rappresentazione egiziana >= diff) ->
//              -> (diff>fraz) & (fraz=1/fraz.denominator ovvero la piu' piccola frazione unitaria della rappresentazione) & 
//              & (ho stampato tutte le frazioni unitarie della rappresentazione egiziana >= diff) -> 
//              -> (ho stampato tutte le frazioni unitarie della rappresentazione egiziana > fraz) & (fraz=ultima frazione unitaria)
