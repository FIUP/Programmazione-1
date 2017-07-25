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
    
    Rational add(Rational a, Rational b){
        
        a.numerator = a.numerator*b.denominator + b.numerator*a.denominator;
        a.denominator = a.denominator*b.denominator;
        
        return a;
    }
    
    Rational sub(Rational a, Rational b){
        
        a.numerator = a.numerator*b.denominator - b.numerator*a.denominator;
        a.denominator = a.denominator*b.denominator;
        
        return a;
    }
    
    Rational mul(Rational a, Rational b){
        
        a.numerator = a.numerator*b.numerator;
        a.denominator = a.denominator*b.denominator;
        
        return a;
    }
    
    Rational div(Rational a, Rational b){
    
        a.numerator = a.numerator*b.denominator;
        a.denominator = a.denominator*b.numerator;
        if (a.denominator<0){
            a.denominator*=-1;
            a.numerator*=-1;
        }
        return a;
    }
    
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
    
    bool less(Rational a, Rational b){ // (a=a1/a2 e b=b1/b2 -> a<b sse a1/a2 < b1/b2 sse a1*b2 < b1*a2)
        
        return ( (a.numerator*b.denominator) < (b.numerator*a.denominator) );
    }
    
    std::ostream & operator<<(std::ostream & s, Rational & r){
        s << r.numerator << "/" << r.denominator << " ";
    }
}
