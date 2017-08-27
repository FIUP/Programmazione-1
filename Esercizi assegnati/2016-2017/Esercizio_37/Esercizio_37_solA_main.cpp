// soluzione di B.Cosentino
#include <iostream>
#include "rational.h"

using namespace std;
using namespace Numbers;

int main() 
{
    cout << "start" << endl;
    char op;
    Rational a,b;
    
    cin >> a.numerator >> a.denominator;
    
    cin >> op;
    
    // PRE_while = (a non e' definita) & (op e' un carattere tra '+', '-', '*', '/' oppure 'q') & (non e' stato stampato nulla)
    while (op!='q'){
    // R_while = ((op=='+') || (op=='-') || (op=='*') || (op=='/') || (op=='q')) & (ho stampato i risultati di tutte le operazioni precedenti)
        cin >> b.numerator >> b.denominator;
        switch (op){
            case '+':
                a=add(a,b);
                break;
                
            case '-':
                a=sub(a,b);
                break;
                
            case '*':
                a=mul(a,b);
                break;
                
            case '/':
                a=div(a,b);
                break;
        }
        
        if (a.denominator > 0){ // 
            a=reduce(a);
        } else {
            a.numerator=0;
            a.denominator=0;
        }
        cout << a;
        cin >> op;
    }
    // POST_while = (ho stampato i risultati di tutte le operazioni tra razionali eseguite) 
    cout << "end" << endl;
}

//****************************************************
// DIMOSTRAZIONE

// PRE_while -> R_while : (a non e' definita) & (op e' un carattere tra '+', '-', '*', '/' oppure 'q') & (non e' stato stampato nulla) -> 
//                      -> ((op=='+') || (op=='-') || (op=='*') || (op=='/') || (op=='q')) & (ho stampato i risultati di tutte le operazioni precedenti (inesistenti)) 
//                      -> R_while valida

// R_while & B <C> R_while : ((op=='+') || (op=='-') || (op=='*') || (op=='/') || (op=='q')) & (ho stampato i risultati di tutte le operazioni precedenti) & (op!='q') ->
//                          -> ((op=='+') || (op=='-') || (op=='*') || (op=='/')) & (ho stampato i risultati di tutte le operazioni precedenti)
//                          <C>
//                          cin >> b.numerator >> b.denominator;    viene preso in input l'altro razionale su cui operare
//                          Viene effettuata un l'operazione op scelta e il risultato viene assegnato alla variabile a
//                          if (a.denominator > 0)                  Se il risultato e' valido
//                              a=reduce(a);                        allora riduco ai minimi termini, 
//                          else {a.numerator=0; a.denominator=0}   altrimenti pongo a=0/0
//                          
//                          Stampo il risultato dell'operazione attuale -> ho stampato tutte le operazioni precedenti e quella attuale
//                          Accetto la nuova operazione. Quindi adesso a contiene il risultato dell'operazione precedente e a e' stato stampato 
//                          -> ((op=='+') || (op=='-') || (op=='*') || (op=='/') || (op=='q')) & (ho stampato i risultati di tutte le operazioni precedenti) ->
//                          -> R_while valida

// R_while & !B -> POST_while : ((op=='+') || (op=='-') || (op=='*') || (op=='/') || (op=='q')) & (ho stampato i risultati di tutte le operazioni precedenti) &
//                              & (op=='q') ->
//                              -> (op=='q') & (ho stampato i risultati di tutte le operazioni precedenti) -> POST_while valida

//****************************************************
