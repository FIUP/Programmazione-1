#include<iostream>

namespace Numbers {
    
    struct Rational{
        int numerator;
        int denominator;
        
        Rational(int num=0, int den=1);
    };

    Rational add(Rational a, Rational b);

    Rational sub(Rational a, Rational b);

    Rational mul(Rational a, Rational b);

    Rational div(Rational a, Rational b);

    Rational reduce(Rational a);
    
    bool less(Rational a, Rational b);

    std::ostream & operator<<(std::ostream & s, Rational & r);
}