#include "vector.h"
#include <iostream>

using namespace std;

Vector::Vector(){vsize=1; arr[0][0]=0;}

Vector::Vector(const int m, Rational n[12])
{
    vsize=m;
    for (int i=0; i<m; i++){
        arr[0][i]=n[i];
    }
}

Vector::operator std::string()const{
    std::string oss="";
    for(int i=0; i<vsize; i++){
        oss += string(arr[0][i]) + "   ";
    }
    return oss;
}

Vector& Vector::operator =(const Vector& that){
    vsize=that.vsize;
    for (int i=0; i<vsize; i++){
        arr[0][i]=that.arr[0][i];
    }
    return *this;
}

Vector& Vector::operator +(const Vector& other){
    if (vsize != other.vsize) {cout<<"\n Error - arrays of different size.\n"; Rational n[1]{0};Vector vect(1, n); return vect;}
    Rational myarr[vsize];
    for (int i=0; i<vsize; i++){
        myarr[i]=this->arr[0][i]+other.arr[0][i];
    }
    Vector vect(vsize, myarr);
    return vect;
}

Vector& Vector::operator -(const Vector& other){
    if (vsize != other.vsize) {cout<<"\n Error - arrays of different size.\n"; Rational n[1]{0}; Vector vect(1, n); return vect;};
    Rational myarr[vsize];
    for (int i=0; i<vsize; i++){
        myarr[i]=this->arr[0][i]-other.arr[0][i];
    }
    Vector vect(vsize, myarr);
    return vect;
}

Rational& Vector::operator *(const Vector& b){
    Rational product=0;
    if (vsize != b.vsize) cout<<"\n FOO!\n"; else {
    for (int i=0; i<vsize; i++){
        product += this->arr[0][i]*b.arr[0][i];
    }
    }
    return product;
}

void Vector::operator +=(const Vector& other){
    *this = *this + other;
    return;
}

void Vector::operator -=(const Vector& other){
    *this = *this - other;
    return;
}
