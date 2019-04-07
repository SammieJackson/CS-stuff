#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED

class Rational{
public:
    Rational(int a, int b);
    Rational(int n);
    Rational operator +(const Rational&)const;
    Rational operator -(const Rational&)const;
    Rational operator *(const Rational&)const;
    Rational operator /(const Rational&)const;
    void operator =(const Rational&)const;
    bool operator ==(const Rational&)const;
    void operator +=(const Rational&);
    void operator -=(const Rational&);
    void operator *=(const Rational&);
    void operator /=(const Rational&);
    operator std::string()const;
    bool iszero()const;
private:
    int numerator, denominator;
    Rational inverse()const;
};

int GCD(int a, int b);
int LCD(int a, int b);

#endif // RATIONAL_H_INCLUDED
