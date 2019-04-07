#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <string>
#include "rational.h"

class Vector{
public:
    Vector();
    Vector(const int m, Rational n[]);
    operator std::string()const;
    Vector& operator =(const Vector&);
    Vector& operator +(const Vector&);
    Vector& operator -(const Vector&);
    Rational& operator *(const Vector&);
    void operator +=(const Vector&);
    void operator -=(const Vector&);
//private:
    int vsize;
    Rational arr[1][12];
};

#endif // VECTOR_H_INCLUDED
