// soluzione di B.Cosentino
#include <iostream>
#include "rational.h"

using namespace std;

namespace Numbers {
    
    Rational::Rational(int num, int den){
        
        if (den>0){
            numerator=num;
            denominator=den;
        } else {
            numerator=0;
            denominator=0;
        }
    }
    
    // PRE = (vengono passati due parametri di tipo Rational)
    Rational add(Rational a, Rational b){
        
        a.numerator = a.numerator*b.denominator + b.numerator*a.denominator;
        a.denominator = a.denominator*b.denominator;
        
        return a;
    }
    // POST = (restituisce la somma non ridotta ai minimi termini di a e b)
    
    // PRE = (vengono passati due parametri di tipo Rational) 
    Rational sub(Rational a, Rational b){
        
        a.numerator = a.numerator*b.denominator - b.numerator*a.denominator;
        a.denominator = a.denominator*b.denominator;
        
        return a;
    }
    // POST = (restituisce la sottrazione non ridotta ai minimi termini tra a e b)
    
    // PRE = (vengono passati due parametri di tipo Rational)
    Rational mul(Rational a, Rational b){
        
        a.numerator = a.numerator*b.numerator;
        a.denominator = a.denominator*b.denominator;
        
        return a;
    }
    // POST = (restituisce la moltiplicazione non ridotta ai minimi termini di a per b)
    
    // PRE = (vengono passati due parametri di tipo Rational)
    Rational div(Rational a, Rational b){
        
        a.numerator = a.numerator*b.denominator;
        a.denominator = a.denominator*b.numerator;
        if (a.denominator<0){
            a.denominator*=-1;
            a.numerator*=-1;
        }
        return a;
    }
    // POST = (restituisce la divisione non ridotta ai minimi termini di a per b)
    
    // PRE = (viene passato un parametro di tipo Rational)
    Rational reduce(Rational a){
        
        int n=a.numerator;
        int M=a.denominator;
        int r=n%M;
        
        while (r != 0){ // trovo MCD tra il numeratore e il denominatore (algoritmo di Euclide)
            n=M;
            M=r;
            r=n%M;
        }
        // POST_while = (M contiene l'MCD tra numeratore e denominatore di a)
        if (M<0) 
            M*=-1;
        
        a.numerator=a.numerator/M;
        a.denominator=a.denominator/M;
        return a;
    }
    // POST = (restituisce la riduzione ai minimi termini della frazione a)
    
    
    std::ostream & operator<<(std::ostream & s, Rational & r){
        cout << r.numerator << "/" << r.denominator << " ";
    }
}
